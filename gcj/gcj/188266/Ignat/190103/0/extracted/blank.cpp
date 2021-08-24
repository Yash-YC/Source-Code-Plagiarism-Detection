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
    freopen("c0.in","r",stdin);
    freopen("output.txt","w",stdout);
}

const int MAX = 50, NMAX = 100000;
double res[MAX][NMAX];
double C[MAX][MAX];
int n, c;

double Prob(int a, int b)
{
	return C[n - a][b - a] * C[a][c - (b - a)] / C[n][c];
}

int main()
{
    initialize();

	C[0][0] = 1.0;
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j > 0) C[i][j] += C[i - 1][j - 1];
			if (j < i) C[i][j] += C[i - 1][j];
		}
	}

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d%d", &n, &c);
		res[0][0] = 1;
		for (int i = 1; i <= n; ++i)
		{	
			for (int j = 1; j < NMAX; ++j)
			{
				res[i][j] = 0.0;
				for (int k = i - 1; k >= 0; --k)
					res[i][j] += res[k][j - 1] * Prob(k, i);
				if (i < n && i >= c)
					res[i][j] += res[i][j - 1] * Prob(i, i);
			}
		}

		double r = 0.0;
		for (int i = 0; i < NMAX; ++i)
			r += res[n][i] * i;
		printf("Case #%d: %.10lf\n", t, r);
	}

    return 0;
}