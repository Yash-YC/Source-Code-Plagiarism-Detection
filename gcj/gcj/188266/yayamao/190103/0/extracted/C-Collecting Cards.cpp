#include<cstdio>
#include<iostream>

using namespace std;

double Co[50][50];

int C,N;

double Ans;

void DFS(int Now,int Time,double Pro)
{
	if(Time>25) return;
	if(Now>=C)
	{
		Ans+=Time*Pro;
		return;
	}
	double Ans=0.0;
	for(int i=0;i<=N;i++) DFS(Now+i,Time+1,Pro*Co[C-Now][i]*Co[Now][N-i]/Co[C][N]);
}

int main()
{
	freopen("C-Small.in","r",stdin);
	freopen("C-Small.out","w",stdout);
	int T;
	scanf("%d",&T);
	memset(Co,0,sizeof(Co));
	for(int i=1;i<50;i++) for(int j=0;j<=i;j++)
	{
		if(i==j||j==0) Co[i][j]=1.0;
		else Co[i][j]=Co[i-1][j]+Co[i-1][j-1];
		//printf("%lf ",Co[i][j]);
		//if(j==i) putchar('\n');
	}
	for(int Case=1;Case<=T;Case++)
	{
		scanf("%d %d",&C,&N);
		Ans=0.0;
		DFS(N,1,1.0);
		printf("Case #%d: %lf\n",Case,Ans);
	}
	return 0;
}
