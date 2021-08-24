#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

int a[15000000];
int ans[15000000];
int an[600];
int i,j,T,I;
char st[3000];
int req[30];
void dfs(int base,int nu)
{
	//printf("%d %d:\n",base,nu);
	a[nu]=-2;
	int t=nu,tmp=0;
	while (t!=0)
	{
		int tt=t%base;
		tmp+=tt*tt;
		t/=base;
	}
	//printf("%d\n",tmp);
	if (tmp==0) a[nu]=0;
	else if (tmp==1) a[nu]=1;
	else 
	{
		if (a[tmp]==-1)
			dfs(base,tmp);
		a[nu]=a[tmp];
	}
}
main()
{
	for (i=2;i<=10;++i)
	{
		memset(a,-1,sizeof a);
		for (j=2;j<=12000000;++j)
		{
			//if (j%100000==0) printf("%d\n",j);
			if (a[j]==-1)
				dfs(i,j);
			if (a[j]==1) ans[j]+=(1<<(i-2));
			//if (i==10 && a[i][j]==1) printf("%d\n",j);
			//printf("%d %d %d\n",i,j,a[i][j]);
		}
	}
	//printf("%d %d\n",ans[3],(ans[3]&3));
	for (i=1;i<=511;++i)
		for (j=2;j<12000000;++j)
		if ((ans[j]&i)==i) {
			an[i]=j;
			break;
		}
	/*for (i=1;i<=511;++i)
		printf("%d\n",an[i]);*/
	scanf("%d\n",&T);
	for (I=1;I<=T;++I)
	{
		printf("Case #%d: ",I);
		gets(st);
		istringstream in((string)st);
		int num=0;
		while (in>>req[num++]);
		--num;
		int tt=0;
		for (i=0;i<num;++i)
			tt+=(1<<(req[i]-2));
		printf("%d\n",an[tt]);
	}
	return 0;
}
		
			
