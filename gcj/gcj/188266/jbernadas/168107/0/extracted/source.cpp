#include "cstdio"
#include "vector"
#include "sstream"
using namespace std;
typedef long long i64;

const int MAX_N = 1000000;
bool memo[10][MAX_N];
bool mark[10][MAX_N];
bool touched[10][MAX_N];

int GetNext(int b, int k) {
  int sum = 0;
  for (; k > 0; k /= b)
    sum += (k % b) * (k % b);
  return sum;
}
bool IsHappy(int b, int k) {
  if (k == 1) return true;
  if (touched[b][k]) return false;
  bool& ok = memo[b][k];
  if (mark[b][k]) return ok;
  mark[b][k] = touched[b][k] = true;
  ok = IsHappy(b, GetNext(b, k));
  return touched[b][k] = false, ok;
}
int FindMin(const vector<int>& v) {
  int result = -1;
  for (int k = 2; k < MAX_N && result == -1; ++k) {
    bool ok = true;
    for (int i = 0; i < (int)v.size() && ok; ++i)
      ok = IsHappy(v[i], k);
    if (ok) result = k;
  }
  return result;
}
int main() {
  memset(mark, false, sizeof(mark));
  memset(touched, false, sizeof(touched));
  static char str[10000];
  const int T = atoi(fgets(str, sizeof(str), stdin));
  for (int Ti = 1; Ti <= T; ++Ti) {
    istringstream iss(fgets(str, sizeof(str), stdin));
    vector<int> v;
    for (int x; iss >> x; v.push_back(x));
    printf("Case #%d: %d\n", Ti, FindMin(v));
  }
  return 0;
}
