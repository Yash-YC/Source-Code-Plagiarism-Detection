#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n;
int a[10];
bool hash[102400];

bool test(int p, int m) {
	memset(hash, 0, sizeof(hash));

	while (true) {
		hash[p] = true;
		
		int q = 0;
		while (p > 0) {
			q += (p%m) * (p%m);
			p /= m;
		}
		if (hash[q])
			return false;
		if (q == 1)
			return true;
		p = q;
	}
	return false;
}

int main() {
	int t;
	string line;

	cin >> t;
	getline(cin, line);	
	for (int ti = 0; ti < t; ti++) {
		int i = 2;

		getline(cin, line);
		stringstream ss;
		ss << line;
		n = 0;
		while (ss >> a[n++]);
		n--;

		while (true) {
			bool found = true;
			for (int j = 0; j < n; j++) {
//				printf("i = %d\n", i);
				if (!test(i, a[j])) {
					found = false;
					break;
				}
			}
			if (found) {
				printf("Case #%d: %d\n", ti+1, i);
				break;
			}
			i++;
		}
	}
}
