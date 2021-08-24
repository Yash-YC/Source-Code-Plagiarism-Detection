#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-7;

int C, N;

double lg[41];
double c(int x, int y) {
	double res = 0.0;
	for (int i = y + 1; i <= x; ++i)
		res += lg[i];
	for (int i = 2; i <= x - y; ++i)
		res -= lg[i];
	return res;
}

double f[41];
double solve() {
	f[C] = 0.0;
	for (int i = C - 1; i >= 0; --i) {
		f[i] = 1.0;
		double r = 1.0;
		for (int j = i + 1; j <= min(C, i + N); ++j) {
			if (i + j < N)
				continue;
			double r0 = exp(c(C - i, j - i) + c(i, N - (j - i)) - c(C, N));
			f[i] += r0 * f[j];
			r -= r0;
		}
		f[i] /= (1.0 - r);
	}

	return f[0];
}

int main() {
	for (int i = 1; i <= 40; ++i)
		lg[i] = log((double)i);
	int T;
	scanf("%d", &T);
	for (int tId = 1; tId <= T; ++tId) {
		scanf("%d %d", &C, &N);
		printf("Case #%d: %.8lf\n", tId, solve());
	}
	return 0;
}


