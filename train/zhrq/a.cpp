#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<10;
char a[maxn], ans[maxn<<1];
int l;
void run()
{
	scanf(" %s",a);
	memset(ans,0,sizeof ans);
	l=1<<10;
	int r=l+1;
	ans[l]=a[0];
	for(int i=1;i<strlen(a);i++)
		if(a[i]>=ans[l]) ans[--l]=a[i];
		else ans[r++]=a[i];
}
int main()
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T, cas=0;
	scanf("%d",&T);
	while(T--)
	{
		run();
		printf("Case #%d: %s\n",++cas,ans+l);
	}
	return 0;
}

