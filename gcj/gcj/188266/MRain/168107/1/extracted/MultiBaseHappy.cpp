#include <cstdio>
#include <string>

int Set[12000000][12];
int List[10000];
int FNow, FWent;

int f(int a, int b)
{
	int p = 0, Sum = 0;
	while (a)
	{
		List[++ p] = a % b;
		a /= b;
	}
	for (int i = 1; i <= p; ++ i) Sum += List[i] * List[i];
	return Sum;
}

int find(int a, int b)
{
	if (Set[a][b] != a) Set[a][b] = find(Set[a][b], b);
	return Set[a][b];
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for (int i = 1; i <= 12000000; ++ i)
		for (int j = 3; j <= 10; ++ j)
			Set[i][j] = i;
	for (int j = 3; j <= 10; ++ j)
		for (int i = 2; i <= 12000000; ++ i)
		{
			FWent = find(f(i, j), j);
			FNow = find(i, j);
			Set[FNow][j] = Set[FWent][j];
		}
	int Tests;
	char Buff[1000];
	scanf("%d\n", &Tests);
	for (int Cases = 1; Cases <= Tests; ++ Cases)
	{
		gets(Buff);
		int l = strlen(Buff), p = 0, tot = 0;
		for (int i = 0; i < l; ++ i)
		{
			if (Buff[i] == ' ') List[++ tot] = p, p = 0;
			else p = p * 10 + (Buff[i] - '0');
		}
		List[++ tot] = p;
		bool found = true;
		for (int i = 2; i <= 12000000; ++ i)
		{
			found = true;
			for (int j = 1; j <= tot; ++ j)
			{
				if (List[j] == 2) continue;
				Set[i][List[j]] = find(Set[i][List[j]], List[j]);
				Set[1][List[j]] = find(Set[1][List[j]], List[j]);
				if (Set[i][List[j]] != Set[1][List[j]])
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				printf("Case #%d: %d\n", Cases, i);
				break;
			}
		}
	}
}
