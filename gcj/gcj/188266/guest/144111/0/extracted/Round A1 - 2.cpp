#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
#define N 30
int n,m;
struct light
{
	long long s,w,t;
} map[N][N];
struct point
{
	int y,x;
};
queue<point> q;
long long time[N][N];
bool inq[N][N];

void f(int y,int x,long long t)
{
	if(time[y][x]>t)
	{
		time[y][x]=t;
		if(inq[y][x]==0 && y>0 && y<=n*2 && x>0 && x<=m*2)
		{
			inq[y][x]=1;
			point p;
			p.y=y;
			p.x=x;
			q.push(p);
		}
	}
}
void SPFA()
{
	point t;
	int x,y,px,py;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		y=t.y;
		x=t.x;
		inq[y][x]=0;
		py=(y+1)/2;
		px=(x+1)/2;
		if(y&1==1)//go down
		{
			f(y-1,x,time[y][x]+2);
			if((time[y][x]-map[py][px].t)%(map[py][px].s+map[py][px].w)<map[py][px].s)
				f(y+1,x,time[y][x]+1);
			else
				f(y+1,x,((time[y][x]-map[py][px].t)/
					(map[py][px].s+map[py][px].w)+1)
					*(map[py][px].s+map[py][px].w)+map[py][px].t+1);
		}
		else//go up
		{
			f(y+1,x,time[y][x]+2);
			if((time[y][x]-map[py][px].t)%(map[py][px].s+map[py][px].w)<map[py][px].s)
				f(y-1,x,time[y][x]+1);
			else
				f(y-1,x,((time[y][x]-map[py][px].t)/
					(map[py][px].s+map[py][px].w)+1)
					*(map[py][px].s+map[py][px].w)+map[py][px].t+1);
		}
		if(x&1==1)// go right
		{
			f(y,x-1,time[y][x]+2);
			if((time[y][x]-map[py][px].t)%(map[py][px].s+map[py][px].w)>=map[py][px].s)
				f(y,x+1,time[y][x]+1);
			else
				f(y,x+1,((time[y][x]-map[py][px].t)/
					(map[py][px].s+map[py][px].w))
					*(map[py][px].s+map[py][px].w)+map[py][px].t+map[py][px].s+1);
		}
		else//go left
		{
			f(y,x+1,time[y][x]+2);
			if((time[y][x]-map[py][px].t)%(map[py][px].s+map[py][px].w)>=map[py][px].s)
				f(y,x-1,time[y][x]+1);
			else
				f(y,x-1,((time[y][x]-map[py][px].t)/
					(map[py][px].s+map[py][px].w))
					*(map[py][px].s+map[py][px].w)+map[py][px].t+map[py][px].s+1);
		}
	}
}

int main()
{
	int t,it,x,y;
	FILE *fin=fopen("B-small.in","r"),*fout=fopen("B-small.out","w");
	fscanf(fin,"%d",&t);
	for(it=1;it<=t;++it)
	{
		fscanf(fin,"%d%d",&n,&m);
		memset(inq,0,sizeof(inq));
		for(y=1;y<=n;++y)
		{
			for(x=1;x<=m;++x)
			{
				fscanf(fin,"%I64d%I64d%I64d",&map[y][x].s,&map[y][x].w,&map[y][x].t);
				map[y][x].t=map[y][x].t%(map[y][x].s+map[y][x].w)-(map[y][x].s+map[y][x].w);
				time[y][x]=10000000000;
			}
		}
		point a;
		a.x=1;
		a.y=n*2;
		time[a.y][a.x]=0;
		q.push(a);
		SPFA();
		fprintf(fout,"Case #%d: %I64d\n",it,time[1][m*2]);
	}
	return 0;
}
