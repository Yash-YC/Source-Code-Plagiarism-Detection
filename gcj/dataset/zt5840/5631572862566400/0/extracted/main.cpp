#include <bits/stdc++.h>
using namespace std;
const int MAX = 60;

int n;
int cur;
bool vis[MAX];

int dfs(int x, vector<vector<int>> &g, int depth) {
	//cout << x << " ";
	if (vis[x]) {
		if (x == cur) {
			return depth;
		}
		return 0;
	}
	vis[x] = true;
	int y = g[x][0];
	return dfs(y, g, depth + 1);
}

int rev_dfs(int x, vector<vector<int>> &g, int depth) {
	if (g[x].size() == 0) {
		return depth;
	}
	int ret = 0;
	for (int i = 0; i < (int)g[x].size(); ++i) {
		int y = g[x][i];
		ret = max(ret, rev_dfs(y, g, depth + 1));
	}
	return ret;
}

void __main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 10);
	vector<vector<int>> rev_graph(n + 10);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		graph[i + 1].push_back(x);
		rev_graph[x].push_back(i + 1);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cur = i;
		memset(vis, false, sizeof(vis));
		int len = dfs(i, graph, 0);
		if (len == 2) {
			vector<int> node;
			for (int j = 1; j <= n; ++j) {
				if (vis[j]) {
					node.push_back(j);
				}
			}
			int sum = 0;
			for (int j = 0; j < (int)node.size(); ++j) {
				int x = node[j];
				int y = node[1 - j];
				int tmp = 0;
				for (int k = 0; k < (int)rev_graph[x].size(); ++k) {
					if (y != rev_graph[x][k]) {
						tmp = max(tmp, rev_dfs(rev_graph[x][k], rev_graph, 1));
					}
				}
				sum += tmp;
			}
			ans = max(ans, sum + 2);
		} else {
			ans = max(ans, len);
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		__main();
	}
	return 0;
}
