#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

double dp[1 << 11], old[1 << 11];
int state[1 << 11], sn;
int C, N;

int main() {
	freopen("F:\\C-small-attempt0.in", "r", stdin);
	freopen("F:\\C-small-attempt0.out", "w", stdout);
	int cas = 0;
	int i, j;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &C, &N);
		sn = 0;
		for (i = 0; i < (1 << C); ++i) {
			int n = i;
			for (j = 0; n; n >>= 1)
				if (n & 1) j++;
				if (j == N) {
					state[sn++] = i;
				//	printf("i = %d\n", i);
				}
		}
	//	printf("sn = %d\n", sn);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int count;
		double ans = 0;
		for (count = 1; count <= 1000; ++count) {
			memcpy(old, dp, sizeof(dp));
			memset(dp, 0, sizeof(dp));
			for (i = 0; i < (1 << C) - 1; ++i)
				for (j = 0; j < sn; ++j)
					dp[i | state[j]] += 1.0 / sn * old[i];
		//	printf("dp[%d] = %lf\n", 3, dp[3]);
			ans += count * dp[(1 << C) - 1];
		}
		printf("Case #%d: %.7lf\n", ++cas, ans);
	}
	return 0;
}


