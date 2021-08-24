#include <cstdio>
#include <cstring>
#include <cstdlib>

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

const int size = 1000;
bool used[11][size], hp[11][size];
bool ishappy(int n, int base)
{
	if (n == 1 || base == 2 || base == 4)
		return true;
		
	int bbb = base * base * base;
	while (n > bbb)
		n = digit_sqr(n, base);
	
	if (used[base][n])
		return hp[base][n];
	
	used[base][n] = true;
	return hp[base][n] = ishappy(digit_sqr(n, base), base);
}


int main()
{
	freopen("A2.in", "r", stdin);
	freopen("A2.out", "w", stdout);
	
	int t, tcs, n, i;
	bool happy;
	
	memset(used, false, sizeof(used));
	
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
