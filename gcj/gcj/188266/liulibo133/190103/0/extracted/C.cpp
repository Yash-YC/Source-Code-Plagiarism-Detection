#include<iostream>

#define N 41

using namespace std;

double pro[10000][N];
__int64 com[N][N];
int n, m;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k;
	for (i = 1; i < N; i++)
		com[i][0] = 1, com[i][i] = 1;
	for (i = 2; i < N; i++)
		for (j = 1; j < i; j++)
			com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
	int t;
	scanf("%d", &t);
	int caseID = 1;
	while (caseID <= t)
	{
		memset(pro, 0, sizeof(pro));
		scanf("%d %d", &n, &m);
		pro[1][m] = 1;
		i = 1;
		do
		{
			i++;
			for (j = m; j <= n; j++)
			{
				pro[i][j] = 0;
				for (k = 0; k <= m; k++)
					pro[i][j] += pro[i - 1][j - k] * com[j - k][m - k] * com[n - j + k][k] / com[n][m]; 
			}
		}
		while (i < 2000);
		double res = 0;
		for (j = 1; j <= i; j++)
			res += j * pro[j][n];
		printf("Case #%d: %lf\n", caseID++, res);
	}
	return 0;
}