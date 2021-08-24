#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

char dp[11][100005];

char vis[11][100005];

int make(int b,int now)
{
	if(now==1)
		return 1;
	if(now<100000 && dp[b][now]!=-1)
		return dp[b][now];
	int sum=0,temp=now;
	if(now<100000)
		vis[b][now]=1;
	while(temp)
	{
		sum+=(temp%b)*(temp%b);
		temp/=b;
	}
	int ret;
	if(vis[b][sum]!=1)
		ret=make(b,sum);
	else
		ret=0;
	if(now<100000)
		vis[b][now]=2,dp[b][now]=ret;
	return ret;
}

int main()
{
	freopen("multi.out","w",stdout);
	int t,cs,base[50],n,i,ans,j;
	char s[1000];
	gets(s);
	sscanf(s,"%d",&t);
	memset(dp,-1,sizeof(dp));
	memset(vis,0,sizeof(vis));
	for(cs=0;cs<t;cs++)
	{
		gets(s);
		n=0;
		int bs=0,dbs=0;
		ans=-1;
		while(sscanf(s+bs,"%d%n",&base[n],&dbs)==1)
			bs+=dbs,n++;
		for(i=2;i<=1000000;i++)
		{
			int ok=1;
			for(j=0;j<n;j++)
				if(!make(base[j],i))
				{
					ok=0;
					break;
				}
			if(ok)
			{
				ans=i;
				break;
			}
		}
		if(ans!=-1)
			goto done;
		int maybe[]={2688153,4817803,2662657,120407,346719,711725,569669,11814485,218301};
		sort(maybe,maybe+9);
		for(i=0;i<9;i++)
			{
				
				int ok=1;
				for(j=0;j<n;j++)
					if(!make(base[j],maybe[i]))
					{
						ok=0;
						break;
					}
				if(ok)
				{
					ans=maybe[i];
					break;
				}
			}
		if(ans==-1)
			for(i=1000001;i<12000000;i+=2)
			{
				
				int ok=1;
				for(j=0;j<n;j++)
					if(!make(base[j],i))
					{
						ok=0;
						break;
					}
				if(ok)
				{
					ans=i;
					break;
				}
			}
done:;			
		printf("Case #%d: %d\n",cs+1,ans);
	}
	return 0;
}