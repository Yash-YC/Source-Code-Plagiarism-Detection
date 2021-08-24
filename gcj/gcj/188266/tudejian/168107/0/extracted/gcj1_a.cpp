#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

const int MAXN = 50000009;

int bit[MAXN];

inline bool isHappy(int n, int base) {
	int count = 0;
	int tt = n;
	for (; count < 100; ++count) {
		int t = n;
		int sum = 0;
		for (; t; t /= base) {
			sum += (t % base) * (t % base);
		}
		if (sum == 1) return true;
		n = sum;
		//if (tt == 1) printf("sum = %d\n", sum);
	}
	return false;
}

void preprocess() {
	int i, j, k;
	
	for (i = 1; i <= 100000; ++i) {
		for (j = 2; j <= 10; ++j) {
			if (isHappy(i, j)) {
				bit[i] |= (1 << j);
			}
		}
	}
}

int main() {
	preprocess();
	//printf("ddddd\n");
	freopen("F:\\A-small-attempt0.in", "r", stdin);
	freopen("F:\\A-small-attempt0.out", "w", stdout);
	int i, j, T, cas = 0;
	char s[1009];
	scanf("%d", &T);
	gets(s);
	while (T--) {
		gets(s);
		stringstream in(s);
		int b = 0, t;
		while (in >> t) {
			b |= (1 << t);
		}
		for (i = 2; i <= 100000; ++i)
			if ((b | bit[i]) == bit[i]) break;
		printf("Case #%d: %d\n", ++cas, i);
	}
	return 0;
}

		