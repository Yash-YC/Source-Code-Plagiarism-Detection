#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define VAR(v, n) typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define FI first
#define SE second

const int INF = 1000000001;
const double EPS = 10e-9;

LL Binom(int n, int k) {
#define Mark(x, y) for(int w = x, t = 2; w > 1; t++) while(!(w % t)) {w /= t; p[t] += y;}
    
  if (n < k || n < 0) return 0;
  int p[n + 1];

  REP(x, n + 1) p[x] = 0;
  FOR(x, n - k + 1, n) Mark(x, 1);
  FOR(x, 1, k) Mark(x, -1);

  LL r = 1;
  FOR(x, 1, n) while(p[x]--) r *= x;
  return r;
}



int zz;
LL t[50][50], n, k, Q;
long double l,r,w[50];

int main() {

scanf("%d", &zz);
FOR(z,1,zz) {
  scanf("%lld%lld", &n, &k); w[0]=1.0; Q=Binom(n,k);

  FOR(x,0,n-k) FOR(y,0,x) t[x][y]=Binom(x, x-y) * Binom(n-x, k-(x-y));
  
  FOR(i,1,n-k) {
    l = Q-t[i][i];
    r = 1.0/l; REP(j,i) r+=((long double)t[i][j]*(w[j]/l));
    w[i]=r;
  }

  if(n!=k) w[n-k]+=1.0;
  printf("Case #%d: %.7Lf\n", z, w[n-k]);
}

return 0;
}
