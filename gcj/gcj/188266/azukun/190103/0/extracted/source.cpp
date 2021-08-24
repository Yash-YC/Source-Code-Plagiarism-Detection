#define _USE_MATH_DEFINES
#include <numeric>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning(disable : 4996 4018)
#pragma comment(linker, "/STACK:16777216")

int P[11][11];
int Perm(int a, int b)
{
	if(!a)
		return 1;
	if(a == b)
		return 1;
	if(a == 1)
		return b;
	if(P[a][b])
		return P[a][b];
	return P[a][b] = Perm(a - 1, b - 1) + Perm(a, b - 1);
}

double Prob(int N, int C, int R, int x)
{
	return 1. * Perm(N - x, R) * Perm(x, C - R) / Perm(N, C);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N, C;
		cin >> C >> N;

		double DP[11][10001] = {};
		DP[N][1] = 1;

		int i, j, k, l;
		for(j = 1; j < 10000; j++)
		{
			for(i = N; i < C; i++)
			{
				for(k = min(N, C - i); k >= 0; k--)
				{
					DP[i + k][j + 1] += DP[i][j] * Prob(N, C, i, k);
				}
			}
		}

		double s = 0;
		for(j = 1; j <= 10000; j++)
			s += DP[C][j] * j;
		printf("Case #%i: %lf\n", t + 1, s);
	}

	return 0;
}
