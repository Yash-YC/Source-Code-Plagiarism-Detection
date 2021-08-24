#include <stdio.h>
#include <string.h>

double p;

double mem[11][11][1024][250];

double calc(int n, int c, int m, int d)
{
	if(d == 250) return 1;
	if(m == (1<<n)-1) return 0;
	if(mem[n][c][m][d] != 0) return mem[n][c][m][d];
	double ret = 0;
	for (int i = 0; i < (1<<n); i = (__builtin_popcount(i) < c) ? (i + 1) : ((i | (i-1)) + 1))
		if(__builtin_popcount(i) == c) ret += p*(1+calc(n, c, m|i, d+1));
	return mem[n][c][m][d] = ret;
}

int escolhe(int n, int k)
{
	int ret = 1;
	for(int i = n-k+1; i <= n; i++)
		ret *= i;
	for(int i = k; i >= 2; i--)
		ret /= i;
	return ret;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int t = 1; t <= nt; t++)
	{
		int n, c;
		memset(mem, 0, sizeof(mem));
		scanf("%d%d", &n, &c);
		p = 1./escolhe(n,c);
		printf("Case #%d: %.7lf\n", t, calc(n, c, 0, 0));
	}
	return 0;
}
