var t0,sum,n,ca,i,p,t,ans:longint;
    z:boolean;
    z0,opt:array[1..10000000,2..10]of boolean;
    a:array[1..100]of integer;
    c:array[1..10000000,2..10]of boolean;

function check(n:longint;b:integer):boolean;
var nt,t,sum:longint;
begin
nt:=n;
if z0[nt,b] then exit(opt[nt,b]);
sum:=0;
if n<>0 then
repeat
t:=n mod b;
inc(sum,sqr(t));
n:=n div b;
until n=0;
if not c[sum,b] then
begin
c[sum,b]:=true;
check:=check(sum,b);
c[sum,b]:=false;
z0[nt,b]:=true;
opt[nt,b]:=check;
end else check:=false;
end;

begin
assign(input,'1.in');reset(input);
assign(output,'1.out');rewrite(output);
for i:=2 to 10 do begin z0[1,i]:=true;opt[1,i]:=true;end;

readln(ca);
for p:=1 to ca do
begin
t0:=0;
repeat
inc(t0);
read(a[t0]);
until eoln(input);
readln;
ans:=1;
repeat
inc(ans);
if ans=143 then
i:=i;
z:=true;
for i:=1 to t0 do
if not check(ans,a[i]) then begin z:=false;break;end;
until z;
writeln('Case #',p,': ',ans);
end;
close(input);
close(output);
end.

