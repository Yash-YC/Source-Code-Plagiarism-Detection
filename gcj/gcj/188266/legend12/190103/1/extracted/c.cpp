#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXCARD 100000

using namespace std;

FILE *fp_r, *fp_w;
int t, n, c;
long long combi[41][41];
double p[MAXCARD + 1][41];

int main() {
	fp_r = fopen("c.in", "r");
	fp_w = fopen("c.out", "w");

	memset(combi, 0, sizeof(combi));
	combi[0][0] = 1;
	for(int i = 1; i < 41; ++i) {
		combi[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
	}

	fscanf(fp_r, "%d", &t);
	for(int i = 0; i < t; ++i) {
		fscanf(fp_r, "%d %d", &n, &c);

		memset(p, 0, sizeof(p));
		p[0][n] = 1.0;

		for(int j = 0; j < MAXCARD; ++j) {
			for(int k = 1; k <= n; ++k) {
				for(int l = 0; l <= min(k, c); ++l) {
					if (c - l <= n - k) {
						p[j+1][k-l] += p[j][k] * combi[k][l] / combi[n][c] * combi[n-k][c-l];
					}
				}
			}
		}

		double sum = 0.0;
		for(int j = 0; j < MAXCARD; ++j) {
			sum += p[j][0] * j;
		}
	
		fprintf(fp_w, "Case #%d: %.7lf\n", i+1, sum);
	}

	fclose(fp_w);
	fclose(fp_r);	

	return 0;
}