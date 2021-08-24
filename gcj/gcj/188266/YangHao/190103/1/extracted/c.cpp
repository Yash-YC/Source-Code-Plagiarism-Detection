#include <stdio.h>
#include <memory.h>
const int maxk = 40;
int i,j,cases,t,n,m;
double c[maxk+1][maxk+1],s,tmp,f[maxk+1];
double C(int i,int j)
{
	if (i<0||j<0||j>i) return 0;
	return c[i][j];
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&cases);
	memset(c,0,sizeof(c));
	for (i=0;i<=maxk;i++) c[i][0]=c[i][i]=1;
	for (i=1;i<=maxk;i++)
		for (j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	for (t=1;t<=cases;t++)
	{
		scanf("%d%d",&m,&n);
		f[m]=0;
		for (i=m-1;i>=0;i--)
		{
			s=0;
			for (j=i+1;j<=m;j++)
				s+=C(i,n-(j-i))*C(m-i,j-i)*f[j];
			s/=C(m,n);
			s+=1;
			tmp=1-C(i,n)*C(m-i,0)/C(m,n);
			f[i]=s/tmp;
		}
		printf("Case #%d: %.5lf\n",t,f[0]);
	}
	return 0;
}