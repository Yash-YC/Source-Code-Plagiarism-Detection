#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

double C(int k, int n){
	if( k > n) return 0;
	if( k < 0) return 0;
	double r = 1.0;
	for(int i = 1; i <= k; i++){
		r *= (n - i + 1);
		r /= i;
	}
	return r;
	
}

double E[50];
int N;
int D;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//	printf("%lf %lf\n", C(1, 5), C(3, 5));
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d %d", &D, &N);
		E[0] = 0;
		for(int n = 1; n <= D; n++){
			double p0 = C(0, n) * C(N - 0, D - n) / C(N, D);
			double s = 0.0;
			for(int k = 1; k <= n; k++){
				s += C(k, n) * C(N - k, D - n) * E[n - k];
			}
			s /= C(N, D);
			s += 1.0;
			E[n] = s / (1 - p0);
		}
		printf("Case #%d: %lf\n", t, E[D]);
	}
}