#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

#define N1 1000

bool pre[15][N1];
bool done[15][N1];

int next(int x, int base) {
  int tmp = 0, tmp2;
  while (x) {
    tmp2 = x % base;
    tmp += tmp2 * tmp2;
    x /= base;
  }
  return tmp;
}

bool calc(int x, int base) {
  if (! done[base][x]) {
    done[base][x] = true;
    pre[base][x] = calc( next(x, base) , base);
  }
  return pre[base][x];
}

void init() {
  int i, j;
  for (i = 2; i <= 10; i++) {
    pre[i][1] = true;
    done[i][1] = true;
  }

  for (i = 2; i <= 10; i++) {
    for (j = 3; j < N1; j++) {
      calc(j, i);
    }
  }
}

bool happy(int x, int base) {
  if (x < N1) return pre[base][x];
  else return happy(next(x, base), base);
}

int main() {
  int cases, q, n, base[15], x, ans, i;
  string s;
  
  init();
  cin >> cases;
  getline(cin, s);
  for (q = 1; q <= cases; q++) {
    getline(cin, s);
    istringstream iss(s);
    n = 0;
    while (iss >> x) {
      base[n++] = x;
    }
    for (ans = 2; true; ans++) {
      for (i = 0; i < n; i++) {
	if (! happy(ans, base[i])) break;
      }
      if (i == n) break;
    }
    printf("Case #%d: %d\n", q, ans);
  }
  return 0;
}
