#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int _a;

#define FOR(i , n) for(int i = 0 ; i < n ; i++)
#define FOT(i , a , b) for(int i = a ; i < b ; i++)
#define GETINT (scanf("%d" , &_a) , _a)
#define pb push_back
#define mp make_pair
#define s(a) (int(a.size()))
#define PRINT(a) cerr << #a << " = " << a << endl

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int , int> PII;
typedef pair< PII, int > PPIII;

int which[][2] = {{1, 3},{0,2},{3,1}, {2, 0}};
int incre[][2] = {{-1,1},{1,1},{1,-1},{-1,-1}};
inline bool GOOD(int num, int bound) {
  return (num >= 0 && num < bound);
  
}
int main() {
  int tests = GETINT;
  FOT(t, 1, tests+1) {
    int ans;
    int n, m;
    n = GETINT;
    m = GETINT;
    vi S, W, T;
    FOR(i, n) FOR(j, m) {
      int a, b, c;
      a = GETINT;
      b = GETINT;
      c = GETINT;
      c %= (a + b);
      S.pb(a); W.pb(b); T.pb(c);
    }
    ll dist[n][m][4];
    bool burnt[n][m][4];
    ll inf = (1LL << 40);
    FOR(i, n) FOR(j, m) FOR(k, 4) dist[i][j][k] = inf;
    FOR(i, n) FOR(j, m) FOR(k, 4) burnt[i][j][k] = false;
    dist[n-1][0][0] = 0;
    int r, c, d;
    r = n - 1; c = 0; d = 0;
    while(1) {
      burnt[r][c][d] = true;
      ll curd = dist[r][c][d];
      FOR(i, 2) {
        int nr = r + i * incre[d][i];
        int nc = c + (1 - i) * incre[d][i];
        int nd = which[d][i];
        if(GOOD(nr, n) && GOOD(nc, m))
          dist[nr][nc][nd] = min(dist[nr][nc][nd], 2 + curd);
      }
      FOR(i, 2) {
        int nr = r;
        int nc = c;
        int nd = which[d][i];
        //        cerr << nr << ' ' << nc << ' ' << nd << endl;
        if(GOOD(nr, n) && GOOD(nc, m)) {
          //          cerr << "checking " << nr << ' ' << nc << ' ' << nd << endl;
          ll step = 1;
          int sum = (S[r*n+c]+W[r*n+c]);
          int what = (curd - T[r*n+c] + sum) % sum;
          if(i == 0) step += max(0, S[r*n+c] - what);
          if(i == 1) step += (what >= S[r*n+c] ? (sum-what) : 0);
          dist[nr][nc][nd] = min(dist[nr][nc][nd], step + curd);          
        }
      }
      ll best = inf;
      FOR(i, n) FOR(j, m) FOR(k, 4) if(!burnt[i][j][k] && dist[i][j][k] < best) {
        best = dist[i][j][k];
        r = i; c = j; d = k;
      }

      if(best == inf) break;
    }
    cout << "Case #" << t << ": " << dist[0][m-1][2] << endl;
  }
  return 0;
}
