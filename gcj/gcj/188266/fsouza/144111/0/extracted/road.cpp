#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int n2, m2;
int city[16][16][4];
int mintime[16][16];

int delay(int y, int x, int y2, int x2, int thetime)
{
	if (y > y2)
		swap(y, y2);
	if (x > x2)
		swap(x, x2);

	if (x == x2 && (y%2) == 0)
		return 2;
	if (y == y2 && (x%2) == 0)
		return 2;
	
	int values[4];

	memcpy(values, city[(y-1)/2][(x-1)/2], sizeof(int)*4);

	while (values[2] >= 0)
		values[2] -= (values[0] + values[1]);

	int t = values[2], st = 0;

	while ((t+values[st]) <= thetime || ((st == 0 && x != x2) || (st == 1 && y != y2))) {
		t += values[st];
		st ^= 1;
	}

	return max(t - thetime, 0) + 1;
}

void go(int y, int x, int thetime)
{
	if (mintime[y][x] != -1 && thetime >= mintime[y][x])
		return;
	mintime[y][x] = thetime;

	const int ndir = 4, dirs[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
	for (int d = 0; d < ndir; d++) {
		int y2 = y+dirs[d][0], x2 = x+dirs[d][1];

		if (0 < y2 && y2 < n2-1 && 0 < x2 && x2 < m2-1)
			go(y2, x2, thetime + delay(y, x, y2, x2, thetime));
	}
}

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);

	for (int t = 0; t < ntest; t++) {
		scanf("%d %d", &n, &m);
		n2 = (n+1)*2;
		m2 = (m+1)*2;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				for (int k = 0; k < 3; k++)
					scanf("%d", &city[y][x][k]);

		memset(mintime, -1, sizeof(mintime));

		go(n2-2, 1, 0);

		printf("Case #%d: %d\n", t+1, mintime[1][m2-2]);
	}

	return 0;
}
