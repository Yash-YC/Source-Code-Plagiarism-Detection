
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define vv vector
#define pb push_back
#define ull unsigned long long
#define ll long long
#define ld long double
#define rep(i,n) for(int i=(0);i<(n);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(var(a,(b).begin());a!=(b).end();++a)
#define var(a,b) __typeof(b) a=(b)
#define ss(a) ((int)((a).size()))
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>
#define pii pair<int, int>
#define x first
#define y second
int cond = 1;
#define db(x) { if (cond > 0) { cond--; cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

#define MOD (2e9+33)
#define pll pair<ull,ull>
map<pll,pll> MAP;
#define x first
#define y second

pll solve(ll prev, ull val, ll bit) {
    if (bit == -1) {
        return pll(val >= 0, 0);
    }
    if (val >= (1ULL<<(bit + 1)))
        val = 1ULL<<(bit + 1);
    pll ha(prev * 256 + bit, val);

    if (MAP.count(ha)) return MAP[ha];
    pll &ret = MAP[ha];
    ret = solve(0, val, bit - 1);
    if (val >= (1ULL<<bit)) {
        pll tmp = solve(1, val - (1ULL<<bit), bit - 1);
        ret.x += tmp.x;
        ret.y += tmp.y;
        if (prev) ret.y += tmp.x;
    }

    return ret;
}

const int sz = 100;
ld DW[sz][sz] = {};
int main(int argc, char ** argv) {
    cond = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    int T;
    cin >> T;
    DW[0][0] = 1;
    rep (i, sz) {
        rep (j, sz) {
            if (i&&j)DW[i][j] += DW[i-1][j-1];
            if (i) DW[i][j] += DW[i-1][j];
        }
    }
    db(DW[5][2]<<" "<<DW[0][0]);
    rep (i, T) {
        int C, N;
        cin >> C >> N;
        ld dp[100] = {};
        dp[0] = 0;
        ld all2 = DW[C][N];
        fo (j, 1, C) {
            //zostalo 
            ld zero = 0;
            ld sum = 1;
            fo (wyb, 0, N) if (j >= wyb) {
                    ld ile = DW[j][wyb] * DW[C-j][N-wyb];
                    if (wyb == 0) {
                        zero = ile / all2;
                    }
                    else {
                        sum += dp[j - wyb] * (ile / all2);
                    }
            }
            dp[j] = sum / (1 - zero);
        }
        printf("Case #%d: %.9lf\n", i+1,(double)dp[C]);
    }
    return 0;
}

