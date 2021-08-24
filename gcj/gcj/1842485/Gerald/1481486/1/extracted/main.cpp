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
typedef long double ld;
typedef pair<int, int> pt;

const int INF = (int)1E9 + 7;
const ld EPS = 1E-9;
const ld PI = 3.1415926535897932384626433832795;

const int NMAX = 15000;

int n;
int L[NMAX], D;
int x[NMAX];

int maxd[NMAX], inq[NMAX];

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

        cin >> n;
        forn(i, n)
            cin >> x[i] >> L[i];
        cin >> D;

        memset(maxd, -1, sizeof maxd);
        memset(inq, 0, sizeof inq);

        queue<int> q;
        maxd[0] = min(L[0], x[0]), q.push(0), inq[0] = 1;

        bool can = 0;

        while(!q.empty()){
            int v = q.front();
            q.pop(), inq[v] = 0;

            for(int u = v-1; u >= 0; --u){
                int cd = x[v] - x[u],
                    curC = min(cd, L[u]);
                if(cd > maxd[v]) break;
                if(maxd[u] < curC){
                    maxd[u] = curC;
                    if(!inq[u]){
                        q.push(u);
                        inq[u] = 1;
                    }
                }               
            }
            for(int u = v+1; u < n; ++u){
                int cd = x[u] - x[v],
                    curC = min(cd, L[u]);
                if(cd > maxd[v]) break;
                if(maxd[u] < curC){
                    maxd[u] = curC;
                    if(!inq[u]){
                        q.push(u);
                        inq[u] = 1;
                    }
                }               
            }

            if(abs(D - x[v]) <= maxd[v]){
                can = 1;
                break;                
            }
        }
        
        puts(can ? "YES" : "NO");
        fprintf(stderr, "Test #%d: %d\n", currentTest, (int)clock());
//        puts("");
    }

    return 0;
}


