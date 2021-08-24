#include <iostream>
#include <string>
#include <etc/cppformat/format.cc>

using namespace std;

int main() {
	ios::ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for(int i = 1 ; i <= tc ; ++i) {
		string x;
		cin >> x;

		string ans = "";
		for(char ch : x) {
			if( ans + ch < ch + ans ) {
				ans = ch + ans;
			} else {
				ans = ans + ch;
			}
		}

		cout << fmt::format("Case #{}: {}", i, ans) << endl;
	}

	return 0;
}