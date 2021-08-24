#include "tmp.h"

string sortgame(string s) {
	if (s.size() == 1) {
		return s;
	}
	else if (s.size() == 2) {
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
	}

	string ret;
	int x = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[x] <= s[i]) {
			x = i;
		}
	}
	ret += string(1,s[x]);
	if(x > 0)
		ret += sortgame(s.substr(0, x));
	if (x < s.size() - 1)
		ret += s.substr(x + 1);

	return ret;
}

int main() {
	cin.sync_with_stdio(false);

	
	freopen("A-large.in", "r", stdin);
	freopen("output_large_A.txt", "w", stdout);
	

	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		string s;
		cin >> s;
		cout << "Case #" << tc << ": " << sortgame(s) << '\n';
	}

	return 0;
}