#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <assert.h>
#include <sstream>
using namespace std;
vector<int> bases;
int n;
map< int, bool> seen;
bool happy(int x, int b) {
  if (x == 1)
    return 1;
  if (seen.count(x))
    return false;
  seen[x] = true;
  int ret = 0;
  while (x) {
    ret += (x%b)*(x%b);
    x /= b;
  }
  return happy(ret, b);
}
bool good(int x) {
  for (int i = 0; i < bases.size(); ++i) {
    seen.clear();
    if (!happy(x, bases[i]))
      return false;
  }
  return true;
}
int main() {
  int nocases;
  cin >> nocases;
  getc(stdin);
  for (int rr = 1; rr <= nocases; ++rr) {
    bases = vector<int>();
    string s, t;
    getline(cin, s);
    istringstream p(s);
    while (p >> t)
      bases.push_back(atoi(t.c_str()));
    n = bases.size();
    int K = 2;
    while (!good(K))
      K++;
    printf("Case #%d: %d\n", rr, K);
  }
  return 0;
}
