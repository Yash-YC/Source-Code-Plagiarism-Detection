#include <iostream>
using namespace std;

const int maxn = 50;
double c[maxn][maxn], f[maxn];
int task, n, m, tt;

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d\n", &task);
    c[0][0] = 1; int i, j;
    for (i = 1; i <= 40; ++i) {
        c[i][0] = 1;
        for (j = 1; j <= 40; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    while (task--) {
          scanf("%d%d\n", &m, &n);
          memset(f, 0, sizeof(f));
          for (i = m - 1; i >= 0; --i) {
              for (j = n - i > 1 ?n - i : 1; j <= n && i + j <= m; ++j)
                  f[i] = f[i] + c[m - i][j] * (f[i + j] + 1) * c[i][n - j] / c[m][n];
              if (i >= n) f[i] = (f[i] + c[i][n] / c[m][n]) / (1 - c[i][n] / c[m][n]);
          }
          printf("Case #%d: %lf\n", ++tt, f[0]);
    }
    return 0;
}
