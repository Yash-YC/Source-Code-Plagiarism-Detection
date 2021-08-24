#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

double p[41][41][41][41];

int main()
{
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);
	int t;
	cin >> t;
	double cnk[41][41];
	cnk[0][0] = 1;
	for (int i = 1; i <= 40; ++i)
	{
		cnk[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
	}
	p[0][0][0][0] = 1;
	for (int i = 0; i <= 40; ++i)
		for (int j = 0; j <= 40; ++j)
			p[i][j][j][0] = 1;
	for (int i = 1; i <= 40; ++i)
		for (int c = 1; c <= i; ++c)
			for (int j = 0; j <= i; ++j)
				for (int k = j; k <= i; ++k)
					for (int l = 1; l <= i; ++l)
						if (l <= j)
							p[i][j][k][c] += p[i - l][j - l][k - l][c - 1] * cnk[i - l][c - 1] / cnk[i][c];
						else
							if (k > j)
								p[i][j][k][c] += p[i - l][0][k - j - 1][c - 1] * cnk[i - l][c - 1] / cnk[i][c];
	cout.precision(12);
	for (int T = 0; T < t; ++T)
	{
		int c, n;
		cin >> n >> c;
		double q[41] = {0};
		q[0] = 0;
		for (int i = 0; i < n; ++i)
			if (i == 0 || i >= c)
			for (int j = i+1; j <= n; ++j)
				q[j] += (q[i] + 1/(1 - p[n][i][i][c]))*p[n][i][j][c]/(1 - p[n][i][i][c]);
		cout << "Case #" << T+1 << ": " << q[n] << '\n';
	}
	return 0;
}
