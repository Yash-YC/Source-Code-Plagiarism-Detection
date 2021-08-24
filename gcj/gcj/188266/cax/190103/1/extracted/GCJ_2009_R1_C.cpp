#include <iostream>
#include <cmath>
using namespace std;

typedef long long int64;
const int N = 50;
double dp[N];
int64 c[N][N];
double a[N][N], b[N];

void gauss(double a[N][N], double b[N], int n)
{
	int i, j, k, p, q;
	static double c[N];
	static int per[N];
	for (i = 0; i < n; ++i) per[i] = i;
	memcpy(c, b, sizeof(double) * n);
	for (i = 0; i < n; ++i)
	{
		double maxV = 0.0;
		for (j = i; j < n; ++j)
			for (k = i; k < n; ++k)
				if (maxV < fabs(a[j][k]))
				{
					maxV = fabs(a[j][k]);
					p = j; q = k;
				}
		if (p != i)
		{
			for (j = i; j < n; ++j)
				swap(a[i][j], a[p][j]);
			swap(c[i], c[p]);
		}
		if (q != i)
		{
			for (j = 0; j < n; ++j)
				swap(a[j][i], a[j][q]);
			swap(per[i], per[q]);
		}
		double tmp = a[i][i];
		for (j = i; j < n; ++j) a[i][j] /= tmp;
		c[i] /= tmp;
		for (j = i + 1; j < n; ++j)
		{
			tmp = a[j][i];
			for (k = i; k < n; ++k)
				a[j][k] -= a[i][k] * tmp;
			c[j] -= c[i] * tmp;
		}
	}
	for (i = n - 1; i >= 0; --i)
		for (j = n - 1; j > i; --j)
			c[i] -= a[i][j] * c[j];
	for (i = 0; i < n; ++i) b[per[i]]= c[i];
}

int main()
{
	int num, cas;
	int m, n;
	int i, j, k;
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &cas);
	for (i = 0; i < N; ++i)
	{
		c[i][0] = c[i][i] = 1;
		for (j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	for (num = 1; num <= cas; ++num)
	{
		scanf("%d %d", &m, &n);
		memset(a, 0, sizeof(a));
		a[m][m] = 1.0;
		b[m] = 0.0;
		for (i = 0; i < m; ++i)
		{
			b[i] = 1.0;
			a[i][i] = 1.0;
			for (j = max(0, n - m + i); j <= i; ++j)
			{
				k = i + n - j;
				a[i][k] -= (double)c[i][j] * c[m - i][n - j] / c[m][n];
			}
		}
		gauss(a, b, m + 1);
		printf("Case #%d: %.7lf\n", num, b[0]);
	}
	return 0;
}
