#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define dbg(x) cout << #x << " -> " << x << "\t" << flush;
#define dbge(x) cout << #x << " -> " << x << "\t" << endl;
#define LET(x,a) typeof(a) x(a)
#define FORI(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(LET(i,a);i < (b);++i)
#define FORZ(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define CS c_str()
#define PB push_back
#define SZ size()
#define INF (int)1e9+1
typedef long long LL;

LL Fac[15];
LL fac(int a)
{
    return Fac[a];
}
LL comb(int a, int b)
{
    if(b > a)
        return 0;
    return fac(a)/(fac(b)*fac(a - b));
}

double DP[11][11][11][5000];
bool   vis[11][11][11][5000];
double imp;

double Prob(int need, int N, int have, int t)
{
    if(need == 0 && t == 0)
        return 1;
    if(t == 0)
        return 0;
    if(need <= 0)
        return 0;
    if(vis[need][N][have][t])
        return DP[need][N][have][t];
    double& ans = DP[need][N][have][t];
    ans = 0;
    for(int i = 0; i <= min(need, N); ++i)
        ans += (comb(have, N - i)*comb(need, i)/imp)*Prob(need - i, N, have + i, t - 1);
    vis[need][N][have][t] = 1;
    return ans;
}

int main()
{
    Fac[0] = 1;
    for(int i = 1; i <= 11; ++i)
        Fac[i] = Fac[i-1]*i;
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        int C = GI, N = GI;
        double ans = 0;
        double prev = ans;
        imp = comb(C, N);
        for(int t = 1; t < 5000; ++t)
        {
            ans += t*(Prob(C, N,0,t));
        /*    if(abs(prev - ans) <= 1e-7)
                break;
                */
   //         dbge(Prob(C, N,0,t));
            prev = ans;
        }
        printf("Case #%d: %0.7lf\n", nc, ans);
    }
}
