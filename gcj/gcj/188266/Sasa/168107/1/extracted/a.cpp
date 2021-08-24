#include<iostream>
using namespace std;
const int M=2000;
int v[11][M];
int w[20],wt=0;
void dfs(int val,int lev)
{
	if(val>=M)
		cout<<"--------------error-------------------"<<endl;
	if(v[lev][val]!=0)
		return;
	v[lev][val]=1;
	for(int i=2;i<M;i++)
	{
		int ti=i;
		int cnt=0;
	//	cout<<i<<" "<<lev<<":";
		while(ti)
		{
			cnt+=(ti%lev)*(ti%lev);
			ti/=lev;
		}
//		cout<<cnt<<endl;
		if(cnt==val&&v[lev][i]==0)
		{
			dfs(i,lev);
		}
	}
}
int fun(int now,int lev)
{
	int i;
	if(now<M)
	{
		return v[lev][now];
	}
	else
	{
		int ti=now;
		int cnt=0;
		while(ti)
		{
			cnt+=(ti%lev)*(ti%lev);
			ti/=lev;
		}
		if(fun(cnt,lev))
			return 1;
		else
			return 0;
	}
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	int i,j,k;
	int n,ca;
	scanf("%d",&ca);
	char ch[100];
	int tca=0;
	for(k=2;k<=10;k++)
	{
		dfs(1,k);
	}
	getchar();
	while(tca<ca)
	{
		wt=0;
		tca++;
		gets(ch);
		char* tch=0;
		tch=strtok(ch," ");
		while(tch)
		{
			w[wt++]=atoi(tch);
			tch=strtok(0," ");
		}

		int now=2;
		while(true)
		{
//			cout<<"now"<<now<<endl;
			for(i=0;i<wt;i++)
				if(fun(now,w[i])==0)
					break;
			if(i==wt)
				break;
			else
				now++;
		}
		printf("Case #%d: %d\n",tca,now);
	}
}
