#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

#define sz(c) ((int) (c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

char s[1000];
int res[1 << 10];

string to(int x, int b)
{
   string res;
   while (x >= b)
   {
      res.pb((x % b) + '0');
      x /= b;
   }
   if (x)
      res.pb(x + '0');
   return res;
}

bool happy(int x, int b)
{
   set < int > was;
   string s = to(x, b);
   int p = x;
   while (p != 1 && !was.count(p))
   {
      was.insert(p);
      int t = 0;
      for (int i = 0; i < sz(s); i++)
         t += (s[i] - '0') * (s[i] - '0');
      p = t;
      s = to(t, b);
   }
   return p == 1;
}

int find(vector < int > &b, int start)
{
   for (int i = start; ; i++)
   {
      bool found = true;
      for (int j = 0; j < sz(b); j++)
         if (b[j] != 2 && b[j] != 4 && !happy(i, b[j]))
         {
            found = false;
            break;
         }
      if (found)
      {
         return i;
         break;
      }
   }
}

int main()
{
   memset(res, ~0, sizeof(res));
   int N = 9;
   for (int i = 1; i < 1 << N; i++)
   {
      int start = 2;
      vector < int > b;
      for (int j = 0; j < N; j++)
         if ((i >> j) & 1)
         {
            if (res[i - (1 << j)] != -1)
               start = max(start, res[i - (1 << j)]);
            if (j != 0 && j != 2)
               b.pb(j + 2);
         }
      res[i] = find(b, start);
      cout << i << " " << res[i] << endl;
   }
   return 0;
}
