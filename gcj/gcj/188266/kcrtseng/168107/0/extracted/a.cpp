#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;
const int N = 12000000;
bool base[11];
int happy[N][11];

int dp(int x, int b) {
  if (x == 0) return 0;
  if (x < N && happy[x][b] != -1) return happy[x][b];
  happy[x][b] = 0;
  long long sum = 0;
  int copy = x;
  // cout << "dp(" << x << ',' << b << ")" << endl;
  while (copy > 0) {
    long long dig = copy % b;
    sum += dig * dig;
    copy /= b;
  }
  // cout << "sum = " << sum << endl;

  int ret = dp(sum, b);
  if (x < N) happy[x][b] = ret;
  return ret;
}

void precompute() {
  memset(happy, -1, sizeof(happy));
  for (int b = 2; b <= 10; ++b) happy[1][b] = 1;
  for (int i = 2; i < N; ++i) {
    for (int b = 2; b <= 10; ++b) {
      happy[i][b] = dp(i, b);
      // if (i == 3) cout << "happy[" << i << "][" << b << "] = " << happy[i][b] << endl;
    }
  }
}

int main() {
  int ncase;
  cin >> ncase;
  string junk;
  getline(cin, junk);

  precompute();

  string bases;
  for (int c = 1; c <= ncase; ++c) {
    getline(cin, bases);
    istringstream iss(bases);
    memset(base, 0, sizeof(base));
    
    int x;
    while (iss >> x) {
      base[x] = true;
    }

    for (int i = 2; i < N; ++i) {
      bool okay = true;
      for (int b = 2; b <= 10; ++b) {
	if (base[b] && happy[i][b] == 0) {
	  // cout << i << "fails at base " << b << endl;
	  okay = false;
	  break;
	}
      }

      if (okay) {
	cout << "Case #" << c << ": " << i << endl;
	break;
      }
    }
  }
}
