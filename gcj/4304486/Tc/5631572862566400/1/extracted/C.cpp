#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
void solve() {
	int n;
	scanf("%d",&n);
	int x[N];
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	int ans = 0;
	int L[N];
	for (int i=1;i<=n;i++) L[i] = 0;
	for (int i=1;i<=n;i++) {
		int cur = i;
		int cnt = 0;
		for (int j=0;j<2*n;j++) {
			cnt++;
			if (x[cur] == i) {
				ans = max(cnt,ans);
				break;
			}
			if (x[x[cur]] == cur) {
				L[cur] = max(L[cur],cnt);
				break;
			} 
			cur = x[cur];
		}
	}
	int sumL = 0;
	for (int i=1;i<=n;i++) {
		//printf("%d ",L[i]);
		sumL += L[i];
	}
	ans = max(ans,sumL);
	printf("%d\n",ans);
}
int main() {
	int T;
	scanf("%d",&T);
	for (int ts=1;ts<=T;ts++) {
		printf("Case #%d: ",ts);
		solve();
	}
	return 0;
}