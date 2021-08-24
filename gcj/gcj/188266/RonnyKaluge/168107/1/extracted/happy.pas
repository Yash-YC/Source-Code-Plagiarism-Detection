const pangkat:array[2..10]of integer=(1,2,4,8,16,32,64,128,256);
var a:array[1..1001,2..10]of boolean;
    i,j,k,l,m,n,t:longint;
    udah:array[0..1001]of boolean;
    bisa:array[2..10]of byte;
    s:string;
    belum:boolean;
    basis:array[1..10]of integer;
    cek:array[0..10]of boolean;
    uda:array[0..513]of longint;

function proses(basis,bil:longint):boolean;
var digit:array[1..20]of integer;
    i,j:longint;
begin
  for i:=1 to 1000 do udah[i]:=false;
  while (bil<>1)and(not udah[bil]) do
  begin
    udah[bil]:=true;
    i:=1;
    while bil>=basis do
    begin
      digit[i]:=bil mod basis;
      bil:=bil div basis;
      inc(i);
    end;
    digit[i]:=bil;
    bil:=0;
    for j:=1 to i do bil:=bil+digit[j]*digit[j];
  end;
  proses:=bil=1;
end;

function proses2(basis,bil:longint):boolean;
var digit:array[1..20]of integer;
    i,j:longint;
begin
  i:=1;
  while bil>=basis do
  begin
    digit[i]:=bil mod basis;
    bil:=bil div basis;
    inc(i);
  end;
  digit[i]:=bil;
  bil:=0;
  for j:=1 to i do bil:=bil+digit[j]*digit[j];
  proses2:=a[bil,basis];
end;

begin
  assign(output,'output.out');rewrite(output);
  assign(input,'input.in');reset(input);
  for i:=1 to 1000 do
    for j:=2 to 10 do a[i][j]:=proses(j,i);
  for i:=0 to 512 do uda[i]:=0;
  readln(t);
  for i:=1 to t do
  begin
    readln(s);
    k:=0;
    for j:=1 to length(s) do
      if (s[j]>='2') and(s[j]<='9') then
      begin
        inc(k);
        basis[k]:=ord(s[j])-48;
      end else if (s[j]='1') then
      begin
        inc(k);
        basis[k]:=10;
      end;
    n:=0;
    for m:=1 to k do
    begin
      cek[basis[m]]:=true;
      n:=pangkat[basis[m]]+n;
    end;
    if uda[n]>0 then l:=uda[n]
    else if cek[5] and cek[6] and cek[7] and cek[8] and cek[9] and cek [10] then l:=11814485
    else
    begin
      belum:=false;
      for l:=2 to 11814485 do
      begin
        belum:=true;
        for m:=1 to k do belum:=belum and proses2(basis[m],l);
        if belum then break;
      end;
      uda[n]:=l;
    end;
    writeln('Case #',i,': ',l);
    for m:=0 to 10 do cek[m]:=false;
  end;
  close(input);
  close(output);
end.