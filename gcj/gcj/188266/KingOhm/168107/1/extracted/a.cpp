#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxm  = 20000000;
const int maxn  = 11;
int s[maxn][maxm];


int calc(int x, int base) {
  int sum = 0;
  while (x > 0) {
    int now = x % base;
    sum += now * now;
    x /= base;
  }
  return sum;
}

int q[maxm];

void init() {
  for (int i = 2; i < maxn; i++) {
    //printf("i = %d\n", i);
    for (int j = 0; j < maxm; j++) s[i][j] = 0;
    s[i][1] = 2;
    s[i][0] = 3;
    for (int j = 2; j < maxm; j++) { 
      if (s[i][j]) continue;
      //printf("j = %d\n", j);
      q[0] = j;
      s[i][j] = 1;
      int res = -1;
      int r;
      for (r = 0; ; r++) {
	int now = calc(q[r], i);
	if (now >= maxm || now < 0) {
	  printf("err\n");
	}
	//printf("f %d t %d\n", q[r], now);
	//printf("%d\n", now);
	q[r + 1] = now;
	if (s[i][now] == 1) {
	  res = 3;
	  break;
	} else if (s[i][now] != 0) {
	  res = s[i][now];
	  break;
	}
	s[i][now] = 1;
	q[r + 1] = now;
      }
      //      if (res > 3) {
      //	for (int k = 0; k <= r + 1; k++) printf("%d ", q[k]);
      //	printf("... %d\n", res);
      //      }
      for (int k = 0; k <= r + 1; k++)
	s[i][q[k]] = res;
      //printf("%d ", res);
    }
  }
}

void work() {
  int t;
  scanf("%d\n", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    char st[100];
    fgets(st, 100, stdin);
    //printf("%s\n", st);
    istringstream sin(st);
    int v[20];
    int n = 0;
    while (sin >> v[n++]);
    n--;
    //for (int i = 0; i < n; i++) printf("%d ", v[i]);
    //printf("\n");
    bool has = false;
    for (int i = 2; i < maxm; i++) {
      bool ok = true;
      for (int j = 0; j < n; j++)
	if (s[v[j]][i] != 2) {
	  ok = false;
	  break;
	}
      if (ok) {
	has = true;
	printf("Case #%d: %d\n", caseno, i);
	break;
      }
    }
    if (!has) printf("err\n");
  }
}

int main() {
  init();
  //printf("%d %d\n", s[9][91], s[10][91]);
  work();
  return 0;
}
