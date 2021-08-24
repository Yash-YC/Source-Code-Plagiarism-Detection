#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
#define maxans 1000

bool vis[maxans],flag[11][maxans]={0};
int d[20],num;
string in;

int findnext(int p,int n)
{
	int re=0;
	while(n)
	{
		re+=(n%p)*(n%p);
		n/=p;
	}
	return re;
}

bool test(int p,int n)
{
	memset(vis,0,sizeof(vis));
	while(1)
	{
		n=findnext(p,n);
		if(n==1||flag[p][n]) return 1;
		if(vis[n]) return 0;
		vis[n]=1;
	}
}

void init()
{
	for(int i=2;i<11;++i)
	{
		for(int j=2;j<maxans;++j)
			if(test(i,j))
			{
				flag[i][j]=1;
				int t=j;
			}
		flag[i][1]=1;
	}
	//int n1,n2;
	//while(scanf("%d%d",&n1,&n2)) printf("%d\n",flag[n1][n2]);
}

int solve()
{
	getline(cin,in);
	stringstream sin(in);
	for(num=0;(sin>>d[num]);++num);
	for(int i=2;i<100000000;++i)
	{
		int j;
		for(j=0;j<num;++j)
			if(!flag[d[j]][findnext(d[j],i)])
				break;
		if(j==num)
			return i;
	}
	return -1;
}

int main()
{
	init();
	int t;
	scanf("%d",&t);
	getline(cin,in);
	for(int i=0;i<t;++i)
		printf("Case #%d: %d\n",i+1,solve());
	return 0;
}

