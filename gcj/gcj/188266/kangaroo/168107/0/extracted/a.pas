var h:array[1..1000000] of boolean;
    a,base:array[1..100] of longint;
    f:array[2..10,1..1000000] of longint;
    t1,t2,n,i,j,len:longint;
    check:boolean;

procedure change(k,base:longint);
  begin
    len:=0;
    while k<>0 do
      begin
        len:=len+1; a[len]:=k mod base; k:=k div base;
      end;
  end;

function ok(k,base:longint):boolean;
var t,bak:longint;
  begin
    if f[base,k]<>0
      then begin
             if f[base,k]=1 then exit(true) else exit(false);
           end;
    fillchar(h,sizeof(h),false);
    h[k]:=true;  bak:=k;
    while true do
      begin
        if f[base,k]=2 then begin f[base,bak]:=2; exit(false);end;
        change(k,base); t:=0;
        while len<>0 do
          begin
            t:=t+sqr(a[len]); len:=len-1;
          end;
        if t=1 then begin f[base,bak]:=1; exit(true); end;
        if h[t]
          then break else h[t]:=true;
        k:=t;
      end;
    f[base,bak]:=2;
    exit(false);
  end;

begin
  assign(input,'tmp.in');
  reset(input);
  for i:=2 to 10 do
    for j:=2 to 400000 do
      read(f[i,j]);
  close(input);
  assign(input,'a.in');
  assign(output,'a.out');
  reset(input);
  rewrite(output);
  readln(t1);
  fillchar(f,sizeof(f),0);
  for t2:=1 to t1 do
    begin
      n:=0;
      while not eoln do
        begin
          n:=n+1; read(base[n]);
        end;
      readln;
      for i:=2 to 400000 do
        begin
          check:=true;
          for j:=1 to n do
            if ok(i,base[j])=false
              then begin
                     check:=false; break;
                   end;
          if check
            then begin
                   writeln('Case #',t2,': ',i); break;
                 end;
        end;
    end;
  close(input);
  close(output);
end.
