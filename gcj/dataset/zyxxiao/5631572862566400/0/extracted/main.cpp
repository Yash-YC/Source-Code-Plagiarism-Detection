/*    brioso     */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;
#define MAXN 1005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

int a[MAXN];
vector<int> b[MAXN];
bool c[MAXN];
char s[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;
int aans;
int ppp;
int qqq;
void ddfs(int num,int sum){
    if(c[num])
        return;
    if(a[num] == ppp){
        if(sum > aans)
            aans = sum;
        return;
    }

    c[num] = true;
    ddfs(a[num],sum+1);
}

void dfs(int num,int sum){

    if(a[num] == qqq){
        if(sum > ans)
            ans = sum;
        return;
    }
    if(vis[num])
        return;
    vis[num] = true;
    if(a[a[num]] == num){
        aans = 0;
        //vis[a[num]] = true;
        ppp = a[num];
        for(int i = 1 ; i <= n ; i++){
             for(int j = 0 ; j < MAXN ; j++)
                c[j] = vis[j];
            ddfs(i,1);
        }
        if(aans + sum+1 > ans)
            ans = aans + sum+1;
        return ;
    }
    else dfs(a[num],sum+1);
}

int main()
{
    freopen("C-small-attempt7.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,ca = 0;
    int p,q;
    scanf("%d",&t);
    for(ca = 1 ; ca <= t ; ca++){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&a[i]);
        }
        ans = 0;
        for(int i = 1 ; i <= n ; i++){
            qqq = i;
            memset(vis,false,sizeof(vis));
            //vis[i] = true;
            dfs(i,1);
        }
        printf("Case #%d: ",ca);
        printf("%d\n",ans);
    }
    return 0;
}


/*

unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：18446744073709551615

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615

*/
