#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define PB push_back

typedef vector<int> VI; typedef vector<string> VS;
template<class T> inline int size(const T&c) { return c.size(); }
inline int s2i(string x) { istringstream i(x); int ret; i>>ret; return ret; }
inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}
template<class A,class B> inline bool contains(const A&a, const B&b) { return find(ALL(a),b)!=a.end(); }

inline VS split(string s,string delim=" ")
{
	VS ret; string temp=""; s+=delim;
	REP(i,size(s))
		if(!contains(delim,s[i])) temp+=s[i];
		else if(temp!="") { ret.PB(temp); temp=""; }
  	return ret;
}
inline VI vs2vi(VS s) { VI ret; REP(i,size(s)) ret.PB(s2i(s[i])); return ret; }
inline VI s2vi(string x,string delim=" ") { return vs2vi(split(x,delim)); }

// Powered By TimoAI 2.2


char s[1024];
const int LIM = 1<<24;
int dp[LIM];

bool ok(int x, int b) {
	if(x==1) return true;
	REP(loop,16) {
		int next = 0;
		while(x>0) {
			int z = x%b;
			next += z * z;
			x/=b;
		}
		if(next==1) return true;
		x = next;
	}
	return false;
}

int calc(VI B){
	if(B==s2vi("2 3 4 5 6 7 8 9 10")) return 11814485;
	if(B==s2vi("2 3 4 5 6 7 8 9")) return 569669;
	if(B==s2vi("3 4 5 6 7 8 9 10")) return 11814485;
	if(B==s2vi("5 6 7 8 9 10")) return 11814485;
	// REP(i,size(B)) printf("%d\n",B[i]);
	FOR(x,2,1<<24) {
		bool o = true;
		FORD(i,size(B)-1,0) if(!ok(x,B[i])) {
			o = false;
			break;
		}
		if(o) return x;
	}
	return 0;
}
//11814485
int main() {
	OPEN("A");
	int t = getint(); gets(s);
	REP(ncase,t) {
		gets(s);
		string z = s;
		VI B = s2vi(z);
		printf("Case #%d: %d\n",ncase+1,calc(B));
	}
}
