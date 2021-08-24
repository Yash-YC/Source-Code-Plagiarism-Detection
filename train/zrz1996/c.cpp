#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,a) for (int i = 0; i < a; i++)
#define Fill(a,b) memset(a,b,sizeof(a))
const int maxn = 10100;
struct edge
{
	int nxt, v;
}E[maxn * 2];
int head[maxn], tot;
void add(int a, int b)
{
	tot++; E[tot].nxt = head[a]; head[a] = tot;
	E[tot].v = b;
}
int n;
int out[maxn];
bool vis[maxn];
void init()
{
	tot = 0;
	memset(head, 0, sizeof(head));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		add(v, i);
		out[i] = v;
	}
	memset(vis, 0, sizeof(vis));
}
vector<int> c;
int findCir(int v)
{
	c.clear();
	while (!vis[v])
	{
		c.push_back(v);
		vis[v] = 1;
		v = out[v];
	}
	return v;
}
bool vis1[maxn];
int dfs(int v)
{
	int ret = 1;
	for (int i = head[v]; i; i = E[i].nxt)
	{
		int v = E[i].v;
		if (vis[v])
			continue;
		ret = max(ret, dfs(E[i].v) + 1);
	}
	return ret;
}
bool vis2[maxn];
void solve(int task)
{
	printf("Case #%d: ", task);
	init();
	int ans, ans1;
	memset(vis2, 0, sizeof(vis2));
	ans1 = ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis2[i])
			continue;
		memset(vis, 0, sizeof(vis));
		int v = findCir(i);
		if (v != i)
			continue;
		if (c.size() != 2)
		{
			ans = max(ans, (int)c.size());
			continue;
		}
		int t1 = dfs(i);
		int t2 = dfs(out[i]);
		vis2[out[i]] = 1;
		ans1 += t1 + t2;
	}
	printf("%d\n", max(ans, ans1));
}
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
}
