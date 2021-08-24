#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

void solve()
{
	int n;
	cin >> n;
	vector<int> bff;
	FOR(i,n) {
		int x;
		cin >> x;
		bff.push_back(x - 1);
	}

	vector<bool> used;
	vector<bool> valid;
	map<pair<int,int>,int> chains;
	used.resize(n, false);
	valid.resize(n, true);

	int true_circle = 0;
	FOR(i,n) {
		if (!valid[i]) continue;
		vector<int> circle;
		circle.push_back(i);
		used[i] = true;
		while (true) {
			int next = bff[circle.back()];
			if (!valid[next]) {
				valid[circle[0]] = false;
				break;
			} else if (used[next]) {
				if (next == circle[0]) {
					if (circle.size() == 2) {
						pair<int,int> p = make_pair(circle[0], circle[1]);
						if (chains.find(p) == chains.end()) chains[p] = 0;
						chains[p] = max(chains[p], (int)circle.size() - 1);
					} else {
						true_circle = max(true_circle, (int)circle.size());
					}
				} else if (next == circle[circle.size()-2]) {
					pair<int,int> p = make_pair(circle[circle.size()-2], circle[circle.size()-1]);
					if (chains.find(p) == chains.end()) chains[p] = 0;
					chains[p] = max(chains[p], (int)circle.size() - 1);
				} else {
					valid[circle[0]] = false;
				}
				break;
			} else {
				used[next] = true;
				circle.push_back(next);
			}
		}
		for (int s : circle) used[s] = false;
	}

	int total_chains = 0;
	for (auto p : chains) total_chains += p.second;
	cout << max(total_chains, true_circle);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
