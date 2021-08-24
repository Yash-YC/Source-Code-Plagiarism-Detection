#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int Base[10];
char Buf[100];
int Have[12][1048576];

int Check(int i, int Base)
{
	int Cur = 0;
	if (i == 1)
		return 1;
	if (i < 1048576 && Have[Base][i])
		return (Have[Base][i] == 1) ? 1 : 0;
	if (i < 1048576)
		Have[Base][i] = 2;
	int t = i;
	while (i)
	{
		Cur += (i % Base) * (i % Base);
		i /= Base;
	}
	if (t < 1048576)
	{
		Have[Base][t] = Check(Cur, Base) ? 1 : 2;
		return (Have[Base][t] == 1) ? 1 : 0;
	}
	return Check(Cur, Base);
}

int Work()
{
	fgets(Buf, 100, stdin);
	istringstream In((string) Buf);
	int T;
	N = 0;
	while (In >> T)
		Base[N ++] = T;
	sort(Base, Base + N);
	if (N == 9)
		return 11814485;
	if (N == 8)
	{
		int Ans[] = {0, 0, 11814485, 11814485, 11814485, 4817803, 346719, 28099, 711725, 2688153, 569669};
		for (int j = 2; j <= 10; j ++)
		{
			int Have = 0;
			for (int i = 0; i < N; i ++)
				if (Base[i] == j)
					Have = 1;
			if (! Have)
				return Ans[j];
		}
	}
	for (int i = 2; ; i ++)
	{
		int OK = 1;
		for (int j = 0; j < N; j ++)
			if (! Check(i, Base[j]))
			{
				OK = 0;
				break;
			}
		if (OK)
			return i;
	}
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	fgets(Buf, 100, stdin);
	for (int Case = 1; Case <= Cases; Case ++)
		printf("Case #%d: %d\n", Case, Work());
	return 0;
}
