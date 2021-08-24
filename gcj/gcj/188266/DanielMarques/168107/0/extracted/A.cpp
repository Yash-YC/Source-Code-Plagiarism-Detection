#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)

int ans[1100];
bool marca[1000000];

bool happy(int n, int b) {
	memset(marca, 0, sizeof(marca));
	marca[n] = true;
	while (1) {
		int soma = 0;
		while (n/b != 0) {
			soma += (n % b)*(n % b);
			n = n / b;
		}
		soma += n*n;
		if (soma == 1) return true;
		if (marca[soma]) return false;
		marca[soma] = true;
		n = soma;
		if (n > 1000000-1) printf("FUDEUUUUUUUUUU\n");
	}
}

char s[100];

int main() {
	/*for (int i=1;i<200;i++) {
		//printf("%d\n", i);
		for (int j=2;1;j++) {
			bool inv = false;
			for (int k=0;k<=8;k++)  if ((i & (1<<k)) != 0) {
				if (!happy(j, k+2)) {
					inv = true;
					break;
				}
			}
			if (!inv) {
				ans[i] = j;
				break;
			}
		}
	}
	for (int i=1;i<200;i++) {
		printf("%d\n", ans[i]);
	}*/
	gets(s);
	int T;
	int _42=1;
	int base;
	sscanf(s, " %d", &T);
	while (T--) {
		gets(s);
		int p=0, k;
		int resp=0;
		int tam = strlen(s);
		while (p < tam) {
			sscanf(s+p, " %d%n", &base, &k);
			p += k;
			WATCH(base);
			resp = (resp + (1<<(base-2)));
		}
		WATCH(resp);
		for (int j=2;1;j++) {
			bool inv = false;
			for (int k=0;k<=8;k++)  if ((resp & (1<<k)) != 0) {
				if (!happy(j, k+2)) {
					inv = true;
					break;
				}
			}
			if (!inv) {
				ans[resp] = j;
				break;
			}
		}
		printf("Case #%d: %d\n", _42++, ans[resp]);
	}
	return 0;
}
