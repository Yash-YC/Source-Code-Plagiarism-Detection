#include<bits/stdc++.h>
using namespace std;
int n;
int F[1024];
int sol() {
	cin >> n;
	for(int j = 1; j <= n; ++j) cin >> F[j];
	int res = 0;
	static bitset<1024> in_circle;
	in_circle.reset();
	for(int s = 1; s <= n; ++s) {
		static bitset<1024> vis;
		vis.reset();
		int x, c = 0;
		for(x = s; !vis.test(x); x = F[x]) {
			vis.set(x);
			++c;
		}
		if(x == s)
			in_circle.set(s);
		if(c > res && x == s)
			res = c;
	}
	int f[1024];
	fill_n(f, n+1, 1);
	for(int tm = n; tm -- ;) {
		for(int i = 1; i <= n; ++i) {
			const int j = F[i];
			if(!in_circle[i]) {
				f[j] = max(f[j], f[i]+1);
			}
		}
	}
	int tmp = 0;
	for(int i = 1; i <= n; ++i) {
		const int j = F[i];
		if(j < i && F[j] == i) {
			tmp += f[i] + f[j];
		}
	}
	return max(res, tmp);
}

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i)
		cout << "Case #" << i << ": " << sol() << endl;
}
