program Problem_A;
{$APPTYPE CONSOLE}
const
  maxLimit = 30000000;
  
var
  T, z: Integer;
  i, j: Integer;
  bc, bb: Integer;
  F: array [1..maxLimit, 2..10] of Integer; // 0 uncalced 1 okay 2 not possible -1 in progress
  bases: array [1..10] of Integer;
  Current: array [1..10] of Integer;
  Flag: Boolean;

procedure BaseConvert(u, base: Integer);
begin
  bb := 0;
  while u <> 0 do
    begin
      inc(bb);
      Current[bb] := u mod base;
      u := u div base
    end  
end;

procedure Calculate(u, base: Integer);
var
  i, p: Integer;

begin
  BaseConvert(u, base);
  if u > maxLimit then
    halt;
  p := 0;
  for i := 1 to bb do
    inc(p, sqr(Current[i]));
  case F[p, base] of
    0: begin
      F[u, base] := -1;
      Calculate(p, base);
      F[u, base] := F[p, base]
    end;

    1: F[u, base] := 1;
    2: F[u, base] := 2;
    -1: F[u, base] := 2
  end
end;

begin
  assign(input, 'A-large.in');
  assign(output, 'A-large.out');
  fillchar(F, sizeof(F), 0);
  for i := 1 to 10 do
    F[1, i] := 1;
  for i := 1 to maxLimit do
    for j := 1 to 10 do
      if F[i, j] = 0 then
        Calculate(i, j);
  reset(input);
  rewrite(output);
  readln(T);
  for z := 1 to T do
    begin
      bc := 0;
      while not eoln do
        begin
          inc(bc);
          read(bases[bc])
        end;
      readln;
      i := 2;
      while i <= maxLimit do
        begin
          Flag := True;
          for j := 1 to bc do
            if F[i, bases[j]] = 2 then
              begin
                Flag := False;
                break
              end;
          if Flag then
            begin
              writeln('Case #', z, ': ', i);
              break
            end;
          inc(i)
        end
    end;
  close(input);
  close(output)
end.
