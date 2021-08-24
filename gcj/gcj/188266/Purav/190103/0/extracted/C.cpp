#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#define f(i, n) for(int i = 0; i < n; i++)
#define s(n) scanf("%d", &n)
#define sc(n) scanf("%s", &n)
#define fill(a, v) memset(a, v, sizeof a)
#define inf (int)1e9
using namespace std;

int n, c, t, zz = 1;
main()
{
	s(t);
	while(t--)
	{
         s(c); s(n);
         double ans = 1;
         while(c > n)
         {
                 ans += 1. * c / n;
                 c -= n;
         }
         printf("Case #%d: %.6lf\n", zz++, ans);
    }
}
