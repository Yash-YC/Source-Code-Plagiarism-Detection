#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <string>

using namespace std;

const int MAXN = 5000001;
const int MINN = 10000;

int sum(int n, int k)
{
	int res = 0;
	while (n)
	{
		res += (n%k) * (n%k);
		n /= k;
	}
	return res;
}

int ans[MINN][11] = {0};
int vis[MINN];

vector <int> a;

int dfs(int n, int i)
{
	if (vis[n] == 1) 
	{
		ans[n][i] = 0;
		vis[n] = 2;
		return 0;
	}
	if (vis[n] == 2)
	{
		return ans[n][i];
	}
	vis[n] = 1;
	int r = dfs(sum(n, a[i]), i);
	ans[n][i] = r;
	vis[n] = 2;
	return r;
}

int main()
{
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int T = 0; T < t; ++T)
	{
		a.clear();
		getline(cin, s);
		int k = 0;
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == ' ')
			{
				a.push_back(k);
				k = 0;
			}
			else
				k = 10*k + s[i] - '0';
		a.push_back(k);
		for (int i = 0; i < a.size(); ++i)
		{
			memset(vis, 0, sizeof(vis));
			vis[1] = 2;
			ans[1][i] = 1;
			for (int k = 2; k < MINN; ++k)
				dfs(k, i);
		}
		cout << "Case #" << T+1 << ": ";
		k = 2;
		while (1)
		{
			int res = 1;
			for (int i = 0; i < a.size(); ++i)
				res &= ans[sum(k, a[i])][i];
			if (res)
			{
				cout << k << '\n';
				break;
			}
			k++;
		}
	}
	return 0;
}
