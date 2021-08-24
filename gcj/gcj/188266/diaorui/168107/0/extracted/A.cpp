#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;
const int N = 100000;
bool dp[N][11];
int input[3];
int n;

int get_next(int n, int base) {
	int res = 0;
	while (n != 0) {
		res += (n % base) * (n % base);
		n /= base;
	}
	return res;
}

int calc() {
	int i, j, tmp, k;
	bool result;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i <= 10; i++) {
		dp[1][i] = 1;
	}
	//printf("n = %d\n", n);
	for (i = 2; i < N; i++) {
		result = true;
		for (j = 0; j < n; j++) {
			k = 0; tmp = i;
			while (k++ < 20 && get_next(tmp, input[j]) > i) tmp = get_next(tmp, input[j]);
			dp[i][input[j]] = dp[get_next(tmp, input[j])][input[j]];
			if (dp[i][input[j]] == 0) {
				result = false;
			}
		}
		if (result) return i;
	}
}

int main() {
	int T;
	char str[10000];
	char *token;
	int t = 1;
	scanf("%d\n", &T);
	while (T--) {
	//scanf("%d\n", &n);
		gets(str);
		//puts(str);
		n = 0;
		token = strtok(str, " ");
		
		while (token != NULL) {
			sscanf(token, "%d", &input[n]);
			n++;
			token = strtok(NULL, " ");
		}
		printf("Case #%d: %d\n", t++, calc());
	}
}
