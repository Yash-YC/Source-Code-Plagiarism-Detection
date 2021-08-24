#include <iostream>

using namespace std;

#define MAXD 1000

const double MIN=0.000000100;
const double stdans[5][10]={{1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
{2.999994,1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
{5.325310,2.499990,1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
{5.837299,3.643783,2.333322,1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,},
{4.107203,4.014126,3.151233,2.249994,1.000000,0.000000,0.000000,0.000000,0.000000,0.000000,}};

int C,N,data[MAXD];
double ans[100][100];

void dfs(int x,double rate,int d)
{
	if (rate<=MIN)
		return;
	if (x+1==(1<<C))
	{
		ans[C][N]+=d*rate;
		return;
	}
	for (int i=1;i<=data[0];i++)
		dfs(x|data[i],rate/data[0],d+1);
	
}

void make(int x,int now,int d)
{
	if (now==N)
	{
		data[++data[0]]=x;
		return;
	}
	if (d>=C)
		return;
	for (int i=d;i<C;i++)
		make(x|(1<<i),now+1,i+1);
}

void run()
{
	make(0,0,0);
	dfs(0,1,0);
}

void ini()
{
	int i,T;
	scanf("%d",&T);
	for (i=1;i<=T;i++)
	{
		scanf("%d%d",&C,&N);
		if (C<=5)
			ans[C][N]=stdans[C-1][N-1];
		if (C==N)
			ans[C][N]=1.00000;
		data[0]=0;
		if (ans[C][N]==0)
			run();
		printf("Case #%d: %lf\n",i,ans[C][N]);
	}
}

int main()
{
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	ini();
	return 0;
}
