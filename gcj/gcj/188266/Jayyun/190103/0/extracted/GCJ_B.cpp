#include <stdio.h>
double ans[15][15];
double f[2][1100];
int trans[1100];
double cal(int c, int n)
{
	int i, j, k, tn = 0;
	for (i = 0; i < (1 << c); i++)
	{
		int cnt = 0;
		for (j = 0; j < c; j++)
			if (i & (1 << j))
				cnt++;
		if (cnt == n)
			trans[tn++] = i;
	}
	int cur = 0;
	for (i = 0; i < (1 << c); i++)
		f[0][i] = 0;
	f[0][0] = 1;
	double res = 0;
	for (i = 1; i <= 1000; i++)
	{
		for (j = 0; j < (1 << c); j++)	
			f[cur ^ 1][j] = 0;
		for (j = 0; j < (1 << c); j++)
			for (k = 0; k < tn; k++)
				f[cur ^ 1][j | trans[k]] += f[cur][j] / tn;
		double tot = 0;
		for (j = 0; j < (1 << c); j++)
			tot += f[cur ^ 1][j];
		if (tot > 0)
			res += i * (f[cur ^ 1][(1 << c) - 1] - f[cur][(1 << c) - 1]) / tot;
		cur ^= 1;
		//printf("%lf %lf\n", res, tot);
	}
	return res;
}
void init()
{
	for (int c = 1; c <= 10; c++)
		for (int n = 1; n <= c; n++)
		{
			ans[c][n] = cal(c, n);
			printf("%d %d %lf\n", c, n, ans[c][n]);
			//return;
		}
}
int main()
{
	init();
	int T, t, c, n;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("ans.txt", "w", stdout);
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		scanf("%d%d", &c, &n);
		printf("Case #%d: %.7lf\n", t + 1, ans[c][n]);
	}
	return 0;
}
