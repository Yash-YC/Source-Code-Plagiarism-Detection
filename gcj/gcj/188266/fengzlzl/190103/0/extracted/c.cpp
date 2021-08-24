#include <stdio.h>
#include <string.h>

const double eps=1e-10;

double f[1030], g[1030];

int an;
int a[1026];

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int T, n, c, x, y, ci, i, j, cas=0;	
	scanf("%d", &T);
while (T--)
{
	scanf("%d%d", &n, &c);
	an=0;
	for (i=1; i<(1<<n); i++)
	{
		x=i;
		y=0;
		while (x>0)
		{
			if (x&1) y++;
			x>>=1;
		}
		if (y==c) a[an++]=i;
	}
	f[0]=1;
	double ans = 0;
	bool flag=false;
	for (ci=1; ci<1000; ci++)
	{
		memset(g, 0, sizeof(g));
		for (i=0; i<(1<<n)-1; i++)
		  if (f[i]>eps)
		    for (j=0; j<an; j++)
		      g[i|a[j]]+=f[i]/an;      
		for (i=0; i<(1<<n); i++)
		  f[i]=g[i];      
		ans += ci*g[(1<<n)-1];
//		if (ci*g[(1<<n)-1]>eps) flag=true;
//		if (flag && ci*g[(1<<n)-1]<eps) break;
	}
	printf("Case #%d: %.7lf\n",++cas, ans+eps);
}
	return 0;
}
