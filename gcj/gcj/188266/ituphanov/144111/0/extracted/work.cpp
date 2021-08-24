#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <vector>
#include <string>
#include <iostream>
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

const int maxn = 25;
const TT inf = TT(1000000000) * 1000000000;

int n, m, s[maxn][maxn], w[maxn][maxn], t[maxn][maxn];
TT d[maxn][maxn][4];
int vis[maxn][maxn][4];

TT get_time(int i, int j, int dir, TT cur_t)
{
   TT sum = s[i][j] + w[i][j];
   cur_t -= t[i][j];
   while (cur_t < 0) cur_t += sum;
   cur_t %= sum;
   TT ans = 0;
   if (dir == 1) {
      if (cur_t < s[i][j]) ans = 0;
      else ans = sum-cur_t;
   } else {
      if (cur_t >= s[i][j]) ans = 0;
      else ans = s[i][j]-cur_t;
   }
   return ans + 1;
}

void relax(int i, int j, int k, int i1, int j1, int k1, TT add)
{
   if (!vis[i1][j1][k1] && d[i1][j1][k1] > d[i][j][k] + add)
      d[i1][j1][k1] = d[i][j][k] + add;
}

int main()
{
   freopen("input.txt" ,"rt", stdin); freopen("output.txt", "wt", stdout);
   
   int i, j, k;
   int test; cin >> test;
   for (int sc = 0; sc < test; sc++) {
      cin >> n >> m;
      for (i = 0; i < n; i++)
         for (j = 0; j < m; j++) {
            cin >> s[i][j] >> w[i][j] >> t[i][j];
            t[i][j] %= s[i][j] + w[i][j];
         }   
      
      memset(vis, 0, sizeof(vis));
      for (i = 0; i < n; i++)
         for (j = 0; j < m; j++)
            for (k = 0; k < 4; k++)
               d[i][j][k] = inf;
      d[n-1][0][2] = 0;
      while (1) {
         TT best = inf;
         int best_i, best_j, best_k;
         for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
               for (k = 0; k < 4; k++)
                  if (!vis[i][j][k] && d[i][j][k] < best) {
                     best = d[i][j][k];
                     best_i = i;
                     best_j = j;
                     best_k = k;
                  }
         if (best == inf) break;
         
         i = best_i;
         j = best_j;
         k = best_k;
         vis[i][j][k] = 1;
         switch (k) {
            case 0:
               if (i) relax(i, j, k, i-1, j, 2, 2);
               if (j) relax(i, j, k, i, j-1, 1, 2);
               relax(i, j, k, i, j, 2, get_time(i, j, 1, d[i][j][k]));
               relax(i, j, k, i, j, 1, get_time(i, j, 2, d[i][j][k]));
               break;
            case 1:
               if (i) relax(i, j, k, i-1, j, 3, 2);
               if (j < m-1) relax(i, j, k, i, j+1, 0, 2);
               relax(i, j, k, i, j, 3, get_time(i, j, 1, d[i][j][k]));
               relax(i, j, k, i, j, 0, get_time(i, j, 2, d[i][j][k]));
               break;
            case 2:
               if (j) relax(i, j, k, i, j-1, 3, 2);
               if (i < n-1) relax(i, j, k, i+1, j, 0, 2);
               relax(i, j, k, i, j, 0, get_time(i, j, 1, d[i][j][k]));
               relax(i, j, k, i, j, 3, get_time(i, j, 2, d[i][j][k]));
               break;
            case 3:
               if (i < n-1) relax(i, j, k, i+1, j, 1, 2);
               if (j < m-1) relax(i, j, k, i, j+1, 2, 2);
               relax(i, j, k, i, j, 1, get_time(i, j, 1, d[i][j][k]));
               relax(i, j, k, i, j, 2, get_time(i, j, 2, d[i][j][k]));
               break;
         }
      }
      
      cout << "Case #" << sc+1 << ": " << d[0][m-1][1] << endl;
   }

   fclose(stdin); fclose(stdout);
   return 0;   
}