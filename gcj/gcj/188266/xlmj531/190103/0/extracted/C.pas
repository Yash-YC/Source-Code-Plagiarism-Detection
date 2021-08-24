program xlmj;
{$R+,Q+,S+}
const
        maxn = 80;

var
        E            : array [0..maxn] of extended;
        n,m,test,i,j : longint;

function C(a,b : longint ): int64;
var
        i : longint;
        s : int64;
begin
        if a<b then exit(0);
        if a-b<b then b:=a-b;
        s:=1;
        for i:=1 to b do s:=s*(a-i+1) Div i;
        C:=s;
end;

begin
   assign(output,'H:\contest\google code jam\Round1A\C-1.out'); rewrite(output);
        readln(test);
        for test:=1 to test do
        begin
           readln(n,m);
           fillchar(E,sizeof(E),0); E[n]:=0;
           for i:=n-1 downto 0 do
           begin
              for j:=1 to m do E[i]:=E[i]+(E[i+j]+1)*C(i,m-j)*C(n-i,j);
              E[i]:=(E[i]+C(i,m))/(C(n,m)-C(i,m));
           end;
           writeln('Case #',test,': ',E[0]:0:7);
        end;
   close(output);
end.
