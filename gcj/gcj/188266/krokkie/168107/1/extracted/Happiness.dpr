program Happiness;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  classes, math;


const MAXBASE = 10;
const MAXCACHE = 12000000;     //11814485
const MAXDIGS = 30;

const
  UNINIT = 0;
  HAPPY = 1;
  UNHAPPY = 2;
  BUSY = 3;
  //positive nrs =


var
  T : integer; //500 max,  number of cases

  cache : array[2..10, 1..MAXCACHE] of integer;



Function IsHappy(base, nr : integer): integer;
var dig : array[0..MAXDIGS] of integer;
    i, nrdigits, nrx : integer;
begin
  if (nr=1) or (cache[base,nr] = HAPPY) then begin
    IsHappy := HAPPY; //irespective of base;
    exit;
  end;

  if (cache[base,nr] = BUSY) or (cache[base,nr] = UNHAPPY) then begin  //detected a loop - i.e. UNHAPPY
    IsHappy := UNHAPPY;
    exit;
  end;

  if((base=4) and (nr=5)) then
    base := 4;

  assert(cache[base,nr]=UNINIT, 'Found '+IntToStr(cache[base,nr])+' in the cache...');
  //we need to find out now...
  cache[base,nr] := BUSY;

  i := 0;
  nrx := nr;
  while (nrx > 0) and (i < MAXDIGS) do begin
    dig[i] := nrx mod base;
    nrx := (nrx - dig[i]) div base;
    inc(i);
  end;
  nrDigits := i;
  assert(nrx = 0, 'Too many digits - ' + IntToStr(nr)+' in base '+intToStR(base));
  nrx := 0;
  for i := 0 to nrDigits - 1 do
    nrx := nrx + dig[i]*dig[i];

  assert(nrx <= MAXCACHE);
  cache[base, nrx] := IsHappy(base, nrx);
  IsHappy := cache[base, nrx];

end;

Procedure InitHappyMatrix();
var i, j : integer;
begin
  fillchar(cache, sizeof(cache),0);

  for i := 2 to MAXBASE do
    for j := 1 to MAXCACHE do
       cache[i,j] := IsHappy(i,j);

end;


Function Solve(s : string) : Integer;
var GCD : array[1..MAXCACHE] of integer;
    i,j,l : integer;
    k : boolean;
    digs : array of integer;
begin
  //split s into array of integer;
  Setlength(digs, 10); //max
  i := 0;
  s := trim(s);
  while s <> '' do begin
    assert((length(s)<=2) or (copy(s,2,1)=' ') or (copy(s,3,1)=' '), 'Foudn string "'+s+'"');
    if copy(s,2,1)=' ' then begin
      digs[i] := StrToInt(s[1]);
      s := trim(copy(s,3,length(s)));
    end else begin
      //double digits
      digs[i] := StrToInt(copy(s,1,2));
      s := trim(copy(s,3,length(s)));
    end;
    inc(i);
  end;

  l := 2;
  while (l < MAXCACHE) do begin
    k := true;
    for j := 0 to i-1 do begin //nr of digits;
      k := k  and (cache[digs[j],l] = HAPPY);
      //debug
 //     if l=91 then writeln(digs[j], ' ', cache[digs[j],l]);
    end;
    if k then begin
      Solve := l;
      exit;
    end;
    inc(l);
  end;

  Solve := -1;
end;

Procedure ReadInputs();
var i, r, c : integer;
    fle : text;
    s : string;
begin
  AssignFile(fle, paramstr(1));
  reset(fle);

  InitHappyMatrix;

  readln(fle, T);
  for i := 1 to T do begin
    readln(fle, s);

    //find MCD in the cache between the bases....
    writeln('Case #',i,': ',Solve(s));
  end;

  CloseFile(fle);
end;

var timer : TDateTime;
//main program
begin
  timer := now();
  try
  if (paramcount<>1) or (not fileExists(paramstr(1))) then begin
    writeln('Usage: '+paramstr(0)+' <inputfile>');
    halt(1)
  end;

  ReadInputs;
  except on e : exception do
    writeln(e.message);
  end;
  // Writeln((now()-timer)*24*3600,' seconds');
end.
