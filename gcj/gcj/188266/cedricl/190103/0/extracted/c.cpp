#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cassert>

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;

using namespace std;

ull binom[50][50];

int main(){
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			binom[i][j] = 0;
	binom[0][0] = 1;
	for (int i = 1; i <= 40; i++){
		binom[i][0] = 1;
		for (int j = 1; j <= i; j++){
			binom[i][j] = binom[i-1][j] + binom[i-1][j-1];
		}
	}
	//cout << binom[3][0] << " " << binom[3][1] << " " << binom[3][2] << " " << binom[3][3] << endl;
	
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		int c,n;
		cin >> c >> n;
		double memo[c+1];
		memo[0] = 0;
		for (int left = 1; left <= c; left++){
			int rest = c - left;
			ull denom = binom[c][n] - binom[rest][n];
			double sum = (double)binom[c][n]/(double)denom;
			for (int i = 1; i <= min(left,n); i++){
				sum += ((double)binom[left][i]*binom[rest][n-i])/(double) denom * memo[left-i];
			}
			memo[left] = sum;
			//cout << left << " " << sum << endl;
		}
		printf("Case #%d: %.7f\n", zzz, memo[c]);
		//cout << "Case #" << zzz << ": " << memo[c] << endl;
	}
	return 0;
}
