#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <cmath>
#include <string>

using namespace std;

double f[100], d[100];
int N, C;

double count(int n, int m)
{
	double ret = 1;
	for (int i = 1; i <= m; ++i)
	{
		ret *= (n - i + 1);
		ret /= i;
	}
	return ret;
}

int	main()
{
	//freopen("input.txt", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int task;
	cin >> task;
	for (int nowCase = 0; nowCase < task; ++nowCase)
	{
		cin >> C >> N;
		f[C] = 0;
		for (int i = C - 1; i >= N; --i)
		{
			f[i] = 0;
			for (int j = i + 1; j <= i + N && j <= C; ++j)
				f[i] += f[j] * count(C - i, j - i) * count(i, N - (j - i)) / count(C, N);
			f[i] = (f[i] + 1) / (1 - count(i, N) / count(C, N));
		}
		printf("Case #%d: %.10lf\n", nowCase + 1, f[N] + 1);
	}
	
	return 0;
}