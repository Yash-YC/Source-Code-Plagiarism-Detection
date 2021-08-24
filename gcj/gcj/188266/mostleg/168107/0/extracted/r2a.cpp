#include <cstdio>
#include <cstring>

const int TOP=1000000;

int L,D,N,T;
bool w[11][TOP];
int base[11];
bool dead[11][10000];

/*
void ready()
{
	int i,j,k,ok;
	int a,b;
	int num[100];
	
	memset(w,0,sizeof(w));
	
	ok=0;
	for (i=2;ok!=1;i++)
	{
		if (i%100==0)
			printf("%d\n",i);
		ok=1;
		for (j=2;j<=10;j++)
		{
			a=i;
			
			//printf("j=%d\n",j);
			memset(dead,0,sizeof(dead));
			while (a>1)
			{
				b=0;
				while (a)
				{
					b++;
					num[b]=a%j;
					a/=j;
				}
			
				for (k=1;k<=b;k++)
				{
			//		printf("%d ",num[k]);
					a+=num[k]*num[k];
				}
				//printf("=%d\n",a);
				if (dead[j][a]==1)
				{
		
					break;
				}
				else
					dead[j][a]=1;
			}
			if (a==1)
				w[j][i]=1;
			else
			{
				//printf("%d:fail at %d\n",i,j);
				ok=0;
					break;
			}
		}
	}
	
	i--;
	printf("%d\n",i);
	for (i=0;i<TOP;i++)
	{
		for (j=2;j<=10;j++)
		{
			
		}
	}*/
//}

void init()
{
	int i,j,len,k;
	char rs[100];
	
	
	memset(base,0,sizeof(base));
	gets(rs);
	len=strlen(rs);
	i=j=0;
	while (i<len)
	{
		sscanf(rs+j,"%d",&k);
		base[k]=1;
		while (rs[j]!=' ')
			j++;
		j++;
		i=j;
	}
}

void work()
{
	int i,j,k,ok;
	int a,b;
	int num[100];
	
	memset(w,0,sizeof(w));
	
	ok=0;
	for (i=2;ok!=1;i++)
	{
		ok=1;
		for (j=2;j<=10;j++)
		{
			if (!base[j])
				continue;
			a=i;
			
			//printf("j=%d\n",j);
			memset(dead,0,sizeof(dead));
			while (a>1)
			{
				b=0;
				while (a)
				{
					b++;
					num[b]=a%j;
					a/=j;
				}
			
				for (k=1;k<=b;k++)
				{
			//		printf("%d ",num[k]);
					a+=num[k]*num[k];
				}
				//printf("=%d\n",a);
			//	if (a>=i)
				{
					if (dead[j][a]==1)
					{
						break;
					}
					else
						dead[j][a]=1;
				}
			
			}
			if (a==1)
				w[j][i]=1;
			else
			{
				//printf("%d:fail at %d\n",i,j);
				ok=0;
					break;
			}
		}
	}
	
	printf("%d\n",i-1);
}

int main()
{
	int i;
	char s[100];
	
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	//ready();
	scanf("%d",&T);
	gets(s);
	for (i=1;i<=T;i++)
	{
		
		init();
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
