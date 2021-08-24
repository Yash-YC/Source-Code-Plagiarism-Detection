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

const int maxn = 12000000;

int vis[2048];
char d[maxn][11];

int calc(int num, int base)
{
   if (d[num][base] > 0) return d[num][base];
   if (d[num][base] < 0) return 2;
   d[num][base] = -1;
   int sd = 0, n = num;
   while (n) {
      sd += (n%base)*(n%base);
      n /= base;
   }
   int ans;
   if (sd == 1) ans = 1; else ans = calc(sd, base);
   return d[num][base] = ans;
}

int main()
{
   freopen("input.txt" ,"rt", stdin); freopen("output.txt", "wt", stdout);
   
   int i, j, k;
   int t; cin >> t;
   string s;
   getline(cin, s);
   VI b;
   memset(vis, 0, sizeof(vis));
   
   vis[2044] = 11814485;
   vis[2040] = 11814485;
   vis[2036] = 11814485;
   vis[2028] = 11814485;
   vis[2012] = 4817803;
   vis[1980] = 346719;
   vis[1916] = 28099;
   vis[1788] = 711725;
   vis[1532] = 2688153;
   vis[1020] = 569669;
   
   memset(d, 0, sizeof(d));
   for (int sc = 0; sc < t; sc++) {
      getline(cin, s);
      istringstream ss(s); 
      b.clear();
      int m = 0;
      while (1) {
         ss >> k;
         if (!ss) break;
         b.PB(k);
         m += (1 << k);
      }
      
      int ans = maxn;
      if (vis[m]) {
         ans = vis[m];
      } else {
         for (j = 2; j < maxn; j++) {
            int ok = 1;
            for (i = 0; i < b.size(); i++) {
               if (calc(j, b[i]) != 1) {ok = 0; break;}
            }
            if (ok) {ans = j; break;}
         }
         vis[m] = ans;
      }
      cout << "Case #" << sc+1 << ": " << ans << endl;
   }

   fclose(stdin); fclose(stdout);
   return 0;   
}