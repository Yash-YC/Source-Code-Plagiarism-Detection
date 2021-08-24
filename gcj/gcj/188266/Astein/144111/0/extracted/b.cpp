#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

struct state
{
	int x, y;
	int pos;
	long long time;

	bool operator < (const state &a) const
	{
		return time > a.time;
	}
};

int N, M;
int S[25][25], W[25][25], T[25][25];
long long table[25][25][4];
char check[25][25][4];
priority_queue< state > Q;

long long GetNS( long long now, int s, int w, int t)
{
	int mod = now % (s + w);
	int remain;

	if (t > w)
	{
		if ( t <= mod || mod < t - w ) return now;
		remain = t - mod;
	}
	else
	{
		if (t <= mod && mod < t + s) return now;
		remain = t - mod;
		if (remain < 0) remain += s + w;
	}
	
	return now + remain;
}

long long GetEW( long long now, int s, int w, int t)
{
	return GetNS( now, w, s, (t + s) % (s + w) );
}

void Update( state next )
{
	if (table[next.x][next.y][next.pos] == -1 || table[next.x][next.y][next.pos] > next.time) 
	{
		table[next.x][next.y][next.pos] = next.time;
		Q.push( next );
	}
}

int main()
{
	int TT;
	cin >> TT;

	for (int q = 1; q <= TT; ++q)
	{
		memset(table, -1, sizeof(table));
		memset(check, 0, sizeof(check));

		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> S[i][j] >> W[i][j] >> T[i][j];
				T[i][j] %= (S[i][j] + W[i][j]);
			}
		}

		state st;
		st.x = N - 1, st.y = 0, st.pos = 0, st.time = 0;
		
		while (!Q.empty()) Q.pop();
		Q.push(st);

		table[N - 1][0][0] = 0;
		while(!Q.empty())
		{
			state now = Q.top(), next; Q.pop();

			if (now.x < 0 || now.y < 0) continue;
			if (now.x == N || now.y == M) continue;

//			printf("%d %d %d time = %d\n", now.x, now.y, now.pos, now.time);

			if (now.x == 0 && now.y == M - 1 && now.pos == 3)
			{
				printf("Case #%d: %I64d\n", q, now.time);
				break;
			}

			if (check[now.x][now.y][now.pos]) continue;
			check[now.x][now.y][now.pos] = 1;

			int i = now.x, j = now.y;

			switch (now.pos)
			{
			case 0:
				next = now; next.pos = 2; next.time = 1 + GetNS( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );
				next = now; next.pos = 1; next.time = 1 + GetEW( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );

				next = now; next.x++; next.pos = 2; next.time = 2 + now.time; Update( next );
				next = now; next.y--; next.pos = 1; next.time = 2 + now.time; Update( next );
				break;
			case 1:
				next = now; next.pos = 3; next.time = 1 + GetNS( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );
				next = now; next.pos = 0; next.time = 1 + GetEW( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );

				next = now; next.x++; next.pos = 3; next.time = 2 + now.time; Update( next );
				next = now; next.y++; next.pos = 0; next.time = 2 + now.time; Update( next );
				break;
			case 2:
				next = now; next.pos = 0; next.time = 1 + GetNS( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );
				next = now; next.pos = 3; next.time = 1 + GetEW( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );

				next = now; next.x--; next.pos = 0; next.time = 2 + now.time; Update( next );
				next = now; next.y--; next.pos = 3; next.time = 2 + now.time; Update( next );
				break;
			case 3:
				next = now; next.pos = 1; next.time = 1 + GetNS( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );
				next = now; next.pos = 2; next.time = 1 + GetEW( now.time, S[i][j], W[i][j], T[i][j] ); Update( next );

				next = now; next.x--; next.pos = 1; next.time = 2 + now.time; Update( next );
				next = now; next.y++; next.pos = 2; next.time = 2 + now.time; Update( next );
				break;
			}
		}
	}


	return 0;
}


