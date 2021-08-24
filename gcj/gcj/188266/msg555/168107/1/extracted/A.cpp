#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

int ok[11][1000000];

bool is_happy(int n, int b) {
  if(n < 1000000 && ok[b][n] != -1) return ok[b][n];
  bool good = false;
  vector<int> v;
  while(n != 1) {
    if(n < 1000000) {
      if(ok[b][n] == -2) {
        break;
      } else if(ok[b][n] != -1) {
        good = ok[b][n];
        break;
      }
      ok[b][n] = -2;
      v.push_back(n);
    }
    int nn = 0;
    while(n) {
      int r = n % b;
      nn += r * r;
      n /= b;
    }
    n = nn;
  }
  good |= n == 1;
  for(int i = 0; i < v.size(); i++) ok[b][v[i]] = good;
  return good;
}

int res[1 << 9];

int main() {
  memset(ok, -1, sizeof(ok));
  vector<int> v;
  for(int i = 0; i < 1 << 9; i++) v.push_back(i);
  for(int i = 2; !v.empty(); i++) {
    int mm = 0;
    for(int k = 0; k < 9; k++) {
      if(is_happy(i, 2 + k)) mm |= 1 << k;
    }
    for(int j = 0; j < v.size(); j++) {
      int m = v[j];
      if((m & mm) == m) {
        res[m] = i;
        v[j] = v.back();
        v.resize(v.size() - 1);
        j--;
      }
    }
  }
  for(int i = 0; i << 9; i++) cout << res[i] << ", ";
  int T; cin >> T;
  string ln; getline(cin, ln);
  for(int t = 1; t <= T; t++) {
    getline(cin, ln);
    istringstream sin(ln);
    int m = 0;
    int x;
    while(sin >> x) {
      m |= 1 << x - 2;
    }
    cout << "Case #" << t << ": " << res[m] << '\n';
  }

  return 0;
}
