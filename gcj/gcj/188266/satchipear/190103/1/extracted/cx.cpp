#include <stdio.h>
#include <string.h>
const int MAXN = 10000;
double p[MAXN + 100][44];

double getp(int n1, int k1, int n2, int k2, int n, int k) {
	double ret = 1.0;
	while (k1 || k2 || k) {
		if (k1) ret *= n1;
		if (k2) ret *= n2;
		if (k) ret *= k;
		if (k1) ret /= k1, k1--, n1--;
		if (k2) ret /= k2, k2--, n2--;
		if (k) ret /= n, k--, n--;
	}
	return ret;
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("out", "w", stdout);	
	int tn, i, j, k, c, n, prob = 0;
	double ans;
	for (scanf("%d", &tn); tn--; ) {
		ans = 0.0;
		memset(p, 0, sizeof(p));
		scanf("%d%d", &c, &n);
		p[0][0] = 1.0;
		for (i = 1; i <= MAXN; i++) {
			for (j = n; j <= c; j++) {
				for (k = 0; k <= j && k <= n; k++) {
					p[i][j] += p[i - 1][j - k] * getp(c - j + k, k, j - k, n - k, c, n);							   
				}
			}
			ans += i * p[i][c];
			p[i][c] = 0;
		}
		printf("Case #%d: %.7lf\n", ++prob, ans);
	}
	return 0;
}
