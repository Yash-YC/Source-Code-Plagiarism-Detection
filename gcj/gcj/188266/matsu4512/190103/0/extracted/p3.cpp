#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <map>
#include <sstream>
using namespace std;
#define EPS 1.-12

int main(){
	int n;
	cin >> n;
	for(int nn = 1; nn <= n; nn++){
		double C, N;
		cin >> C >> N;
		double sum=N, rest = C-N, p=1, v=(1.0/(rest/C))/N;
		if(C == N ) printf("Case #%d: %.5f\n", nn, 1);
		else printf("Case #%d: %.5f\n", nn, v+p);
	}
}
