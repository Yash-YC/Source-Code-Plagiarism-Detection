#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<cstdlib>
#include<sstream>
#include<functional>
using namespace std;

typedef long long LL;

bool f[25][25][4];

struct node
{
	int x,y,k,t;
}pp,qq;

bool operator<(node p,node q)
{
	return p.t>q.t;
}

int main()
{
	int tt,cs,n,m,i,j,k,st;
	int s[50][50],w[50][50],t[50][50];
	freopen("s.in","r",stdin);
	freopen("s.out","w",stdout);
	//freopen("l.in","r",stdin);
	//freopen("l.out","w",stdout);
	scanf("%d",&tt);
	for(cs=1;cs<=tt;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d%d%d",&s[i][j],&w[i][j],&t[i][j]);
		memset(f,0,sizeof(f));
		priority_queue<node> pq;
		pp.x=n-1;
		pp.y=0;
		pp.k=0;
		pp.t=0;
		pq.push(pp);
		while(!pq.empty())
		{
			pp=pq.top();
			pq.pop();
			if(f[pp.x][pp.y][pp.k])
				continue;
			f[pp.x][pp.y][pp.k]=1;
			if(pp.x==0&&pp.y==m-1&&pp.k==2)
				break;
			if(pp.k==0)
			{
				qq.x=pp.x;
				qq.y=pp.y-1;
				qq.k=1;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x+1;
				qq.y=pp.y;
				qq.k=3;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=1;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1+s[pp.x][pp.y]-st;
				else
					qq.t=pp.t+1;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=3;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1;
				else
					qq.t=pp.t+1+s[pp.x][pp.y]+w[pp.x][pp.y]-st;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);
			}
			else if(pp.k==1)
			{
				qq.x=pp.x;
				qq.y=pp.y+1;
				qq.k=0;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x+1;
				qq.y=pp.y;
				qq.k=2;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=0;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1+s[pp.x][pp.y]-st;
				else
					qq.t=pp.t+1;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=2;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1;
				else
					qq.t=pp.t+1+s[pp.x][pp.y]+w[pp.x][pp.y]-st;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);
			}
			else if(pp.k==2)
			{
				qq.x=pp.x;
				qq.y=pp.y+1;
				qq.k=3;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x-1;
				qq.y=pp.y;
				qq.k=1;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=3;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1+s[pp.x][pp.y]-st;
				else
					qq.t=pp.t+1;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=1;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1;
				else
					qq.t=pp.t+1+s[pp.x][pp.y]+w[pp.x][pp.y]-st;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);
			}
			else
			{
				qq.x=pp.x;
				qq.y=pp.y-1;
				qq.k=2;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x-1;
				qq.y=pp.y;
				qq.k=0;
				qq.t=pp.t+2;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=2;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1+s[pp.x][pp.y]-st;
				else
					qq.t=pp.t+1;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);

				qq.x=pp.x;
				qq.y=pp.y;
				qq.k=0;
				st=(pp.t-t[pp.x][pp.y])%(s[pp.x][pp.y]+w[pp.x][pp.y]);
				if(st<0)
					st+=s[pp.x][pp.y]+w[pp.x][pp.y];
				if(st<s[pp.x][pp.y])
					qq.t=pp.t+1;
				else
					qq.t=pp.t+1+s[pp.x][pp.y]+w[pp.x][pp.y]-st;
				if(qq.x<0||qq.y<0||qq.x>=n||qq.y>=m)
					;
				else
					pq.push(qq);
			}
		}
		printf("Case #%d: %d\n",cs,pp.t);
	}
}