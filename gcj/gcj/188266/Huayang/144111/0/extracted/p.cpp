#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <cmath>
#include <string>

using namespace std;

int dist[100][100][4];
int inQ[100][100][4];
int S[100][100];
int T[100][100];
int W[100][100];
int N, M;

struct state_t
{
	//state_t(const state_t &s) : x(s.x), y(s.y),.
	int x, y, pos;
};

deque<state_t> queue;

void refresh(int x, int y, int p, int cost)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return;

	if (dist[x][y][p] < 0 || cost < dist[x][y][p])
	{
		dist[x][y][p] = cost;
		if (!inQ[x][y][p])
		{
			inQ[x][y][p] = 1;
			state_t s;
			s.x = x;
			s.y = y;
			s.pos = p;
			queue.push_back(s);
			//puts("here");
		}
	}
}

int	main()
{
	//freopen("input.txt", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b_small.out", "w", stdout);

	int task;
	cin >> task;
	for (int nCase = 0; nCase < task; ++nCase)
	{
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				cin >> S[i][j] >> W[i][j] >> T[i][j];
				T[i][j] %= (S[i][j] + W[i][j]);
			}

		memset(dist, 255, sizeof(dist));
		queue.clear();
		memset(inQ, 0, sizeof(inQ));

		refresh(N - 1, 0, 0, 0);
		while (queue.size())
		{
			state_t s = queue.front();
			queue.pop_front();

			inQ[s.x][s.y][s.pos] = 0;
			int horP = s.pos ^ 2;
			int verP = s.pos ^ 1;
			int cost = dist[s.x][s.y][s.pos];
			int horWait = (cost - T[s.x][s.y] + S[s.x][s.y] + W[s.x][s.y]) % (S[s.x][s.y] + W[s.x][s.y]);
			int verWait = (cost - T[s.x][s.y] + S[s.x][s.y] + W[s.x][s.y]) % (S[s.x][s.y] + W[s.x][s.y]);

			if (verWait <= S[s.x][s.y] - 1) 
				verWait = 0;
			else
				verWait = (S[s.x][s.y] + W[s.x][s.y]) - verWait;

			if (horWait >= S[s.x][s.y] && horWait <= (S[s.x][s.y] + W[s.x][s.y]) - 1) 
				horWait = 0;
			else
				horWait = (S[s.x][s.y] - horWait + (S[s.x][s.y] + W[s.x][s.y])) % (S[s.x][s.y] + W[s.x][s.y]);

			if (S[s.x][s.y] > 0) refresh(s.x, s.y, horP, cost + horWait + 1);
			if (W[s.x][s.y] > 0) refresh(s.x, s.y, verP, cost + verWait + 1);

			switch (s.pos)
			{
			case (0):
				refresh(s.x + 1, s.y, verP, cost + 2);
				refresh(s.x, s.y - 1, horP, cost + 2);
				break;
			case (1):
				refresh(s.x - 1, s.y, verP, cost + 2);
				refresh(s.x, s.y - 1, horP, cost + 2);
				break;
			case (2):
				refresh(s.x + 1, s.y, verP, cost + 2);
				refresh(s.x, s.y + 1, horP, cost + 2);
				break;
			case (3):
				refresh(s.x - 1, s.y, verP, cost + 2);
				refresh(s.x, s.y + 1, horP, cost + 2);
				break;
			}
		}
		printf("Case #%d: %d\n", nCase + 1, dist[0][M - 1][3]);
	}

	return 0;
}