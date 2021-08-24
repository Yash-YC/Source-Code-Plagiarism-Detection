#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include <memory.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef long double ld;
typedef vector <int > VI;
typedef vector < VI > VVI;
typedef vector < ll > VLL;
typedef vector < dd > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define VAR(V,init) __typeof(init) V=(init)
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define ALL(X) (X).begin(),(X).end()
#define CLE(a,b) memset(a,b,sizeof(a))
#define MINN(a,b) ((a)>(b)?(b):(a))
#define MAXX(a,b) ((a)<(b)?(b):(a))
#define PB push_back
#define PF push_front
#define CB pop_back
#define CF pop_front
#define MP make_pair
#define FI first
#define SE second
#define SZ(X) ((int)(X.size()))
#define INF 1000000000
#define INFLL 1000000000000000000ll
int COND = 100;
#define DB(x) ({if(COND){COND--; cerr << __LINE__ << " : " << #x << ": " << x << endl; };})
#define deb(A) //A
//////////////////

#define MAX_L 1000
#define MAX_N 100000
#define MAX_B 10

int testsnr;
VI base;
VS tokens;
char line[MAX_L];
map< pair<int, int> , int> ok;
bool good;

VS parse(string s)
{
  string a;
  VS wyn;
  REP(i,(int)s.size())
    if (s[i]!=' ') a+=s[i];
    else if (!a.empty()) { wyn.PB(a); a=""; }
  if (!a.empty()) wyn.PB(a);
  return wyn;
}

bool isDigt(char a) { return a>='0' && a<='9'; }

int stringToInt(string a)
{
  int num=0, sign=1, ia=0, len=a.length();
  if(len==0)
    return 0;
  if(a[0]=='-')
  {
    sign=-1;
    ia++;
  }
  while(ia<len)
    num=num*10+a[ia++]-'0';
  return num*sign;
}

string intToString(ll a)
{
  string res=""; char  b[30];
  sprintf(b,"%lld",a);
  REP(i,(int)strlen(b))
		res+=b[i];
	return res;
}

VI toBase(int a, int b)
{
	VI res;
	res.clear();
	if(a == 0) {
		res.PB(a);
		return res;
	}
	while(a > 0) {
		res.PB(a % b);
		a /= b;
	}
	return res;
}

int toBase10(const VI & a, int b) {
	int res = 0, pb = 1;
	FOREACH(ia, a) {
		res = res + pb * (*ia);
		pb *= b;
	}
	return res;
}

VI sum(const VI & a, int b) {
	int res = 0;
	FOREACH(ia, a)
		res += (*ia) * (*ia);
	return toBase(res, b);
}

int isOk(const VI & a, int b) {
	int aa = toBase10(a, b);
	if(SZ(a) == 1 && a[0] == 1) {
		ok[MP(aa, b)] = 1;
		return 1;
	}
	if(ok.find(MP(aa, b)) != ok.end()) {
		if(ok[MP(aa, b)] == 0)
			return 0;
		return ok[MP(aa, b)];
	}
	ok[MP(aa, b)] = 0;
	return ok[MP(aa, b)] = isOk(sum(a, b), b);
}

int main()
{
	scanf("%d\n", &testsnr);
	REP(nrt, testsnr)
	{
		fprintf(stderr, "Solving test nr = %d / %d\n", nrt + 1, testsnr);
		base.clear();
		gets(line);
		tokens = parse(string(line));
		FOREACH(it, tokens)
			base.PB(stringToInt(*it));
		ok.clear();
		int res = 2;
		while(1) {
			good = true;
			FOREACH(ib, base) {
				good &= isOk(toBase(res, *ib), *ib);
				if(!good)
					break;
			}
			if(good)
				break;
			++res;
		}
		//FOREACH(ib, base)DB(*ib);
		printf("Case #%d: %d\n", nrt + 1, res);
	}
	return 0;
}
