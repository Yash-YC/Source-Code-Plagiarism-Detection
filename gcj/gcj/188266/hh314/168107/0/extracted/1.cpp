#include<stdio.h>
#include<string.h>
int a[100];
int k;
int d[12][100002];
void get(int n, int m)
{
	k = 0;
	while(n)
	{
		a[k++] = n % m;
		n = n / m;
	}
}
int set(int n, int m)
{
	int r, i;
	get(n, m);
	int ret = 0;
	for(i = 0; i < k; i++)
	{
		ret += a[i] * a[i];
	}
	if(d[m][ret] == 0)
	{
		d[m][n] = 0;
	}
	else if(d[m][ret] == 1)
	{
		d[m][n] = 1;
	}
	else if(d[m][ret] == 2)
	{
		d[m][n] = 0;
	}
	else
	{
		d[m][n] = 2;
		d[m][n] = set(ret, m);
	}
	return d[m][n];
}
void init()
{
	int i, j;
	memset(d, -1, sizeof(d));
	for(i = 2; i <= 10; i++)
	{
		for(j = 1; j <= 100000; j *= i)
		{
			d[i][j] = 1;
		}
		for(j = 2; j <= 100000; j++)
		{
			set(j, i);
		}
	}
}
int main()
{
	int T;
	int tt, i, j, n, ans;
	char ch;
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	init();
	scanf("%d",&T);
	for(tt = 1; tt <= T; tt++)
	{
		n = 0;
		while(1)
		{
			scanf("%d%c",&a[n++],&ch);
			if(ch == '\n') break;
		}
		for(j = 2; j <= 100000; j++)
		{
			for(i = 0; i < n; i++)
			{
				if(d[a[i]][j] != 1) break;
			}
			if(i == n)
			{
				ans = j;
				break;
			}
		}
		printf("Case #%d: %d\n",tt, ans);
	}
	return 0;
}
