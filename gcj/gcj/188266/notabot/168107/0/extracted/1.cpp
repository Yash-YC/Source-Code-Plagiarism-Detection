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

string to(ll x, int b)
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

ll from(string s, int b)
{
   ll res = 0;
   for (int i = 0, j = 1; i < sz(s); i++, j *= b)
      res += (s[i] - '0') * j;
   return res;
}

bool happy(int x, int b)
{
   set < string > was;
   string s = to(x, b);
   int n;
   while (s != "1" && !was.count(s))
   {
      was.insert(s);
      int t = 0;
      for (int i = 0; i < sz(s); i++)
         t += (s[i] - '0') * (s[i] - '0');
      s = to(t, b);
   }
   return s == "1";
}

int main()
{
   int T;
   scanf("%d\n", &T);
   for (int tt = 0; tt < T; tt++)
   {
      int x;
      gets(s);
      istringstream iss(s);
      vector < int > b;
      while (iss >> x)
         b.pb(x);
      int res = -1;
      for (int i = 2; ; i++)
      {
         bool found = true;
         for (int j = 0; j < sz(b); j++)
            if (!happy(i, b[j]))
            {
               found = false;
               break;
            }
         if (found)
         {
            res = i;
            break;
         }
      }
      printf("Case #%d: %d\n", tt + 1, res);
   }
   return 0;
}
