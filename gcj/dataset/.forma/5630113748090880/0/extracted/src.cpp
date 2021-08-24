//~In The Name Of Allah~//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <sstream>
#include <fstream>
#include <functional>
#include <stack>
#include <utility> 
#include <set>
#include <list>
#include <queue>
#include <bitset>
#include <time.h>
using namespace std;

#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define all(_) _.begin(), _.end()
#define rall(_) _.rbegin(), _.rend()
#define rep(i, j) for (int i = 0; i < j; i++)
#define Rep(i, j, k) for (int i = j; i < k; i++)
#define siz(_) (int)_.size()
#define ll long long
#define endl '\n'

const double PI = 2.0 * acos(0.0);
const double EX = 2.7182818284;
const int MOD = 1e9 + 7;
const int oo = 2e9 + 1e8;

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x%y); }

int main() {
	read;
	write;
	int t, n, cs = 0;
	cin >> t;
	while (t-- && cin >> n) {
		vector<vector<int>> in(2 * n - 1), opt;
		map<vector<int>, pair<int, int>> have;
		rep(i, 2 * n - 1) {
			in[i].resize(n);
			rep(j, n)
				cin >> in[i][j];
			have[in[i]].second++;
		}
		sort(all(in));
		int grid[155][155], x, y;
		memset(grid, 0, sizeof grid);
		x = y = 0;
		rep(i, n)
			grid[0][i] = in[0][i];
		rep(i, n) {
			int idx = -1;
			Rep(j, 1, 2 * n - 1) if (in[j][0] == grid[0][i]) {
				if (!i) {
					idx = j;
					break;
				}
				bool good = 1;
				Rep(k, 1, n) if (in[j][k] <= grid[k][i - 1]) {
					good = 0;
					break;
				}
				if (good) {
					idx = j;
					if (grid[1][i - 1])
						break;
				}
			}
			if (idx != -1) {
				Rep(k, 1, n)
					grid[k][i] = in[idx][k];
			}
		}

		/*puts("");
		rep(i, n) {
		rep(j, n)
		cout << grid[i][j] << " ";
		cout << endl;
		}
		puts("");*/
		while (1) {
			rep(i, n) {
				vector<int> a, b;
				rep(j, n) {
					if (grid[i][j])
						a.push_back(grid[i][j]);
					if (grid[j][i])
						b.push_back(grid[j][i]);
				}
				if (siz(a) == n)
					have[a].first++;
				if (siz(b) == n)
					have[b].first++;
			}

			int idx = -1;
			rep(i, n) if (!grid[1][i]) {
				idx = i;
				break;
			}

			if (idx != -1) {
				int x = 1;
				rep(i, 2 * n - 1) if (have[in[i]].first < have[in[i]].second) {
					grid[x++][idx] = in[i][idx];
					have[in[i]].first++;
				}
			}
			else
				break;
			rep(i, 2 * n - 1)
				have[in[i]].first = 0;
		}

		/*puts("");
		rep(i, 2 * n - 1) {
		rep(j, n)
		cout << in[i][j] << " ";
		cout << endl;
		}
		puts("");

		puts("");
		rep(i, n) {
		rep(j, n)
		cout << grid[i][j] << " ";
		cout << endl;
		}
		puts("");*/

		cout << "Case #" << ++cs << ": ";
		rep(i, n) {
			vector<int> a, b;
			rep(j, n) {
				a.push_back(grid[i][j]);
				b.push_back(grid[j][i]);
			}
			opt.push_back(a);
			opt.push_back(b);
		}
		sort(all(opt));
		vector<int> ans;
		rep(i, 2 * n - 1) if (opt[i] != in[i]) {
			ans = opt[i];
			break;
		}
		if (ans.empty())
			ans = opt.back();
		rep(i, n)
			cout << ans[i] << " ";
		puts("");
	}
	return 0;
}