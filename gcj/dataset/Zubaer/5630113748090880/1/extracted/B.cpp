#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FRI freopen("B-large.in","r",stdin)
#define FRO freopen("B-large.out","w",stdout)
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
    int t=0,T,hcnt[3005],i,x,n;
    vector<int>ans;
    scanf("%d",&T);
    while(t++<T) {
        for(i=0;i<3000;i++)
            hcnt[i]=0;
        scanf("%d",&n);
        for(i=0;i<(2*n-1)*n;i++) {
            scanf("%d",&x);
            hcnt[x]++;
        }
        ans.clear();
        for(i=0;i<3000;i++)
            if(hcnt[i]&1)
                ans.PB(i);
        sort(ans.begin(),ans.end());
        printf("Case #%d:",t);
        for(i=0;i<n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
