#include <stdio.h>
#include <string.h>
int flag[18000000];
int isHappy(int n, int b)
{
	if (n == 1)
		return 1;
	if (flag[n] & (1 << b))
		return 1;
	if (flag[n] & (1 << (b + 10)))
		return 0;
	flag[n] |= (1 << (b + 10)); 
	int tot = 0, tn = n;
	while (tn)
	{
		tot += (tn % b) * (tn % b);
		tn /= b;
	}
	if (isHappy(tot, b))
	{
		flag[n] |= 1 << b;
		flag[n] &= ~(1 << (b + 10));
		return 1;
	}
	else
	{
		return 0;
	}
}
void print(int n)
{
	if (n == 1)
		printf("1");
	else
	{
		print(n / 2);
		printf("%d", n % 2);
	}
}
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("ans.txt", "w", stdout);
	memset(flag, 0, sizeof(flag));
	int i, j;
	for (i = 2; i < (1 << 20); i++)
		for (j = 2; j <= 10; j++)
			if (isHappy(i, j))
				flag[i] |= 1 << j;
	//print(flag[3]);
	//printf("\n");
	int T;
	scanf("%d\n", &T);
	int tcnt = 1;
	while (T--)
	{
		int base = 0;
		int cur = 0;
		char chr;
		while (scanf("%c", &chr) != EOF && chr != '\n')
		{
			if (chr >= '0' && chr <= '9')
				cur = cur * 10 + chr - '0';
			else
			{
				base |= 1 << cur;
				cur = 0;
			}
		}
		base |= 1 << cur;
		//print(base);
		for (i = 2; i <= (1 << 20); i++)
			if ((flag[i] & base) == base)
				break;
		printf("Case #%d: %d\n", tcnt, i);
		tcnt++;
	}
	return 0;
}
