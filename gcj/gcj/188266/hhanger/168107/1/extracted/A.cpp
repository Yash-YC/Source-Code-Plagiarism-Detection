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
	num = next;
	next = 0;
	do {
		int nn = num % base;
		next += nn * nn;
		num /= base;
	}
	while (num);
	return stt[base].find(next) != stt[base].end();
}

const int MAXCASE = 11814485;
int secondMAX[16] = {0, 0, 11814485, 11814485, 11814485, 4817803, 346719, 28099, 711725, 2688153, 569669};
const int thirdMax = 2662657;

int main()
{
	freopen("Ain.txt", "r", stdin);
	//freopen("Aout.txt", "w", stdout);
	FILE *fp = fopen("Aout.txt", "w");
	/*int num = 11814485;
	for (int i = 2; i <= 10; ++i) {
		printf("%d\n", ishappy(num, i));
	}
	return 0;*/
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
	/*int b[8] = {3, 5, 6, 7, 8, 9};	// used to generate the largest case and second largest case.
	for (int i = 1000; ; ++i) {
		int j;
		if (i % 10000 == 0) printf("%d\n", i);
		for (j = 0; j < 6; ++j) {
			if (!ishappy2(i, b[j])) {
				break;
			}
		}
		if (j >= 6) {
			printf("%d\n", i);
			break;
		}
	}*/
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int ct = 1; ct <= t; ++ct) {
		getline(cin, s);
		stringstream S(s);
		set<int> bb;
		int b;
		while (S >> b) {
			bb.insert(b);
		}
		set<int> bb2;
		bb2 = bb;
		if (bb2.count(4)) {
			bb2.erase(bb2.find(4));
		}
		if (bb2.count(2)) {
			bb2.erase(bb2.find(2));
		}
		int res;
		if (bb2.size() == 7) {
			res = MAXCASE;
		}
		else if (bb2.size() == 6) {
			int num;
			for (num = 3; num <= 10; ++num) {
				if (num != 4 && bb2.count(num) == 0) {
					break;
				}
			}
			res = secondMAX[num];
		}
		else if (bb2.size() == 5 && !bb2.count(3) && !bb2.count(5)) {
			res = thirdMax;
		}
		else {
			for (int i = 2; ; ++i) {
				set<int>::iterator mi = bb.begin();
				for (; mi != bb.end(); ++mi) {
					if (!ishappy2(i, *mi)) {
						break;
					}
				}
				if (mi == bb.end()) {
					res = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", ct, res);
		fprintf(fp, "Case #%d: %d\n", ct, res);
	}
	fclose(fp);
	return 0;
} 