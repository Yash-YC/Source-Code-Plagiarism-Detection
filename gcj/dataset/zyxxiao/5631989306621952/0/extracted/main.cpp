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
#define MAXN 2005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

char a[MAXN];
char b[MAXN];
int c[MAXN];
char s[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,ca = 0;
    int p,q;
    scanf("%d",&t);
    for(ca = 1 ; ca <= t ; ca++){
        scanf("%s",s);
        printf("Case #%d: ",ca);
        int l = strlen(s);
        a[l] = s[0];
        p = l;q = l;
        for(int i = 1 ; i < l ; i++){
            if(s[i] >= a[p]){
                a[--p] = s[i];
            }
            else if(s[i] < a[p]){
                a[++q] = s[i];
            }
        }
        for(int i = p ; i <= q ; i++)
            printf("%c",a[i]);
        printf("\n");
//        int a = 0;
//        int b = l-1;
//        while(a <= b){
//            bool left = false;
//            for(int i = 0 ; i+a <= b ; i++){
//                if(s[a+i] >s[b-1]){
//                    left = true;
//                    break;
//                }
//                else if(s[a+i] < s[b-i]){
//                    left = false;
//                    break;
//                }
//            }
//            if(left) putchar(s[a++]);
//            else putchar(s[b--]);
//        }
//        printf("\n");
        //printf("%d\n",ans);
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
