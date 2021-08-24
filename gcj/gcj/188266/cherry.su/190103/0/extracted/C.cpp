#include <iostream>

using namespace std;

int main() {
	freopen("C.txt", "r", stdin);
	freopen("C.out.txt", "w", stdout);
	
	int T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		int C, N;
		cin >> C >> N;
		if(C == N) printf("Case #%d: %.7f\n", i+1, 1.);
		else {
			double result = 1+(double)C/N;
			printf("Case #%d: %.7f\n", i+1, result);
		}
	}
	return 0;
}