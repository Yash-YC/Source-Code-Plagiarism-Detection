#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 45
typedef __int64 int64;

int cs;
int n,m;
__int64 c[MAXN][MAXN];
double dp[MAXN];
void init(int sz)
{
	int i,j;
	c[0][0] = 1;
	for(i=1;i<=sz;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i && j) c[i][j] += c[i-1][j-1];
			if(i) c[i][j] += c[i-1][j];
		}
	}
}

int main()
{
	int i,j,cn=1;
	freopen("C-small-attempt3.in","r",stdin);
	freopen("c-out.txt","w",stdout);
	init(42);
	scanf("%d",&cs);
	while(cs--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++){
				dp[i] = 0;
		}
		dp[m] = 1;
		for(i = m; i < n; i++)
		{
			for(j=0;j<=m;j++){
				if(i+j<=n)
				{
					if(i==m && j==0) continue;
					dp[i+j] += dp[i]*(1.0*c[n-i][j]*c[i][m-j]/c[n][m]);
				}
			}
		}
		printf("Case #%d: %.7lf\n",cn++,n==m?1:(1/dp[n]+1));
	}
	return 0;
}

