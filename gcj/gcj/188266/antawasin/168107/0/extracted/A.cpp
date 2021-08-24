#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define Int signed long long int  /* 64b Unix : %lld , %llu  */
// #define Int __int64            /* 64b win  : %I64d, %I64u */

// #define DEBUG
#define DB(x) { cout << __LINE__ << ": " << #x << " " << x << endl; }
#define HERE { cout << "HERE\n"; }

#define INF 1000000000

#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define NL printf("\n");
#define RET return
#define sqr(x) ((x)*(x))
#define myabs(x) (((x)<0)?(-(x)):(x))

#define VAR(a,T) __typeof(T) a=(T)
#define BEG(c) (c).begin()
#define BEGR(c) (c).rbegin()
#define END(c) (c).end()
#define ENDR(c) (c).rend()
#define ALL(c) BEG(c), END(c)
#define POS(c,x) ((c).find(x) != END(c))
#define CLEAR(a, v, b) memset(a, v, b)
#define REVERSE(c) reverse(ALL(c))
#define SORT(c) sort(ALL(c))
#define SIZE(c) ((int) (c).size())
#define SSORT(c) stable_sort(ALL(c))
#define REP(i,e) for(int i = 0; i < (e); ++i)
#define FORU(i,b,e) for(int i = (b); i <= (signed)(e); ++i)
#define FORD(i,b,e) for(int i = (b); i >= (signed)(e); --i)
#define VELU(it,c) for(VAR(it, BEG(c)); it != END(c); ++it)
#define VELD(it,c) for(VAR(it, BEGR(c)); it != ENDR(c); ++it)
#define TLE FORU(yy,0,1000000000) FORU(xx,0,1000000000) cout << "\n";

typedef vector<int> vi;

string const digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string to_base(unsigned long num, int base)
{
  if (num == 0)
    return "0";

  string result;
  while (num > 0) {
    ldiv_t temp = div(num, (long)base);
    result += digits[temp.rem];
    num = temp.quot;
  }
  reverse(result.begin(), result.end());
  return result;
}

unsigned long from_base(string const& num_str, int base)
{
  unsigned long result = 0;
  for (string::size_type pos = 0; pos < num_str.length(); ++pos)
    result = result * base + digits.find(num_str[pos]);
  return result;
}

vi split (string s, string del = " ") {
  vi res; int ss = SIZE(s), sdel = SIZE(del);
  for (int p = 0, q; p < ss; p = q+sdel) {
    if ((q = s.find(del, p)) == (signed)string::npos) q = ss;
    if (q-p>0) res.PB(atoi(s.substr(p,q-p).c_str()));
  } RET res;
}

template <class T> inline std::string toString (const T& t) {
	std::stringstream ss; ss << t; return ss.str();
}

map< pair<unsigned long, int >, bool > memo;
set<unsigned long> vis;

bool isHappy (unsigned long n, int base) {
	if (vis.find(n) != END(vis)) return false;
	vis.insert(n);
	string ns = toString(n);
	long L = ns.size()-1, sum = 0;
	FORU(i,0,L) {
		sum += (ns[i]-'0')*(ns[i]-'0');
	}
	string ssum = to_base(sum, base);
	// cout << sum << " " << ssum << endl;
	unsigned long ssuml = atol(ssum.c_str());
	if (ssuml == 1) return true;
  return isHappy(ssuml, base);
}

int main() {

  int T;
  string bases;

  memo.clear();
  scanf("%d\n",&T);
  FORU(testcase,1,T) {
    int ans = 0;
    getline(cin, bases);
    vi B = split(bases);
    int num = 2;
    while (1) {
    	bool happy = true;
    	FORU(i,0,B.size()-1) {
    	  string numb = to_base(num, B[i]);
    	  // cout << num << " base " << B[i] << " = " << numb << endl;
    	  unsigned long numbl = atol(numb.c_str());

    	  bool hap;
    	  if (memo.find(MP(numbl,B[i])) != END(memo)) {
    	  	hap = memo[MP(numbl,B[i])];
    	  } else {
    	  	vis.clear();
    	  	hap = isHappy(numbl, B[i]);
    	  }

    	  if (!hap) {
    	  	happy = false; break;
    	  }
    	}
    	if (happy) break;
    	++num;
    }

    printf("Case #%d: %d\n",testcase,num);
  }

  return 0;
}
