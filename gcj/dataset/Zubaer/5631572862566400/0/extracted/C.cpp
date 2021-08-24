#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FRI freopen("C-small-attempt1.in","r",stdin)
#define FRO freopen("C-small-attempt1.out","w",stdout)
#define debug(args...) {dbg,args; cerr<<endl;}
#define EPS 1e-12
#define RAD(x) ((x*PI)/180)
#define MAXN 100005
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

const double PI=acos(-1.0);

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int circleID[1005],bff[1005],color[1005],circleCnt;
vector<int>adj[1005],member[1005];

int FindCircle(int s) {
    int c;
    if(color[s]==BLACK) {
        return -1;
    }
    else if(color[s]==GREY) {
        color[s]=BLACK;
        circleID[s]=circleCnt;
        member[circleCnt].PB(s);
        circleCnt++;
        return circleID[s];
    }
    else {
        color[s]=GREY;
        c=FindCircle(bff[s]);
        if(c==-1)
            adj[bff[s]].PB(s);
        if(circleID[s]!=-1)
            return -1;
        color[s]=BLACK;
        circleID[s]=c;
        if(c!=-1)
            member[c].PB(s);
        return c;
    }
}

int DFS(int s) {
    int i,ret=0;
    for(i=0;i<adj[s].size();i++)
        ret=max(ret,DFS(adj[s][i]));
    return ret+1;
}

int main() {
    FRI;
    FRO;
    int t=0,T,n,i,j,ans1,ans2;
    scanf("%d",&T);
    while(t++<T) {
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            scanf("%d",&bff[i]);
            bff[i]--;
            color[i]=WHITE;
            circleID[i]=-1;
            adj[i].clear();
            member[i].clear();
        }
        circleCnt=0;
        for(i=0;i<n;i++)
            if(color[i]==WHITE)
                FindCircle(i);
        ans1=ans2=0;
        for(i=0;i<n;i++)
            if(member[i].size()!=2)
                ans1=max(ans1,(int)member[i].size());
        for(i=0;i<n;i++)
            if(member[i].size()==2)
                ans2+=DFS(member[i][0])+DFS(member[i][1]);
        printf("Case #%d: %d\n",t,max(ans1,ans2));
    }
    return 0;
}
