var co:array[1..40,0..40] of double;
    t1,t2,i,j,n,c:longint;
    tmp,a1,q:double;
    f:array[1..40] of double;

function max(x,y:longint):longint;
  begin
    if x>y then max:=x
           else max:=y;
  end;

begin
  assign(input,'c.in');
  assign(output,'c.out');
  reset(input);
  rewrite(output);
  readln(t1);
  co[1,0]:=1; co[1,1]:=1;
  for i:=2 to 40 do
    begin
      co[i,0]:=1; co[i,i]:=1;
      for j:=1 to i-1 do
        co[i,j]:=co[i-1,j]+co[i-1,j-1];
    end;
  for t2:=1 to t1 do
    begin
      readln(c,n);
      f[n]:=1;
      for i:=n+1 to c do
        begin
          tmp:=0;
          for j:=i downto max(n,i-n) do
            begin
              if j=c then continue;
              a1:=co[j,n-i+j]*co[c-j,i-j]/ co[c,n]; q:=co[j,n]/co[c,n];
              tmp:=tmp+((f[j]+1)*a1+a1*q/(1-q))/(1-q);
            end;
          f[i]:=tmp;
        end;
      write('Case #',t2,': ');
      writeln(f[c]:0:7);
    end;
  close(input);
  close(output);
end.
