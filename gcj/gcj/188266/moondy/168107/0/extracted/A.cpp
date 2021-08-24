#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

const int MAXN = 12000000;
char st[100];

int now[20000000][11];

inline int sqr(int x) {
	return x * x;
}

bool solve(int cur, int base) {
	now[cur][base] = -1;
	int tmp = cur, sum = 0;
	while (cur) {
		sum += sqr(cur % base);
		cur /= base;
	}
	cur = tmp;
	if (sum == 1) {
		now[cur][base] = 1;
		return true;
	}
	if (now[sum][base]) {
		now[cur][base] = now[sum][base];
		return now[sum][base] == 1;
	}
	now[cur][base] = solve(sum, base);
	return now[cur][base] == 1;
}

int ans[1000];

int main() {

	memset(now, 0, sizeof(now));
	for (int i = 0; i < (1 << 9); i++) ans[i] = MAXN;
	for (int i = 2; i < MAXN; i++) {
		int state = 0;
		for (int base = 2; base <= 10; base++) {
			if (!now[i][base]) solve(i, base);
			if (now[i][base] == 1) {
				state += (1 << (base - 2));
			}
		}
		for (int j = 0; j <= state; j++)
			if ((j & state) == j) ans[j] = min(ans[j], i);
//		ans[state] = min(ans[state], i);
	}
	for (int i = 1; i < (1 << 9); i++) printf("mask = %d, ans = %d\n", i, ans[i]);


	int test, x;
	scanf("%d", &test);
	getchar();
	for (int i = 1; i <= test; i++) {
		printf("Case #%d: ", i);
		gets(st);
		istringstream is(st);
	
		int res = 0;
		while (is >> x) {
//			printf("x = %d\n", x);
			res += 1 << (x - 2);
		}
		printf("%d\n", ans[res]);				
	}
	return 0;
}

