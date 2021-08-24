#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>
using namespace std;
#define sz(c) (int)c.size()
#define pb push_back
#define all(c) c.begin(), c.end()


void initialize()
{
    freopen("a0.in","r",stdin);
    freopen("output.txt","w",stdout);
}


const int S = 10000;
char str[S];

int sqr(int num)
{
	return num * num;
}

int dig_sum(long long num, int base)
{
	int res = 0;
	while (num > 0)
	{
		res += sqr(num % base);
		num /= base;
	}
	return res;
}

const int MAX = 100000;
int good[MAX];
bool g[MAX];

const int SMAX = 1000;
bool visited[SMAX];

int main()
{
    initialize();

	int T;
	scanf("%d", &T);gets(str);
	for (int t = 1; t <= T; ++t)
	{
		memset(good, 0 ,sizeof(good));
		vector<int> numbers;

		gets(str); int num;
		istringstream stringIn(str);
		while (stringIn >> num)
			numbers.pb(num);

		good[1] = 1;
		for (int b = 0; b < numbers.size(); ++b)
		{
			memset(g, 0, sizeof(g));
			for (int i = 2; i < SMAX; ++i)
			{
				memset(visited, 0, sizeof(visited));
				int num = i;
				while (!visited[num])
				{
					visited[num] = true;
					num = dig_sum(num, numbers[b]);
				}
				if (num == 1) good[i]++, g[i] = true;
			}
			for (int i = SMAX; i < MAX; ++i)
				if (g[dig_sum(i, numbers[b])]) g[i] = true, good[i]++;
		}

		int res = -1;
		for (int i = 0; i < MAX; ++i)
		{
			if (good[i] == numbers.size())
			{
				res = i; 
				break;
			}
		}
		printf("Case #%d: %d\n", t, res);
	}

    return 0;
}