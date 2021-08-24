#include<stdio.h>
#include<string.h>
int i,j,tn,ti,a[50],yet[50000000],t[5000];
char str[50];
int calc(int x,int y)
{
	int s,temp;
	if (x==1)
	{
		yet[x]=0;
		return 1;
	}
	if (yet[x])
	{
		yet[x]=0;
		return 0;
	}
	yet[x]=1;
	temp=x;
	t[0]=0;
	while (x)
	{
		t[++t[0]]=x%y;
		x/=y;
	}
	while (t[0]>=1)
	{
		x+=t[t[0]]*t[t[0]];
		t[0]--;
	}
	s=calc(x,y);
	yet[temp]=0;
	return s;
}
int main()
{
	scanf("%d\n",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		printf("Case #%d: ",ti);
		gets(str);
		memset(a,0,sizeof(a));
		for (i=0;str[i];)
		{
			a[0]++;
			for (j=i;str[j]>='0'&&str[j]<='9';j++)
				a[a[0]]=a[a[0]]*10+str[j]-'0';
			if (!str[j]) break;
			i=j+1;
		}
		for (i=2;;i++)
		{
			for (j=1;j<=a[0];j++)
				if (!calc(i,a[j])) break;
			if (j==a[0]+1) break;
		}
		printf("%d\n",i);
	}
	return 0;
}
