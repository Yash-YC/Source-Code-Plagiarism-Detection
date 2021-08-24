program xlmj;
{$R+,Q+,S+}
const
        maxn = 11814485;

var
        can                   : array [0..maxn,2..10] of boolean;
        bo                    : array [0..maxn] of longint;
        q                     : array [1..9] of longint;
        n,first,test,bit,sign : longint;

procedure init;
var
        i : longint;
begin
        n:=0;
        while not eoln do
        begin
                inc(n);
                read(q[n]);
        end;
        readln;
end;

function decode(x : longint ): longint;
var
        s : longint;
begin
        s:=0;
        while x>0 do
        begin
           inc(s,sqr(x Mod bit));
           x:=x Div bit;
        end;
        exit(s);
end;

function dfs(n : longint ): boolean;
begin
        if n=1 then exit(true);
        if bo[n]=sign then exit(false);
        bo[n]:=sign;
        exit(dfs(decode(n)));
end;

procedure prepare;
var
        j : longint;
begin
        for first:=2 to maxn do
           for j:=2 to 10 do
           begin
              bit:=j;
              sign:=first*10+j;
              can[first,j]:=dfs(first);
           end;
end;

function check : boolean;
var
        j : longint;
begin
        for j:=1 to n do
           if not can[first,q[j]] then exit(false);
        check:=true;
end;

procedure work;
begin
        for first:=2 to maxn do
           if check then break;
        writeln('Case #',test,': ',first);
end;

begin
        prepare;
        assign(input,'H:\contest\google code jam\Round1A\A-1.in'); reset(input);
        assign(output,'H:\contest\google code jam\Round1A\A-1.out'); rewrite(output);
        readln(test);
        for test:=1 to test do
        begin
           init;
           work;
        end;
        close(input); close(output);
end.
