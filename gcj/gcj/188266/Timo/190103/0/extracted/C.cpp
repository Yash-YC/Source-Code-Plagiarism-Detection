#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define PB push_back

typedef vector<int> VI;
template<class T> inline int size(const T&c) { return c.size(); }
inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2


int C,N,GOAL;
const int V = 400;
double cache[V][1<<10];
int seen[V][1<<10];
VI S;


double calc(int depth,int now) {
	double &ret=cache[depth][now];
	if(seen[depth][now]) return ret;
	seen[depth][now]=1;
	if(now==GOAL) return ret=0.0;
	if(depth>=V-1) return ret=0.0;
	ret = 0.0;
	REP(i,size(S)) {
		ret += 1 + calc(depth+1,now | S[i]);
	}
	ret = ret / size(S);
	return ret;
}

int main() {
	OPEN("C");
	REP(ncase,getint()) {
		C = getint();
		N = getint();
		GOAL = (1<<C)-1;
		memset(seen,0,sizeof(seen));
		S.clear();
			VI p(C,1); REP(i,N) p[i]=0;


			do {
				int card = 0;
				REP(i,C) if(p[i]==0) card |= (1<<i);
				S.PB(card);
			}while(next_permutation(ALL(p)));


		printf("Case #%d: %.7lf\n",ncase+1,calc(0,0));
	}
	return 0;
}
