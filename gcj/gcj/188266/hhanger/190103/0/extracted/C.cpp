#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const double EPS = 1e-10;

bool gaussIt(int n, double a[][MAXN], double b[]) {
	int i, j, k, row;
	double maxp, t;
	for (k = 0; k < n; k++) {
		for (maxp = 0, i = k; i < n; i++) {
			if (fabs(a[i][k]) > fabs(maxp)) {
				maxp = a[row = i][k];
			} 
		}
		if (fabs(maxp) < EPS) {
			return false;
		}
		if (row != k) {
			for (j = k; j < n; j++) {
				t = a[k][j];
				a[k][j] = a[row][j];
				a[row][j] = t;
			}
			t = b[k];
			b[k] = b[row];
			b[row] = t;
		}
		for (j = k + 1; j < n; j++) {
			a[k][j] /= maxp;
			for (i = k + 1; i < n; i++) {
				a[i][j] -= a[i][k] * a[k][j];
			} 
		}
		b[k] /= maxp;
		for (i = k + 1; i < n; i++) {
			b[i] -= b[k] * a[i][k];
		} 
	}
	for (i = n - 1; i >= 0; i--) {
		for (j = i + 1; j < n; j++) {
			b[i] -= a[i][j] * b[j];
		} 
	}
	return true;
}

double C[64][64];

double a[MAXN][MAXN];
double b[MAXN];

double run()
{
	int n, c;
	scanf("%d %d", &n, &c);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; ++i) {
		int j = n - i;
		a[i + 1][i] = 1;
		for (int selv = 0; selv <= c; ++selv) {
			int other = c - selv;
			if (selv > i) continue;
			if (other > j) continue;
			double p = C[i][selv] * C[j][other] / C[n][c];
			a[i + 1][other + i] -= p;
		}
		b[i + 1] = -1;
	}
	a[0][0] = 1;
	b[0] = 0;
	gaussIt(n + 1, a, b);
	return b[n];
}

int main()
{
	freopen("Cin.txt", "r", stdin);
	freopen("Cout.txt", "w", stdout);
	C[0][0] = 1;
	for (int i = 1; i < 64; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: %.7lf\n", i, run());
	}
	return 0;
}