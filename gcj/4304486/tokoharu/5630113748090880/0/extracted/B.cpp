#include<bits/stdc++.h>
using namespace std;

vector<int> solve() {
	vector<int> ret;
	int N;
	cin >> N;
	vector<int> cnt(10000,0);
	
	for(int i=0; i<(2*N-1); i++)
		for(int j=0; j<N; j++) {
			int p;
			cin >> p;
			cnt[p] ++ ;
			
		}
	for(int i=0; i<10000;i ++) {
		if(cnt[i] % 2 == 1) ret.push_back(i);
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for(int _=0; _<T; _++) {
		vector<int> ans = solve();
		cout << "Case #" << _+1 << ":";
		for(int i=0; i<ans.size(); i++)
			 cout << " " << ans[i];
		
		
		cout <<  endl;
		
	}
	
	return 0;
	
}

