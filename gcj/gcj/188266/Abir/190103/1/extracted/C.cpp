#include <cstdio>
using namespace std;

const int MAXN=50;

typedef long long i64;

double dp[MAXN];
i64 binom[MAXN][MAXN];

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for(int i = 0;i<MAXN;i++)
		binom[i][i]=binom[i][0]=1;
	
	for(int i=2;i<MAXN;i++)
		for(int j=1;j<i;j++)
			binom[i][j]=binom[i-1][j]+binom[i-1][j-1];

	int T;
	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++)
	{
		int C,N;
		scanf("%d%d",&C,&N);
		dp[C]=0;
		for(int i = C-1; i >= 0; i--)
		{
			dp[i]=binom[i][N]*1.0/binom[C][N];
			for(int j = 1;j<=N && i+j <= C;j++)
			{
				dp[i] += (1+dp[i+j])*binom[i][N-j]*binom[C-i][j]/binom[C][N];
			}
			dp[i] /= 1 - (( binom[i][N]*1.0)/binom[C][N] );
		}
		printf("Case #%d: %.7lf\n",cas, dp[ 0 ] );
	}

	return 0;
}
