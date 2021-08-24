Program gcj_a;
Const
  Maxn = 10;
  Maxm = 1000;
Var
  i, j, k, m, n, p, q, x, y, t, tt, v, ans : longint;
  a : array[1 .. Maxn] of longint;
  b : array[1 .. Maxm] of longint;
Begin
  assign(input, 'a.in');
  assign(output, 'a.out');
  reset(input);
  rewrite(output);
  readln(t);
  for tt := 1  to  t  do
  begin
    n := 0;
    while not eoln do
    begin
      inc(n); read(a[n]);
    end;
    readln;
    for i := 2  to  Maxlongint  do
    begin
     for v := 1  to  n  do
      begin
        j := i; k := 0;
        for p := 1  to  100 do
        begin
          if j = 1 then begin k := 1; break; end;
          x := 0; y := j;
          while y <> 0 do
          begin
            inc(x);
            b[x] := y mod a[v];
            y := y div a[v];
          end;
          j := 0;
          for y := 1  to  x  do
           j := j + b[y] * b[y];
        end;
        if k = 0 then break;
      end;
     if k = 1 then
     begin
       ans := i;
       break;
     end;
    end;
    writeln('Case #', tt, ': ', ans);
  end;
  close(input);
  close(output);
End.
