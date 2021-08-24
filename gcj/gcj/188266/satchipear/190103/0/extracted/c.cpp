#include <stdio.h>
#include <string.h>
double p[11111][44];
int cnk[11][11];

void makecnk() {
	int n, k;
	cnk[0][0] = cnk[1][0] = cnk[1][1] = 1;
	for (n = 2; n <= 10; n++) {
		cnk[n][0] = cnk[n][n] = 1;
		for (k = 1; k < n; k++) {
			cnk[n][k] = cnk[n - 1][k - 1] + cnk[n - 1][k];
		}
	}
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	makecnk();
	int tn, i, j, k, c, n, prob = 0;
	double ans;
	for (scanf("%d", &tn); tn--; ) {
		ans = 0.0;
		memset(p, 0, sizeof(p));
		scanf("%d%d", &c, &n);
		p[0][0] = 1.0;
		for (i = 1; i <= 1000; i++) {
			for (j = n; j <= c; j++) {
				for (k = 0; k <= j && k <= n; k++) {
					p[i][j] += p[i - 1][j - k] * (
							   (double)cnk[c - j + k][k] * cnk[j - k][n - k] / cnk[c][n]);
				}
			}
			ans += i * p[i][c];
			p[i][c] = 0;
		}
		printf("Case #%d: %.7lf\n", ++prob, ans);
	}
	return 0;
}
