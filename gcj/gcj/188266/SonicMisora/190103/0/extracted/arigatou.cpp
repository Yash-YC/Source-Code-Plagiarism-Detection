#include<iostream>
using namespace std;

int CASE;
int n,c;
double f[41];
double g[41];

double C(int x,int y)
{
	double ans=1;
	for (int i=x;i>=x-y+1;i--)
		ans*=i;
	for (int i=y;i>=1;i--)
		ans/=i;
	return ans;
}

int main()
{
	freopen("arigatou.in","r",stdin);
	freopen("arigatou.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (CASE=1;CASE<=T;CASE++)
	{
		scanf("%d%d",&n,&c);
		f[0]=0; g[0]=1;
		for (int i=1;i<c;i++)
		{
			f[i]=-1;
			g[i]=0;
		}
		for (int i=c;i<=n;i++)
		{
			f[i]=0; double cnt=0;
			for (int j=1;j<=c;j++)
				//if (f[i-j]!=-1)
					cnt+=g[i-j];
			for (int j=1;j<=c;j++)
				//if (f[i-j]!=-1)
					f[i]+=(f[i-j]+C(i,c)/C(i-j,c-j))*(g[i-j]/cnt);
			g[i]=cnt;
		}
		printf("Case #%d: %.7lf\n",CASE,f[n]);
	}
}