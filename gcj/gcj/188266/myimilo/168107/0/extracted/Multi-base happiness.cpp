#include <stdio.h>
#include <string.h>

int n;
char flag[11][100000];
char line[1000];
int bases[10];
int b_cnt;

void happy_in_base(int num, int base)
{
	bool f = false;
	flag[base][num] = -1;
	int m = 0;
	int num2 = num;
	while (num2)
	{
		m += (num2 % base) * (num2 % base);
		num2 /= base;
	}
	while (flag[base][m] == 0)
	{
		flag[base][m] = -1;
		num2 = m;
		m = 0;
		while (num2)
		{
			m += (num2 % base) * (num2 % base);
			num2 /= base;
		}
	}

	if (flag[base][m] == 1)
	{
		flag[base][num] = 1;
		m = 0;
		num2 = num;
		while (num2)
		{
			m += (num2 % base) * (num2 % base);
			num2 /= base;
		}
		while (flag[base][m] == -1)
		{
			flag[base][m] = 1;
			num2 = m;
			m = 0;
			while (num2)
			{
				m += (num2 % base) * (num2 % base);
				num2 /= base;
			}
		}
	}
}

int init()
{
	memset(flag, 0, sizeof(flag));
	for (int i = 2; i <= 10; i++)
	{
		flag[i][1] = 1;
		for (int j = 2; j < 100000; j++)
		{
			if (flag[i][j] != 0)
			{
				continue;
			}
			happy_in_base(j, i);
		}
	}
}

int main()
{
	init();
	/*
	for (int i = 2; i < 11; i++)
	{
		printf("base %d:\n", i);
		for (int j = 1; j < 200; j++)
		{
			if (flag[i][j] == 1)
			{
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	*/
	scanf("%d", &n);
	int n2 = n;
	gets(line);
	while (n--)
	{
		gets(line);
		char *p = line;
		b_cnt = 0;
		while (*p >= '0' && *p <= '9')
		{
			sscanf(p, "%d", bases + b_cnt);
			b_cnt++;
			while (*p >= '0' && *p <= '9')
			{
				p++;
			}
			if (*p == ' ')
			{
				p++;
			}
		}
		/*
		printf("%d : ", b_cnt);
		for (int i = 0; i < b_cnt; i++)
		{
			printf("%d ", bases[i]);
		}
		*/
		int i, j;
		for (i = 2; i < 100000; i++)
		{
			for (j = 0; j < b_cnt; j++)
			{
				int base = bases[j];
				if (flag[base][i] != 1)
				{
					break;
				}
			}
			if (j == b_cnt)
			{
				break;
			}
		}
		printf("Case #%d: %d\n", n2-n, i);
	}
}
