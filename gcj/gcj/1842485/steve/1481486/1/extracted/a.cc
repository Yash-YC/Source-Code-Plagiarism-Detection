#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define pb push_back
#define go(x,it) for(typeof((x).begin()) it=(x).begin(); it!=(x).end(); it++)
#define x first
#define y second

typedef long long ll;

bool solve(int C) {
  printf("Case #%d:", C);
  int n;
  cin>>n;
  vector< pair<int, int> > d(n);
  for (int i = 0; i < n; i++) {
      cin>>d[i].x>>d[i].y;
  }
  int D;
  cin>>D;
  sort(d.begin(), d.end());
  vector<int> reachable(n);
  reachable[0] = d[0].x;
  for (int i = 0; i < n; i++) {
      if (reachable[i]) {
          for (int j = i + 1; j < n; j++) {
              if (d[j].x - d[i].x <= reachable[i]) {
                  reachable[j] = max(reachable[j], min(d[j].y, d[j].x - d[i].x));
              }
          }
      }
  }
  for (int i = 0; i < n; i++) {
      if (reachable[i] + d[i].x >= D) {
          printf(" YES\n");
          return true;
      }
  }

  printf(" NO\n");
  return true;
}

int main() {
  srand(time(NULL));
  int n = 1;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    if (!solve(i)) {
      break;
    }
  }
  return 0;
}

