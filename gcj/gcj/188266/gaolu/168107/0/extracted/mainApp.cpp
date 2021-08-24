#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUM 10000
int happynum[11][MAXNUM];

int res[100];
int order[100];

char src[30];
int base[10];
int ptr[11];

void input()
{
	int i, k, length;
	k = 0;
	gets(src);
	length = strlen(src);
	for (i = 0; i < length; ++i)
	{
		if (src[i] == '1')
		{
			++i;
			base[k++] = 10;
		}
		else
		{
			base[k++] = src[i] - '0';
		}
		++i;
	}
	base[k] = -1;
}

void solve(int index)
{
	int i, min, max, minN, maxN, flag;
	for (i = 0; i < 11; ++i)
	{
		ptr[i] = -1;
	}
	i = 0;
	while(base[i] != -1)
	{
		ptr[base[i]] = 0;
		++i;
	}
	flag = 1;
	while (flag)
	{
		min = 100000; max = 0;
		minN = 0; maxN = 0;
		for (i = 2; i < 11; ++i)
		{
			if (ptr[i] == -1)
			{
				continue;
			}
			if (happynum[i][ptr[i]] <= min)
			{
				min = happynum[i][ptr[i]];
				minN = i;
			}
			if (happynum[i][ptr[i]] >= max)
			{
				max = happynum[i][ptr[i]];
				maxN = i;
			}
		}
		if (min == max)
		{
			printf("Case #%d: %d\n", index, min);
			flag = 0;
		}
		ptr[minN] ++;
		if (ptr[minN] > MAXNUM)
		{
			printf("Case #%d: error\n", index);
			flag = 0;
		}
	}
}

int trans(int base, int number)
{
	int i = 0;
	while (number != 0)
	{
		order[i++] = number % base;
		number /= base;
	}
	order[i] = -1;
	return i;
}

int calc(void)
{
	int i = 0, res = 0;
	while (order[i] != -1)
	{
		res += order[i] * order[i];
		++i;
	}
	return res;
}

int judge(int base, int number)
{
	int i, k;
	trans(base, number);
	res[0] = calc();
	k = 0;
	while (1)
	{
		if (res[k] == 1)
		{
			return 1;
		}
		for (i = 0; i < k; ++i)
		{
			if (res[i] == res[k])
			{
				return 0;
			}
		}
		trans(base, res[k]);
		res[++k] = calc();
	}
}

int main(void)
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k, T;
	scanf("%d", &T);
	for (i = 2; i <= 10; ++i)
	{
		j = 2;
		k = 0;
		while (k < MAXNUM)
		{
			if (judge(i, j) == 1)
			{
				happynum[i][k++] = j;
			}
			++j;
		}
	}
	gets(src);
	for (i = 0; i < T; ++i)
	{
		input();
		solve(i + 1);
	}
	return 0;
}
