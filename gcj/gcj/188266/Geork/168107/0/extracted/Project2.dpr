program Project2;

{$APPTYPE CONSOLE}
 {$O- $H+}
uses
  SysUtils;
type long=array[-1..1000] of byte;
var g:array[2..10] of long;
    a:array[1..500] of byte;
    b:array[2..10,1..10000000] of byte;
    n,i,j,m,max:integer;
    s:int64;
    t:boolean;
    c:char;
procedure sum1( var g:long);
var c,i:integer;
begin
  c:=1;
  i:=1;
  while (i<=g[0]) and (c>0) do
  begin
    c:=c+g[i];
    g[i]:=c mod g[-1];
    c:=c div g[-1];
    inc(i);
  end;
  if c>0 then
  begin
    inc(g[0]);
    g[g[0]]:=1;
  end;
end;
function f10(g:long):int64;
var l,s:int64;
    i:integer;
begin
  l:=1;
  s:=0;
  for i:=1 to g[0] do
  begin
    s:=s+g[i]*l;
    l:=l*g[-1];
  end;
  f10:=s;
end;
function fi(s:int64; k:integer):long;
var i:integer; g:long;
begin
  i:=0;
  g[-1]:=k;
  while s>0 do
  begin
    inc(i);
    g[i]:=s mod k;
    s:=s div k;
  end;
  g[0]:=i;
  fi:=g;
end;
function happy(g:long):boolean;
var i:integer; s:int64; t:boolean;
begin
  if b[g[-1],f10(g)]=1 then happy:= true else
  if (b[g[-1],f10(g)]=0) or (b[g[-1],f10(g)]=4) then happy:=false else
  begin
    b[g[-1],f10(g)]:=4;
    s:=0;
    for i:=1 to g[0] do s:=s+g[i]*g[i];
    t:=happy(fi(s,g[-1]));
    if t then b[g[-1],f10(g)]:=1 else b[g[-1],f10(g)]:=0;
    happy:=t;
  end;
end;
function f(i:integer):long;
var g:long;
begin
  g[0]:=1; g[1]:=1; g[-1]:=i;
  repeat
  sum1(g);
  until happy(g);
  f:=g;
end;
begin
  reset(input,'A-small-attempt1.in'); rewrite(output,'A-small-attempt1.out');
  readln(n);
  for i:=2 to 10 do
  begin               
    b[i,1]:=1;
    for j:=2 to 100000 do
      b[i,j]:=3;
  end;
  for i:=2 to 10 do
    g[i]:=f(i);
  for i:=1 to n do
  begin
    m:=0;
    while not(seekeoln) do
    begin
      inc(m);
      read(a[m]);
    end;
    readln;
    max:=1;
    for j:=2 to m do
      if f10(g[a[j]])>f10(g[a[max]]) then max:=j;
    s:=f10(g[a[max]])-1;
    repeat
      s:=s+1;
      t:=true;
      for j:=1 to m do
      begin
        t:=t and happy(fi(s,a[j]));
      end;
    until t=true;
    writeln('Case #',i,': ',s);
  end;
end.
