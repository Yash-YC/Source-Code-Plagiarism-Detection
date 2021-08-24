const
  fi='';
  fo='';
type
  m2=array[1..100000,2..10] of integer;
  m3=array[1..100000,2..10] of boolean;
  m1=array[1..10] of boolean;
var f,g:text;
    t:longint;
    dung: boolean;
    ans: longint;
    a:m1;
    b:m2;
    c:m3;
procedure mofile;
begin
  assign(f,fi);
  reset(f);
   assign(g,fo);
   rewrite(g);
end;
procedure dongfile;
begin
  close(f);
  close(g);
end;
procedure input;
var so: longint;
begin
  fillchar(a,sizeof(a),false);
  while not(seekeoln(f)) do
   begin
   read(f,so);
   a[so]:=true;
   end;
  readln(f);
end;
function chuyen(u,v:longint):longint;
var i,j,gt: longint;
begin
  gt:=0;
  j:=1;
  while u>0 do
   begin
   i:=u mod v;
   gt:=gt+i*i;
   u:=u div v;
   end;
  exit(gt);
end;
procedure visit(u,v: longint);
var u1: longint;
begin
   c[u,v]:=true;
  u1:=chuyen(u,v);
  if b[u1,v]<>0 then begin b[u,v]:=b[u1,v]; exit end;
  if c[u1,v]=true then begin b[u,v]:=-1; exit; end;
  visit(u1,v);
  b[u,v]:=b[u1,v];
end;
function happy(u,v:longint):integer;
begin
 if b[u,v]<>0 then exit(b[u,v]);
 visit(u,v);
 exit(b[u,v]);
end;
procedure chbi;
var i:longint;
begin
  fillchar(b,sizeof(b),0);
 fillchar(c,sizeof(c),false);
  for i:=2 to 10 do
    begin
    b[1,i]:=1;
    c[1,i]:=true;
    end;
end;
procedure solve;
var i,j:longint;
     top:boolean;
begin
     ans:=0;
     dung:=false;
     for i:=2 to 1000000 do
       begin
        top:=false;
        for j:=2 to 10 do
         if a[j] then
          if happy(i,j)=-1 then
           begin
           top:=true;
           break;
           end;
         if top=false then
          begin
          ans:=i;
          exit;
          end;
       end;
end;
procedure output;
begin
   writeln(g,'Case #',t,': ',ans);
end;
procedure bailam;
begin
    input;
    solve;
    output;
end;
begin
  mofile;
   readln(f,t);
     chbi;
   for t:=1 to t do
     bailam;
  dongfile;
end.