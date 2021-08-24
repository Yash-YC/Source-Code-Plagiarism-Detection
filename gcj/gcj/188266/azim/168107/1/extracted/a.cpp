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
const int MAX = 12000000;

int zz,t[20],k,d;
string s;
bool wyn, w[MAX][12];
char h;
set<int> q;

bool Try(int n, int b) {
  int x; q.clear();

  while(n!=1 && q.find(n)==q.end()) {
//    printf("%d, ", n);
    q.insert(n); x=0;

    while(n) {
      x+=((n%b)*(n%b));
      n/=b;
    }

    n=x;
  }

  return (n==1);
}

bool Func(int n, int b) {
  int x=0, y=n; 
  while(n) {
    x+=((n%b)*(n%b));
    n/=b;
  }

  if(x==y) return false; else 
  if(x<y) return w[x][b]; else
  printf("GÓWNO!: %d %d %d\n", b, x, y);
}

int main() {

//FOR(i,2,MAX-1) FOR(j,2,10) w[i][j]=Try(i,j);
FOR(j,2,10) {
  w[1][j]=true;
  FOR(i,2,250) w[i][j]=Try(i,j);
  FOR(i,251,MAX-1) w[i][j]=Func(i,j);
  
}
//printf("done!\n");



scanf("%d", &zz); scanf("%c", &h);
FOR(z,1,zz) {
  REP(i,20) t[i]=0;
  getline(cin, s); d=0; k=SIZE(s);

  REP(i, k)
    if(s[i]==' ') d++; else t[d]=10*t[d]+(s[i]-(int)'0');
  d++;

//  REP(i,d) printf("%d, ", t[i]); printf("\n");
/*
  wyn=false; k=1;
  while(!wyn) {
    wyn=true; k++;
    REP(i,d) if(!Try(k, t[i])) { wyn=false; break; }
//    printf(" %d\n", k);
  }

  printf("Case #%d: %d\n", z, k);
*/

  wyn=false; k=1;
  while(!wyn) {
    wyn=true; k++;
    REP(i,d) if(!w[k][t[i]]) { wyn=false; break; }
  }

  printf("Case #%d: %d\n", z, k);
}


return 0;
}
