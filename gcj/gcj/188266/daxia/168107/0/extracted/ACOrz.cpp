#include<stdio.h>
int a[111],b[111],n,top;
int f(int t,int base)
{
	top=0;
	while(t)
	{
		b[top++]=t%base;
		t/=base;
	}
	int i,ret=0;
	for(i=0;i<top;i++)
		ret+=b[i]*b[i];
	return ret;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int i,j,k,p,t,tt=1,times;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		n=0;
		while(scanf("%d",&a[n++]))
		{
			c=getchar();
			if(c=='\n')break;
		}
		for(i=2;;i++)
		{
			for(j=0;j<n;j++)
			{
				k=i;
				times=1000;
				while(times--)
				{
					p=f(k,a[j]);
					if(p==1||p==k)break;
					k=p;
				}
				if(p!=1)break;
			}
			if(j==n)break;
		}
		printf("Case #%d: %d\n",tt++,i);
	}
	return 0;
}
