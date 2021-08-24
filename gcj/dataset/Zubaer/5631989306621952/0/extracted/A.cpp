#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FRI freopen("A-small-attempt0.in","r",stdin)
#define FRO freopen("A-small-attempt0.out","w",stdout)
#define debug(args...) {dbg,args; cerr<<endl;}
#define EPS 1e-12
#define RAD(x) ((x*PI)/180)
#define MAXN 100005
using namespace std;

const double PI=acos(-1.0);

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int main() {
    FRI;
    FRO;
    char s[1005],rawAns[2005],ans[1005];
    int t=0,T,i,j,n,head,tail;
    scanf("%d",&T);
    while(t++<T) {
        scanf("%s",s);
        n=strlen(s);
        head=tail=1001;
        rawAns[1001]=0;
        for(i=0;i<n;i++) {
            if(s[i]>=rawAns[head])
                rawAns[--head]=s[i];
            else
                rawAns[tail++]=s[i];
        }
        for(i=head,j=0;i<tail;i++,j++)
            ans[j]=rawAns[i];
        ans[j]=0;
        printf("Case #%d: %s\n",t,ans);
    }
    return 0;
}
