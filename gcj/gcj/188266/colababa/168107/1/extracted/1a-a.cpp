// 1a-a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <vector>
#include <hash_set>

using namespace std;
using namespace stdext;

const int MaxT = 500;

typedef set<int> HappyPerBase;
HappyPerBase happyPerBase[11];
int calculated = 1;

int nextValue(int value, int base)
{
	int sum = 0;

	while (value != 0)
	{
		sum += (value % base) * (value % base);
		value /= base;		
	}
	return sum;
}

void calculateMore(int calculateTo)
{
	for (int base = 2; base <= 10; base++)
	{
		for (int i = calculated + 1; i <= calculateTo; i++)
		{
			hash_set<int> visited;
			int value = i;
			while (value != 1)
			{
				value = nextValue(value, base);
				if (visited.find(value) != visited.end())
					break;
				visited.insert(value);
			}
			if (value == 1)
			{
				happyPerBase[base].insert(i);
			}
		}
	}
	calculated = calculateTo;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	scanf("%d\n", &t);

	calculateMore(100);

	for (int ti = 1; ti <= t; ti++)
	{
		char line[512];
		gets(line);
		vector<int> bases;
		char* token = strtok(line, " \r\n");

		bases.clear();
		while (token)
		{
			bases.push_back(atoi(token));

			token = strtok(NULL, " \r\n");
		}

		int v = 2;
		while (1)
		{
			bool all = true;
			for (int bii = 0; bii < (int)bases.size(); bii++)
			{
				int base = bases[bii];
				HappyPerBase::iterator it = happyPerBase[base].lower_bound(v);
				if (it == happyPerBase[base].end())
				{
					calculateMore(calculated * 2);
					all = false;
					break;
				}
				int vv = *it;
				if (vv != v)
				{
					v = vv;
					all = false;
					break;
				}
			}
			if (all)
			{
				printf("Case #%d: %d\n", ti, v);
				break;
			}
		}
	}

	return 0;
}
