#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct snode{
	int idy,idx,d;
	int v;
}snode;

struct cmp{
	bool operator ()(const snode &i,const snode &j){
		return i.v>j.v;
	}
};

int C,N,M,n,m;
int S[32][32],W[32][32],T[32][32],sum[32][32];
priority_queue<snode,vector<snode>,cmp> q;
int dist[32][32][4];

void init()
{
	int i,j;
	
	scanf("%d%d",&N,&M);
	n=n*2;
	m=m*2;
	for (i=N;i>=1;i--)
	{
		for (j=1;j<=M;j++)
		{
			scanf("%d%d%d",&S[i][j],&W[i][j],&T[i][j]);
			sum[i][j]=S[i][j]+W[i][j];
			T[i][j]%=sum[i][j];
		}
	}
}

int cross(snode o, int dire)
{
	int y=o.idy,x=o.idx;
	int start=o.v;
	int zt= (o.v+sum[y][x]-T[y][x])%sum[y][x];
	int wait;
	
	if (dire)
	{
		if (zt>=S[y][x])
			wait=0;
		else
			wait=S[y][x]-zt;
	}
	else
	{
		if (zt<S[y][x])
			wait=0;
		else
			wait=sum[y][x]-zt;
	}
	return start+wait+1;
}

int go(int y,int x,int d,int v,snode *g)
{
	if (y<1 || x<1 || y>N || x>M)
		return 0;
	if (dist[y][x][d]>v)
	{
		dist[y][x][d]=v;
		(*g).idy=y;
		(*g).idx=x;
		(*g).d=d;
		(*g).v=v;
		return 1;
	}
	return 0;
}

void work()
{
	snode tmp,g;
	int i,j,k;
	
	tmp.v=0;
	tmp.idy=tmp.idx=1;
	tmp.d=0;
	while (!q.empty())
		q.pop();
	
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			for (k=0;k<4;k++)
			{
				dist[i][j][k]=1000000000;
			}
	dist[1][1][0]=0;
	
	q.push(tmp);
	while (!q.empty())
	{
		tmp=q.top();
		q.pop();
		
		if (dist[tmp.idy][tmp.idx][tmp.d]<tmp.v)
			continue;
		//printf("<%d %d %d, %d>\n",tmp.idy,tmp.idx,tmp.d,tmp.v);
		if (tmp.idy==N && tmp.idx==M && tmp.d==3)
			break;
		switch (tmp.d)
		{
		case 0:
			if (go(tmp.idy-1,tmp.idx,2,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx-1,1,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,1,cross(tmp,1),&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,2,cross(tmp,0),&g))
				q.push(g);
			break;
		case 1:
			if (go(tmp.idy-1,tmp.idx,3,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx+1,0,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,0,cross(tmp,1),&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,3,cross(tmp,0),&g))
				q.push(g);
			break;
		case 2:
			if (go(tmp.idy+1,tmp.idx,0,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx-1,3,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,0,cross(tmp,0),&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,3,cross(tmp,1),&g))
				q.push(g);
			break;
		case 3:
			if (go(tmp.idy+1,tmp.idx,1,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx+1,2,tmp.v+2,&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,1,cross(tmp,0),&g))
				q.push(g);
			if (go(tmp.idy,tmp.idx,2,cross(tmp,1),&g))
				q.push(g);
			break;
		}
	}
	
	printf("%d\n",dist[N][M][3]);
}

int main()
{
	int i;
	
	freopen("B-small-attempt3.in","r",stdin);
	freopen("B-small-attempt3.out","w",stdout);
	//ready();
	scanf("%d",&C);
	//gets(s);
	for (i=1;i<=C;i++)
	{
		init();
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
