#include <iostream>
#include <vector>

using namespace std;

#define MAXB 4
#define MAXN 111
#define sqr(x) (x)*(x)

int ans,data[MAXN];
short hash[MAXB][100001];

bool check(int x,int k)
{
	if (x==1)
	{
		hash[k][x]=true;
		return true;
	}
	int nx=0,z;
	z=x;
	while (z!=0)
	{
		nx+=sqr(z%data[k]);
		z=z/data[k];
	}
	if (hash[k][nx]==-1)
	{
		hash[k][x]=0;
		check(nx,k);
	}
	hash[k][x]=hash[k][nx];
	return hash[k][x];
}

void run()
{
	int i,k;
	bool flag;
	for (i=2;;i++)
	{
		flag=true;
		for (k=1;k<=data[0];k++)
			if (!check(i,k))
			{
				flag=false;
				break;
			}
		if (flag)
		{
			ans=i;
			return;
		}
	}
}

void ini()
{
	int i,T,x;
	char c;
	scanf("%d\n",&T);
	for (i=1;i<=T;i++)
	{
		data[0]=ans=0;
		memset(hash,-1,sizeof(hash));
		do
		{
			if (scanf("%d%c",&x,&c)==EOF)
				break;
			data[++data[0]]=x;
			if (c==10 || c==13)
				break;
		}while (true);
		scanf("\n");
		
		run();
		printf("Case #%d: %d\n",i,ans);
	}
	
}

int main()
{
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	ini();
	return 0;
}
