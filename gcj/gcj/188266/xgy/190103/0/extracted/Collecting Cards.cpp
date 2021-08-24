#include <cstdio>
#include <cstring>
using namespace std;

double dp[50];
double p[50][50][50][50] = { 0 };
int num[50] = { 0 };
int c[50][50] = { 0 };

int main()
{
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	int N = 1 << 10;
	for (int mask = 1; mask < N; ++mask) {
		for (int i = 0; i < 10; ++i)
			if (mask & (1 << i)) {
				num[mask] = num[mask ^ (1 << i)] + 1;
				break;
			}
	}
	for (int i = 1; i <= 10; ++i) {
		c[i][1] = i;
		for (int j = 2; j <= 10; ++j) {
			if (j > i)
				c[i][j] = 0;
			else
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			//printf("%d %d %d\n", i, j, c[i][j]);
		}
	}
	for (int mask1 = 1; mask1 < N; mask1 = (mask1 << 1) + 1) {
		for (int i = 1; i <= 10; ++i) {
			for (int mask2 = 1; mask2 < (1 << i); ++mask2) {
				int mask = mask1 | mask2;
				p[i][num[mask1]][num[mask2]][num[mask]] += 1.0 / c[i][num[mask2]];
			}
		}
	}
	//printf("%d %.6lf\n", c[3][2], p[3][2][2][3]);
	int t;
	scanf("%d", &t);
	int n, cc;
	for (int T = 1; T <= t; ++T) {
		scanf("%d %d", &n, &cc);
		memset(dp, 0, sizeof(dp));
		dp[cc] = 1;
		double tmp[50];
		double res = dp[n];
		for (int it = 0; it < 100000; ++it) {
			memset(tmp, 0, sizeof(tmp));
			for (int i = cc; i < n; ++i) {
				for (int j = i; j <= n; ++j) {
					tmp[j] += dp[i] * p[n][i][cc][j];
				}
			}
			memcpy(dp, tmp, sizeof(tmp));
			//for (int i = 1; i <= 10; ++i)
			//	printf("%.6lf ", dp[i]);
			//putchar('\n');
			res += (it + 2) * dp[n];
			//printf("%.6lf %.6lf\n", dp[n], res);
		}
		printf("Case #%d: %.7lf\n", T, res);
	}
	return 0;
}
