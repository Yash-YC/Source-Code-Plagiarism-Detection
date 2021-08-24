#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1010;
int p[N], visit[N], cnt[N], dp[N], c[N], gp[N], len[N], mark[N], lnk[N];

void in_circle(int k) {
	visit[k] = 1;
	if (visit[p[k]] == 1)
		c[k] = 1;
	if (visit[p[k]] == 0)
		in_circle(p[k]);
	visit[k] = 2;
}

void in_circle2(int k, int val) {
	visit[k] = 1;
	mark[k] = val;
	cnt[val]++;
	lnk[val] = k;
	if (!visit[p[k]])
		in_circle2(p[k], val);
}

void dp2(int k) {
	visit[k] = 1;
	if (mark[p[k]] != 0) {
		gp[k] = p[k];
		len[k] = 1;
	} else {
		if (!visit[p[k]]) dp2(p[k]);
		gp[k] = gp[p[k]];
		len[k] = len[p[k]] + 1;
	}
	dp[gp[k]] = max(dp[gp[k]], len[k]);
}

void run(int cas) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", p + i);
	memset(visit, 0, sizeof(visit));
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
		if (!visit[i])
			in_circle(i);
	memset(visit, 0, sizeof(visit));
	memset(mark, 0, sizeof(mark));
	memset(cnt, 0, sizeof(cnt));
	int nr_c = 0;
	for (int i = 1; i <= n; i++)
		if (!visit[i] && c[i])
			in_circle2(i, ++nr_c);
	memset(dp, 0, sizeof(dp));
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++)
		if (!mark[i] && !visit[i])
			dp2(i);
	int sum = 0, ans = 0;
	for (int i = 1; i <= nr_c; i++)
		ans = max(ans, cnt[i]);
	for (int i = 1; i <= nr_c; i++)
		if (cnt[i] == 2)
			sum += cnt[i] + dp[lnk[i]] + dp[p[lnk[i]]];
	ans = max(sum, ans);
	printf("Case #%d: %d\n", cas, ans);
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int cas = 1; cas <= tt; cas++)
        run(cas);
}


