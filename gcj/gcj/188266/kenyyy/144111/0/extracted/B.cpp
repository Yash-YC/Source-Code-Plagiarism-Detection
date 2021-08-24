#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Q
{
	int s;
	int w;
	int t;
}q[50][50];

int dp[50][50];
int flag[50][50];
int m,n;

int gos( int a, int b, int val )
{
	int t = (val-q[a][b].t)/(q[a][b].s+q[a][b].w)*(q[a][b].s+q[a][b].w)+q[a][b].t;
	if( t + q[a][b].s <= val )
		return t+q[a][b].s+q[a][b].w+1;
	return val+1;
}

int gow( int a, int b, int val)
{
	int t = (val-q[a][b].t)/(q[a][b].s+q[a][b].w)*(q[a][b].s+q[a][b].w)+q[a][b].t;
	if( t + q[a][b].s <= val )
		return val+1;
	return t+q[a][b].s+1;
}

void search( int x, int y, int val)
{
	dp[x][y] = val;
	if( x -1 >= 0 )
	{
		int t;
		if( x % 2 == 1 )
			t = gos(x/2,y/2,dp[x][y]);
		else
			t = dp[x][y] + 2;
		if( dp[x-1][y] == 0 || dp[x-1][y] > t )
		{
			if( x-1 !=0 || y!=0 )
			{
				search( x-1,y, t);
			}
		}
	}
	if( x+1 < n+n )
	{
		int t;
		if( x % 2 == 0 )
			t = gos(x/2,y/2,dp[x][y]);
		else
			t = dp[x][y] + 2;
		if( dp[x+1][y] == 0 || dp[x+1][y] > t )
		{
			if( x+1 !=0 || y!=0 )
			{
				search( x+1,y, t);
			}
		}
	}
	if( y-1 >= 0 )
	{
		int t;
		if( y % 2 == 1 )
			t = gow(x/2,y/2,dp[x][y]);
		else
			t = dp[x][y] + 2;
		if( dp[x][y-1] == 0 || dp[x][y-1] > t )
		{
			if( x !=0 || y-1!=0 )
			{
				search( x,y-1, t);
			}
		}
	}
	if( y+1 < m+m )
	{
		int t;
		if( y % 2 == 0)
		{
			t = gow(x/2,y/2,dp[x][y]);
		}
		else
		{
			t = dp[x][y] + 2;
		}
		if( dp[x][y+1] == 0 || dp[x][y+1] > t )
		{
			if( x !=0 || y+1!=0 )
			{
				search( x,y+1, t);
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	int ca;
	int i,j;
	for( ca = 1; ca <= T; ca ++ )
	{
		memset( dp, 0,sizeof(dp));
		memset( flag, 0,sizeof(flag));
		scanf("%d%d", &n, &m);
		for( i = n-1; i >= 0; i -- )
		{
			for( j = 0; j< m; j ++ )
			{
				scanf("%d%d%d", &q[i][j].s, &q[i][j].w, &q[i][j].t);
				q[i][j].t -= (q[i][j].t)/(q[i][j].s+q[i][j].w) * (q[i][j].s+q[i][j].w);
				if( q[i][j].t > 0 )
					q[i][j].t -= q[i][j].s + q[i][j].w;
			}
		}
		search( 0,0, 0);
		printf("Case #%d: %d\n", ca, dp[n+n-1][m+m-1]);
	}
	return 0;
}