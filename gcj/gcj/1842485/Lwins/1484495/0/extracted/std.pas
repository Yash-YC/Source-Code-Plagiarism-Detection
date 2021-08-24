Var
  x0,y0,t:int64;
  n,w,l,u:longint;
  r,x,y:array[0..3000] of int64;
  i,j,group,tot:longint;
  o,p:array[0..3000] of longint;
Function Dfs(k:longint):boolean;
var
  t,i:longint;
  flag:boolean;
begin
  if k=n+1 then exit(true);

  t:=2;
  repeat
    dec(t);
    x0:=random(w+1);
    y0:=random(l+1);
    flag:=true;
    for i:=1 to k-1 do
      if sqr(x0-x[i])+sqr(y0-y[i])<sqr(r[i]+r[k]) then
      begin
        flag:=false;
        break;
      end;
    x[k]:=x0; y[k]:=y0;
    if flag and Dfs(k+1) then exit(true);
  until t=0;
  exit(false);
end;
Begin
  randomize;
  assign(input,'d:\work\0526\b\in.txt');
  assign(output,'out.txt');
  reset(input);
  rewrite(output);
  read(tot);
  for group:=1 to tot do
  begin
    read(n,w,l);
    for i:=1 to n do begin read(r[i]); o[i]:=i; end;
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if r[i]<r[j] then
        begin
          t:=r[i]; r[i]:=r[j]; r[j]:=t; u:=o[i]; o[i]:=o[j]; o[j]:=u;
        end;
    Dfs(1);
    for i:=1 to n do p[o[i]]:=i;
    write('Case #',group,':');
    for i:=1 to n do write(' ',x[p[i]],' ',y[p[i]]);
    writeln;
  end;
End.