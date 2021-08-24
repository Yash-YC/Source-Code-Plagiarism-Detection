#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int T,n,a[1010],vis[1010],c[1010],Max,f[1010][2],cir[1010];
vector<int> V[1010];
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
void add(int x,int y)
{
	V[x].push_back(y);
}
void dfs(int u,int fa)
{
	vis[u]=1;
	for(int i=0;i<V[u].size();i++)
	{
		int v=V[u][i];
		if (v!=fa)
		{
			dfs(v,u);
			if (f[u][0]<f[v][0]+c[v])
			{
				f[u][1]=f[u][0];
				f[u][0]=f[v][0]+c[v];
			}
			else if (f[u][1]<f[v][0]+c[v])
			{
				f[u][1]=f[v][0]+c[v];
			}
		}
	}
	//Max=max(Max,f[u][0]+f[u][1]+c[u]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		printf("Case #%d: ",_);
		scanf("%d",&n);
		int ans=0,pre=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),cir[i]=0;
		for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) vis[j]=0,f[j][0]=f[j][1]=0;
				int u=i;
				while (!vis[u])
				{
					vis[u]=1;u=a[u];
				}
				int st=u,cnt=1;
				for(u=a[u];u!=st;u=a[u]) cnt++;
				if (cnt==2)
				{
					if (cir[u]) continue;
					cir[u]=cir[a[u]]=1;
					for(int j=1;j<=n;j++) V[j].clear(),c[j]=1;
					for(int j=1;j<=n;j++) 
						if (j!=u&&j!=a[u]) add(a[j],j);
					dfs(a[u],0);
					dfs(u,0);
					ans=max(ans,f[u][0]+f[a[u]][0]+2);
					ans=max(ans,pre+f[u][0]+f[a[u]][0]+2);
					pre+=f[u][0]+f[a[u]][0]+2;
				}
				ans=max(ans,cnt);
			}
		printf("%d\n",ans);
	}
}


