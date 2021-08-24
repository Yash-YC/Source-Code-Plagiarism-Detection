#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char str[100];
int num[20];
int t;
int dp[11][100010];
int bit[100];
bool flag[11][101000];
void dfs(int k,int i)
{
	if(flag[k][i])
    {
    	return;
    }
    flag[k][i]=true;
    
    int temp=i;
    int y=0;
    while(temp)
    {
    	bit[y++]=temp%k;
    	temp/=k;
    }
    temp=0;
    for(int j=0;j<y;j++)
    	temp+=bit[j]*bit[j];
    dfs(k,temp);
    dp[k][i]=dp[k][temp];
    
}
int main(void)
{
	memset(dp,0,sizeof(dp));
	memset(flag,0,sizeof(flag));
	for(int t=2;t<=10;t++)
	{
		dp[t][1]=1;
		flag[t][1]=true;
		for(int i=2;i<=100000;i++)		
		{
			dfs(t,i);				   
		}
	}
/*	for(int i=2;i<100;i++)
	{
		int k=1;
		for(int j=2;j<=10;j++)
		{
			cout<<dp[j][i]<<" ";
			k&=dp[j][i];
		}
		cout<<endl;
		if(k)
		{
		   printf("%d\n",i);
		   break;
		}
	}*/
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
    int tn;
    int cas=0;
	scanf("%d",&tn);
    getchar();
	while(tn--)
    {
	gets(str);
	t=0;
	char *p;
	p=str;
	while(*p!='\0')
	{
		if(*p>='0'&&*p<='9')
		{
		    sscanf(p,"%d",&num[t++]);
		    while(*p>='0'&&*p<='9')
		    	p++;
		}
		else if(*p==' ')
			p++;
	}
	for(int i=2;i<100000;i++)
	{
		int k=1;
		for(int j=0;j<t;j++)
		{
			k&=dp[num[j]][i];
		}
		if(k)
		{
		   printf("Case #%d: %d\n",++cas,i);
		   break;
		}
	}
    }
	return 0;
}
