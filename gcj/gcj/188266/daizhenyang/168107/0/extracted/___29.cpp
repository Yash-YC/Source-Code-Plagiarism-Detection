#include<stdio.h>
#include<stdlib.h>
#include<set>
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
		
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\aaa.txt","w",stdout);
	int i,j,k,cas,sum=0,ca=0;
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
}
