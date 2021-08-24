#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <vector>
#include <deque>
#include <cmath>
#include <string>

using namespace std;

const int M_LIMIT = 1000;
int state[11][M_LIMIT];

inline int count(int b, int n)
{
	int s = 0; 
	for (int x = n; x > 0; x /= b)
		s += (x % b) * (x % b);
	return s;
}

int dfs(int b, int n)
{
	if (n == 1) return 1;
	if (state[b][n]) return state[b][n];
	state[b][n] = -1;
	state[b][n] = dfs(b, count(b, n));
}

int	main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("A-small-attempt0 (1).in", "r", stdin);
	//freopen("a_small.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("a_large.out", "w", stdout);

	memset(state, 0, sizeof(state));
	for (int i = 2; i <= 10; ++i)
		for (int j = 1; j < M_LIMIT; ++j)
			if (!state[i][j]) dfs(i, j);

	char buffer[1000];
	int task;
	gets(buffer);
	sscanf(buffer, "%d", &task);
	for (int nCase = 0; nCase < task; ++nCase)
	{
		gets(buffer);
		istringstream is(buffer);

		int n = 0;
		int x;
		int base[20];
		while (is >> x) base[n++] = x;

		for (x = 2; ; ++x)
		{
			int pass = true;
			for (int j = 0; pass && j < n; ++j) if (state[base[j]][count(base[j], x)] < 0) pass = 0;
			if (pass) break;
		}
		printf("Case #%d: %d\n", nCase + 1, x);
	}
	return 0;
}