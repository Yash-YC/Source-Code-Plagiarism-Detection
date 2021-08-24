#include <stdio.h>
#include <stdlib.h>
#define maxn 50
#define maxv 1000000
#define eps 1e-12

double a[maxv];
int k,c;

double cc(int x,int y)
{
	double t;
	int i;
	
	t=1;
	for(i=x;i>x-y;i--)
	{
		t*=i;
		t/=(x-i+1);
		//printf("t i %.9lf %d\n",t,i);
	}
	
	return t;
}

double calc(int k,int c)
{
	double t;
	int i;

	/*
	t=1;
	t*=cc(k,c);
	
	printf("k c %d %d\n",k,c);
	printf("cc %.9lf\n",t);
	for(i=1;i<=k;i++)
	{
		t/=c;
	}
	for(i=1;i<=c;i++)
	{
		//t/=c;
		t*=i;
	}	
	printf("calc %.9lf\n",t);
	*/
	
	//t=1.0/c;

	t=1;	
	for(i=1;i<k;i++)
	{
		t/=c-1;
	}
	t/=c;
		
	return t;
}

int solve()
{
	double add;
	double ans;
	double t;
	int i,j;
	int start;
	int kk;
	int flag;
	
	kk=k;
	k=1;
	
	if (c%k==0)
		start=c/k;
	else
		start=c/k+1;
		
	ans=0;
	i=start;
	flag=1;
	for(j=0;j<start;j++)
		a[j]=0;
	do
	{
		t=calc(1,c);
		
		//printf("i t:%d %.9lf\n",i,t);
		add=1;
		//a[i]=t;
		for(j=start;j<i;j++)
		{
			add-=a[j];
		}
		add*=t;
		a[i]=add;
		//ans+=i*add;
		if (i%kk==0)
		{
			t=0;
			/*if (flag==1)
			{
				for(j=1;j<=i;j++)
				{
					t+=a[j];
				}
				flag=0;
			}
			else*/
				for(j=i-kk+1;j<=i;j++)
				{
					t+=a[j];
				}
			//printf("t %.9lf\n",t);
			if (i>=c)
			{
				//ans+=t*i/kk;
			}
		}
		ans+=add*i/kk;
		i++;
		
		//printf("add %.9lf\n",add);
		//printf("ans %.9lf\n",ans);
		
		//system("pause");
		
		//t=calc(k,c);
	}
	while(add>eps);
	
	printf("%.7lf\n",ans);
	
	return 0;
}

int main()
{
	int kc,kn;
	
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	scanf("%d",&kc);
	for(kn=1;kn<=kc;kn++)
	{
		scanf("%d %d",&c,&k);
		printf("Case #%d: ",kn);
		solve();
	}	
	
	return 0;
}