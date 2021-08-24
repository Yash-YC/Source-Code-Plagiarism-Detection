#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int point,link;
}list[2010];
bool b[2010];
int v[1010],g[1010],e[1010],q[1010],d[1010];
bool vis[1010];
int n,num,tot;
bool flag;
void join(int x,int y)
{
	num++; list[num].point=y; list[num].link=v[x]; v[x]=num;
}
void dfs(int i,int x)
{
	int j,k,y;
	vis[i]=true; j=v[i];
	while (j!=-1)
	{
		if (!vis[list[j].point])
		{
			g[list[j].point]=j; dfs(list[j].point,j);
		}
		else if ((!flag)&&(j!=(x^1)))
		{
			flag=true; tot=1; y=i; e[1]=j; k=g[i];
			while (y!=list[j].point)
			{
				tot++; y=list[k^1].point; e[tot]=k; k=g[y];
			}
		}
		j=list[j].link;
	}
}
int bfs(int i)
{
	int j,x,h,t;
	memset(d,0xff,sizeof(d));
	h=0; t=1; q[1]=i; d[i]=0;
	while (h<t)
	{
		h++; x=q[h]; j=v[x];
		while (j!=-1)
		{
			if (b[j]&&(d[list[j].point]==-1))
			{
				d[list[j].point]=d[x]+1; t++; q[t]=list[j].point;
			}
			j=list[j].link;
		}
	}
	x=0;
	for (j=1;j<=n;j++) x=max(x,d[j]);
	return x;
}
int main()
{
	int i,x,y,_T,T,Z,ans;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	for (_T=1;_T<=T;_T++)
	{
		scanf("%d",&n);
		memset(v,0xff,sizeof(v));
		num=-1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			join(i,x); join(x,i);
		}
		memset(vis,false,sizeof(vis));
		memset(b,true,sizeof(b));
		ans=0; Z=0;
		for (i=1;i<=n;i++)
			if (!vis[i])
			{
				flag=false; g[i]=-1; dfs(i,-1);
				if (tot>2) ans=max(ans,tot);
				else
				{
					b[e[1]]=false; b[e[1]^1]=false;
					b[e[2]]=false; b[e[2]^1]=false;
					x=list[e[1]].point; y=list[e[1]^1].point;
					Z+=bfs(x)+bfs(y)+2;
					b[e[1]]=true; b[e[1]^1]=true;
					b[e[2]]=true; b[e[2]^1]=true;
				}
			}
		printf("Case #%d: %d\n",_T,max(Z,ans));
	}
	return 0;
}
