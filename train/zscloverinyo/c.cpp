#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int T,n,ans,a[1005];
int f[1005];
int nxt;
int sum,dq;
vector<int> v[1005];

void dfs(int x,int y)
{
	dq=max(dq,y);
	for (int i=0;i<v[x].size();++i)
	{
		dfs(v[x][i],y+1);
	}
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	for (int z=1;z<=T;++z)
	{
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
		{
			memset(f,0,sizeof(f));
			dq=i;f[dq]=1;
			while (true)
			{
				nxt=a[dq];
				if (f[nxt]==0)
				{
					f[nxt]=f[dq]+1;
					dq=nxt;
				}
				else
				{
					ans=max(ans,f[dq]-f[nxt]+1);
					break;
				}
			}
		}
		for (int i=1;i<=n;++i) v[i].clear();
		sum=0;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
			{
				if (a[j]!=i) continue;
				if (a[i]==j) continue;
				v[i].push_back(j);
			}
		}
		for (int i=1;i<=n;++i)
		{
			if (a[a[i]]==i)
			{
				dq=0;
				dfs(i,1);
				sum+=dq;
			}
		}
		ans=max(ans,sum);
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
