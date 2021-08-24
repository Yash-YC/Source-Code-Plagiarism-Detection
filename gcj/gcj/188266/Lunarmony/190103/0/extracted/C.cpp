#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-7;

int C, N, cnt;
int lst[1000];

void search(int now, int taken, int cur) {
	if (now == C) {
		lst[cnt++] = cur;
		return;
	}
	if (taken < N)
		search(now + 1, taken + 1, cur | (1 << now));
	if (C - now - 1 >= N - taken)
		search(now + 1, taken, cur);
}

double f[1024][1024], b[1024];

double solve() {
	cnt = 0;
	search(0, 0, 0);
	double p = -1.0 / (double)cnt;
	for (int i = 0; i < (1 << C) - 1; ++i) {
		for (int j = 0; j < (1 << C); ++j)
			f[i][j] = 0.0;
		f[i][i] = 1.0;
		b[i] = 1.0;
		for (int k = 0; k < cnt; ++k)
			f[i][i | lst[k]] += p;
	}
	for (int i = 0; i < (1 << C); ++i)
		f[(1 << C) - 1][i] = 0.0;
	f[(1 << C) - 1][(1 << C) - 1] = 1.0;
	b[(1 << C) - 1] = 0.0;
	
	for (int i = 0; i < (1 << C); ++i) {
		double bestVal = fabs(f[i][i]);
		int bestRow = i;
		for (int j = i + 1; j < (1 << C); ++j)
			if (fabs(f[j][i]) > bestVal + EPS) {
				bestVal = fabs(f[j][i]); 
				bestRow = j;
			}
		if (bestRow != i) {
			for (int j = 0; j < (1 << C); ++j)
				swap(f[bestRow][j], f[i][j]);
			swap(b[bestRow], b[i]);
		}

		double factor = f[i][i];
		for (int j = 0; j < (1 << C); ++j)
			f[i][j] /= factor;
		b[i] /= factor;

		for (int j = i + 1; j < (1 << C); ++j)
			if (fabs(f[j][i]) > EPS)
			{
				double mul = -f[j][i];
				for (int k = 0; k < (1 << C); ++k)
					f[j][k] += mul * f[i][k];
				b[j] += mul * b[i];
			}
	}
	
	for (int i = (1 << C) - 1; i >= 0; --i) {
		b[i] /= f[i][i]; f[i][i] = 1.0;
		for (int j = i - 1; j >= 0; --j)
			if (fabs(f[j][i]) > EPS) {
				b[j] -= f[j][i] * b[i];
				f[j][i] = 0.0;
			}
	}

	return b[0];
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tId = 1; tId <= T; ++tId) {
		scanf("%d %d", &C, &N);
		printf("Case #%d: %.8lf\n", tId, solve());
	}
	return 0;
}


