//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 1010;
char s[NUM];
string ans;
int n;
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
#endif
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		scanf("%s", s);
		n = strlen(s);
		ans = s[0];
		for(int i = 1; i < n; ++i)
		{
			if(s[i] >= ans[0])
			{
				ans = s[i] + ans;
			}
			else
			{
				ans += s[i];
			}
		}
		printf("Case #%d: %s\n", cas, ans.data());
	}
	return 0;
}
