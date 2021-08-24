#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<string>
#include<queue>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef unsigned long long ull;

typedef long long Weight;
struct Edge {
  int i;
  int j;
  Weight dist;
  Edge(int _i, int _j, Weight d) { i = _i; j = _j; dist = d; }
};


bool operator < (const Edge &e, const Edge &f) {
  return e.dist !=  f.dist ? e.dist >  f.dist : // !!INVERSE!!
    e.i != f.i ? e.i < f.i : e.j < f.j;
}

bool P[50][50];
Weight dist[50][50];

long long S[25][25], W[20][25], T[20][25];

int N, M;

int di[4] = { 1, 0, -1, 0};
int dj[4] = { 0, 1,  0,-1};

#define INF 100000000000ll

long long f(int i, int j, int di, int dj, int t) {
  if(i%2==0 and di == -1) return 2;
  if(j%2==0 and dj == -1) return 2;
  if(i%2==1 and di ==  1) return 2;
  if(j%2==1 and dj ==  1) return 2;
  int si = i/2;
  int sj = j/2;
  long long mS = S[si][sj];
  long long mW = W[si][sj];
  long long mT = T[si][sj];
  if(mW == 0 and mS == 0) return INF;
  if (dj == 0) { //NorthSouth
    if(mS == 0) return INF;
    long long buf = (t >= mT) ? (t - mT) % (mS + mW)
      : (mS + mW - (mT - t) % (mS + mW)) % (mS + mW);
    return 1 + ((buf < mS) ? 0 : mS + mW - buf);
  } else {
    if(mW == 0) return INF;
    long long buf = (t >= mT) ? (t - mT) % (mS + mW)
      : (mS + mW - (mT - t) % (mS + mW)) % (mS + mW);
    return 1 + ((buf < mS) ? mS - buf : 0 );
  }
}

void shortestPath() {
  REP(i,N*2) REP(j,M*2) dist[i][j] = -1;
  REP(i,N*2) REP(j,M*2) P[i][j] = false;
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(2*N-1, 0, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (P[e.i][e.j]) continue;
    //cout << e.i << ':' << e.j << '#' << e.dist << endl;
    P[e.i][e.j] = true;
    dist[e.i][e.j] = e.dist;
    REP(k, 4) {
      int ni = di[k] + e.i;
      int nj = dj[k] + e.j;
      if (ni < 0 or N*2 <= ni) continue;
      if (nj < 0 or M*2 <= nj) continue;
      //cout << e.i << ':' << e.j << '#' << ni << ':' << nj << '#' <<  f(e.i, e.j, di[k], dj[k], e.dist) << endl;
      Q.push(Edge(ni, nj, e.dist + f(e.i, e.j, di[k], dj[k], e.dist)));
    }
  }
}

int main () {
  int C;
  cin >> C;
  REP(k,C) {
    cin >> N >> M;
    REP(i, N) REP(j,M) cin >> S[i][j] >> W[i][j] >> T[i][j];
    shortestPath();
    printf("Case #%d: %lld\n", k+1, dist[0][M*2-1]);
  }
}
