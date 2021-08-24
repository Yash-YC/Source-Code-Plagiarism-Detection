#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

#define maxans 100000

int d[10],num;

bool vis[maxans];

int findnext(int n,int p)
{
	int re=0;
	while(n)
	{
		re+=(n%p)*(n%p);
		n/=p;
	}
	return re;
}

bool test(int n,int p)
{
	memset(vis,0,sizeof(vis));
	//printf("%d\t%d\n",n,p);
	while(1)
	{
	//	printf("%d\n",n);
		vis[n]=1;
		n=findnext(n,p);
		if(n==1) return 1;
		if(vis[n]) return 0;
	}
	return 1;
}

string in;

int solve()
{
	getline(cin,in);
	stringstream sin(in);
	for(num=0;(sin>>d[num]);++num);
	for(int i=2;;++i)
	{
		int j;
		for(j=0;j<num;++j)
			if(!test(i,d[j]))
				break;
		if(j==num)
			return i;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	getline(cin,in);
	for(int i=0;i<t;++i)
		printf("Case #%d: %d\n",i+1,solve());
	return 0;
}

