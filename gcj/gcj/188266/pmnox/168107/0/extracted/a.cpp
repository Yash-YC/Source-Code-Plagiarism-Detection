
#include <cassert>
#include <sstream>
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


const int sz = 100000;
char check[12][sz + 13];

int next(int val, int ba) {
    int ret = 0;
    while (val) { 
        ret += (val%ba) * (val%ba);
        val /= ba;
    }
    return ret;
}

map<int,int> Q;

int main(int argc, char ** argv) {
    cond = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    fo (ba, 2, 10) {
        check[ba][1] = 1;
        fo (i, 2, sz) if (check[ba][i] == 0) {
            int cu = i;
            int result = 0;
            while (1) {
                int ne = next(cu, ba);
                check[ba][cu] = -1;
                if (check[ba][ne] != 0) {
                    result = check[ba][ne];
                    break;
                }
                cu = ne;
            }
            cu = i;
            if (result == -1) result = -2;
            while (1) {
                int ne = next(cu, ba);
                check[ba][cu] = result;
                if (check[ba][ne] != -1) break;
                cu = ne;
            }
            //if (i < 10) db(ba<<" "<<i<<" "<<check[ba][i]);
        }
    }
    fo (i, 2, sz) { int cnt = 0;
        fo (ba, 2, 10) {
            if (check[ba][i] == 1) cnt++;
        }
        if (cnt == 8) { db(i); 
            fo (ba, 2, 10) {
                if (check[ba][i] == 1) db(ba);
            }
            
            break; 
        }
    }
    char buf[50000];
    gets(buf);
    int t;
    sscanf(buf, "%d", &t);
    rep (iii, t) {
        gets(buf);
        stringstream ss(buf);
        vi test;
        int x;
        while (ss>>x) test.pb(x);
        bool ok = 0;
        fo (j, 2, sz - 1) {
            int cnt = 0;
            fore (it, test) if (check[*it][j] == 1) cnt++;
            if (cnt == (test.size())) { 
                printf("Case #%d: %d\n", 1+iii, j);
                ok = 1;
                break; 
            }
        }
        if (ok == 0) {
            cerr<<"23"<<endl;
            assert(0);
        }

    }

    return 0;
}

