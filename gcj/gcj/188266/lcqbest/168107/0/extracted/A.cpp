#include <stdio.h>
#include <string.h>
#define LIM 12000000
int f[11][LIM+2], s[10000000+2], ap[12];

void pre(int n, int b)
{
	int top = 0, tmp;
	while (!f[b][n]) {
		f[b][n] = -1;
		s[top++] = n;
		tmp = 0;
		while (n) {
			tmp += (n%b)*(n%b);
			n /= b;
		}
		n = tmp;
	}
	if (f[b][n] == 1)
		for (int i = 0; i < top; i++)
			f[b][s[i]] = 1;
}
int d[] = {7, 6, 8, 9, 10, 3, 5};
int main()
{
	freopen("A-small-attempt0(3).in", "r", stdin);
	freopen("A-small-attempt0(3).out", "w", stdout);
	int T;
	char str[100];
	for (int i = 0; i < 7; i++) {
		f[d[i]][1] = 1;
		for (int x = 2; x < LIM; x++)
			pre(x, d[i]);
	}
	scanf("%d\n", &T);
	for (int cas = 1; cas <= T; cas++) {
		gets(str);
		memset(ap, 0, sizeof(ap));
		for (int i = 0; i < strlen(str); i++)
			if (str[i] == '1') {
				ap[10] = 1;
				i++;
			}
			else ap[str[i]-'0'] = 1;
		for (int i = 2; i < LIM; i++) {
			int j;
			for (j = 0; j < 7; j++)
				if (ap[d[j]] && f[d[j]][i] == -1) break;
			if (j == 7) {
				printf("Case #%d: %d\n", cas, i);
				break;
			}
		}
	}
	return 0;
}