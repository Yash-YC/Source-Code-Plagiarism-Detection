#define _USE_MATH_DEFINES
#include <numeric>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
#pragma warning(disable : 4996 4018)
#pragma comment(linker, "/STACK:16777216")

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	set<int> S[11];

	for(int j = 2; j < 11; j++)
	{
		for(int i = 1; i < 50000; i++)
		{
			bool M[50000] = {};
			int x = i;
			bool f = true;
			while(x != 1)
			{
				if(M[x])
				{
					f = false;
					break;
				}
				M[x] = true;
				int s = 0;
				int y = x;
				while(y)
				{
					int d = y % j;
					s += d * d;
					y /= j;
				}
				x = s;
			}
			if(f)
			{
				S[j].insert(i);
			}
		}
	}

	char bf[1000];
	gets(bf);

	int T;
	sscanf(bf, "%i", &T);
	for(int t = 0; t < T; t++)
	{
		gets(bf);
		stringstream ss = stringstream(string(bf));
		vector<int> B;
		int b;
		while(ss >> b)
			B.push_back(b);
		int i, j;
		for(i = 2; i < 50000; i++)
		{
			for( j = 0; j < B.size(); j++)
				if(!S[B[j]].count(i))
					break;
			if(j == B.size())
				break;
		}
		printf("Case #%i: %i\n", t + 1, i);

	}


	return 0;
}
