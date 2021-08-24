#include <cstdio>
#include <cstring>
typedef long long LL;


int Q[1000], b[20], bn;
bool v[1000];
int dp[1000][12];

bool check(LL n, int base) {
	int sum=0;
	while (n) {
		int tmp = (n%base);
		sum +=tmp*tmp;
		n /= base;
	}
	if (dp[sum][base]!=-1) return dp[sum][base];
	memset(v, 0, sizeof(v));
	int h=0;
	while (sum!=1) {
		if (v[sum]) {
			for (int t=0;t<h;t++) dp[Q[t]][base]=0;
			return 0;
		}
		v[sum]=1; Q[h++]=sum;
		int m=sum; sum=0; 
		while (m) {
			int tmp = m%base;
			sum += tmp*tmp;
			m /= base;
		}
	}
	for (int t=0;t<h;t++) dp[Q[t]][base]=1;
	return 1;
}

LL go() {
	bool f=0;
	for (LL i=2;!f;i++) {
		//printf("trying %d\n", i);
		for (int j=0;j<bn;j++) {
			f = check(i, b[j]);
			if (!f) break;
		}
		if (f) return i;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	char s[10000];
	int T; scanf("%d", &T); gets(s);
	for (int cas=0; cas<T;cas++) {
		int sp=0, spn; bn=0;
		gets(s);
		while (sscanf(s+sp, "%d%n", &b[bn], &spn)>0) {
			bn++;
			sp+=spn;
		}
		//for (int i=0;i<bn;i++) printf("%d ", b[i]); puts("");
		LL ret = go();
		printf("Case #%d: %d\n", cas+1, ret);
	}
	return 0;
}
