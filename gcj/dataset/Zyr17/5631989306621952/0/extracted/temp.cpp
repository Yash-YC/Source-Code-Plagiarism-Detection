#include <bits/stdc++.h>
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n;
char s[11111],a[11111];
int main(){
	Init;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ){
		printf("Case #%d: ", i);
		scanf("%s", s);
		int len = strlen(s);
		int t = 1111, w = 1111;
		memset(a, 0, sizeof a);
		a[1111] = s[0];
		for (int i = 1; i < len; i ++ )
			if (s[i] >= a[t]) a[ -- t] = s[i];
			else a[ ++ w] = s[i];
		printf("%s\n", a + t);
	}
}
