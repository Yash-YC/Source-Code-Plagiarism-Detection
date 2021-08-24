#include <cstdio>
#include <cstring>
int lst[10];
int bigInt[1000], l;
bool flag[60001];
void dec2x(int num, int x) {
	l = 0;
	while (num) {
		bigInt[l ++] = num % x;
		num /= x;
	}
}
int x2dec(int x) {
	int i, j, sum = 0;
	for (i = 0, j = 1; i < l; ++i, j *= x)
		sum += bigInt[i] * j;
	return sum;
}
bool check(int x) {
	int i, tmp = x2dec(x);
	if (flag[tmp] && tmp != 1)
		return false;
	if (tmp == 1)
		return true;
	flag[tmp] = true;
	int sum = 0;
	for (i = 0; i < l; ++ i)
		sum += bigInt[i] * bigInt[i];
	dec2x(sum, x);
	return check(x);
}
int main ()
{
	int t, i, j, ca, n;
	char c;
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &t);
	for (ca = 1; ca <= t; ++ ca) {
		n = 0;
		do {
			scanf("%d", &lst[n++]);
			c = getchar();
		} while (c != '\n');
		for (i = 2; ; ++ i) {
			for (j = 0; j < n; ++ j) {
				dec2x(i, lst[j]);
				memset(flag, 0, sizeof(flag));
				if (!check(lst[j]))
					break;
			}
			if (j == n)
				break;
		}
		printf("Case #%d: %d\n", ca, i);
	}
}
