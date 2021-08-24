#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

int a[11][6000000];
int i,j,T,I;
char st[3000];
int req[30];
void dfs(int base,int nu)
{
	//printf("%d %d:\n",base,nu);
	a[base][nu]=-2;
	int t=nu,tmp=0;
	while (t!=0)
	{
		int tt=t%base;
		tmp+=tt*tt;
		t/=base;
	}
	//printf("%d\n",tmp);
	if (tmp==0) a[base][nu]=0;
	else if (tmp==1) a[base][nu]=1;
	else 
	{
		if (a[base][tmp]==-1)
			dfs(base,tmp);
		a[base][nu]=a[base][tmp];
	}
}
main()
{
	memset(a,-1,sizeof a);
	for (i=2;i<=10;++i)
	{
		for (j=2;j<=500000;++j)
		{
			if (a[i][j]==-1)
				dfs(i,j);
			//printf("%d %d %d\n",i,j,a[i][j]);
		}
	}
	scanf("%d\n",&T);
	for (I=1;I<=T;++I)
	{
		printf("Case #%d: ",I);
		gets(st);
		istringstream in((string)st);
		int num=0;
		while (in>>req[num++]);
		--num;
		for (i=2;i<500000;++i)
		{
			bool f=1;
			for (j=0;j<num;++j)
				if (a[req[j]][i]!=1) 
				{
					f=0;
					break;
				}
			if (f) 
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
		
			
