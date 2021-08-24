#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<string>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef unsigned long long ull;

bool is_a_happy(long long n, int base) {
  if (n == 1) return true;
  if (n % base != 0) return false;
  return is_a_happy(n / base, base);
}

bool is_happy(long long x, int base) {
  set<long long> m;
  int y = x;
  while(true) {
    if (m.find(y) != m.end()) return false;
    if(is_a_happy(y, base)) return true;
    m.insert(y);
    int ny = 0;
    while(y) {
      int mod = (y % base);
      ny += mod * mod;
      y /= base;
    }
    y = ny;
  }
}

bool is_valid(long long n, vector<int>& bases) {
  FOR(it, bases) {
    if(! is_happy(n, *it)) return false;
  }
  return true;
}

long long solve() {
  long long N = 2;
  char line[1000];
  cin.getline(line, 1000);
  vector<int> base;
  char* p = line;
  int x = 0;
  while(*p != '\0' and *p != '\n') {
    if(*p == ' ') {
      base.push_back(x);
      x =0;
    } else if('0' <= *p and *p <= '9')
      x = x*10 + *p - '0';
    p++;
  }
  base.push_back(x);

  while(1) {
    if (is_valid(N, base)) return N;
    N++;
  }
}
int main () {
  int T;
  scanf("%d\n", &T);

  REP(i,T) {
    printf("Case #%d: %lld\n", i+1, solve());
  }
}
