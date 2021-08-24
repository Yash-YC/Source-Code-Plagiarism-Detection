#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>

using namespace std;

typedef long double real;
typedef long long TT;

#define PB push_back
#define SQR(x) ((x)*(x))
#define PII pair<int, int>
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VTT vector<TT>
#define VR vector<real>
#define A first
#define B second

const int maxn = 50;

real c[maxn][maxn], f[maxn], d[maxn];

int main()
{
   freopen("input.txt" ,"rt", stdin); freopen("output.txt", "wt", stdout);
   
   int i, j, k;

   f[0] = 1;
   for (i = 1; i < maxn; i++) f[i] = f[i-1] * i;
   for (i = 0; i < maxn; i++) {
      for (j = 0; j <= i; j++)
         c[i][j] = f[i] / f[j] / f[i-j];
      for (j = i+1; j < maxn; j++)
         c[i][j] = 0.0;
   }

   int t; cin >> t;
   for (int sc = 0; sc < t; sc++) {
      int a, n;
      cin >> a >> n;

      d[a] = 0.0;
      for (k = a-1; k >= 0; k--) {
         real s = 0;
         for (i = 1; i <= n; i++)
            if (n-i >= 0 && k+i <= a)
               s += c[k][n-i] * c[a-k][i] / c[a][n] * (d[k+i] + 1.0);
         s += c[k][n]/c[a][n];
         d[k] = s / (1 - c[k][n]/c[a][n]);
      }
      
      cout << "Case #" << sc+1 << ": " << fixed << setprecision(6) << d[0] << endl;
   }

   fclose(stdin); fclose(stdout);
   return 0;   
}