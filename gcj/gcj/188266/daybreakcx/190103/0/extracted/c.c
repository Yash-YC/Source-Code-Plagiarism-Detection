#include<stdio.h>
int a[500000],le,mul,n,ti,tn,c,i;
int cn(int s)
{
	long long i,ret=0;
	for (i=0;i<n;i++)
		if (s&(1<<i)) ret++;
	return ret;
}
double calc(int s,int dep)
{
	int i;
	double temp=0.0;
	if (s==(1<<n)-1) return 0.0;
	if (dep>=le) return 0.0;
	for (i=1;i<=a[0];i++)
		temp+=calc(s|a[i],dep+1);
	return 1.0+temp/a[0];
}
int main()
{
	scanf("%d",&tn);
	for (ti=1;ti<=tn;ti++)
	{
		scanf("%d%d",&n,&c);
		a[0]=0;
		for (i=0;i<(1<<n);i++)
			if (cn(i)==c) a[++a[0]]=i;
		if (a[0]==1) le=5;
		else for (le=1,mul=a[0];mul<1000000;le++,mul*=a[0]);
		printf("Case #%d: %.7lf\n",ti,calc(0,0));
	}
}
