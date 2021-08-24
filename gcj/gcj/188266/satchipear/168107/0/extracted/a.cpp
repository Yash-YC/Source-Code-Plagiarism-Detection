#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;
char happy[11][111111];

void checkhappy(int b, int n) {
	int d[111], dn = 0, x = 0;
	int m = n;
	if (m == 1) {
		happy[b][m] = 1;
		return;
	}
	happy[b][m] = 2;
	while (n) d[++dn] = n % b, n /= b;
	for (int i = 1; i <= dn; i++) {
		x += d[i] * d[i];
	}
	if (x == m) {
		happy[b][m] = 2;
		return;
	}
	if (!happy[b][x]) checkhappy(b, x);
	happy[b][m] = happy[b][x];
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	char s[1111];
	int tn;
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j <= 100000; j++) {
			checkhappy(i, j);
		}
	}
/*	for (int i = 2; i <= 9; i++) {
		printf("Base %d:", i);
		for (int j = 1; j <= 200; j++) {
			if (happy[i][j] == 1) printf(" %d", j);
		}
		printf("\n");
	}	
	printf("hello\n");*/
	int chk[12], cn, prob = 0;
	for (scanf("%d", &tn), gets(s); tn--; ) {
		gets(s);
		istringstream in(s);
		cn = 0;
		while (in >> chk[cn + 1]) cn++;
		for (int i = 2; i <= 100000; i++) {
			bool found = true;
			for (int j = 1; j <= cn; j++) {
				if (happy[chk[j]][i] != 1) {
					found = false; break;
				}
			}
			if (found) {
				printf("Case #%d: %d\n", ++prob, i);
				break;
			}
		}
	}
	return 0;
}
