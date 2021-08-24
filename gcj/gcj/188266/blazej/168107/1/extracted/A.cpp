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
typedef vector<short int> VIS;
typedef vector<vector<int> > VII;
typedef vector<string> VS;

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

const int N = 1000007, M = 12814485;

short int isl[11][N];

int check(int l,int p){
  if(l < N){
    if(isl[p][l] == 2){
      return (isl[p][l] = -1);
    }
    if(isl[p][l])
      return isl[p][l];
    isl[p][l] = 2;
  }
  int nl = 0, kl = l, x;
  while(kl>0){
    x = kl % p;
    nl += x*x;
    kl /= p;
  }
  int f = check(nl,p);
  if(l < N)
    isl[p][l] = f;
  return f;
}

map<VIS, int> res;

bool fill(VIS & ak, int w){
  if(res.find(ak) == res.end()){
    res[ak] = w;
    if(ak.size()>2)
      REP(i,(int)ak.size()){
        VIS copy = ak;
        copy.erase(copy.begin()+i);
        fill(copy, w);
      }
    return true;
  }
  return false;
}

int main()
{
  freopen( "res.in", "w", stdout);
  FOR(p,2,10){
    isl[p][1] = 1;
    isl[p][0] = -1;
  }

  FOR(i,2,M){
    VIS ak;
    FOR(p,2,10){
      if( check(i,p) == 1)
        ak.PB(p);
    }
    if(ak.size()>1)
      if(fill(ak, i)){
        printf("%u: ",ak.size());
        FOREACH(it, ak)
          printf("%d ",*it);
        printf(" \n %d\n",i);
      }
  }
  printf("0\n");
	return 0;
}
