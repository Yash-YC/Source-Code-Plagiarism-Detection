#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <sys/time.h>
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl

#define SZ(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACHD(it,c) for(typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)

#define ALL(c) (c).begin(),(c).end()

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

typedef pair<int,int> II;

typedef long long llong;
typedef unsigned long long ullong;

string convert_base(int x, int b) {
   string s;
   while (x) {
      s += '0' + x % b;
      x /= b;
   }
   reverse(s.begin(), s.end());
   return s;
}

bool is_happy(int x, int b) {
   string s = convert_base(x, b);
   set<string> seen;
   while (true) {
      if (s == "1")
         break;
      if (seen.find(s) != seen.end())
         return false;
      seen.insert(s);
      int sum = 0;
      for (int i = 0; i < s.size(); ++i)
         sum += (s[i]-'0')*(s[i]-'0');
      s = convert_base(sum, b);
   }
   return true;
}

int main(int argc, char *argv[]) {
   string line;
   getline(cin, line);
   int TC;
   istringstream is(line);
   is >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      getline(cin, line);
      is.clear();
      is.str(line);
      int b;
      vector<int> bases;
      while (is >> b) {
         bases.push_back(b);
      }
      int res;
      for (res = 2; ; ++res) {
         bool ok = true;
         for (int i = 0; i < bases.size(); ++i)
            if (!is_happy(res, bases[i])) {
               ok = false;
               break;
            }
         if (ok) break;
      }
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
