#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int mark[1010];
bool P[1010];
int son[1010];
int ans;
vector<int>fa[1010];
void dfs(int u)
{
	if(mark[son[u]]==0){
		mark[son[u]]=mark[u]+1;
		dfs(son[u]);
	}
	else{
		ans=max(ans,mark[u]-mark[son[u]]+1);
	}
}
int S[1010];
void ufs(int u)
{
	S[u]=1;
	mark[u]=1;
	for(int i=0;i<fa[u].size();i++)
	{
		int v=fa[u][i];
		if(mark[v]==1)continue;
		ufs(v);
		S[u]=max(S[u],S[v]+1);
	}
}
int main()
{
	freopen("C-large (1).in","r",stdin);
	freopen("C-large (1).out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		cas++;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&son[i]);
			fa[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			fa[son[i]].push_back(i);
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(mark,0,sizeof(mark));
			mark[i]=1;
			dfs(i);
		}
		memset(mark,0,sizeof(mark));
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(mark[i]==1)continue;
			if(son[son[i]]==i)
			{
				mark[i]=mark[son[i]]=1;
				ufs(i);
				ufs(son[i]);
				cnt+=S[i];
				cnt+=S[son[i]];
			}
		}
	
		if(cnt>ans)ans=cnt;
		printf("Case #%d: %d\n",cas,ans);
	}
}