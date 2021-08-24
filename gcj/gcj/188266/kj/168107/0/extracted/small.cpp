#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <limits>
#include <cassert>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef complex<double> C;

const double pi = 3.141592653589793238462643383279;
const double napier = 2.718281828459045235360287471352;
const C eye = C(0, 1);

#define FOREACH(it, col) for (typeof((col).begin()) it = (col).begin(); it != (col).end(); ++it)
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR3(i, m, n) for (int i = (int)m; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

int nTestCases;
vector<int> bases;
int ans;

void read_input()
{
  string s;
  getline(cin, s);
  istringstream ss(s);
  bases.resize(0);
  for (;;) {
    int b;
    ss >> b;
    bases.push_back(b);
    if (ss.eof())
      break;
  }
}

bool happy_on(int n, int base)
{
  if (n == 1)
    return true;

  set<int> s;
  s.insert(n);
  for (;;) {
    int sum = 0;
    int m = n;
    while (m) {
      int a = m / base;
      int b = m % base;
      sum += b * b;
      m = a;
    }
    if (sum == 1)
      return true;
    n = sum;
    if (s.find(n) != s.end())
      break;
    s.insert(n);
  }
  return false;
}

bool happy(int n)
{
  FOR (i, bases.size())
    if (!happy_on(n, bases[i]))
      return false;
  return true;
}

void solve()
{
  for (int i = 2;; ++i) {
    if (happy(i)) {
      ans = i;
      break;
    }
  }
}

int main()
{
  cin >> nTestCases;
  string s;
  getline(cin, s);
  REP (i, nTestCases) {
    read_input();
    solve();
    cout << "Case #" << i << ": " << ans << endl;
    cerr << "Case #" << i << ": " << ans << endl;
  }

  return 0;
}
