#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool feliz[1000][20], marca[1000];
char s[300];
bool bases[20];

int num_base(int n, int b) {
	int soma = 0;
	int aux = n;
	while (aux/b != 0) {
		soma += (aux % b) * (aux % b);
		aux = aux / b;
	}
	soma += aux * aux;
	return soma;
}
/*
bool happy(int n, int b) {
	if (marca[n][b]) {
		return feliz[n][b];
	}
	marca[n][b] = true;

	if (n == 1) {
		feliz[n][b] = true;
		return true;
	}

	int soma = 0;
	int aux = n;
	while (aux/b != 0) {
		soma += (aux % b) * (aux % b);
		aux = aux / b;
	}
	soma += aux * aux;

	feliz[n][b] = happy(soma, b);
	return feliz[n][b];
}
*/
bool happy(int n, int b) {
    memset(marca, 0, sizeof(marca));
    //marca[n] = true;
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
        if (n > 1000-1) printf("FUDEUUUUUUUUUU\n");
    }
}

int main() {
	memset(marca, 0, sizeof(marca));
	memset(feliz, 0, sizeof(feliz));
	for (int i=2;i<=800;i++) {
		for (int j=2;j<=10;j++) {
			if (happy(i, j)) feliz[i][j] = true;
		}
	}
	//printf("%d %d %d\n", feliz[210][6], feliz[210][7], feliz[210][8]);
	int T, num, _42=1;
	gets(s);
	sscanf(s, " %d", &T);
	while (T--) {
		gets(s);
		int p=0, k, tam=strlen(s);
		memset(bases, 0, sizeof(bases));
		while (p < tam) {
			sscanf(s+p, " %d%n", &num, &k);
			p += k;
			bases[num] = true;
		}
		int ans=0;
		for (int i=2;i<1000000000;i++) {
			bool val = true;
			for (int j=2;j<=10;j++) if (bases[j]) {
				int num = num_base(i, j);
				//int num=i;
				if (!feliz[num][j]) {
					val = false;
					break;
				}
			}
			if (val) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", _42++, ans);
	}
	return 0;
}
