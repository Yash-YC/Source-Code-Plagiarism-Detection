#include <stdio.h>
#include <string.h>
int hei[2555];
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		int n;
		scanf("%d",&n);
		memset(hei,0,sizeof(hei));
		for(int i=1;i<2*n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int d;
				scanf("%d",&d);
				hei[d]++;
			}
		}
		int ans[111];
		int tot=0;
		for(int i=0;i<=2500;i++)
		{
			if(hei[i]%2==1)ans[tot++]=i;
		}
		printf("Case #%d: ",cas);
		for(int i=0;i<tot;i++)
		{
			printf("%d",ans[i]);
			if(i==tot-1)printf("\n");
			else printf(" ");
		}
	}
}