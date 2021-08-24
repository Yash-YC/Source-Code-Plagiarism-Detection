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
#define MAXN 2555
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

int a[105][105];
int b[MAXN];
int c[MAXN];
char s[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,ca = 0;
    int p,q;
    scanf("%d",&t);
    for(ca = 1 ; ca <= t ; ca++){
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for(int i = 0 ; i < n*2-1 ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf("%d",&a[i][j]);
                b[a[i][j]]++;
            }
        }
        int num = 0;
        memset(c,0,sizeof(c));
        for(int i = 0 ; i < MAXN ; i++){
            if(b[i] %2){
                c[num++] = i;
            }
        }
        sort(c,c+num);
        printf("Case #%d:",ca);
        for(int i = 0 ; i < num ; i++){
            printf(" %d",c[i]);
        }
        printf("\n");
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
