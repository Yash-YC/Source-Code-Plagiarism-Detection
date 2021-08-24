#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

const int MAXN = 10;
const int MAXL = 512;
const int MAXSTEPS = 1000;

int T = 0;
int N = 0;
int a[MAXN] = {0};

void read(void) {
	scanf("%d\n", &T);
}

void init(void) {
	N = 0;
	memset(a, 0, sizeof(a));
}

void readI(void) {
	char str[MAXL] = {0};
	gets(str);
	int L = strlen(str);
	for (int i = 0; i < L; ++i) {
		if ('2' <= str[i] && str[i] <= '9')
			a[N++] = str[i] - '0';
		if ('1' == str[i])
			a[N++] = 10;
	}
}

bool happy(int n, int b) {
	//printf("n, b == %d, %d\n", n, b); fflush(stdout);
	for (int i = 0; i < MAXSTEPS; ++i) {
		int sum = 0;
		while (n > 0) {
			int mod = n % b;
			sum += mod * mod;
			n /= b;
		}
		if (1 == sum) return true;
		n = sum;
	}
	return false;
}

int solveI(void) {
	int cur = 2;
	while (cur) {
		bool allhappy = true;
		for (int i = 0; i < N; ++i)
			if (!happy(cur, a[i])) {
				allhappy = false;
				break;
			}
		if (allhappy) break;
		++cur;
	}
	return cur;
}

void solve(void) {
	for (int i = 0; i < T; ++i) {
		init();
		readI();
		printf("Case #%d: %d\n", i + 1, solveI());
	}
}

int main(void) {
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);
	read();
	solve();
	return 0;
}
