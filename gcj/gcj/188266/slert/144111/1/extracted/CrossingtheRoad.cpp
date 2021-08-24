#include <cstdio>
#include <set>
#define oo 1000000000
using namespace std;

int r[25][25];
int w[25][25];
int t[25][25];

int weight[40][40][4];

struct edge{
	int x,y,i;
	edge(){}
	edge(int _x, int _y, int _i){x = _x; y = _y; i = _i;}
	bool operator < (const edge &R) const {
		if(weight[x][y][i] != weight[R.x][R.y][R.i])return weight[x][y][i] < weight[R.x][R.y][R.i];
		if(x != R.x)return x < R.x;
		if(y != R.y)return y < R.y;
		return i < R.i;
	}
};

set<edge> pq;

int dir[4][6] = { {0,-1,1,1,0,3},{0,1,0,1,0,2},{0,1,3,-1,0,1},{0,-1,2,-1,0,0} };
int dir2[4][2] = { {3,1},{2,0},{1,3},{0,2} };

int main()
{	
	int testIndex, testCount;
	scanf("%d", &testCount);
	for(testIndex = 1; testIndex <= testCount; testIndex++)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		printf("Case #%d: ",testIndex);
		int o = n*m;
		int i,j,k;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
			{
				scanf("%d %d %d", &r[i][j], &w[i][j], &t[i][j]);
				t[i][j] = t[i][j] %(r[i][j] + w[i][j]);
				for(k = 0; k < 4; k++)
					weight[i][j][k] = oo;
			}

		pq.clear();
		weight[n-1][0][0] = 0;
		pq.insert(edge(n-1,0,0));

		while(!pq.empty())
		{
			edge h = *(pq.begin());
			pq.erase(pq.begin());
			//printf("%d %d %d ", h.x,h.y,h.i);

			if(h.x == 0 && h.y == m-1 && h.i == 2)
			{
				printf("%d\n", weight[h.x][h.y][h.i]);
				break;
			}
			for(int z = 0; z < 6; z+=3)
			{
				if(h.x + dir[h.i][z+0] >= 0 && h.x + dir[h.i][z+0] < n
				&& h.y + dir[h.i][z+1] >= 0 && h.y + dir[h.i][z+1] < m)
				{
					if(weight[h.x+dir[h.i][z+0]][h.y+dir[h.i][z+1]][dir[h.i][z+2]] > weight[h.x][h.y][h.i] + 2)
					{
						pq.erase(edge(h.x+dir[h.i][z+0],h.y+dir[h.i][z+1],dir[h.i][z+2]));
						weight[h.x+dir[h.i][z+0]][h.y+dir[h.i][z+1]][dir[h.i][z+2]] = weight[h.x][h.y][h.i] + 2;
						pq.insert(edge(h.x+dir[h.i][z+0],h.y+dir[h.i][z+1],dir[h.i][z+2]));
					}
				}
			}
			
			int d;
			int waitmore;
			if( (weight[h.x][h.y][h.i]-t[h.x][h.y] + r[h.x][h.y]+w[h.x][h.y])%(r[h.x][h.y]+w[h.x][h.y]) < r[h.x][h.y] )
			{
				d = 0;
				waitmore = r[h.x][h.y] - (weight[h.x][h.y][h.i]-t[h.x][h.y] + r[h.x][h.y]+w[h.x][h.y])%(r[h.x][h.y]+w[h.x][h.y]);
			}
			else
			{
				d = 1;
				waitmore = r[h.x][h.y]+w[h.x][h.y] - (weight[h.x][h.y][h.i]-t[h.x][h.y] + r[h.x][h.y]+w[h.x][h.y])%(r[h.x][h.y]+w[h.x][h.y]);
			}
			//printf("%d %d\n", weight[h.x][h.y][h.i], d);
			if(weight[h.x][h.y][dir2[h.i][d]] > weight[h.x][h.y][h.i] + 1)
			{
				pq.erase(edge(h.x,h.y,dir2[h.i][d]));
				weight[h.x][h.y][dir2[h.i][d]] = weight[h.x][h.y][h.i] + 1;
				pq.insert(edge(h.x,h.y,dir2[h.i][d]));
			}
			if(weight[h.x][h.y][dir2[h.i][!d]] > weight[h.x][h.y][h.i] + 1 + waitmore)
			{
				pq.erase(edge(h.x,h.y,dir2[h.i][!d]));
				weight[h.x][h.y][dir2[h.i][!d]] = weight[h.x][h.y][h.i] + 1 + waitmore;
				pq.insert(edge(h.x,h.y,dir2[h.i][!d]));
			}
		}
	}
	return 0;
}