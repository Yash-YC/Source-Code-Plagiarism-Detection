var	c:array[0..50,0..50]of extended;
	f:array[0..50]of extended;
	i,j,n,m,Tests,Cases:longint;
	p,s:extended;
begin
	assign(input,'input.txt');
	reset(input);
	assign(output,'output.txt');
	rewrite(output);
	readln(Tests);
	for Cases:=1 to Tests do
	begin
		write('Case #', Cases, ': ');
		readln(m,n);
		for i:=0 to 40 do
		begin
			c[i][0]:=1;
			c[i][i]:=1;
		end;
		for i:=2 to 40 do
			for j:=1 to i-1 do
				c[i][j] := c[i-1][j-1] + c[i-1][j];
		f[m]:=0;
		for i:=m-1 downto 0 do
		begin
			s:=0;
			for j:=1 to m-i do
				s:=s + c[i][n - j] * c[m - i][j] / c[m][n] * (f[i + j] + 1);
			p := c[i][n] / c[m][n];
			if i < n then f[i] := s
			else f[i] := (s + p) / (1 - p);
		end;
		writeln(f[0] : 0 : 7);
	end;
	close(input);
	close(output);
end.