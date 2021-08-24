#include<cstdio>

const int maxn=1200000+10;
bool flag[maxn];
int delta[maxn];
int base;

void dfs(int x)
{
		
	if (flag[x]) return;
	flag[x]=true;
	if (x==1)
	{
		delta[x]|=(1<<base);
		return;
	}
	//printf("%d\n",x);
	
	int tmp[32],len=0;
	for (int k=x,i=0;k;k/=base)
		tmp[len++]=k%base;
	int sum=0;
	for (int i=0;i<len;i++) sum+=tmp[i]*tmp[i];
	dfs(sum);
	if (delta[sum]&(1<<base)) delta[x]|=(1<<base);
}		

int main()
{
	freopen("input.txt","r",stdin);
	
	for (base=2;base<=10;base++)
	{
		printf("%d\n",base);
		for (int i=1;i<maxn;i++) flag[i]=false;
		for (int i=1;i<maxn;i++)
		if (!flag[i]) dfs(i);
	}
	
	
	int test;
	scanf("%d\n",&test);
	char data[1000];
	
	for (int i=1;i<=test;i++)
	{	
		gets(data);
		int tmp=0;
		for (int j=0;data[j];j++)
		{
			while (data[j]==' ') j++;
			if (!data[j]) break;
			int xxx=0;
			while (data[j]>='0' && data[j]<='9') 
			{
				xxx=xxx*10+data[j]-'0';
				j++;
			}
			tmp|=(1<<xxx);
			if (!data[j]) break;
		}
		for (int j=2;j<maxn;j++)
		if ((delta[j]&tmp)==tmp)
		{
			printf("Case #%d: %d\n",i,j);
			break;
		}
	}
}
