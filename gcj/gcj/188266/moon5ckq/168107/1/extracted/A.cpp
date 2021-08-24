#include <cstdio>
#include <sstream>
using namespace std;
#define oo 12000005
#define bb 11
char f[bb][oo];
int Test,Case,N,a[bb];

inline int sqr(int x)
{
	return x*x;
}

int DFS(int u,int i)
{
	if (f[u][i]) return f[u][i];
	f[u][i]=2;
	int cnt=0,v=i;
	while (true)
	{
		int val=0;
		for (int x=v;x;x/=u)
			val+=sqr(x%u);
		v=val;
		if (val>12000000) v=val;
		else break;
		if ((++cnt)>100)
		{
			f[u][i]=2;
			return 2;
		}
	}
	
	return f[u][i]=DFS(u,v);
}

inline void WorkBase(int u)
{
	f[u][1]=1;
	
	for (int i=2;i<=12000000;++i)
		DFS(u,i);
}

inline void Prepare()
{
	for (int i=2;i<=10;++i)
		WorkBase(i);
}

char s[100];
inline void Readin()
{
	gets(s);
	stringstream sin(s);
	N=1;
	while (sin >> a[N])
		++N;
	--N;
}

inline void Solve()
{
	for (int i=2;i<=12000000;++i)
	{
		bool flag=true;
		for (int j=1;j<=N;++j)
			flag&=f[a[j]][i]==1;
		if (flag)
		{
			printf("%d\n",i);
			return;
		}
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	
	Prepare();
	for (scanf("%d",&Test),gets(s);Test--;)
	{
		printf("Case #%d: ",++Case);
		Readin();
		Solve();
	}
	
	return 0;
}
