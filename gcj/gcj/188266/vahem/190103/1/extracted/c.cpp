#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

string fl = "C-large";
string inp = fl+".in";
string outp = fl+".out";

const int CMAX = 61, KMAX=30000;
double dyn[KMAX][CMAX];
double bin[CMAX][CMAX];
int main()
{
  freopen(inp.c_str(), "r", stdin);
  freopen(outp.c_str(), "w", stdout);
  int i, j;
  for (i = 0; i < CMAX; i++)
  {
    bin[i][0] = bin[i][i] = 1;
    for (j = 1; j < i; j++)
      bin[i][j] = bin[i-1][j] + bin[i-1][j-1];
  }
  int nt;
  cin >> nt;
  for (int it = 0; it < nt; it++)
  {
    cerr << it;
    int i, j, c, n, k;
    cin >> c >> n;
    for (k = 0; k < KMAX; k++)
      for (i = 0; i <=c ;i++)
        dyn[k][i] = 0;
    dyn[0][0] = 1;
    double ans = 0;
    for (k = 0; k < KMAX-1; k++)
    {
      for (i = 0; i < c; i++)
        for (j = 0; j + i <= c && j <= n; j++)
        {
          dyn[k+1][i+j] += dyn[k][i] * bin[i][n-j] * bin[c-i][j] / bin[c][n];
        }
      ans += k * dyn[k][c];
    }


    printf("Case #%d: %.9f\n", it+1, ans);
  }
  return 0;
}
