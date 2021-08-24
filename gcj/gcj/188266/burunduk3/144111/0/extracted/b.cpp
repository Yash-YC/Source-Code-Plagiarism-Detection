#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

typedef long long ll;

const int maxr = 44;

int tn, n, m;
int s[maxr][maxr], w[maxr][maxr], t[maxr][maxr];
int c[maxr][maxr];
ll d[maxr][maxr];

void goTo( int i, int j, ll dd )
{
  if (i < 0 || j < 0 || i >= 2 * n || j >= 2 * m)
    fprintf(stderr, "[bad!]\n");
  d[i][j] = min(d[i][j], dd);
}

int main()
{
  scanf("%d", &tn);
  for (int test = 1; test <= tn; test++)
  {
    scanf("%d%d", &n, &m);
    for (int i = n - 1; i >= 0; i--)
      for (int j = 0; j < m; j++)
      {
        scanf("%d%d%d", &s[i][j], &w[i][j], &t[i][j]);
        t[i][j] %= s[i][j] + w[i][j];
      }
    memset(d, 0x7f, sizeof(d));
    memset(c, 0, sizeof(c));
    d[0][0] = 0;
    while (true)
    {
      int j1 = -1, j2 = -1;
      for (int i1 = 0; i1 < 2 * n; i1++)
        for (int i2 = 0; i2 < 2 * m; i2++)
        {
          if (c[i1][i2] != 0)
            continue;
          if (j1 == -1 || d[i1][i2] < d[j1][j2])
            j1 = i1, j2 = i2;
        }
      if (j1 == -1)
        break;
      c[j1][j2] = 1;
//      fprintf(stderr, ".");
      if (j1 != 0 && j1 != 2 * n - 1)
        goTo(((j1 - 1) ^ 1) + 1, j2, d[j1][j2] + 2);
//      fprintf(stderr, ",");
      if (j2 != 0 && j2 != 2 * m - 1)
        goTo(j1, ((j2 - 1) ^ 1) + 1, d[j1][j2] + 2);
      int ii = j1 / 2, jj = j2 / 2, curTime;
      curTime = d[j1][j2] % (s[ii][jj] + w[ii][jj]);
      ll wait0, wait1;
      if (curTime < t[ii][jj] - w[ii][jj])
        wait0 = 0, wait1 = t[ii][jj] - w[ii][jj] - curTime;
      else if (curTime < t[ii][jj])
        wait0 = t[ii][jj] - curTime, wait1 = 0;
      else if (curTime < t[ii][jj] + s[ii][jj])
        wait0 = 0, wait1 = t[ii][jj] + s[ii][jj] - curTime;
      else
        wait0 = t[ii][jj] + s[ii][jj] + w[ii][jj] - curTime, wait1 = 0;
//      fprintf(stderr, ":");
      goTo(j1 ^ 1, j2, d[j1][j2] + wait0 + 1);
//      fprintf(stderr, ";");
      goTo(j1, j2 ^ 1, d[j1][j2] + wait1 + 1);
    }
    printf("Case #%d: %lld\n", test, d[2 * n - 1][2 * m - 1]);
  }
  return 0;
}

