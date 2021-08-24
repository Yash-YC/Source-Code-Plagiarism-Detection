Const   MaxN    =       12000000;
Var
	Tests,N,Ans,i,tts,k     :LongInt;
	ff		        :Boolean;
	b		        :Array[0..10] of LongInt;
        lis                     :Array[0..MaxN] of LongInt;
        F                       :Array[0..MaxN,0..10] of LongInt;

	Function Check(x,p:LongInt):LongInt;
	Var	t,w,y   :LongInt;
	Begin
		If F[x,p]>0 Then Exit;
		lis[0]:=1;
		lis[1]:=x;
		F[x,p]:=0;
		While x<>1 do
                Begin
			t:=x; w:=0;
			While t>0 do
			Begin
				w:=w+(t Mod p)*(t Mod p);
				t:=t Div p;
			End;
                        x:=w;
			If F[x,p]>0 Then
			Begin
				While lis[0]>0 do
				Begin
					F[lis[lis[0]],p]:=F[x,p];
					Dec(lis[0]);
				End;
                                Exit;
			End
			Else
			If F[x,p]=0 Then
			Begin
				F[x,p]:=2;
				While lis[0]>0 do
				Begin
					F[lis[lis[0]],p]:=F[x,p];
					Dec(lis[0]);
				End;
                                Exit;
			End
			Else
			Begin
				F[x,p]:=0;
				Inc(lis[0]);
				lis[lis[0]]:=x;
			End;
                End;
	End;
Begin
	Assign(Input,'A.in');Reset(Input);
	Assign(Output,'A.out');Rewrite(Output);

	FillChar(F,SizeOf(F),$FF);
        For k:=2 to 10 do
        Begin
                i:=1;  F[1,k]:=1;
                While i<MaxN do
                Begin
                        Inc(i);
                        Check(i,k);
                End;
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
                        If F[Ans,b[i]]=2 Then
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
