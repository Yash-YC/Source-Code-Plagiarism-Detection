#include <cstdio>
#include <iostream>

using namespace std;
long long a[50][50];
double f[50];
int i,j,k,n,m,c,p,T,I;
main()
{
	a[0][0]=1;
	for (i=1;i<=40;++i)
	{
		a[i][0]=a[i][i]=1;
		for (j=1;j<i;++j)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	f[0]=0;
	scanf("%d",&T);
	for (I=1;I<=T;++I)
	{
		scanf("%d%d",&c,&n);
		for (p=1;p<=c-n;++p)
		{
			double tmp=0;
			for (j=1;j<=min(n,p);++j)
			{
				tmp+=(double)a[p][j]/(double)a[c][n]*a[c-p][n-j]*(f[p-j]+1);
			}
			tmp=tmp+(double)a[p][0]/(double)(a[c][n])*double(a[c-p][n]);
			f[p]=tmp/(1-(double)a[p][0]/(double)(a[c][n])*double(a[c-p][n]));
		}
		printf("Case #%d: %.7lf\n",I,f[c-n]+1);
	}
	return 0;
}
