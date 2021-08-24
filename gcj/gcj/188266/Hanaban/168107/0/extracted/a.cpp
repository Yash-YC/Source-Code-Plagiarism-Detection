#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define MAX_N	1000000

int lucky[11][MAX_N];

int get_next(int base, int n) {
	int ret = 0;
	while (n) {
		ret += (n % base) * (n % base);
		n /= base;
	}
	
	return ret;
}

void make_lucky(int base)
{
	lucky[base][0] = 0;
	lucky[base][1] = 1;
	for (int i = 2; i < MAX_N; ++i) {
		if (lucky[base][i] >= 0) continue;
		deque<int> li;
		int n = i;
		while (lucky[base][n] < 0) {
			li.push_back(n);
			lucky[base][n] = 0;
			n = get_next(base, n);
		}
		if (lucky[base][n] == 1) {
			for (int j = 0; j < li.size(); ++j) {
				lucky[base][li[j]] = 1;
			}
		}
	}
	
	return;
}

			
int main()
{
	memset(lucky, 0xFF, sizeof(lucky) );
	for (int i = 2; i < 11; ++i) {
		make_lucky(i);
	}
	
	string x;
	getline(cin, x);
	istringstream iss(x);
	int n;
	iss >> n;
	int ans[MAX_N];
	for (int i = 0; i < n; ++i) {
		getline(cin, x);
		istringstream iss(x);
		int base;
	memset(ans, 0, sizeof(ans) );
		int cnt = 0;
		while (iss >> base) {
			++cnt;
			for (int j = 2; j < MAX_N; ++j) {
				if (lucky[base][j] == 1) ++ans[j];
			}
		}
		for (int j = 2; j < MAX_N; ++j) {
			if (ans[j] == cnt) {
				printf("Case #%d: %d\n", i + 1, j);
				break;
			}
		}
	}
	
	return 0;
}

