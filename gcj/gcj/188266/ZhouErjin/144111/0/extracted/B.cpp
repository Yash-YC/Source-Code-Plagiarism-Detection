#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=20+10;
const int oo=10000000;

const int xxx[4][2]={{3,1},{2,0},{1,3},{0,2}};
const int dx[4][2]={{-1,0},{-1,0},{1,0},{1,0}};
const int dy[4][2]={{0,-1},{0,1},{0,1},{0,-1}};

int dist[maxn][maxn][4];
int S[maxn][maxn];
int W[maxn][maxn];
int T[maxn][maxn];
int n,m;
int test,cases;

void prepare()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		scanf("%d%d%d",&S[i][j],&W[i][j],&T[i][j]);
		T[i][j]%=(S[i][j]+W[i][j]);
	}
}

int gtime(int t,int u,int v,int dir)
{
	if (dir==0)
	{
		if (t>=T[u][v])
		{
			if ((t-T[u][v])%(S[u][v]+W[u][v])<S[u][v]) return t;
			return ((t-T[u][v])/(S[u][v]+W[u][v])+1)*(S[u][v]+W[u][v])+T[u][v];
		}
		if (t<T[u][v]-W[u][v]) return t;
		return T[u][v];
	}
	if (t>=T[u][v])
	{
		if ((t-T[u][v])%(S[u][v]+W[u][v])>=S[u][v]) return t;
		return ((t-T[u][v])/(S[u][v]+W[u][v]))*(S[u][v]+W[u][v])+S[u][v]+T[u][v];
	}
	if (t>=T[u][v]-W[u][v]) return t;
	return T[u][v]-W[u][v];
}

void work()
{
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	for (int k=0;k<4;k++)
		dist[i][j][k]=oo;
	dist[0][0][0]=0;
	
	for (int i=0;i<n*m*4;i++)
	{
		int u=-1,v,w;
		for (int a=0;a<n;a++)
		for (int b=0;b<m;b++)
		for (int c=0;c<4;c++)
		if (dist[a][b][c]>=0 && (u==-1 || dist[a][b][c]<dist[u][v][w]))
			u=a,v=b,w=c;
		
		if (u==n-1 && v==m-1 && w==2)
		{
			printf("Case #%d: %d\n",++cases,dist[u][v][w]);break;
		}
		for (int a=0;a<2;a++)
		for (int b=0;b<2;b++)
		{
			if (b==0) dist[u][v][xxx[w][a]]=min(dist[u][v][xxx[w][a]],gtime(dist[u][v][w],u,v,a)+1);
			else 
			{
				if (u+dx[w][a]>=0 && u+dx[w][a]<n && v+dy[w][a]>=0 && v+dy[w][a]<m)
				{
					dist[u+dx[w][a]][v+dy[w][a]][xxx[w][a]]=
					min(dist[u+dx[w][a]][v+dy[w][a]][xxx[w][a]],dist[u][v][w]+2);
				}
			}
		}
		dist[u][v][w]=-1;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	
	for (scanf("%d",&test);test;test--)
	{
		prepare();
		work();
	}
}