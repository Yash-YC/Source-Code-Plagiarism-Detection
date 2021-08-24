#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <assert.h>
using namespace std;
int C, N;
long double dpp[41][41][41];
long double dpg[41];
long double p(int a, int b, int left) {
  if (a > b)
    return 0;
  if (left == 0)
    return a == b;
  long double &ret = dpp[a][b][left];
  if (ret > -.5)
    return ret;
  ret = 1.*(C - (N - left) - b)/(C - (N - left)) * p(a, b, left - 1);
  ret += 1.*b/(C - (N - left)) * p(a, b - 1, left - 1);
  return ret;
}
long double go(int x) {
  if (!x)
    return 0;
  long double &ret = dpg[x];
  if (ret > -.5)
    return ret;
  ret = 0;
  for (int i = 0; i < x; ++i)
    ret += p(i, x, N) * (1 + go(i));
  ret += p(x, x, N);
  ret /= (1. - p(x, x, N));
  return ret;
}
int main() {
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    cin >> C >> N;
    if (C == N) {
      printf("Case #%d: 1\n", rr);
      continue;
    }
    for (int i = 0; i <= 40; ++i)
      for (int j = 0; j <= 40; ++j)
	for (int k = 0; k <= 40; ++k)
	  dpp[i][j][k] = dpg[i] = -1;
    printf("Case #%d: %.6Lf\n", rr, go(C));
  }
  return 0;
}
