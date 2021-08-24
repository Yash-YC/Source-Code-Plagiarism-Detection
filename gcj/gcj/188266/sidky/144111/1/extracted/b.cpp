#include <iostream>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

#define	sz(v)	(int)v.size()
#define	rep(i,n)	for((i)=0;(i) < (n); (i)++)
#define	rab(i,a,b)	for((i)=(a);(i) <= (b); (i)++)
#define	Fi(N)		rep(i,N)
#define	Fj(N)		rep(j,N)
#define	Fk(N)		rep(k,N)

long long	min_time[40][40];
bool		flag[40][40];
int	S[40][40],W[40][40],T[40][40];
int	N,M;

int	dr[] = {-1,0,1,0};
int	dc[] = {0,-1,0,1};

void dijkstra(int sr,int sc)
{
	int	i,j;
	int	nr,nc;
	int	r,c;
	long long	d,curr;
	long long	y,clen;

	Fi(2 * N) Fj(2 * M) min_time[i][j] = (1LL << 60),flag[i][j] = false;
	min_time[sr][sc] = 0;

	while(true)
	{
		sr = sc = -1;

		Fi(2 * N) Fj(2 * M)
		{
			if(flag[i][j]) continue;

			if(sr < 0 || min_time[i][j] < min_time[sr][sc])
			{
				sr = i;
				sc = j;
			}
		}

		if(sr == -1) break;
		flag[sr][sc] = true;

		r = sr / 2;
		c = sc / 2;
		clen = S[r][c] + W[r][c];
		curr = min_time[sr][sc];

		//printf("relaxing node: %d %d\n",sr,sc);

		Fi(4)
		{
			nr = sr + dr[i];
			nc = sc + dc[i];

			if(nr < 0 || nr >= 2 * N || nc < 0 || nc >= 2 * M) continue;

			if(nr == sr)
			{
				if((sc + 1) / 2 == (nc + 1) / 2)
					d = curr + 2;
				else
				{
					y = (curr - T[r][c]) % clen;

					//printf("y = %lld\n",y);

					if(S[r][c] <= y && y < clen)
						d = curr + 1;
					else
						d = curr + (S[r][c] - y) + 1;
				}
			}
			else
			{
				if((sr + 1) / 2 == (nr + 1) / 2)
					d = curr + 2;
				else
				{
					y = (curr - T[r][c]) % clen;

					//printf("vert y = %lld\n",y);

					if(y < S[r][c])
						d = curr + 1;
					else
						d = curr + (clen - y) + 1;
				}
			}

			min_time[nr][nc] = min(min_time[nr][nc],d);
		}
	}
}

int main()
{
	int	T,cs;
	int	i,j,k;
	int	r,c;

	scanf("%d",&T);

	rab(cs,1,T)
	{
		scanf("%d %d",&N,&M);
		Fi(N) Fj(M) 
		{
			scanf("%d %d %d",&S[i][j],&W[i][j],&::T[i][j]);
			int	cycle = S[i][j] + W[i][j];
			int	x = (::T[i][j] + cycle - 1) / cycle;

			::T[i][j] -= x * cycle;
			//printf("(%d,%d):%d ",i,j,::T[i][j]);
		}

		dijkstra(2 * N - 1,0);

		/*Fi(2 * N)
		{
			Fj(2 * M)
			{
				printf("%lld ",min_time[i][j]);
			}
			printf("\n");
		}*/

		printf("Case #%d: %lld\n",cs,min_time[0][2 * M - 1]);
	}
	return 0;
}
