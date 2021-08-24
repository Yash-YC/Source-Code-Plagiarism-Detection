#include <cstdio>
#include <cstdlib>
#include <set>
using std::set;

int x[15], lx;
void readln()
{
	char line[35], *p;
	gets(line);
	p = line;
	lx = 0;
	while (*p)
		x[lx++] = strtol(p, &p, 10);
	//for (int i = 0; i < lx; ++i)
	//	printf("%d ", x[i]);
	//printf("\n");
}

int digit_sqr(int n, int base)
{
	int p, sum = 0;
	while (n)
	{
		p = n % base;
		sum += p * p;
		n /= base;
	}
	return sum;
}

bool ishappy(int n, int base)
{
	set<int> has;
	while (true)
	{
		if (has.find(n) != has.end())
			return false;
		has.insert(n);
		n = digit_sqr(n, base);
		if (n == 1)
			return true;
	}
}


int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int t, tcs, n, i;
	bool happy;
	scanf("%d", &t);
	getchar();
	
	for (tcs = 1; tcs <= t; ++tcs)
	{
		readln();
		for (n = 2; true; ++n)
		{
			for (i = 0; i < lx; ++i)
				if (!ishappy(n, x[i]))
					break;
			if (i == lx)
			{
				printf("Case #%d: %d\n", tcs, n);
				break;
			}
		}
	}
	
	return 0;
}
