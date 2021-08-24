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
    freopen("A.in","r",stdin);
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

const int SMAX = 10000;
bool visited[SMAX];
bool good[50][SMAX];

int main()
{
    initialize();

	int T;
	scanf("%d", &T);gets(str);
	for (int t = 1; t <= T; ++t)
	{
		cerr << "t = " << t << endl;
		memset(good, 0 ,sizeof(good));
		vector<int> numbers;
		int res = -1;

		gets(str); int num;
		istringstream stringIn(str);
		while (stringIn >> num)
			numbers.pb(num);

		for (int b = 0; b < numbers.size(); ++b)
		{
			memset(good[b], 0, sizeof(good[b]));
			for (int i = 2; i < SMAX; ++i)
			{
				memset(visited, 0, sizeof(visited));
				int num = i;
				while (!visited[num])
				{
					visited[num] = true;
					num = dig_sum(num, numbers[b]);
				}
				if (num == 1) good[b][i] = true;
			}
		}
		for (int i = 0; i < SMAX; ++i)
		{
			bool ok = true;
			for (int j = 0; j < numbers.size() && ok; ++j)
				if (!good[j][i]) ok = false;
			if (ok)
			{
				res = i;
				break;
			}
		}

		if (res == -1)
		{
			for (int i = SMAX; ;++i)
			{
				bool ok = true;
				for (int j = numbers.size() - 1; j >= 0 && ok; --j)
					if (!good[j][dig_sum(i, numbers[j])]) ok = false;
				if (ok)
				{
					res = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", t, res);
	}

    return 0;
}