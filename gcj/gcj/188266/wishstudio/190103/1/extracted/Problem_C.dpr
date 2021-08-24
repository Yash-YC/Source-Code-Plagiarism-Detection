program Problem_C;
{$APPTYPE CONSOLE}
const
  maxN = 40;
  maxC = 40;
  maxLimit = 10000;

var
  T, z: Integer;
  N, C: Integer;
  i, j, k: Integer;
  CC: array [0..maxN, 0..maxN] of Extended;
  F: array [1..maxLimit, 0..maxC] of Extended;
  Ans: Extended;

function min(a, b: Integer): Integer; inline;
begin
  if a < b then
    Result := a
  else
    Result := b
end;

begin
  assign(input, 'C-large.in');
  assign(output, 'C-large.out');
  for i := 0 to maxN do
    begin
      CC[i, 0] := 1;
      CC[i, i] := 1;
      for j := 1 to i - 1 do
        CC[i, j] := CC[i - 1, j] + CC[i - 1, j - 1]
    end;
  reset(input);
  rewrite(output);
  readln(T);
  for z := 1 to T do
    begin
      fillchar(F, sizeof(F), 0);
      readln(C, N);
      F[1, N] := 1;
      Ans := F[1, C];
      for i := 2 to maxLimit do
        begin
          for j := N to C do
            for k := 0 to N do
              if (j <> C) or (k <> 0) then
                F[i, j] := F[i, j] + F[i - 1, j - k] * CC[C - j + k, k] * CC[j - k, N - k] / CC[C, N];
          Ans := Ans + F[i, C] * i
        end;
      writeln('Case #', z, ': ', Ans:0:10)
    end;
  close(output);
  close(input)
end.
