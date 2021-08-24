#include <bits/stdc++.h>
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n;
int a[11111];
int main(){
	Init;
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++ ){
		printf("Case #%d: ", i);
		scanf("%d", &n);
		for (int i = 1; i < n * 2; i ++ )
			for (int j = 1; j <= n; j ++ ){
				int t;
				scanf("%d", &t);
				a[t] ^= 1;
			}
		for (int i = 0; i <= 3000; i ++ )
			if (a[i]) printf("%d ", i);
		printf("\n");
		memset(a, 0, sizeof a);
	}
}
