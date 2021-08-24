#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define debug(x) {cerr << #x << " = " << x << endl;}
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

inline int bit(int m, int i){
    return (m >> i) & 1;
}

inline int sb(int m, int i){
    if(bit(m, i))
        m ^= (1 << i);
    return m;
}

void solve(vector<pt>& r, vector<int>& used, ld x, ld y, int w, int h, int can, vector<pair<ld, ld> >& ans){
    if(w < 0 || h < 0) return;

    forn(i, sz(r)){
        int cr = r[i].X;
        int id = r[i].Y;

        if(used[id]) continue;

        int minx = 0, maxx = w;    
        if(!bit(can, 0))
            minx = cr;
        if(!bit(can, 1))
            maxx = w - cr;

        int miny = 0, maxy = h;    
        if(!bit(can, 2))
            miny = cr;
        if(!bit(can, 3))
            maxy = h - cr;

        if(minx > maxx || miny > maxy) continue;

        used[id] = 1;
        ans[id].X = x + minx, ans[id].Y = y + miny;

        int nw = minx + cr, nh = miny + cr;

        if(h > nh){
            solve(r, used, x + nw, y, w - nw, min(nh, h), sb(sb(can, 0), 3), ans); 
        }else
            solve(r, used, x + nw, y, w - nw, min(nh, h), sb(can, 0), ans); 

        if(w > nw)
            solve(r, used, x, y + nh, min(nw, w), h - nh, sb(sb(can, 2), 1), ans);
        else
            solve(r, used, x, y + nh, min(nw, w), h - nh, sb(can, 2), ans);

        solve(r, used, x + nw, y + nh, w - nw, h - nh, sb(sb(can, 0), 2), ans);
        //used[id] = 0;
        return;
    }
}

int main() {
    #ifdef myproject
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    #endif

    int testCount = 0;
    scanf("%d", &testCount); char testBuf[10]; gets(testBuf);
    for1(currentTest, testCount){
        printf("Case #%d: ", currentTest);
        //solution

        int n, w, h;
        cin >> n >> w >> h;
        vector<pt> r(n);
        forn(i, n){
            cin >> r[i].X;
            r[i].Y = i;
        }

        sort(all(r));
        reverse(all(r));

        vector<pair<ld, ld> > ans(n);
        vector<int> used(n, 0);
                
        solve(r, used, 0, 0, w, h, (1<<4)-1, ans);

        forn(i, sz(ans)){
            assert(used[i]);
            printf("%.10lf %.10lf ", ans[i].X, ans[i].Y);
            if(!(0 <= ans[i].X+EPS && ans[i].X <= w+EPS))
                throw;
            if(!(0 <= ans[i].Y+EPS && ans[i].Y <= h+EPS))
                throw;
        }

        forn(i, sz(ans)){
            forn(j, i){
                ld d = sqr(ans[r[i].Y].X - ans[r[j].Y].X) + sqr(ans[r[i].Y].Y - ans[r[j].Y].Y);

                if(sqr(r[i].X + r[j].X) > d + EPS)
                    throw;
            }
        }

        fprintf(stderr, "Test #%d: %d\n", currentTest, (int)clock());
        puts("");
    }

    return 0;
}


