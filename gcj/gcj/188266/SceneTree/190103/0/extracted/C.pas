Var
	Tests,A,B,tts   :LongInt;
Begin
	Assign(Input,'C.in');Reset(Input);
	Assign(Output,'C.out');Rewrite(Output);

	Readln(Tests);
	While Tests>0 do
	Begin
		Dec(Tests);

		Readln(A,B);
                Inc(tts);
		Writeln('Case #',tts,': ',(A+B)/B:0:7);
	End;

	Close(Input);Close(Output);
End.
