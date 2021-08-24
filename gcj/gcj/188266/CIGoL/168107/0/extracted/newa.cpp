#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#ifndef ONLINE_JUDGE
int poj();
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	poj();
	return 0;
}
#define main poj
#endif

#define clr(x) memset(x, 0, sizeof(x))
#define MAXINT 200000000
#define EPS 0.00000001
#define MAXN 500000

int blist[20];
//bool exist[1000000];
int fu[20][2000000];
int big , bb;

int change(int n, int base)
{
	int i, result = 0, t;
	while (n)
	{
		t = n % base;
		result += t * t;
		n /= base;
	}
	return result;
}

int dfs(int n)
{
	int t;
	if (fu[bb][n] == 2) return -1;
	if (fu[bb][n] == 1 || fu[bb][n] == -1)
	{
		return fu[bb][n];
	}
	fu[bb][n] = 2;
	//exist[n] = 1;
	fu[bb][n] = dfs(change(n,bb));
	return fu[bb][n];
}

int main()
{
	int tcase, i, j, now, base, t, bn, num;
	char buf[1000], str[1000];
	
	
	for (i = 2; i <= 10; i++)
	{
		fu[i][1] = 1;
		//printf("BASE %d:\n", i);
		for (j = 2; j <= MAXN; j++)
		{
			if (!fu[i][j])

			big = j;
			bb = i;
			dfs(j);
			//if (fu[i][j] == 1) printf("%d ", j);
		}
		//printf("\n");
	}
	//return 0;
	scanf("%d\n", &tcase);
	num = 0;
	while (tcase--)
	{
		num++;
		fgets(buf, 900, stdin);
		now = 0;
		bn = 0;
		while (sscanf(now + buf, "%s", str) == 1)
		{
			//printf("%s\n", str);
			//printf("%s", str);
			sscanf(str, "%d", &base);
			blist[bn++] = base;
			now += (strstr(now + buf, str) - (now + buf)) + strlen(str);
		}/*
		now = 2;
		for (i = 0; i < bn; i++)
			printf("%d\n", blist[i]);
		continue;*/
		now = 2;
		while (1)
		{
			for (i = 0; i < bn; i++)
			{
				if (fu[blist[i]][now] != 1) break;
				else
				{
					big = MAXN;
					bb = blist[i];
					if (dfs(now) == -1) break;
				}
			}
			if (i == bn)
			{
				printf("Case #%d: %d\n", num, now);
				break;
			}
			else now++;
		}
	}
	
	return 0;
}
