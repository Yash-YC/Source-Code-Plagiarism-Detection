#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cassert>
#include <sstream>

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;

using namespace std;

int get_next(int num, int base){
	int sum = 0;
	while (num){
		sum += (num%base)*(num%base);
		num /= base;
	}
	return sum;
}

const int max_size = 2000000;
int memo[11][2000001];

int doit(int num, int base){
	if (num <= max_size && memo[base][num] != -1) return memo[base][num];
	int next = get_next(num,base);
	if (num > max_size){
		return doit(next,base);
	}
	memo[base][num] = 0;
	memo[base][num] = doit(next,base);
	return memo[base][num];
}

bool wanted[11];

int main(){
	for (int i = 2; i <= 10; i++){
		memo[i][1] = 1;
		for (int j = 2; j <= max_size; j++)
			memo[i][j] = -1;
	}

	int n; cin >> n; string s; getline(cin,s);
	for (int zzz = 1; zzz <= n; zzz++){
		memset(wanted, false ,sizeof(wanted));
		getline(cin,s);
		istringstream sin(s);
		int temp;
		while (sin >> temp){
			wanted[temp] = true;
			//cout << temp << endl;
		}
		int ans = -1;
		for (int j = 2; j <= 100000000; j++){
			bool okay = true;
			for (int i = 2; i <= 10; i++){
				if (wanted[i]){
					if (doit(j,i) == 0){
						okay = false;
						break;
					}
				}
			}
			if (okay){
				ans = j;
				break;
			}
		}
		cout << "Case #" << zzz << ": " << ans << endl;
	}
	return 0;
}
