#include <stdio.h>
#include <string.h>
#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		char str[1001];
		char ans[3001];
		scanf("%s",str);
		int len=strlen(str);
		int t=1499;
		int w=1501;
		ans[1500]=str[0];
		for(int i=1;i<len;i++)
		{
			if(str[i]>=ans[t+1])ans[t--]=str[i];
			else ans[w++]=str[i];
		}
		printf("Case #%d: ",cas);
		for(int i=t+1;i<w;i++)printf("%c",ans[i]);
		printf("\n");
	}
}