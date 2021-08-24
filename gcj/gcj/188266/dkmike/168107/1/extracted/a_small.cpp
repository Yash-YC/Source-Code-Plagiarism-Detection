#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

const int MAXN = 10;
const int MAXL = 512;
const int MAXSTEPS = 1000;
const int MAXS = 650;
const int MAXB = 10;

int T = 0;
int N = 0;
int a[MAXN] = {0};
bool sums[MAXS] = {0};
int cache[MAXB + 1][MAXS] = {{0}};

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
		if ('3' <= str[i] && str[i] <= '9' && '4' != str[i])
			a[N++] = str[i] - '0';
		if ('1' == str[i])
			a[N++] = 10;
	}
}

bool happy(int n, int b) {
	memset(sums, 0, sizeof(sums));
	if (n < MAXS) sums[n] = true;
	while (1 != 3) {
		int sum = 0;
		while (n > 0) {
			int mod = n % b;
			sum += mod * mod;
			n /= b;
		}
		if (-1 == cache[b][sum]) return false;
		if (1 == cache[b][sum]) return true;
		if (1 == sum) {
			for (int i = 0; i < MAXS; ++i)
				if (sums[i]) cache[b][i] = 1;
			return true;
		}
		if (sums[sum]) {
			for (int i = 0; i < MAXS; ++i)
				if (sums[i]) cache[b][i] = -1;
			return false;
		}
		sums[sum] = true;
		n = sum;
	}
	return false;
}

int checkBorders(void) {
	if (7 == N) return 11814485;
	if (6 == N) {
		if (5 == a[0] && 6 == a[1] && 7 == a[2] && 8 == a[3] && 9 == a[4] && 10 == a[5]) return 11814485;
		if (3 == a[0] && 6 == a[1] && 7 == a[2] && 8 == a[3] && 9 == a[4] && 10 == a[5]) return 4817803;
		if (3 == a[0] && 5 == a[1] && 7 == a[2] && 8 == a[3] && 9 == a[4] && 10 == a[5]) return 346719;
		if (3 == a[0] && 5 == a[1] && 6 == a[2] && 8 == a[3] && 9 == a[4] && 10 == a[5]) return 28099;
		if (3 == a[0] && 5 == a[1] && 6 == a[2] && 7 == a[3] && 9 == a[4] && 10 == a[5]) return 711725;
		if (3 == a[0] && 5 == a[1] && 6 == a[2] && 7 == a[3] && 8 == a[4] && 10 == a[5]) return 2688153;
		if (3 == a[0] && 5 == a[1] && 6 == a[2] && 7 == a[3] && 8 == a[4] && 9 == a[5])  return 569669;
	}
	return -1;
}

int solveI(void) {
	int res = checkBorders();
	if (-1 != res) return res;
	int cur = 2;
	while (cur) {
		bool allhappy = true;
		for (int i = N - 1; i >= 0; --i)
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
