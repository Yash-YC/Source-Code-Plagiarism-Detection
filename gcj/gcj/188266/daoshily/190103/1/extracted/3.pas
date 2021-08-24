var
    p0,sum:extended;
    c:array[0..50,0..50]of extended;
    dp:array[0..50]of extended;
    t,tt,i,j,n,m,min:longint;
procedure pre;
begin
    c[0,0]:=1;
    c[1,0]:=1;c[1,1]:=1;
    for i:=1 to 40 do
        begin
            c[i,0]:=1;
            c[i,i]:=1;
            for j:=1 to i-1 do
                c[i,j]:=c[i-1,j-1]+c[i-1,j];
        end;
end;
begin
    assign(input,'C-large.in');reset(input);
    assign(output,'out.out');rewrite(output);
    pre;
    readln(tt);
    for t:=1 to tt do
        begin
            readln(n,m);
            dp[n]:=0;
            for i:=n-1 downto 0 do
                begin
                    sum:=0;
                    min:=n;
                    if min>i+m then min:=i+m;
                    for j:=i+1 to min do
                        sum:=sum+c[n-i,j-i]/c[n,m]*c[i,m-j+i]*(dp[j]+1);
                    p0:=c[i,m]/c[n,m];
                    dp[i]:=(sum+p0)/(1-p0);
                end;
            writeln('Case #',t,': ',dp[0]:0:9);
        end;
    close(input);close(output);
end.