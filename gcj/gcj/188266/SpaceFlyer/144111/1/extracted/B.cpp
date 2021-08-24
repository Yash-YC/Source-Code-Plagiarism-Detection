#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 20;
const int MAXQ = MAXN*MAXN*2*2;
const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M, R, C;
int S[MAXN][MAXN], W[MAXN][MAXN], T[MAXN][MAXN];
long dist[MAXN*2][MAXN*2];
bool footmark[MAXN*2][MAXN*2];

void read()
{
	cin >> N >> M;
	for(int r=N-1; r >= 0; r--)
		for(int c=0; c<M; c++)
			cin >> S[r][c] >> W[r][c] >> T[r][c];
}

void bfs()
{
	memset(dist, -1, sizeof(dist));
	memset(footmark, false, sizeof(footmark));
	dist[0][0] = 0;
	R = 2*N, C = 2*M;
	while (true)
	{
		int r = -1, c = -1;
		for(int ir=0; ir<R; ir++)
			for(int ic=0; ic<C; ic++)
				if (dist[ir][ic] != -1 && !footmark[ir][ic])
					if (r == -1 || dist[ir][ic] < dist[r][c])
					{
						r = ir;
						c = ic;
					}
	
		if (r == -1)
			break;

		int now = dist[r][c];
		footmark[r][c] = true;
		for(int d=0; d<4; d++){
			int nr = r+DIR[d][0], nc = c+DIR[d][1];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || footmark[nr][nc])
				continue;
			int wait = 0, pass = 2;
			int i = r/2, j = c/2;
			int round = S[i][j]+W[i][j];
			int mark = ((now-T[i][j])%round+round)%round;
			if (d < 2 && r%2 == 0)
			{
				if (mark >= S[i][j])
					wait = round-mark;
				pass = 1;
			}
			if (d >= 2 && c%2 == 0)
			{
				if (mark < S[i][j])
					wait = S[i][j]-mark;
				pass = 1;
			}

			int ndist = now+pass+wait;
			if (dist[nr][nc] == -1 || ndist < dist[nr][nc])
				dist[nr][nc] = ndist;
		}
	}
}

int main(int argc, char* args[]){
	if (argc < 3){
		cout << "lack of args" << endl;
		return 0;
	}
	freopen(args[1], "r", stdin);
	freopen(args[2], "w", stdout);
	int C;
	cin >> C;
	for(int ic=0; ic<C; ic++)
	{
		read();
		bfs();
		printf("Case #%d: ", ic+1);
		cout << dist[2*N-1][2*M-1] << endl;
	}
}

