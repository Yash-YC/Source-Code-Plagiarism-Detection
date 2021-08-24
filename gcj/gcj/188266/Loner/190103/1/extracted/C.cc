#include <cstdio>
#include <cstring>

int N, K;
double C[45][45];

double dp[45];

double calc( int p, int q )
{
	if (q > K) return 0;

	return C[p][K - q] * C[N - p][q] / C[N][K]; 
}

int main( void )
{
//	freopen( "C.in", "r", stdin );

	int prob, nprob; scanf( "%d", &nprob );

	memset(C, 0, sizeof(C));
	for( int i = 0; i <= 40; ++i ) {
		C[i][0] = 1.0;
		for( int j = 1; j <= i; ++j )
			C[i][j] = C[i-1][j-1] + C[i-1][j];
	}

	for( prob = 0; prob < nprob; ) {
		scanf( "%d %d", &N, &K );

		memset(dp, 0, sizeof(dp));
		dp[N] = 0.0;

		for( int i = N-1; i >= K; --i ) {
			double value = 1.0;

			for( int j = i+1; j <= i+K && j <= N; ++j ) {
				value += calc(i, j-i) * dp[j]; 
			}

			dp[i] = value / (1 - calc(i, 0));
		}

		printf( "Case #%d: %.6lf\n", ++prob, dp[K] + 1.0 );
	}

	return 0;
}


