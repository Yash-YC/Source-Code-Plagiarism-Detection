#include <bits/stdc++.h>
using namespace std;
const int N = 60;
void solve() {
	int n;
	int s[N*N];
	for (int i=0;i<N*N;i++) s[i] = 0;
	scanf("%d",&n);
	for (int i=0;i<2*n*n-1*n;i++) {
		int x;
		scanf("%d",&x);
		s[x]++;
	}
	for (int i=1;i<N*N;i++) if (s[i] % 2 == 1) printf(" %d",i);
	printf("\n");
}
int main() {
	int T;
	scanf("%d",&T);
	for (int ts=1;ts<=T;ts++) {
		printf("Case #%d:",ts);
		solve();
	}
	return 0;
}