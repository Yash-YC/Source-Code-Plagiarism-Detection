#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

bool check(int num, int d)
{
	vector <int> seq;
	
	while (num > 1)
	{
		for (int i = 0; i < seq.size(); ++i)
			if (seq[i] == num) return false;
		seq.push_back(num);
		int next = 0;
		while (num > 0)
		{
			int mod = num % d;
			next += mod * mod;
			num /= d;
		}
		num = next;
	}
	return true;
}

int main()
{
	int T;

	char s[1005];
	fgets(s, 1000, stdin);
	istringstream sin(s);
	sin >> T;

	for (int q = 1; q <= T; ++q)
	{
		vector<int> a;
		int tmp;

		fgets(s, 1000, stdin);
		istringstream sin(s);
		while (sin >> tmp) a.push_back(tmp);

		for (int i = 2; ; ++i)
		{
			bool isOK = true;
			for (int j = 0; j < a.size(); ++j)
				if (!check(i, a[j]))
				{
					isOK = false;
					break;
				}

			if (isOK)
			{
				printf("Case #%d: %d\n", q, i);
				break;
			}
		}
	}


	return 0;
}

