#include<iostream>
#include<string.h>
using namespace std;

const int MAX=130000;
int dp[MAX][12];
int mark[MAX];

int deal(int k,int b)
{
	int ret=0;
	while(k)
	{
		ret+=(k%b)*(k%b);
		k/=b;
	}
	return ret;
}

int dfs(int k,int b)
{
	dp[k][b]=0;
	int p=deal(k,b);
	if(dp[p][b]==-1)
		dp[k][b]=dfs(p,b);
	return dp[k][b]=dp[p][b];
}
char line[100];
int base[10];
int main()
{
	int b;
	memset(dp,-1,sizeof(dp));
	memset(mark,0,sizeof(mark));
	for(int b=3;b<=10;++b)
	{
		dp[1][b]=1;
		mark[1]|=(1<<b);
		for(int k=2;k<MAX;++k)
		{
			dfs(k,b);
//if(b==3)			printf("dp[%d][%d]=%d\n",k,b,dp[k][b]);
			if(dp[k][b])mark[k]|=(1<<b);
		}
	}
	int cases;
	scanf("%d",&cases);
	gets(line);
	for(int t=1;t<=cases;++t)
	{
		gets(line);
		int len=strlen(line);
		int k=0;
		int tag=0;
		for(int i=0;i<len;)
		{
			char tmp[5];
			int q;
			sscanf(line+i,"%d",&q);
			if(q==10)
				i+=3;
			else
				i+=2;
			if(q==2)continue;
			tag|=(1<<q);
		}
//		printf("%d\n",tag);
		printf("Case #%d: ",t);
		for(int i=2;i<MAX;++i)
		{
			if((tag&mark[i])==tag)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
