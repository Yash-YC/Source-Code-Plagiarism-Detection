#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<functional>
using namespace std;

typedef long long LL;

double g[1024][1024];

inline int ones(int n)
{
	if(n==0)
		return 0;
	return ones(n&(n-1))+1;
}

int main()
{
	int t,cs,c,n,i,j,k;
	LL f[50][50];
	freopen("s.in","r",stdin);
	freopen("s.out","w",stdout);
	//freopen("l.in","r",stdin);
	//freopen("l.out","w",stdout);
	for(i=0;i<50;i++)
		f[i][0]=f[i][i]=1;
	for(i=0;i<50;i++)
		for(j=1;j<i;j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1];
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		scanf("%d%d",&c,&n);
		g[0][0]=1.0;
		for(i=1;i<1024;i++)
			g[0][i]=0.0;
		double ans=0.0;
		for(i=0;;i++)
		{
			for(j=0;j<(1<<c);j++)
				g[i+1][j]=0.0;
			for(j=0;j<(1<<c)-1;j++)
			{
				if(g[i][j]==0.0)
					continue;
				for(k=1;k<(1<<c);k++)
				{
					if(ones(k)!=n)
						continue;
					g[i+1][j|k]+=g[i][j]/f[c][n];
				}
			}
			if(i>30&&g[i+1][(1<<c)-1]*(i+1)<1e-6)
				break;
			ans+=g[i+1][(1<<c)-1]*(i+1);
		}
		printf("Case #%d: %lf\n",cs,ans);
	}
}