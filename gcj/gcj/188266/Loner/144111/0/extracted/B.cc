#include <cstdio>
#include <cstring>

#include <queue>

using namespace std;

typedef long long llint;

struct light {
	llint s, w, t;

	llint next_sw(llint u) {
		if( !w ) return -1;

		llint v = (u-t) % (s+w) + (s+w);
		v %= (s+w);

		if( v < s ) return s-v;
		return 0;
	}

	llint next_ns(llint u) {
		if( !s ) return -1;

		llint v = (u-t) % (s+w) + (s+w);
		v %= (s+w);

		if( v >= s ) return s+w-v;
		return 0;
	}
};

int n, m;
light lights[20][20];

llint dist[20][20][4];
bool inqueue[20][20][4];
queue<int> q;

void better( int x, int y, int d, llint _dist )
{
	if( dist[x][y][d] < 0 || _dist < dist[x][y][d] ) {
		dist[x][y][d] = _dist;

		if( !inqueue[x][y][d] ) {
			dist[x][y][d] = _dist;
			q.push((x<<7) | (y<<2) | d);
		}
	}
}

int main( void )
{
//	freopen( "B.in", "r", stdin );

	int prob, nprob; scanf( "%d", &nprob );

	for( prob = 0; prob < nprob; ) {
		scanf( "%d %d", &n, &m );

		for( int i = 0; i < n; ++i )
			for( int j = 0; j < m; ++j ) {
				llint s, w, t; scanf( "%lld %lld %lld", &s, &w, &t );
				lights[i][j] = (light) {s, w, t};
			}	
	
		memset(dist, -1, sizeof(dist));
		dist[n - 1][0][0] = 0;

		memset(inqueue, false, sizeof(inqueue));
		q.push((n - 1) << 7);

		while( !q.empty() ) {
			int state = q.front();
			q.pop();

			int x = state>>7;
			int y = (state>>2) & 31;
			int d = state & 3;
			int i = x;
			int j = y;

			inqueue[x][y][d] = false;

			if( d == 0 ) {
				if( j ) better(i, j-1, 1, dist[x][y][d] + 2);
				if( i+1 < n ) better(i+1, j, 3, dist[x][y][d] + 2);

				llint wait = lights[x][y].next_ns(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 3, dist[x][y][d] + wait + 1);

				wait = lights[x][y].next_sw(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 1, dist[x][y][d] + wait + 1);
			} else if( d == 1 ) {
				if( j+1 < m ) better(i, j+1, 0, dist[x][y][d] + 2);
				if( i+1 < n ) better(i+1, j, 2, dist[x][y][d] + 2);

				llint wait = lights[x][y].next_ns(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 2, dist[x][y][d] + wait + 1);

				wait = lights[x][y].next_sw(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 0, dist[x][y][d] + wait + 1);
			} else if( d == 2 ) {
				if( j+1 < m ) better(i, j+1, 3, dist[x][y][d] + 2);
				if( i ) better(i-1, j, 1, dist[x][y][d] + 2);

				llint wait = lights[x][y].next_ns(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 1, dist[x][y][d] + wait + 1);

				wait = lights[x][y].next_sw(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 3, dist[x][y][d] + wait + 1);
			} else if( d == 3 ) {
				if( j ) better(i, j-1, 2, dist[x][y][d] + 2);
				if( i ) better(i-1, j, 0, dist[x][y][d] + 2);

				llint wait = lights[x][y].next_ns(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 0, dist[x][y][d] + wait + 1);

				wait = lights[x][y].next_sw(dist[x][y][d]);
				if( wait >= 0 ) better(i, j, 2, dist[x][y][d] + wait + 1);
			}
		}

		printf( "Case #%d: %lld\n", ++prob, dist[0][m-1][2] );
	}

	return 0;
}

