#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <stack>
#include <iostream>
#include <utility>


#define TEST
#define MAX 1010
#define QMAX 2000000
#define INF 0x7f7f7f7f
#define EPS 1e-10
#define S2(x) ((x)*(x))
#define IS1(x,k) ((x&(1<<k))!=0)
#define IS0(x,k) (!IS1(x,k))
#define SET1(x,k) (x|(1<<k))
#define SET0(x,k) (x(1<<k))

int b[200];
char buf1[20];
int p10[100];

int r[10][1000];

int getNew()
{
	int p=0;
	int ans=0;
	while (buf1[p]!=0)
	{
		int x=buf1[p]-'0';
		ans+=x*x;
		p++;
	}
	return ans;
}

int rev(int num,int base)
{
	int ans=0;
	int p=1;
	while (num!=0)
	{
		int x=num%base;
		ans+=x*p10[p];
		num=num/base;
		p++;
	}
	return ans;
}

bool isHapp(int num,int base)
{
	char buf[20];
	char * stop;
	while (1)
	{
		
		int x=rev(num,base);
		if (x==1) return true;
		if (base==2)
		{
			return true;
		}
		if (base==3)
		{
			if (x==2) return false;
			if (x==12) return false;
			if (x==22) return false;
		}
		if (base==4)
		{
			return true;
		}
		if (base==5)
		{
			if (x==4) return false;
			if (x==23) return false;
			if (x==33) return false;
		}
		if (base==6)
		{
			if (x==32) return false;
		}
		if (base==7)
		{
			if (x==2) return false;
			if (x==34) return false;
			if (x==13) return false;
			if (x==23) return false;
			if (x==63) return false;
			if (x==44) return false;
		}
		if (base==8)
		{
			if (x==4) return false;
			if (x==5) return false;
			if (x==32) return false;
			if (x==24) return false;
			if (x==64) return false;
		}
		if (base==9)
		{
			if (x==55) return false;
			if (x==58) return false;
			if (x==45) return false;
			if (x==75) return false;
		}
		if (base==10)
		{
			if (x==4) return false;
			
		}
		sprintf(buf1,"%d",x);
		num=getNew();
	}

}


int main()
{
	freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj2009\\A-small-attempt1.in\\A-small-attempt1.in","r",stdin);
	freopen("C:\\Documents and Settings\\Administrator\\×ÀÃæ\\gcj2009\\A-small-attempt1.in\\out.txt","w",stdout);
	int i,j,t,cn=0;
	p10[1]=1;
	for (i=2;i<=10;i++) p10[i]=p10[i-1]*10;
	scanf("%d",&t);
	
	getchar();
	
	while (t--)
	{
		cn++;
		int num=0;
		char ch;
		do
		{
			b[++num]=getchar()-'0';
			ch=getchar();
			if (ch=='0') 
			{
				b[num]=b[num]*10+(ch-'0');
				ch=getchar();
			}
		}while (ch!='\n');
		int ans;
		for (i=2;;i++)
		{
			bool f=true;
			for (j=1;j<=num;j++)
			{
				if (isHapp(i,b[j])==false)
				{
					f=false;
					break;
				}
			}
			if (f==true)
			{
				ans=i;
				break;
			}
		}
		printf("Case #%d: %d\n",cn,ans);
	}
	return 0;
}
