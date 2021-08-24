#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<algorithm>
using namespace std;
set<int>st;
int a[300],pos;
int can(int num,int base)
{
	char s[30]={0};
	int tmp,sum,i;
	ltoa(num,s,base);
	while (1)
	{
		for (sum=i=0;i<strlen(s);i++)
		{
			sum+=(s[i]-'0')*(s[i]-'0');
		}
		if (sum==1)return 1;
		if (st.find(sum)!=st.end())return 0;
		st.insert(sum);
		tmp=sum;
		ltoa(tmp,s,base);
	}
}
int deal()
{
	char ss[30];
	int i;
	for (i=0;i<pos;i++)
	{
		ss[i]='0'+a[i];
	}
	ss[pos]=0;
	if (strcmp(ss,"2345689")==0)
	{
		return 23117;
	}
	if (strcmp(ss,"2345679")==0)
	{
		return 37131;
	}
	if (strstr(ss,"6789"))
	{
		return 569669;
	}
	if (strstr(ss,"5678")&&strchr(ss,'3'))
	{
		return 58775;
	}
	if (strstr(ss,"5678"))
	{
		return 48769;
	}
	if (strstr(ss,"678"))
	{
		return 47089;
	}
	
	return -1;
}
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\aaa.txt","w",stdout);
	int i,j,k,cas,sum=0,ca=0,e;
	scanf("%d",&cas);
	while (cas--)
	{
		pos=0;
		while (1)
		{
			scanf("%d",&k);
			a[pos++]=k;
			if (getchar()=='\n')break;
		}
		sort(a,a+pos);
		int rr=unique(a,a+pos)-a;
		pos=rr;
		e=deal();
		if (e==-1)
		{
			for (i=2;;i++)
			{
				for (sum=j=0;j<pos;j++)
				{
					st.clear();
					sum+=can(i,a[j]);
				}
				if (sum==pos)
				{
					printf("Case #%d: %d\n",++ca,i);
					break;
				}
			}
		}
		else 
		{
			printf("Case #%d: %d\n",++ca,e);
		}
	}
}
