#include <cstdio>
#include <algorithm>
using namespace std;

double com(int n, int m) {
  double res = 1;
  for (int i = m+1; i <= n; i++)
    res *= i;
  for (int i = 2; i <= n-m; i++)
    res /= i;
  //printf("%d %d %lf\n", n, m, res);
  return res;
}


const int maxn = 1000000;
const int maxm = 50;
double p[maxn][maxm];
double calc(int c, int n) {
  for (int i = n + 1; i <= c; i++) p[1][i] = 0;
  p[1][n] = 1;
  
  double sum = 1 * p[1][c];
  double sum_old = sum;
  int i;
  for (i = 2; i < maxn; i++) {
    for (int j = n; j <= c; j++) {
      p[i][j] = 0;
      for (int k = n; k <= j && k < c; k++) {
	int need = j - k;
	p[i][j] += p[i-1][k] * com(c-k, need) * com(k, n-need) / com(c, n);
      }
    }
    sum += i * p[i][c];
    if (i > c + 10 && sum - sum_old < 1e-10) break;
    sum_old = sum;
  }
  //if (i * p[i][c] > 1e-6) printf("err\n");
  return sum;
}

int main() {
  int count;
  scanf("%d", &count);
  for (int caseno = 1; caseno <= count; caseno++) {
    int c, n;
    scanf("%d %d", &c, &n);
    printf("Case #%d: %.8lf\n", caseno, calc(c, n));
  }

  return 0;
}
