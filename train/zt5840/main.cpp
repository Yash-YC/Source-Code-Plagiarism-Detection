#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
#define INF 0x3f3f3f3f

char arr[MAX];

char find_max() {
	char j = 'Z';
	for (; j >= 'A'; --j) {
		if (arr[(int)j] > 0) {
			break;
		}
	}
	return j;
}

void __main() {
	string s;
	cin >> s;
	memset(arr, 0, sizeof(arr));
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		arr[(int)s[i]]++;
	}
	string ans = "";
	ans += s[0];
	for (int i = 1; i < n; ++i) {
		char c = s[i];
		if (c >= ans[0]) {
			ans = c + ans;
		} else {
			ans = ans + c;
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
