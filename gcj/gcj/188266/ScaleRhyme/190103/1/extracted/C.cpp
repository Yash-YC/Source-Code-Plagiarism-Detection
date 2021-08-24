
	#include <stdio.h>
	#include <stdlib.h>
	#include <algorithm>
	using namespace std;

	double f[45], p[45];
	int n, c;

	void work()
	{
		f[c] = 0;
		for (int i = c - 1; i >= 0; i --)
		{
			f[i] = 1;
			p[0] = 0;
			for (int j = 0; j <= n; j ++)
				if (j <= c - i && n - j <= i)
				{
					p[j] = 1;
					for (int k = 1; k <= j; k ++)
						p[j] *= (double)(c - i - k + 1) / k;
					//printf("%d %d %.8lf\n", i, j, p[j]);
					for (int k = 1; k <= n - j; k ++)
						p[j] *= (double)(i + 1 - k) / k;
				//	printf("%d %d %.8lf\n", i, j, p[j]);
					for (int k = 1; k <= n; k ++)
						p[j] *= (double)k / (c + 1 - k);
					//printf("%d %d %.8lf\n", i, j, p[j]);
					if (j > 0)
						f[i] += p[j] * f[i + j];
					//printf("%d %d %.8lf\n", i, j, p[j]);
				}
			f[i] /= (1 - p[0]);
			//printf("	%.8lf\n", f[i]);
		}
		printf("%.8lf\n", f[0]);
	}

	int main(int argc, char *argv[])
	{
		int T;
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
		scanf("%d", &T);
		for (int i = 0; i < T; i ++)
		{
			scanf("%d%d", &c, &n);
			printf("Case #%d: ", i + 1);
			work();
		}
		return 0;
	}
