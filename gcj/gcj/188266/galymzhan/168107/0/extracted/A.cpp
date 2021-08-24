#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PROBLEM "A"

char a[11][1000000]; // 1-ok, 2-not
int sum(int x, int b) {
  int r = 0;
  while(x) {
    r += (x % b) * (x % b);
    x /= b;
  }
  return r;
}

char get(int x, int b) {
  if(b == 2) return 1;
  if(x < 1000000 && a[b][x]) return a[b][x];
  map<int,bool> f;
  char val;
  do {
    f[x] = true;
    x = sum(x, b);
    if(f[x]) {
      if(x != 1) {
        val = 2;
      }
      else {
        val = 1;
      }
      break;
    }
  } while(true);
  for(map<int,bool>::iterator it = f.begin(); it != f.end(); it++) {
    if(it->first < 1000000) a[b][it->first] = val;
  }
  return val;
}

int main() {
  memset(a, 0, sizeof(a));
  for(int i = 3; i <= 10; i++) {
    a[i][1] = 1;
  }
  /*
  for(int i = 1; i <= 10; i++) {
    cout << i << " = " << (int)get(i, 3) << "\t";
    if(i % 10 == 0) cout << endl;
  }
  return 0;
  */
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int N;
  cin >> N;
  for(int test = 1; test <= N; test++) {
    int K = 0;
    char buf[501];
    cin.get();
    cin.get(buf, 501);
    int a[9], c = 0, n = 0;
    for(int i = 0; i < strlen(buf); i++) {
      if(buf[i] == ' ') {
        a[c++] = n;
        n = 0;
      }
      else {
        n = n * 10 + buf[i] - '0';
      }
    }
    if(n) a[c++] = n;
    for(K = 2; K <= 2147483647; K++) {
      bool f = true;
      for(int i = 0; i < c; i++) {
        if(get(K, a[i]) != 1) {
          f = false;
          break;
        }
      }
      if(f) break;
    }
    cout << "Case #" << test << ": " << K << endl;
  }
  return 0;
}
