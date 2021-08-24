#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>
#include <queue>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef long long int64;
typedef pair<ld, ld> pt;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define y1 PALEVO

char ans[11][1000];
int an[3000];

string s;

inline int nw(int x, int y)
{
	int res = 0;
	while (x > 0)
	{
		int v = x % y;
		x /= y;
		res += v * v;
	}
	return res;
}

bool check(int x, int y)
{
	if (ans[y][x] > -1)
		return ans[y][x];
	if (x == 1)
		return true;
	if (ans[y][x] == -2)
		return ans[y][x] = 0;
	ans[y][x] = -2;
	int xx = x;
	int tmp = nw(x, y);
	bool can = check(tmp, y);
	if (can)
		return ans[y][x] = 1;
	else
		return ans[y][x] = 0;
}

int main()
{
	
	int t;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	scanf("%d\n", &t);
	memset(ans, 255, sizeof ans);
	memset(an, 255, sizeof an);
	for (int i = 2; i <= 11815000; i++)
	{
		int val = 0;
		for (int j = 2; j <= 10; j++)
		{
			if (check(nw(i, j), j))
				val += (1 << j);
		}
		if (an[val] == -1)
		{
			an[val] = i;
		}
	}
	for (int test = 0; test < t; test++)
	{
		getline(cin, s);
		stringstream ss;
		ss << s;
		int v;
		vector <int> tt;
		while (ss >> v)
		{
			tt.push_back(v);
		}
		sort(tt.begin(), tt.end());
		tt.erase(unique(tt.begin(), tt.end()), tt.end());
		int vvv = 0;
		for (int i = 0; i < (int)tt.size(); i++)
			vvv += (1 << tt[i]);
		int res = 1000000000;
		for (int i = 0; i < 3000; i++)
		{
			if (vvv == (vvv & i) && an[i] != -1)
				res = min(res, an[i]);
		}
		printf("Case #%d: %d\n", test + 1, res);
	}
	return 0;
}

