#include<cstdio>
#include<cstring>
bool b[2550];
int n;
int main()
{
	int i,T,_T,x;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (_T=1;_T<=T;_T++)
	{
		printf("Case #%d:",_T);
		scanf("%d",&n);
		memset(b,false,sizeof(b));
		for (i=1;i<=n*(2*n-1);i++)
		{
			scanf("%d",&x);
			b[x]=!b[x];
		}
		for (i=1;i<=2500;i++)
			if (b[i]) printf(" %d",i);
		printf("\n");
	}
	return 0;
}
