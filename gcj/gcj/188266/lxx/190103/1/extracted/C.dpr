var
        c:array[-1..40,-1..40]of int64;
        f:array[0..40]of extended;
        m,n,time,now:longint;

        procedure ready;
        var
                i,j,k:longint;
        begin
                fillchar(c,sizeof(c),0);
                c[0,0]:=1;
                for i:=1 to 40 do
                        for j:=0 to i do
                                c[i,j]:=c[i-1,j]+c[i-1,j-1];
        end;

        procedure main;
        var
                i,j,k:longint;
                s:extended;
        begin
                read(m,n);
                f[m]:=0;
                for i:=m-1 downto 0 do
                begin
                        s:=0;
                        if i+n>m then k:=m
                                else k:=i+n;
                        for j:=i+1 to k do
                                s:=s+(c[m-i,j-i]*c[i,n-(j-i)])/(c[m,n])*(f[j]+1);
                        if i<n then
                                f[i]:=s
                        else
                                f[i]:=(s+c[i,n]/c[m,n])/(1-c[i,n]/c[m,n]);
                end;
                writeln(f[0]:0:8);
        end;

begin
        assign(input,'C.in');
        reset(input);
        assign(output,'C.out');
        rewrite(output);
        ready;
        readln(time);
        for now:=1 to time do
        begin
                write('Case #',now,': ');
                main;
        end;
        close(input);
        close(output);
end.

