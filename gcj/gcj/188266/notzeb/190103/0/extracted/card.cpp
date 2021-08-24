#include <iostream>
#include <algorithm>
#include <cstdlib>

#define f(x,y) for (int x = 0; x < y; ++x)

using namespace std;

double choose(int a, int b) {
	if (a < b) return 0;
	if (b < 0) return 0;
	double ans = 1.0;
	f(i,a) ans *= (i+1);
	f(i,b) ans /= (i+1);
	f(i,a-b) ans /= (i+1);
	
	return ans;
}

double prob(int x, int y, int c, int n) {
	return choose(x,y)*choose(c-x,n-y)/choose(c,n);
}

int main() {
	srand((unsigned) time(NULL));

	int t;
	cin >> t;
	f(counter,t) {
		int n, c;
		cin >> c >> n;
		
		double ans[c+1];
		ans[0] = 0.0;
		
		for (int i = 1; i <= c; ++i) {
			double fudge = prob(i, 0, c, n);
			ans[i] = 1.0;
			f(j,i) {
				ans[i] += prob(i, i-j, c, n)*ans[j];
			}
			ans[i] /= 1.0-fudge;
		}
		
		cout << "Case #" << (counter+1) << ": " << ans[c] << endl;
	}

	return 0;
}

