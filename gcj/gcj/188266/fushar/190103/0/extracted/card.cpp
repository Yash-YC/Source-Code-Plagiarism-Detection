#include <cstdio>
#include <cstring>

int T, C, N;
double dp[1<<10];
bool used[1<<10];

double DP(int u)
{
	if (!used[u])
	{
		used[u] = true;
		double res = 0;
		double tot = 0;
		for (int v = 0; v < (1<<C); v++)
		{
			if (__builtin_popcount(v) != N)
				continue;
			if ((u|v) == u)
			{
				res += 1;
			}
			else
			{
				tot += 1;
				res += 1 + DP(u|v);
			}

		}
		dp[u] = res/tot;
	}
	return dp[u];
}

int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		memset(used, false, sizeof used);
		scanf("%d%d", &C, &N);
		used[(1<<C)-1] = true;
		dp[(1<<C)-1] = 0;
		printf("Case #%d: %lf\n", t, DP(0));
	}
}
