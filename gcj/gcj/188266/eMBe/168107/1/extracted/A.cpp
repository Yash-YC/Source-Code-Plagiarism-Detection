#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<int, bool> done[11];

bool happy(int x, int b)
{
  set<int> S;
  S.insert(1);
  int xx = x;
  while (S.count(x) == 0) {
    if (done[b].count(x)) return done[b][x];
    S.insert(x);
    int y = 0;
    while (x > 0) {
      int d = x % b;
      y += d*d;
      x /= b;
    }
    x = y;
  }
  return done[b][xx] = (x == 1);
}

bool fajne[11][1000];

bool happy2(int x, int b)
{
  int y = 0;
  while (x > 0) {
    int d = x % b;
    y += d*d;
    x /= b;
  }
  return fajne[b][y];
}

int res[1 << 8];

void prepare()
{
  res[0] = 2;
  for (int S = 1; S < (1 << 8); S++) {
    int m = 2;
    for (int i = 0; i < 9; i++) {
      if (S & (1 << i)) m = max(m, res[S ^ (1 << i)]);
    }
    while (true) {
      for (int i = 0; i < 8; i++) {
        if (S & (1 << i)) {
          if (!happy2(m, i+3)) goto niefajnie;
        }
      }
      break;
      niefajnie:
      m++;
    }
    res[S] = m;
  }
}

int solve()
{
  int S = 0;
  vector<int> bases;
  char buf[1234]={};
  gets(buf);
  char* y = buf;
  while (true) {
    char* x = y;
    while (*x >= '0' && *x <= '9') x++;
    bool k = false;
    if (*x == '\0') k = true;
    *x = '\0';
    int aa = atoi(y);
    if (aa > 2) {
      S |= 1 << (aa - 3);
    }
    if (k) break;
    y = x+1;
  }
  return res[S];
}

int main()
{
  for (int b = 2; b <= 10; b++) {
    for (int i = 0; i < 1000; i++) {
      fajne[b][i] = happy(i, b);
    }
  }
  prepare();
  int t;
  scanf("%d ", &t);
  for (int c = 1; c <= t; c++) {
    printf("Case #%d: %d\n", c, solve());
  }
  return 0;
}
