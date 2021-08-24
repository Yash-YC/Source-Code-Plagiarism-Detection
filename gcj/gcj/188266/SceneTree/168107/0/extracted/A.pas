Const   MaxN    =       100000;
Var
	Tests,N,Ans,i,tts,k     :LongInt;
	ff		        :Boolean;
	b		        :Array[0..10] of LongInt;
        H                       :Array[0..MaxN] of Boolean;
        F                       :Array[0..MaxN,0..10] of Boolean;

	Function Check(x,p:LongInt):Boolean;
	Var	t,w	:LongInt;
	Begin
                FillChar(H,SizeOf(H),0);
		While True do
                Begin
                        If x=1 Then Exit(True);
                        If H[x] Then Exit(False);
                        H[x]:=True;
			t:=x; w:=0;
			While t>0 do
			Begin
				w:=w+(t Mod p)*(t Mod p);
				t:=t Div p;
			End;
                        x:=w;
		End;
		Exit(x=1);
	End;
Begin
	Assign(Input,'A.in');Reset(Input);
	Assign(Output,'A.out');Rewrite(Output);

        i:=1;
        While i<MaxN do
        Begin
                Inc(i);
                For k:=2 to 10 do
                F[i,k]:=Check(i,k);
        End;

	Readln(Tests);
        tts:=0;
	While Tests>0 do
	Begin
		Dec(Tests);

                Inc(tts);
                Write('Case #',tts,': ');

		N:=0;
		While Not Eoln do
		Begin
			Inc(N);
			Read(b[N]);
		End;Readln;
		Ans:=2;
		While True do
		Begin
			ff:=True;
			For i:=1 to N do
                        If Not F[Ans,b[i]] Then
			Begin
				ff:=False;
				Break;
			End;
			If ff Then Break;
			Inc(Ans);
		End;
		Writeln(Ans);
	End;

	Close(Input);Close(Output);
End.
