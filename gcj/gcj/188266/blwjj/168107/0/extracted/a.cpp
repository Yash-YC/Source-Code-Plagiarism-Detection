#include <iostream>

using namespace std;

bool used[1000000];
bool check(int i, int j)
{
	memset(used, 0, sizeof(used));
	int a[15];
	int k = 0;
	int now , next;
	used[j] = 1;
	while(j)
	{
		a[k ++] = j % i;
		j /= i;
	}
	while(1)
	{
		k --;
		now = 0;
		while(k >= 0)
		{
			now += a[k] * a[k];
			k --;
		}

		if(used[now])
			return false;
		used[now] = 1;
		if(now == 1)
			return true;
		k = 0;
		while(now)
		{
			a[k ++] = now %i;
			now /= i;
		}
	}
}

char str[1000];
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int base, i , j , tt, k ,Test = 1;
	int bb[15];
	scanf("%d",&tt);
	getchar();
	while(tt --)
	{
		gets(str);
		k = 0;
		int num = 0;
		for(i = 0; str[i] != '\0'; i ++)
		{
			if(str[i] == ' ')
			{
				bb[k ++] = num;
				num = 0;
			}
			else
			{
				num = num * 10 + str[i] - '0';
			}
		}
		if(num != 0)
			bb[k ++] = num;

		for(j = 2; ; j ++)
		{
			for(i = 0; i < k; i ++)
			{
				if(check(bb[i], j) == 0)
					break;
			}
			if(i == k)
			{
				break;
			}
		}
		printf("Case #%d: %d\n", Test ++, j);
	}

	return 0;
}
