var a,b : array[1..10] of longint;
    test,t,i,n,j,ii : longint;
    ok : boolean;
function check(num , base : longint) : boolean;
var x,xx,s : longint;
 begin
   x := 0;
   while true do begin
     if x > 100 then break;
     inc(x);
     xx := num; s:= 0;
     while xx > 0 do begin
       s := s + sqr(xx mod base);
       xx := xx div base;
     end;
     if (s = 1) then exit(true);
     num := s;
   end;
   check:=false;
 end;
begin
  assign(input ,'input.txt' ); reset(input);
  assign(output , 'output.txt'); rewrite(output);
    readln(test);
    for t :=1 to test do begin
      n:=0;
      while not eoln do begin
        inc(n);
        read(a[n]);
      end;
      readln;
      i := 2;
      while true do begin
        ok := true;
        for j:=1 to n do
          if (check(i , a[j]) = false) then begin ok:=false; break; end;
        if ok then break;
        inc(i);
      end;
      writeln('Case #',t,': ',i);
    end;
  close(output);
end.
