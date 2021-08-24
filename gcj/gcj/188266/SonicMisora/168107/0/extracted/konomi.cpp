#include<iostream>
using namespace std;

int num;
int a[11];
unsigned char b[11][1000000];
int CASE;

inline int sqr(int x)
{
	return x*x;
}

bool dfs(int z,int x)
{
	if (b[z][x]==2)
		return false;
	else if (b[z][x]==1)
		return true;
	else if (b[z][x]==3)
	{
		b[z][x]=2;
		return false;
	}
	b[z][x]=3;
	int t=x,ans=0;
	while (t)
	{
		ans+=sqr(t%a[z]);
		t/=a[z];
	}
	if (dfs(z,ans))
	{
		b[z][x]=1;
		return true;
	}
	else
	{
		b[z][x]=2;
		return false;
	}
}

void work()
{
	memset(b,0,sizeof(b));
	for (int i=1;i<=num;i++)
		b[i][1]=1;
	for (int i=2;i<=1000000;i++)
	{
		bool flag=true;
		for (int j=1;j<=num;j++)
			if (!dfs(j,i))
			{
				flag=false;
				break;
			}
		if (flag)
		{
			printf("Case #%d: %d\n",CASE,i);
			break;
		}
	}
}

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	scanf("%d\n",&T);
	for (CASE=1;CASE<=T;CASE++)
	{
		char ch;
		num=1; memset(a,0,sizeof(a));
		while (true)
		{
			scanf("%c",&ch);
			if (ch=='\n')
				break;
			else if (ch==' ')
				num++;
			else
				a[num]=a[num]*10+ch-'0';
		}
		work();
	}
}
