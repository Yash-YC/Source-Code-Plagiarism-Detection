#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

double dp[50];
long long C[40][40];

/*double C(double n, double k)
{
	printf("n = ")
	double ans = 1;
	for(int i = 0; i < k; i++){
		ans *= ((n - 1.0 * i) / (k - 1.0 * i));
	}
}*/

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("check.txt", "w", stdout);
	C[0][0] = 1;
	for(int i = 1; i <= 45; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	int n, m, T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++)
	{
		scanf("%d%d", &m, &n);
		dp[m] = 0;
		for(int t = m - 1; t >= 0; t--){
			dp[t] = 0;
			for(int x = 1; x <= m - t && x <= n; x++){
				double p = 1.0 * C[t][n] / C[m][n], q = 1.0 * C[t][n - x] * C[m - t][x] / C[m][n];
				dp[t] += (q / ((1 - p) * (1 - p)) + q * dp[t + x] / (1 - p));
			}
		}
		printf("Case #%d: %.6f\n", ca, dp[0]);
	}
	fclose(stdout);
	return 0;
}



