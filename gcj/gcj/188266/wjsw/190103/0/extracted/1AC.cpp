#include<stdio.h>
long long C[41][41];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	C[0][0]=1;
	for(int i=1;i<=40;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int c,n;
		scanf("%d%d",&c,&n);
		double r[41];
		r[0]=0;
		for(int m=1;m<=c;m++)
		{
			r[m]=0;
			for(int i=1;i<=m&&i<=n;i++)
			{
				int j=n-i;
				if(j>c-m)continue;
				r[m]+=(r[m-i]+1)/C[c][n]*C[m][i]*C[c-m][j];
			}
			if(n<=c-m)
			{
				double x=1.0*C[c-m][n]/C[c][n];
				r[m]=(r[m]+x)/(1-x);
			}
		}
		printf("Case #%d: %.9lf\n",tt,r[c]);
	}
}
