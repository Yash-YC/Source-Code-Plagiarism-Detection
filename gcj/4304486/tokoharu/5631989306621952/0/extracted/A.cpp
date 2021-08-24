#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
	
	int n = s.size();
	string t = s.substr(0,1);
	for(int i=1; i<n; i++) {
		string tmp = s.substr(i, 1);
		if(t[0] > tmp[0])
			t += tmp;
		else t = tmp + t;
	}
	return t;
}

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N;i ++) {
		
		string s;
		cin >> s;
		string ans = solve(s);
		cout << "Case #" << i+1 << ": " << ans << endl;
		
	}
	
	return 0;
	
}

