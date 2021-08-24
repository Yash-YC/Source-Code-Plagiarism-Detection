#include<stdio.h>
#define maxn 41
double C[maxn][maxn]={0};
double ans[maxn];

void init()
{
	C[0][0]=C[1][0]=C[1][1]=1;
	for(int i=2;i<maxn;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}

int n,c;

double solve()
{
	scanf("%d%d",&n,&c);
	ans[0]=0;
	for(int i=1;i<=n;++i)
	{
		double re1=1.0,re2=1.0-(C[n-i][c]/C[n][c]);
		//printf("re2=%lf\n",re2);
		for(int j=1;j<=i&&j<=c;++j)
		{
		//	printf("re=%lf\n",re1);
			re1+=ans[i-j]*(C[i][j]*C[n-i][c-j]/C[n][c]);
		}
		ans[i]=re1/re2;
		//printf("*%lf\n",ans[i]);
	}
	return ans[n];
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
		printf("Case #%d: %.8lf\n",i+1,solve());
	return 0;
}

