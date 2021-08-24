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

typedef pair<int, pair<int, int> > pt;
bool intersect(pt a, pt b) {
    int x = abs(a.y.x - b.y.x);
    int y = abs(a.y.y - b.y.y);
    return !((a.x <= x && b.x <= x)) || ((b.x <= y && a.x <= y));
} 

typedef pair<int , int> cd;

bool solve(int C) {
  printf("Case #%d:", C);

  int n, w, l;
  cin>>n>>w>>l;

  vector<int> r(n);
  for (int i = 0; i < n; i++) {
      cin>>r[i];
  }

  sort(r.begin(), r.end(), greater<int>());

  queue<cd> q;
  q.push(cd(0, 0));

  vector<pt> done;
  for (int i = 0; i < n; i++) {
      bool good = false;
      while (!good) {
          cd c = q.front();
          q.pop();
          pt p = pt(r[i], cd(c.x, c.y));
          good = true;
          for (int j = 0; j < i; j++) {
              if (intersect(p, done[j])) {
                  good = false;
                  break;
              }
          }
          if (good) {
              q.push(cd(p.y.x, p.y.y + r[i]));
              q.push(cd(p.y.x + r[i], p.y.y));
              q.push(cd(p.y.x + r[i], p.y.y + r[i]));
              printf(" %d %d", p.y.x, p.y.y);
              fflush(stdout);
              done.pb(p);
          }
      }
  }
  printf("\n");

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

