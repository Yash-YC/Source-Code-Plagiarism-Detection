#include <cstdio>
#include <cstring>

typedef long double dbl;

const int maxn = 44;

int tn, n, m;
dbl d[maxn];
dbl c[maxn][maxn];

int main()
{
  memset(c, 0, sizeof(c));
  c[0][0] = 1.0;
  for (int i = 0; i < 42; i++)
    for (int j = 0; j < 42; j++)
    {
      c[i + 1][j] += c[i][j];
      c[i + 1][j + 1] += c[i][j];
    }
  scanf("%d", &tn);
  for (int test = 1; test <= tn; test++)
  {
    scanf("%d%d", &m, &n);
    d[0] = 0.0;
    for (int i = 1; i <= m; i++)
    {
      dbl sum1 = 0.0, sum2 = 0.0, p1 = 0.0;
      for (int j = 0; j <= n; j++)
        if (j <= i && n - j <= m - i)
        {
          dbl pp = c[i][j] * c[m - i][n - j];
          sum1 += pp;
          if (j == 0)
            p1 = pp;
          else
            sum2 += pp * d[i - j];
        }
      d[i] = (sum2 + sum1) / (sum1 - p1);
    }
    printf("Case #%d: %.20Lf\n", test, d[m]);
  }
/*  dbl ans = 0.0;
  for (int i = 0; i < 40; i++)
    ans += 40.0 / (40.0 - i);
  fprintf(stderr, "[ans = %.20Lf]\n", ans);*/
  return 0;
}

