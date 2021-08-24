program conapp_A_2;

uses Windows, SysUtils;

{$R *.RES}
{$APPTYPE CONSOLE}

type
  TTestCount = 1..500;
  TBaseCount = 0..10;
  TBase = 2..10;
const
  //FILE_IN = 'A-test.in.txt';
  //FILE_OUT = 'A-test.out.wri';
  FILE_IN = 'A-small.in.txt';
  FILE_OUT = 'A-small.out.wri';
  //FILE_IN = 'A-large.in.txt';
  //FILE_OUT = 'A-large.out.wri';
  SQRS: array[0..9]of byte = (0, 1, 4, 9, 16, 25, 36, 49, 64, 81);

var T_TestCount: TTestCount;
    N_BaseCount: TBaseCount;
    Bases: array[TBaseCount] of TBase;
    T: TTestCount;
    FileIn: TextFile;
    FileOut: TextFile;
    X: integer;
    B: TBaseCount;
    IsMultiHappy: boolean;

procedure ReadTest;
begin
  N_BaseCount := 0;
  while not EoLn(FileIn) do begin
    inc(N_BaseCount);
    Read(FileIn, Bases[N_BaseCount]);
  end;
  ReadLn(FileIn);
end;

function HappySum(no: integer; base: TBase): integer;
var s: integer;
    nodd: integer;
begin
  nodd := 0;
  s := 0;
  while no>0 do begin
    s := s + SQRS[no mod base];
    //if odd(no mod base) then inc(nodd);
    no := no div base;
  end;
  HappySum := s;
  //if (s>1) and (odd(nodd)) then HappySum := 0;
end;

function IsHappy(no: integer; base: TBase): boolean;
var Bad: set of byte;
begin
  Bad := [];
  repeat
    Bad := Bad +[no];
    no := HappySum(no, base);
  until (no=1)or(no =0)or(no in Bad);
  IsHappy := (no = 1);
end;

begin
  AssignFile(FileIn, FILE_IN);
  AssignFile(FileOut, FILE_OUT);
  try
    Reset(FileIn);
    Rewrite(FileOut);
    ReadLn(FileIn, T_TestCount);
    for T:=1 to T_TestCount do begin
      ReadTest;
      isMultiHappy := false; X := 1;
      while not isMultiHappy do begin
        inc(X); B := 1;
        while (B<=N_BaseCount)and(IsHappy(X,Bases[B])) do inc(B);
        isMultiHappy := (B>N_BaseCount);
      end;
      Write(FileOut, 'Case #'+IntToStr(T)+': ', X, Chr($0A));
    end;
  finally
    CloseFile(FileOut);
    CloseFile(FileIn);
  end;
end.
