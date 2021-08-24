// qa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

#define M 50000

bool check(int t,int b)
{
	bool has[M] = {0};

	has[t] = true;
	while (true)
	{
		int sum = 0;

		while (t != 0)
		{
			int d = t % b;
			t /= b;
			sum += d * d;
		}

		t = sum;
		if (t == 1)
			return true;

		if (has[t] == true)
			return false;
		
		has[t] = true;
	}
}

bool a[11][M];
int ba[10];
int len;

int main()
{
	freopen("e:\\s2.in","r",stdin);
	freopen("a.txt","w",stdout);
	int n;
	int ans = 0;
	int i,j;

	for (int i = 2; i < 11; i++)
	{
		for (int j = 2; j < M; j++)
		{
			a[i][j] = check(j,i);
			//printf("%d %d\n",i,j);
		}
		//printf("%d\n",i);
	}

	scanf("%d",&n);

	for (int z = 1; z <= n; z++)
	{
		char ch;
		len = 0;

		while (scanf("%d%c",&ba[len++],&ch) != EOF && ch != '\n');

		for (i = 2; i < M; i++)
		{
			for (j = 0; j < len; j++)
				if (a[ba[j]][i] == false)
					break;

			if (j == len)
			{
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n",z,ans);
	}

	return 0;
}