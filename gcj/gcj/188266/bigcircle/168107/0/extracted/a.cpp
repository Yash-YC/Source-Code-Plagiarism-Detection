#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int a[10];
map<int,int> my;
char s[1000],f[5];
int change(int x,int y)
{
	int temp=0;
	while(x>0)
	{
		temp=temp*10+x%y;
		x/=y;
	}
	return temp;
}

bool judge(int x,int y)
{
	int sum=0,i=0,temp1=x;
	if(x==1)
		return true;
	my.clear();
	my[x]++;
	while(true)
	{
		sum=0;
		while(x>0)
		{
			temp1=x%10;
			sum+=temp1*temp1;
			x/=10;
		}
		if(sum==1)
			return true;
		else
		{
			x=change(sum,y);
			my[x]++;
			if(my[x]>1)
				return false;
		}
	}
	return false;
}
int main()
{
	freopen("outa1.txt","w",stdout);
	freopen("ina1.in","r",stdin);
    int i,j,t,test=0;
	scanf("%d",&t);
	getchar(f);
	while(t>0)
	{
		t--;
		test++;
		gets(s);
		int len=strlen(s),sum=0,count=0,temp=0,temp1=0;
		for(i=0;i<=len;i++)
		{
			if(s[i]==' '||i==len)
			{
				if(sum>0)
					a[count++]=sum;
				sum=0;
			}
			else if(s[i]<='9'&&s[i]>='0')
				sum=sum*10+(s[i]-'0');
		}
		for(i=2;i<=100000;i++)
		{
			bool flag=false;
			for(j=0;j<count;j++)
			{
				temp=i;
				temp=change(temp,a[j]);
				if(judge(temp,a[j]))
					continue;
				else
				{
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				printf("Case #%d: %d\n",test,i);
				break;
			}
		}
	}
	return 0;
}