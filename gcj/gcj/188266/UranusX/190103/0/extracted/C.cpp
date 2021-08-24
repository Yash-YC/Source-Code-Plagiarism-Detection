#include <cstdio>
#include <cstring>
#include <cstdlib>

int N, M;
double C[50][50];
double F[1000][50];

double Work()
{
	scanf("%d%d", &N, &M);
	memset(F, 0, sizeof(F));
	F[0][0] = 1;
	for (int R = 0; R < 1000; R ++)
		for (int i = 0; i < N; i ++)
			for (int j = 0; j <= M; j ++)
				if (j <= i && (M - j) <= (N - i))
					F[R + 1][i + (M - j)] += F[R][i] * C[i][j] * C[N - i][M - j] / C[N][M];
	double Ans = 0;
	for (int i = 0; i < 1000; i ++)
		Ans += F[i][N] * i;
	return Ans;
}

int main()
{
	C[0][0] = 1;
	for (int i = 1; i < 50; i ++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j ++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %.7lf\n", Case, Work());
	return 0;
}
