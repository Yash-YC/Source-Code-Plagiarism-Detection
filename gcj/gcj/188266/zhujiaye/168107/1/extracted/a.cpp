#include<cstdio>
#include<cstring>
#define sqr(x) (x)*(x)
#define maxn 13000000
int b[12],test;
char s[100];
int can[12][maxn],list[maxn];
inline void check(int x,int b)
{
	if (can[b][x]>=1) return;
	int len=1;
	list[1]=x;can[b][x]=0;
	while (x!=1)
	{
		int tmp=0;
		for (;x!=0;tmp+=sqr(x%b),x/=b);
		x=tmp;
		if (can[b][x]>=1) 
		{
			for (int i=1;i<=len;can[b][list[i++]]=can[b][x]);
			return;
		}
		else if (can[b][x]==0) 
		{
			can[b][x]=2;
			for (int i=1;i<=len;can[b][list[i++]]=can[b][x]);
			return;
		}
		else 
		{
			can[b][x]=0;
			list[++len]=x;
		}
	}
}
inline void Prepare()
{
	memset(can,-1,sizeof(can));
	for (int j=2;j<=10;++j)
	{
		can[j][1]=1;
		for (int i=2;i<=maxn;++i)
			check(i,j);
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&test);
	Prepare();
	int cnt=1;
	for (;test;--test,++cnt)
	{
		printf("Case #%d: ",cnt);
		int len=0;
		gets(s);
		int n=strlen(s);
		for (int i=0;i<n;++i)
		if (s[i]>='0' && s[i]<='9')
		{
			if (i+1<n && s[i+1]>='0' && s[i+1]<='9')
			{
				b[++len]=10;++i;
			}
			else b[++len]=s[i]-'0';
		}
		for (int i=2;;++i)
		{
			bool boo=true;
			for (int j=1;j<=len && boo;++j) if (can[b[j]][i]==2) boo=false;
			if (boo) 
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
