#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

bool go(int n, int base)
{
	map<int, int> check;
	check[n] = 1;
		while (true) {
		vector<int> nums;
		while (n > 0) {
			nums.push_back(n % base);
			n /= base;
		}
		int sqr = 0;
		for (int i = 0; i < (int)nums.size(); i++) {
			sqr += nums[i] * nums[i];
		}
		n = sqr;
		if (n == 1) return true;
		if (check[n] == 1) return false;
		check[n] = 1;
	}
}

int main()
{
	char buff[1024];
	int T;
	gets(buff);
	T = atoi(buff);
	for (int t = 1; t <= T; t++) {
		gets(buff);
		stringstream sin(buff);
		int base;
		vector<int> bases;
		while (sin >> base) bases.push_back(base);
		
		int ans = 2;
		bool ok = true;
		do {
			ok = true;
			for (int i = 0; i < (int)bases.size(); i++) {
				if (go(ans, bases[i]) == false) {
					ans++;
					ok = false;
					break;
				}
			}			
		} while (ok == false);

		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
