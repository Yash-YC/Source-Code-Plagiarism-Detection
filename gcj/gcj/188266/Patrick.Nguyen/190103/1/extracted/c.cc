#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, (n))

int c, n;
double cache[100], com[100][100];

double comb(int n, int k) {
  assert(n >= k);
  if (k == 0) return 1;
  if (k == 1) return n;
  if (n == k) return 1;
  
  double & ret = com[n][k];
  if (ret > 0) return ret;
  ret = comb(n - 1, k) + comb(n - 1, k - 1);
  return ret;
}

double prob(int k, int i) {
  return comb(c - k, i) * comb(k, n - i) / comb(c, n);
}

double cal(int k) {
  if (c == k) return 0;
  double & ret = cache[k];
  if (ret > 0) return ret;

  ret = (k >= n ? prob(k, 0) : 0);
  for (int i = 1; i <= n && i + k <= c; i++) 
    if (k >= n - i) {
      double tmp = prob(k, i);
      ret += (cal(i + k) + 1) * prob(k, i);
    }
  ret /= (1 - (k >= n ? prob(k, 0) : 0));
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int C = 1; C <= T; ++C) {
    memset(cache, 0, sizeof cache);
    cin >> c >> n;
    printf("Case #%d: %.7lf\n", C, cal(0));
  }
}
