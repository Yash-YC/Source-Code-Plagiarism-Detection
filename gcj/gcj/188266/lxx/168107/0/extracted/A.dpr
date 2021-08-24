var
        a:array[1..1000000,2..10]of longint;
        p:array[1..100]of longint;

        function father(now,b:longint):longint;
        begin
                if a[now,b]=-1 then father:=now
                else
                begin
                        a[now,b]:=father(a[now,b],b);
                        father:=a[now,b];
                end;
        end;

        function ask(now,b:int64):int64;
        var
                s,j:int64;
        begin
                s:=0;
                while now<>0 do
                begin
                        j:=now mod b;
                        now:=now div b;
                        s:=s+j*j;
                end;
                ask:=s;
        end;

        procedure ready;
        var
                i,j,x,y:longint;
                k:int64;
        begin
                fillchar(a,sizeof(a),255);
                for j:=2 to 10 do
                        for i:=1 to 1000000 do
                        begin
                                k:=ask(i,j);
                                if k<=1000000 then
                                begin
                                        x:=father(i,j);
                                        y:=father(k,j);
                                        if x<>y then
                                                a[x,j]:=y;
                                end;
                        end;
        end;

        procedure main;
        var
                i,j,k,now,time,n:longint;
                pd:boolean;
        begin
                readln(time);
                for now:=1 to time do
                begin
                        n:=0;
                        while not seekeoln(input) do
                        begin
                                n:=n+1;
                                read(p[n]);
                        end;
                        readln;
                        for i:=2 to 1000000 do
                        begin
                                pd:=true;
                                for j:=1 to n do
                                        if father(i,p[j])<>1 then
                                        begin
                                                pd:=false;
                                                break;
                                        end;
                                if pd then
                                begin
                                        write('Case #',now,': ');
                                        writeln(i);
                                        break;
                                end;
                        end;
                end;
        end;

begin
        assign(input,'A.in');
        reset(input);
        assign(output,'A.out');
        rewrite(output);
        ready;
        main;
        close(input);
        close(output);
end.

