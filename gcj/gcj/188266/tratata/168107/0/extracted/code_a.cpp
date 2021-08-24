#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;


char sr[1024];
long el[11], el_num;
long pos[11];
void init()
{
	gets(sr);
	istringstream in(sr);
	el_num = 0;
	for( ;in >> el[el_num+1]; )
	{
		el_num++;
		//cout << el[el_num] << " ";
	}
	
}
long iteration(long arg, long base)
{
	long sum = 0;
	long y, a;
	for(; arg; arg /= base)
	{
		a = arg % base;
		sum += a*a;
	}
	return sum;
}
long check(long arg, long base)
{
	long y;
	for(y = 1; y <= 20; y++)
	{
		if (arg == 1) {return 1;}
		arg = iteration(arg, base);
	}
	return 0;
}
void logic()
{
	long y, j, flag;
	init();
	long cur;
	for(y = 2; ; y++)
	{
		cur = y;
		flag = 1;
		for(j = 1; j <= el_num; j++)
		{
			if (!check(cur, el[j]))
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << cur;
			break;
		}
	}
}
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	long y, t;
	cin >> t;
	gets(sr);
	for(y = 1; y <= t; y++)
	{
		cout << "Case #" << y << ": ";
		logic();
		cout << "\n";
	}
}
