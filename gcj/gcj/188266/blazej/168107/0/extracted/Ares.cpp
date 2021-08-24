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


map<VIS, int> res;

FILE * F;

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

char buf[400];

int main()
{
  F=fopen("res.in","r");
  for(;;){
    int d,a;
    fscanf(F,"%d",&d);
    if(d==0)
      break;
    fscanf(F,":");
    VIS ak;
    while(d--){
      fscanf(F,"%d",&a);
      ak.PB(a);
    }
    fscanf(F,"%d",&a);
    fill(ak,a);
//    fprintf(stderr,"%u\n",res.size());
  }
	fclose(F);
  int D;
  scanf("%d\n",&D);
  FOR(I,1,D){
    gets(buf);
    int d = strlen(buf),a;
    VIS ak;
    for(int i=0;i<d;i+=2){
      sscanf(buf+i,"%d",&a);
      ak.PB(a);
    }
    if(a==0)
      break;
    printf("Case #%d: %d\n",I, res[ak]);
  }
	return 0;
}
