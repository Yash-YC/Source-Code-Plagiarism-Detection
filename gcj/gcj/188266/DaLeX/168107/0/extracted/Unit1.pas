unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    dlgOpen1: TOpenDialog;
    btn1: TButton;
    edt1: TEdit;
    mmo1: TMemo;
    procedure btn1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.btn1Click(Sender: TObject);
type numbers=record
       digits:array[1..100]of Integer;
       nd,base:Integer;
     end;
Var infile, outfile:textfile;
    cn,number,i,p,k,T,numbases : integer;
    cnumber:numbers;
    bases,happy:array[1..10]of Integer;

function allhappy:Integer;
var i:Integer;
begin
  result:=1;
  for i:=1 to numbases do result:=result*happy[i];
end;

procedure GetDigits(number,base:integer);
var i:Integer;
Begin
  i:=1;
  repeat
    cnumber.digits[i]:=number mod base;
    number:=number div base;
    Inc(i);
  until number=0;
  cnumber.nd:=i-1;
End;

function GetNumber:Integer;
var i:Integer;
Begin
  result:=0;
  for i:=1 to cnumber.nd do result:=Result+cnumber.digits[i]*cnumber.digits[i];
End;

begin
  If dlgOpen1.Execute Then begin
    Mmo1.Lines.Clear;
    Assignfile(infile, dlgOpen1.FileName);
    reset(infile);
    assignfile(outfile,edt1.Text);
    rewrite(outfile);
    Readln(infile, T);
    for i:=1 to T do begin
      numbases:=0;
      while (not Eoln(infile))and(not Eof(infile))do begin
        Inc(numbases);
        read(infile, bases[numbases]);
      end;
      if not Eof(infile)then readln(infile);
      for k:=1 to numbases do happy[k]:=0;
      number:=1;
      While allhappy=0 do begin
        inc(number);
        for k:=1 to numbases do happy[k]:=0;
        For k:=1 to numbases do begin
          p:=0;
          cn:=number;
          while (p<1000)and(happy[k]=0) do begin
            GetDigits(cn,bases[k]);
            cn:=GetNumber;
            if cn=1 then happy[k]:=1;
            inc(p);
          end;
        end;
      end;
      mmo1.Lines.Add(IntToStr(number));
      writeln(outfile, 'Case #',i,': ',number);
    end;
    closefile(infile);
    closefile(outfile);
  end;
end;

end.
