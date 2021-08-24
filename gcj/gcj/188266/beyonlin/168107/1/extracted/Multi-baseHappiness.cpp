#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 12814485;
bool happy[maxn][12];
bool flag[1000];
char str[64];
int b[10];
int size;
bool isHappy(int n, int base)
{
	memset(flag, 0, sizeof(flag));
	while (true)
	{
		if (happy[n][base])
		{
			return true;
		}

		itoa(n, str, base);
		int i = 0, t = 0;
		while (str[i])
		{
			t += (str[i] - '0') * (str[i] - '0');
			i++;
		}
		n = t;
		if (flag[n])
		{
			return false;
		}
		flag[n] = true;
	}
	return n == 1;
}

int main()
{
	int i, j, c = 0, t;
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	//freopen("in.txt", "r", stdin);
	for (j = 2; j <= 10; j++)
	{
		happy[1][j] = true;
	}

	for (i = 2; i < maxn; i++)
	{
		for (j = 2; j <= 10; j++)
		{
			if (isHappy(i, j))
			{
				happy[i][j] = true;
			}
		}
	}
	cin>>t;
	getchar();
	while (t--)
	{
		gets(str);
		stringstream ss(str);
		size = 0;
		while (ss>>b[size])
		{
			size++;
		}
		for (i = 2; i < maxn; i++)
		{
			bool bf = true;
			for (j = 0; j < size; j++)
			{
				if (!happy[i][b[j]])
				{
					bf = false;
					break;
				}
			}
			if (bf)
			{
				printf("Case #%d: %d\n", ++c, i);
				break;
			}
		}
	}
	return 0;
}
