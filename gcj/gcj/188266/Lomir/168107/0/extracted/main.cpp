#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>
#include <cassert>

using namespace std;

inline void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("test.out", "wt", stdout);
#endif
}

void solve();

int main() {
	openFiles();
	int t; scanf("%d\n", &t);
	while (t--)	solve();
	return 0;
}

bool isGood(int val, int base, std::set<int>& ss) {
	if (val == 1) return 1;
	ss.insert(val);
	int sum = 0;
	while (val) {
		int dig = val % base;
		sum += dig * dig;
		val /= base;
	}
	if (ss.find(sum) != ss.end()) {
		return false;
	}
	return isGood(sum, base, ss);
}

void solve() {
	char buf[10000]; gets(buf);
	std::vector<int> bases;
	std::stringstream ss(buf);
	int base;
	while (ss >> base) {
		bases.push_back(base);
	}
	
	for (int i = 2; true; ++i) {
		bool good = true;
		for (int j = 0; j < bases.size(); ++j)
			good &= isGood(i, bases[j], std::set<int>());
		if (good) {
			static int ntest = 0;
			printf("Case #%d: %d\n", ++ntest, i);
			break;
		}
	}

}
