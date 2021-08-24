#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000;
const int N = 1000010;

char s[N];
int a[N];

int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    int n, f;
    double _f;
    scanf("%d %lf", &n, &_f);
    f = (int)(_f * inf + 0.5);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - '0';
    }
    // input data ends
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    // solution starts
    long long bnum = 1;
    long long bden = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
      int ones = 0, zeros = 0;
      for (int j = i; j < n; j++) {
        if (a[j] == 1) {
          ones++;
        } else {
          zeros++;
        }
        long long num = abs(ones * (inf - f) - zeros * f);
        long long den = ones + zeros;
        if (num * bden < bnum * den) {
          bnum = num;
          bden = den;
          start = i;
        }
      }
    }
    printf("%d\n", start);
    // solution ends
    fflush(stdout);
    fprintf(stderr, "test %d solved, time = %d ms\n", qq, (int)clock());
  }
  return 0;
}
