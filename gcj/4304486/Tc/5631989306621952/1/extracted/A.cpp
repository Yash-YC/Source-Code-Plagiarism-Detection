#include <bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	string ans;
	cin >> s;
	for (int i=0;i<s.length();i++)
		if (ans[0] <= s[i]) ans = s[i] + ans;
		else ans = ans + s[i];
	cout << ans << endl;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int ts=1;ts<=T;ts++) {
		printf("Case #%d: ",ts);
		solve();
	}
	return 0;
}