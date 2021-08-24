#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> para;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;
typedef long double LD;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOREACH(a,n) for (__typeof(n.begin())a=n.begin();a!=n.end();++a)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define FORD(i,a,b) for (int i=(a);i>=(b);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define ALL(x) x.begin(),x.end()
#define CLR(t) memset(t,0,sizeof(t));

LD tnpk[50][50],res[50];

LD inline npk(int n, int k){
  if(0<=k && k<=n)
    return tnpk[n][k];
  return 0.;
}

int main()
{ 
  tnpk[0][0] = 1.;
  FOR(i,1,40){
    tnpk[i][0] = 1.;
    FOR(j,1,i)
    tnpk[i][j] = tnpk[i-1][j] + tnpk[i-1][j-1];
  }
  int n,c,D;
  scanf("%d",&D);
  FOR(I,1,D){
    scanf("%d %d",&c,&n);
    res[c]=0.;
    FORD(k,c-1,0){
      LD mian = npk(c,n) - npk(k,n);
      LD licz = npk(k,n);
      FOR(i,1,n){
        if(i>(c-k))
          break;
        licz += (1.+res[k+i]) * npk(c-k,i) * npk(k, n-i);
      }
      res[k] = licz / mian;
    }
    printf("Case #%d: %.8Lf\n",I,res[0]);
  }
	return 0;
}
