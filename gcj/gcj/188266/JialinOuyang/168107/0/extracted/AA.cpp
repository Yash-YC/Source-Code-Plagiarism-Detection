#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <set>
using namespace std;

const int MAXN = 1010;

int BASE;
int tag[11][MAXN];

inline int SQR(int x) {
	return x * x;
}

inline int SQRSUM(int x) {
	int ret = 0;
	while (x) {
		ret += SQR(x % BASE);
		x /= BASE;
	}
	return ret;
}

inline bool isLucky(int num) {
	set <int> S;
	S.clear();
	int n = num;
	while (true) {
		if (S.count(n)) break;
		S.insert(n);
		n = SQRSUM(n);
		if (n == 1) return true;
	}
	return false;
}

inline void parseBase(int x) {
	while (x) {
		printf("%d", x % BASE);
		x /= BASE;
	}
	putchar('\n');
}

int main() {
	for (int num = 1; num < MAXN; num++) {
		for (BASE = 2; BASE <= 10; BASE++) {
			tag[BASE][num] = isLucky(num);
		}
	}
	char tmpstr[1024];
	int task;
	scanf("%d", &task);
	gets(tmpstr);
	string line;
	int base[15], n;
	for (int oo = 0; oo < task; oo++) {
		gets(tmpstr);
		line = tmpstr;
		istringstream iss(line);
		n = 0;
		while (iss >> base[n]) n++;
		for (int num = 2; ; num++) {
			int cc = 0;
			for (int i = 0; i < n; i++) {
				BASE = base[i];
				if (num < MAXN) {
					if (tag[BASE][num]) cc++;
				} else {
					int tmp = SQRSUM(num);
					if (tmp >= MAXN) {
						puts("error");
						return 0;
					}
					if (tag[BASE][tmp]) cc++;
				}
			}
			if (cc == n) {
				printf("Case #%d: %d\n", oo + 1, num);
				break;
			}
		}
	}
/*	for (int num = 2; ; num++) {
		int cc = 0;
		for (BASE = 2; BASE <= 10; BASE++) {
			if (num < MAXN) {
				if (tag[BASE][num]) cc++;
			} else {
				int tmp = SQRSUM(num);
				if (tmp >= MAXN) {
					puts("error");
					return 0;
				}
				if (tag[BASE][tmp]) cc++;
			}
		}
		printf("%d %d\n", num, cc);
		if (cc == 9) {
			printf("num = %d\n", num);
			break;
		}
	}*/
}
