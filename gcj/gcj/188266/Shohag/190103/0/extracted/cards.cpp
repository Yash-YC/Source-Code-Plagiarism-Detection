#include<stdio.h>
#include<string.h>

#define LL long long

LL ncr[45][45];

LL make(int n,int r)
{
	if(!r || n==r)
		return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r]=make(n-1,r-1)+make(n-1,r);
	return ncr[n][r];
}

double dp[45];

int c,n;

double make1(int now)
{
	if(now==c)
		return 0.0;
	if(dp[now]>-1)
		return dp[now];
	int i;
	dp[now]=1.0;
	for(i=1;i<=n;i++)
	{
		if(n-i>now || i>c-now)
			continue;
		double k=make(now,n-i);
		k*=make(c-now,i);
		k/=make(c,n);
		dp[now]+=(k*make1(now+i));
	}
	if(now>=n)
	{
		double k=make(now,n);
		k/=make(c,n);
		dp[now]/=(1-k);
	}
	return dp[now];
}

int main()
{
	freopen("card.out","w",stdout);
	int t,cs,i;
	scanf("%d",&t);
	memset(ncr,-1,sizeof(ncr));
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&c,&n);
		for(i=0;i<=c;i++)
			dp[i]=-1;
		printf("Case #%d: %.7lf\n",cs+1,make1(0));
	}
	return 0;
}
