#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

set<int> stt[16];

bool ishappy(int num, int base)
{
	set<int> st;
	st.insert(num);
	while (num != 1) {
		int next = 0;
		do {
			int nn = num % base;
			next += nn * nn;
			num /= base;
		}
		while (num);
		if (st.find(next) != st.end()) return false;
		st.insert(next);
		num = next;
	}
	return true;
}

bool ishappy2(int num, int base)
{
	int next = 0;
	do {
		int nn = num % base;
		next += nn * nn;
		num /= base;
	}
	while (num);
	return stt[base].find(next) != stt[base].end();
}

int main()
{
	freopen("Ain.txt", "r", stdin);
	freopen("Aout.txt", "w", stdout);
	for (int j = 2; j <= 10; ++j) {
		stt[j].insert(1);
	}
	for (int i = 2; i < 1000; ++i) {
		int j;
		for (j = 2; j <= 10; ++j) {
			if (ishappy(i, j)) {
				stt[j].insert(i);
			}
		}
	}
	int t;
	cin >> t;
	int b[16];
	string s;
	getline(cin, s);
	for (int ct = 1; ct <= t; ++ct) {
		getline(cin, s);
		stringstream S(s);
		int nums = 0;
		while (S >> b[nums]) {
			++nums;
		}
		for (int i = 2; ; ++i) {
			int j;
			for (j = 0; j < nums; ++j) {
				if (!ishappy2(i, b[j])) {
					break;
				}
			}
			if (j >= nums) {
				printf("Case #%d: %d\n", ct, i);
				break;
			}
		}
	}
	return 0;
} 