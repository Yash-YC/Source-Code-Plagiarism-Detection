#include <cstdio>
#include <cstring>

long long C[50][50];
double ans[50];
int Test;
void work()
{
	int n, c;
	scanf("%d%d", &n, &c);
	memset(ans, 0, sizeof(ans));
	ans[n] = 0;
	for (int i = n - 1; i + 1; --i)
	{
		for (int t = i + 1; t <= n && t <= i + c; ++t)
		{
			double p = 1.0 * C[n - i][t - i] * C[i][c - t + i] / C[n][c];
			ans[i] += p * ans[t];
		}
		double p = 1.0 * C[i][c] / C[n][c];
		ans[i] += 1;
		ans[i] /= (1 - p);
		//p unmove, (1-p) within ans[i]

	}
	printf("Case #%d: %.9lf\n", ++Test, ans[0]);
}
int main()
{
	C[0][0] = 1;
	for (int n = 1; n <= 40; ++n)
	{
		C[n][0] = C[n][n] = 1;
		for (int a = 1; a < n; ++a)
			C[n][a] = C[n - 1][a] + C[n - 1][a - 1];
	}
	int T;
	scanf("%d", &T);
	while (T--)
		work();
}
