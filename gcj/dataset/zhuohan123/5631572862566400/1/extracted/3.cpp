#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n;
int f[2100],ind[2100];
int lc[2100];
void lccheck()
{
	for(int i=1;i<=n;i++)lc[i]=1;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(ind[i]==0)q.push(i);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		lc[f[now]]=max(lc[f[now]],lc[now]+1);
		ind[f[now]]--;
		if(ind[f[now]]==0)q.push(f[now]);
	}
}
bool vis[2100];
int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		memset(vis,0,sizeof vis);
		memset(ind,0,sizeof ind);
		cout<<"Case #"<<ti<<": ";
		cin>>n;
		for(int i=1;i<=n;i++)cin>>f[i],ind[f[i]]++;
		lccheck();
		int ans1=0;
		for(int i=1;i<=n;i++)
			if(f[f[i]]==i)ans1+=lc[i];
		int ans2=0;
		for(int i=1;i<=n;i++)
			if(ind[i]>0)
			{
				vis[i]=true;
				int j=f[i],tans=1;
				while(!vis[j])
				{
					vis[j]=true;
					tans++;
					j=f[j];
				}
				ans2=max(tans,ans2);
			}
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}
