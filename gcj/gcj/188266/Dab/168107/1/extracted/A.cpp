#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <list>
#include <map>
#include <cmath>

using namespace std;

char line[512];
vector<int> bases;

int memo[11-2][20000000];

int happy(int base, int x) {

	if(memo[base-2][x] == 2) return memo[base-2][x] = 0;
	if(memo[base-2][x] != -1) return memo[base-2][x];
	memo[base-2][x] = 2;

	int xx = x;
	int result = 0;
	while(x > 0) {
		int d = x%base;
		x/=base;
		result += d*d; 
	}
	if(result == 1) memo[base-2][xx] = 1;
	else memo[base-2][xx] =  happy(base, result);
	return memo[base-2][xx];
}


int f(int x) {
	for(int i = 0; i < bases.size(); i++) if(!happy(bases[i], x)) return false;
	return true;
}

void solve() {	
	bases.clear();
	cin.getline(line, 512);
	for(int i = 0; i < strlen(line); i+=2) {
		if(line[i] == '1'){
			bases.push_back(10);
			i++;
		} else bases.push_back(line[i]-'0');
	}

	int i = 2;
	while(!f(i)) {
		i++;			
	}
	cout << i;

}


int main() {	
	memset(memo, -1, sizeof(memo));
	int C;
	cin >> C;
	cin.getline(line, 512);
	for(int i = 1; i <= C; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}