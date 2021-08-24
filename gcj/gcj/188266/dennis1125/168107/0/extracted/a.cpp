#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define maxn 111

int a[11];
int n;
int an;

int check(int x,int k)
{
	int y=x;
	int t,i;
	int sum;
	int bt[maxn];
	int by[maxn];
	int bn;
	int flag;
	
	bn=0;
	do
	{
		t=y;
		sum=0;
		while(t>0)
		{
			sum+=(t%k)*(t%k);
			t/=k;
		}
		t=y;
		y=sum;
		flag=1;
		for(i=1;i<=bn;i++)
		{
			if (t==bt[i]&&y==by[i])	
			{
				flag=0;
				break;
			}
		}
		if (flag==0)
			break;
		bn++;
		bt[bn]=t;
		by[bn]=y;
		
		//system("pause");
	}
	while(t!=y);
	//printf("t y:%d %d\n",t,y);
	
	if (t==1)
		return 1;
	else
		return 0;
}

int solve()
{
	int i,j;
	int flag;

	
	/*
	printf("an %d\n",an);
	for(i=1;i<=an;i++)
		printf("%d\n",a[i]);
	*/
	
	i=1;

	do
	{
		flag=1;
		i++;
		for(j=1;j<=an;j++)
		{
			flag=flag&&check(i,a[j]);
			if (!flag)
				break;
		}
	}
	while(flag==0);
	
	printf("%d\n",i);
}


int main()
{
	freopen("a.out","w",stdout);
	freopen("a.in","r",stdin);
	
	int kn,kc;
	char str[maxn];
	int i,j;
	
	scanf("%d",&kc);
	while(getchar()!='\n');
	for(kn=1;kn<=kc;kn++)
	{
		gets(str);
		//printf("str %s\n",str);
		an=0;
		i=0;
		j=0;
		for(i=0;i<strlen(str);i++)
		{
			if (str[i]!=' ')
				j=j*10+str[i]-'0';
			else
			{
				an++;
				a[an]=j;
				j=0;
			}
		}
		if (j!=0)
		{
			an++;
			a[an]=j;
			j=0;
		}
		printf("Case #%d: ",kn);
		solve();
	}
	
	return 0;
}
 