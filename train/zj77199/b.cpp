#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int T,n;
vector<int>vec[105];
vector<int> tmp[55][2];
bool vis[105];
int mm[105],ans1,ans2;
void init()
{
    ans1=ans2=-1;
    memset(vis,0,sizeof(vis));
    for(int t=1;t<=n;++t)
    {
        int _m=0x7fffffff;
        for(int i=1;i<(n<<1);++i)
        {
            if(vis[i])continue;
            _m=min(_m,vec[i][t-1]);
        }
        int cnt=0;
        mm[t]=_m;
        for(int i=1;i<(n<<1);++i)
        {
            if(vis[i])continue;
            if(vec[i][t-1]==_m)
            {
                tmp[t][cnt++]=vec[i];
                vis[i]=1;
            }
        }
        if(cnt<2)
            ans1=t,
            tmp[t][1]=vector<int>(n,-1);
    }
}
bool dfs(int t)
{
    if(t>n)
        return 1;
    int i,j;
    if(tmp[t][0][0]>=0)
        for(i=1;i<t;++i)
            if(tmp[i][1][t-1]>=0&&tmp[i][1][t-1]!=tmp[t][0][i-1])
                return 0;
    if(tmp[t][1][0]>=0)
        for(i=1;i<t;++i)
            if(tmp[i][0][t-1]>=0&&tmp[i][0][t-1]!=tmp[t][1][i-1])
                return 0;
    if(dfs(t+1))
        return 1;
    swap(tmp[t][0],tmp[t][1]);
    return dfs(t+1);
}
void solve()
{
    dfs(1);
    if(tmp[ans1][0][0]>=0)
        ans2=1;
    else ans2=0;
/*
    printf("\tans1:\t%d\t\tans2:\t%d\n",ans1,ans2);
    for(int i=1;i<=n;++i)
        for(int c=0;c<2;++c)
    {
        for(int j=0;j<n;++j)
            printf(" %d",tmp[i][c][j]);
        puts("");
    }

    return;

*/
    if(ans2)
    {
        for(int i=1;i<=n;++i)
            printf(" %d",tmp[i][0][ans1-1]);
    }
    else
    {
        for(int i=1;i<=n;++i)
            printf(" %d",tmp[i][1][ans1-1]);
    }
    putchar('\n');
}
int main()
{
    int i,j,a;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%d",&n);
        for(i=1;i<(n<<1);++i)
        {
            vec[i].clear();
            vec[i].reserve(n);
            for(j=1;j<=n;++j)
            {
                scanf("%d",&a);
                vec[i].push_back(a);
            }
        }
        printf("Case #%d:",t);
        init();
        solve();
    }
    return 0;
}
