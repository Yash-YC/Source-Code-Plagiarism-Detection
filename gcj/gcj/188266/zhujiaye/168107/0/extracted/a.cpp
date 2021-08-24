#include<cstdio>
#include<cstring>
#define sqr(x) (x)*(x)
#define maxn 100000
int b[12],test;
char s[100];
bool can[maxn][12];
inline bool ok(int x,int b)
{
//	memset(hash,false,sizeof(hash));
//	hash[x]=true;
	int cnt=0;
	while (x!=1 && cnt<=100)
	{
		int tmp=0;
		for (;x!=0;tmp+=sqr(x%b),x/=b);
		x=tmp;++cnt;
	//	if (hash[x]) break;
	//	hash[x]=true;
	}
	return (x==1);
}
inline void Prepare()
{
	for (int i=2;i<=maxn;++i)
	for (int j=2;j<=10;++j)
		can[i][j]=ok(i,j);
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
		for (int i=1;;++i)
		{
			bool boo=true;
			for (int j=1;j<=len && boo;++j) if (!can[i][b[j]]) boo=false;
			if (boo) 
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
