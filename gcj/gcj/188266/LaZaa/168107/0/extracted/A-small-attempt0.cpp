#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <numeric>
#include <iostream>
#include <sstream> 
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define ll long long
#define ull unsigned long long
#define ld long double
#define VV vector
#define VI VV<int>
#define VL VV<ll>
#define VS VV<string>
#define MP(x,y) make_pair(x,y)
#define LET(a,b) typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define PUB push_back
#define POF pop_front
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

int COND=0;
#define DBG(x){if(COND>0){COND--;cerr<<__LINE__<<" "<<#x<<" "<<x<<endl;cerr.flush();}}

#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(ll i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(ll i=(a),_b=(b);i>=_b;--i)
#define FORE(a,b) for(LET(a,(b).begin());a!=(b).end();++a)

#define two(X) (((ll)1)<<(X))
template<class T> inline void mini(T &a,T b){if(b<a)a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a)a=b;}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T gcd(T a,T b){if(a<0)a=-a;if(b<0)b=-b;return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b){if(a<0)a=-a;if(b<0)b=-b;return a*(b/gcd(a,b));}
template<class T> inline VV<pair<T,int>> factorize(T n)
	{VV<pair<T,int>> R;T _i=1;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.PUB(MP(i,C));}
	i+=_i;_i=2;if (i*i>n) i=n;}if (n>1) R.PUB(MP(n,1));return R;}
template<class T> inline bool prime(T n)
	{if(n<=1)return false;T _i=1;for (T i=2;i*i<=n;i+=_i,_i=2) if (n%i==0) return false;return true;}

//----------------------------------------------
const int MAX = 500000;
bool happy[11][MAX];
bool vis[11][MAX];


int go() {
	return 0;
}

bool ishappy(int b, int x_){
	int n = b, m, sum=0, x=x_;
	if (vis[b][x_]) return happy[b][x_];
	vis[b][x_] = true;
	while(x>0){
		m=x%n;
		if(m>0){x-=m;m=(m*b)/n;sum+=m*m;}
		n*=b;
	}
	if (sum>=MAX) return happy[b][x_]=false;
	return happy[b][x_]=ishappy(b,sum);
}

void init() {
	CLR(happy, false);
	CLR(vis, false);
	FOR(i, 3, 10){
		happy[i][1] = true;
		vis[i][1] = vis[i][0] = true;
		FOR(x,2,MAX){
			ishappy(i,x);
		}
	}

}

bool all[MAX];

int solve() {
	//cin >>
	CLR(all,true);
	string line;
	getline(cin,line);
	istringstream iss(line);
	int b; 
	while(iss>>b) {
		if(b>2)
			REP(i,MAX)
			all[i]&=happy[b][i];
	}

	FOR(i,2,MAX-1)
		if(all[i])
			return i;
	return 0;
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
	COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
	init();
	int caseCount; cin >> caseCount;
	string temp; getline(cin,temp);
	FOR (c, 1, caseCount) {
		int i = solve();
		cout << "Case #" << c <<": "<<i<<"\n";
		//printf("Case #%d: %d\n", c, i);
	}
	return 0;
}
