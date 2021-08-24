#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for(int i = 1 ; i <= tc ; ++i) {
		int N;
		map<int,int> X;

		cin >> N;

		for(int j = 0 ; j < 2*N-1 ; ++j) {
			for(int k = 1 ; k <= N ; ++k) {
				int x;
				cin >> x;
				X[x]++;
			}
		}

		cout << "Case #" << i << ":";
		for(auto it = X.begin() ; it != X.end() ; ++it) {
			if( it->second % 2 == 1 ) {
				cout << " " << it->first;
			}
		}
		cout << endl;
	}

	return 0;
}