{$M 50000000}
const maxl=13000000;
var
    father:array[2..10,1..maxl]of longint;
    s:array[1..10]of longint;
	q,p,num,pan,i,j,n,m,t,tt:longint;
procedure init;
begin
            n:=0;
            while not(eoln) do
                begin
                    inc(n);
                    read(s[n]);
                end;
            readln;
end;
function getfather(q,p:longint):longint;
begin
    if father[q,p]=p then exit(p) else 
        begin
            father[q,p]:=getfather(q,father[q,p]);
            exit(father[q,p]);
        end;
end;
function check(t,w:longint):longint;
var
    num,i,j:longint;
begin
    num:=w;check:=0;
    while num>0 do
        begin
            check:=check+sqr(num mod t);
            num:=num div t;
        end;
end;
procedure pre;
begin
    for i:=2 to 10 do
        for j:=1 to maxl do
            father[i,j]:=j;
    for i:=2 to 10 do
        for j:=2 to maxl do
            begin
                num:=check(i,j);
                q:=getfather(i,num);p:=getfather(i,j);
                if q<>p then father[i,q]:=p;
            end;
end;
begin
    assign(input,'A-large.in');reset(input);
    assign(output,'out.out');rewrite(output);
    readln(tt);
    pre;
    for t:=1 to tt do
        begin
            init;
            for i:=2 to maxl do
            begin
                pan:=0;
                for j:=1 to n do
                    begin
                        q:=getfather(s[j],i);p:=getfather(s[j],1);
                        if q<>p then begin pan:=1;break;end;
                    end;
                if pan=0 then break;
            end;
            writeln('Case #',t,': ',i);
        end;
    close(input);close(output);
end.