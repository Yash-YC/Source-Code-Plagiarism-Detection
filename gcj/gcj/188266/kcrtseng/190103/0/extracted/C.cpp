#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;
ld eps = 1e-7;
int C, N;
ld memo[64];
ll totalType;

ll nCr(int n, int r) {
  r = min(r, n-r);
  ll prod = 1;
  for (int i = 0; i < r; ++i) {
    prod *= ((ll) (n - i));
    prod /= (i+1);
  }
  return prod;
}

ld dp(int have) {
  // cout << "dp(" << have << ")" << endl;
  if (have == C) return 0;
  // cout << "dp(" << have << ")" << endl;
  // cout << "memo[" << have << "] = " << memo[have] << endl;
  if (memo[have] > -1 + eps) return memo[have];

  // cout << "dp(" << have << ")" << endl;
  ld ret = 1;
  for (int n = min(N, C-have); n >= 1; --n) {
    // buys a pack with n new cards and N-n cards already had
    if (N-n > have) break;
    // cout << "n = " << n << endl;
    ld curType = ((ld) nCr(C-have, n)) * nCr(have, N-n);
    // cout << "curType = " << curType << endl;
    // cout << "totalType = " << totalType << endl;
    ret += curType / totalType * dp(have + n);
  }

  if (have >= N) {
    // may get cards already had
    ld same = ((ld) nCr(have, N)) / totalType;
    // cout << "same = " << same << endl;
    ret = ret / (1-same);
  }
  // cout << "memo[" << have << "] = " << ret << endl;
  return memo[have] = ret;
}

int main() {
  int numcase;
  cin >> numcase;
  for (int ncase = 1; ncase <= numcase; ++ncase) {
    cin >> C >> N;
    for (int i = 0; i <= C; ++i) memo[i] = -1;
    totalType = nCr(C, N);
    long double ret = dp(0);
    printf("Case #%d: %.7Lf\n", ncase, ret);
  }
}
