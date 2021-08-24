#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

bool done[11];
set<int> happyDigs[11];

int sumb(int x, int y, int b)
{
	int res = 0;
	int car = 0;
	int ten = 1;
	while(x != 0 || y != 0)
	{
		int xd = x % 10;
		int yd = y % 10;
		int s = xd + yd + car;
		car = s / b;
		s %= b;
		res += ten * s;
		ten *= 10;
		x /= 10;
		y /= 10;
	}
	res += ten * car;
	return res;
}

int squareb(int d, int b)
{
	int res = 0;
	int t = d * d;
	int mul = 1;
	while(t > 0)
	{
		int dig = t % b;
		t /= b;
		res += dig * mul;
		mul *= 10;
	}
	return res;
}

int ctob(int a, int b)
{
	int n = 0;
	int p = b, ten = 1;
	while(a > 0)
	{
		int v = a % p;
		n += v * ten;
		a /= p;
		ten *= 10;
	}
	return n;
}

int cfb(int a, int b)
{
	int n = 0;
	int p = 1;
	while(a > 0)
	{
		int d = a % 10;
		a /= 10;
		n += d * p;
		p *= b;
	}
	return n;
}

int isHappy(int num, int b)
{
	int n = ctob(num, b);
	int v = n, nd = 0;
	while(v > 0)
	{
		v /= 10;
		++nd;
	}
	set<int> got;
	int cur = n;
	bool can = false;
	got.insert(num);
	while(1)
	{
		int v = cur, s = 0;
		while(v > 0)
		{
			int d = v % 10;
			v /= 10;
			s = sumb(s, squareb(d, b), b);
			// s += d * d;
		}
		cur = s;
		int sdec = cfb(s, b);
		if(got.find(sdec) == got.end())
		{
			if(sdec == 1)
			{
				can = true;
				break;
			}
			else
				got.insert(sdec);
		}
		else 
		{
			can = false;
			break;
		}
	}
	if(can)
		happyDigs[b].insert(got.begin(), got.end());
	return can;
}

void findHappy(int b)
{
	if(done[b]) return;
	for(int i = 2; i < 100000; ++i)
		isHappy(i, b);
	done[b] = true;
}

int main()
{
	FILE* fin = fopen("in.txt", "r");
	FILE* fout = fopen("out.txt", "w");
	int T;
	char str[2048];
	fgets(str, 2048, fin);
	sscanf(str, "%d", &T);
	for(int tests = 1 ; tests <= T; ++tests)
	{
		vector<int> bases;
		fgets(str, 2048, fin);
		int l = strlen(str);
		if(str[l - 1] < '0' && str[l - 1] > '9')
			str[l - 1] = '\0';
		string stri(str);
		stringstream ss(stri);
		while(!ss.eof())
		{
			int v;
			ss >> v;
			bases.push_back(v);
		}
		
		for(int i = 0; i < bases.size(); ++i)
			findHappy(bases[i]);
		int hi = bases[bases.size() - 1];
		int res = 0;
		for(set<int>::iterator iter = happyDigs[hi].begin(); iter != happyDigs[hi].end(); ++iter)
		{
			int v = *iter;
			bool can = true;
			for(int i = 0; i < bases.size() - 1; ++i)
				if(happyDigs[bases[i]].find(v) == happyDigs[bases[i]].end())
				{
					can = false;
					break;
				}
			if(can)
			{
				fprintf(fout, "Case #%d: %d\n", tests, v);
				break;
			}
		}
	}

	fclose(fin);
	fclose(fout);

	return 0;
}