program gcjroundI1;
 var
  a,t,ti,i,b:longint;
  base:array[1..9] of longint;
  s:string;
  sl:boolean;
 function check(a,b:longint):boolean;
  var
   i,t1,t2,a1,a2:longint;
  begin
   t1:=a;t2:=a;
   repeat
    a1:=t1;t1:=0;
    while a1>0 do
     begin
      t1:=t1+(a1 mod b)*(a1 mod b);a1:=a1 div b;
     end;
    a2:=t2;t2:=0;
    while a2>0 do
     begin
      t2:=t2+(a2 mod b)*(a2 mod b);a2:=a2 div b;
     end;
    a2:=t2;t2:=0;
    while a2>0 do
     begin
      t2:=t2+(a2 mod b)*(a2 mod b);a2:=a2 div b;
     end;
   until (t1=1) or (t1=t2);
   if t1=1 then exit(true) else exit(false);
  end;
 begin
  assign(input,'a.in');
  assign(output,'a.out');
  reset(input);rewrite(output);
  readln(t);
  for ti:=1 to t do
   begin
    a:=0;
    while not eoln(input) do begin inc(a);read(base[a]);end;
    readln;
    b:=1;sl:=false;
    while not sl do
     begin
      inc(b);sl:=true;
      for i:=1 to a do
       if not check(b,base[i]) then begin sl:=false;break;end;;
     end;
    writeln('Case #',ti,': ',b);
   end;
  close(input);close(output);
 end.
