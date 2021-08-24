#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<10;
int n, a[maxn], b[maxn], d[maxn], vis[maxn];
int run()
{
	memset(b,0,sizeof b);
	memset(d,0,sizeof d);
	memset(vis,0,sizeof vis);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		d[a[i]]++;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]) continue;
		memset(vis,0,sizeof vis);
		int cnt=0, x=i;
		while(!vis[x]) cnt++, vis[x]=1, x=a[x];
		if(a[a[x]]==x) b[x]=max(b[x],cnt-2);
	}
	for(int i=1;i<=n;i++) if(a[a[i]]==i) res+=b[i]+1;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		int cnt=0, x=i;
		while(!vis[x]) cnt++, vis[x]=1, x=a[x];
		if(x==i) res=max(res,cnt);
	}
	return res;
}
int main()
{
	//freopen("C-small-attempt1.in","r",stdin);
	//freopen("C-large.in","r",stdin);
	//freopen("out2.txt","w",stdout);
	int T, cas=0;
	scanf("%d",&T);
	while(T--) printf("Case #%d: %d\n",++cas,run());
	return 0;
}

