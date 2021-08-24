#include <cstring>
#include <cstdio>
#include <cstdlib>

int s[2500];

void run(int cas) {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < 2*n-1; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			s[x] ^= 1;
		}
	printf("Case #%d:", cas);
	for (int i = 0; i <= 2500; i++)
		if (s[i] == 1) {
			s[i] = 0;
			printf(" %d", i);
		}
	printf("\n");
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int cas = 1; cas <= tt; cas++)
        run(cas);
}

