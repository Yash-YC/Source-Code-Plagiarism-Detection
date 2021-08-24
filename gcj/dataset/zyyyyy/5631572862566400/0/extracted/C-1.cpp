#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

const int N=101;
const int M=10001*2;
const int INF=1<<29;
struct edge
{
	int go,next,val;
};
edge eg[M];
int last[N],done[N],d[N],pre[N];
int tot;

void add(int x,int y,int z)
{
	eg[++tot].go=y;
	eg[tot].val=z;
	eg[tot].next=last[x];
	last[x]=tot;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int T,t,n,m,i,x,y,z;
	
	scanf("%d",&T);
	for (t=1;t<=T;t++)
	{
		tot=0;
		scanf("%d",&n);
		memset(last,0,sizeof(last));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			add(i,x,1);
			add(x,i,1);
		}
		priority_queue<pii> q;
		bool vis[N];
		memset(vis,0,sizeof(vis));
		int ans=-INF;
		for (int s=1;s<=n;s++)
		if (!vis[s])
		{
		for (i=1;i<=n;i++) d[i]=-INF;
		memset(done,0,sizeof(done));
		d[s]=0;
		q.push(make_pair(s,1));
		while (!q.empty())
		{
			pii u=q.top();
			q.pop();
			int v=u.second;
			if (done[v]) continue;
			done[v]=1;
			for (i=last[v];i;i=eg[i].next)
			{
				int x=eg[i].go;
				if (d[x]>n) continue;
				if (d[x]<d[v]+eg[i].val)
				{
					d[x]=d[v]+eg[i].val;
					q.push(make_pair(d[x],x));
				}
			}
		}
		vis[s]=1;
		for (i=1;i<=n;i++)
			if (d[i]!=-INF) vis[i]=1;
		for (i=1;i<=n;i++)
			ans=max(ans,d[i]);
		}
		ans=min(ans,n);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
