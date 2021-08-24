#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;
#define sz(c) (int)c.size()
#define pb push_back
#define all(c) c.begin(), c.end()


void initialize()
{
    freopen("b1.in","r",stdin);
    freopen("output.txt","w",stdout);
}


const long long INF = (long long)1e15;
const int MAX = 22;
bool visited[MAX][MAX][2][2];
long long minlen[MAX][MAX][2][2];
long long a[MAX][MAX], b[MAX][MAX], time[MAX][MAX];

int Switch(int x, int y, int t, bool side)
{
	int s = a[x][y] + b[x][y];
	t -= ((t - time[x][y]) / s) * s;
	if (side)
	{
		if (t < time[x][y] + a[x][y]) return 1;
		return time[x][y] + s - t + 1;
	}
	else
	{
		if (t >= time[x][y] + a[x][y]) return 1;
		return time[x][y] + a[x][y] - t + 1;
	}
}

int main()
{
    initialize();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = n - 1; i >= 0; --i)
			for (int j = 0; j < m; ++j)
			{
				scanf("%lld%lld%lld", &a[i][j], &b[i][j], &time[i][j]);
				int s = a[i][j] + b[i][j];
				time[i][j] -= ((time[i][j] / s) + 1) * s;
			}
	
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int i1 = 0; i1 < 2; ++i1)
					for (int j1 = 0; j1 < 2; ++j1)
					{
						minlen[i][j][i1][j1] = INF;
						visited[i][j][i1][j1] = false;
					}
		minlen[0][0][0][0] = 0;
		
		while (true)
		{
			int x = -1, y = 0, l = 0, r = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					for (int i1 = 0; i1 < 2; ++i1)
						for (int j1 = 0; j1 < 2; ++j1)
						{
							if (visited[i][j][i1][j1]) continue;
							if (x == -1 || minlen[i][j][i1][j1] < minlen[x][y][l][r])
								x = i, y = j, l = i1, r = j1;
						}
			if (x == -1) break;

			visited[x][y][l][r] = true;

			minlen[x][y][1 - l][r] = min(minlen[x][y][1 - l][r], minlen[x][y][l][r] + Switch(x, y, minlen[x][y][l][r], true));
			minlen[x][y][l][1 - r] = min(minlen[x][y][l][1 - r], minlen[x][y][l][r] + Switch(x, y, minlen[x][y][l][r], false));

			int nx = x + l * 2 - 1, ny = y + r * 2 - 1, nl = 1 - l, nr = 1 - r;
			if (nx >= 0 && nx < n)	minlen[nx][y][nl][r] = min(minlen[nx][y][nl][r], minlen[x][y][l][r] + 2);
			if (ny >= 0 && ny < m)	minlen[x][ny][l][nr] = min(minlen[x][ny][l][nr], minlen[x][y][l][r] + 2);
		}

		printf("Case #%d: %lld\n", t, minlen[n - 1][m - 1][1][1]);
	}

    return 0;
}