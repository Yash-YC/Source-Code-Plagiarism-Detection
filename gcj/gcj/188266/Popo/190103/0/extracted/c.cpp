#include<iostream>
#include<cmath>

#define EPS 1e-10

using namespace std;

long long ch(int a, int b){
	if(a <= 0 || b < 0 || b > a) return 0;

	if(b > a / 2) b = a - b;

	long long re = 1;

	for(int i = 1; i <= b; ++i){
		re *= a - i + 1;
		re /= i;
	}

	return re;
}

long double prob(int n, int c, int d){
	long double re = 0;
	int i, j, b = 1;

	for(i = 0; ; ++i, b = -b){
		long double tmp = ch(n, i) * pow(ch(n-i, c) / (long double) ch(n, c), d);


		if(tmp < EPS) break;

		re += tmp * b;
	}

	return re;
}

int main(){
	int cs;

	cin >> cs;

	for(int tc = 1; tc <= cs; ++tc){
		long double ans = 0;
		long double last_prob = 0;
		int n, c;

		cin >> n >> c;

		for(int i = 1; ; ++i){
			long double tmp = prob(n, c, i);

			if(i > 10 && i * (tmp - last_prob) < EPS) break;
			ans += i * (tmp - last_prob);
			
			last_prob = tmp;
		}

		printf("Case #%d: %.7llf\n", tc, ans);
	}

	return 0;
}
