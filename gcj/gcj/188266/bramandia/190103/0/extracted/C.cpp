#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

#define LL long long

LL thecomb[50][50];

// A combinasi B
LL comb(int A, int B)
{
	if (A<0 || B<0 || B>A)
		return 0;
	if (B==0)
		return 1;
	return thecomb[A][B];
}

void gencomb(int maxe)
{
	int i,j;
	thecomb[0][0]=1;
	for (i=1; i<=maxe; i++)
	{
		thecomb[i][0]=1;
		for (j=1; j<=i-1; j++)
		{
			thecomb[i][j]=thecomb[i-1][j]+thecomb[i-1][j-1];
		}
		thecomb[i][j]=1;
	}
}

double dp[41];
bool isset[41];

int C,N;

double go(int c)
{
	int sisa=C-c;
	if (sisa==0)
		return 0;
	int dapet=0;
	LL co=comb(c,N-dapet)*comb(sisa,dapet);
	double x=co;
	double tot=0;
	LL de=comb(C,N);
	for (dapet=1; dapet<=min(sisa,N); dapet++)
	{
		LL z=comb(c,N-dapet)*comb(sisa,dapet);
		tot+=((double)z/de)*go(c+dapet);
		co+=z;
	}
	double y=(double)co/de;
	x=x/de;
	return (y+tot)/(1-x);
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	gencomb(40);
	int T,t;
	scanf("%d", &T);
	for (t=1; t<=T; t++)
	{
		scanf("%d %d", &C, &N);
		memset(isset,0,sizeof(isset));
		double ans=go(0);
		printf("Case #%d: %.7lf\n",t,ans);
	}
	return 0;
}
