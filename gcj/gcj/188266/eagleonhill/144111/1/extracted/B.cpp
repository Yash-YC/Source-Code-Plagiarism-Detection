#include <cstdio>
#include <cstring>

int s[30][30], w[30][30], t[30][30], vis[60][60];
long long dis[60][60];
int Test;

long long getsn(int x, int y, long long curt)
{
	if ((curt - t[x][y]) % (s[x][y] + w[x][y]) < s[x][y])
		return curt;
	else
	{
		long long a = (curt - t[x][y]) / (s[x][y] + w[x][y]) + 1;
		return a * (s[x][y] + w[x][y]) + t[x][y];
	}
}

long long getew(int x, int y, long long curt)
{
	if ((curt - t[x][y]) % (s[x][y] + w[x][y]) >= s[x][y])
		return curt;
	else
	{
		long long a = (curt - t[x][y]) / (s[x][y] + w[x][y]);
		return a * (s[x][y] + w[x][y]) + t[x][y] + s[x][y];
	}
}

void work()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%d%d%d", &s[i][j], &w[i][j], &t[i][j]);
			t[i][j] %= (s[i][j] + w[i][j]);
			t[i][j] -= s[i][j] + w[i][j];
		}
	memset(dis, 0x3f, sizeof(dis));
	int p = (n * 2 - 1) << 16;
	dis[n * 2 - 1][0] = 0;
	memset(vis, 0, sizeof(vis));
	while (p < (n * 2 + 1) << 16)
	{
		int x = p >> 16, y = p & 0xFFFF;
	//	fprintf(stderr, "%d:%d  ", x, y);
		vis[x][y] = 1;
		long long tmp;
		tmp = dis[x][y] + 2;
		if (x & 1)
		{
			if (x + 1 < n * 2 && dis[x + 1][y] > tmp)
				dis[x + 1][y] = tmp;
		}
		else
		{
			if (x - 1 >= 0 && dis[x - 1][y] > tmp)
				dis[x - 1][y] = tmp;
		}
		if (y & 1)
		{
			if (y + 1 < m * 2 && dis[x][y + 1] > tmp)
				dis[x][y + 1] = tmp;
		}
		else
		{
			if (y - 1 >= 0 && dis[x][y - 1] > tmp)
				dis[x][y - 1] = tmp;
		}

		tmp = getsn(x / 2, y / 2, dis[x][y]) + 1;
		if (dis[x ^ 1][y] > tmp)
			dis[x ^ 1][y] = tmp;
		tmp = getew(x / 2, y / 2, dis[x][y]) + 1;
		if (dis[x][y ^ 1] > tmp)
			dis[x][y ^ 1] = tmp;

		int nx = n * 2 + 1, ny = 0;
		for (int i = 0; i < 2 * n; ++i)
			for (int j = 0; j < 2 * m; ++j)
				if (!vis[i][j] && dis[i][j] < dis[nx][ny])
				{
					nx = i; ny = j;
				}
		p = nx << 16 | ny;
	}
	printf("Case #%d: %lld\n", ++Test, dis[0][m * 2 - 1]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		work();
}
