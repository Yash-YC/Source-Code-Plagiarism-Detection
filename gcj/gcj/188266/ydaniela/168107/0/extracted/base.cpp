#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int comp(const void *a, const void *b) {
	char *aux = (char *) a;	
	char *aux2 = (char *) b;
	
	if ((*aux) < (*aux2)) {
		return -1;	
	} else if ((*aux) == (*aux2)) {
		return 0;	
	} else {
		return 1;	
	}
}

int main () {
	int i, j, k, l, m, n, o, p, q, r, s, t, b;
	char vet[105];
	int bases[15];
	int MAX = 700000;
	int str[100];
	
	set<int> conj;
	set<int>::iterator it;
	char **happy;
	happy = (char **) malloc(sizeof(char *) * MAX);
	for (i = 0; i < MAX; i++) {
		happy[i] = (char *) malloc(sizeof(char) * 11);	
	}
	
	for (i = 0; i < 11; i++) {
		happy[1][i] = '1';
		happy[0][i] = '0';	
	}
	for (i = 2; i < MAX; i++) {
		for(b = 2; b < 11; b++) {
			happy[i][b-1] = '2';
		}	
	}
	
	for (b = 2; b < 11; b++) {
		for (i = 2; i < MAX; i++) {
			if (happy[i][b-1] == '2') {
			k = i;
			l = 0;
	//		printf("%d %d ", b, k);
			while (k > 0) {
				l = l + (k%b)*(k%b);
				k = k/b;
			}
	//		sprintf(vet, "%d", l);	
	//		printf("%d ", l);
	//		qsort(vet, strlen(vet), sizeof(char), comp);
	//		l = atoi(vet);
	//		printf("%d\n", l);
			if (l < i) {
				happy[i][b-1] = happy[l][b-1];	
			} else {
				conj.clear();
				conj.insert(l);
				k = l;
				while (1) {
					l = 0;
					while (k > 0) {
						l = l + (k%b)*(k%b);
						k = k/b;
					}
					if (l < i) {
						happy[i][b-1] = happy[l][b-1];
					/*	for (it = conj.begin(); it != conj.end(); it++) {
							m = *it;
							happy[m][b-1] = happy[l][b-1];	
						}*/
						break;
					}
					k = l;
					
					if (conj.find(k) == conj.end()) {
						conj.insert(k);
					} else {
						happy[i][b-1] = '0';
					/*	for (it = conj.begin(); it != conj.end(); it++) {
							m = *it;
							happy[m][b-1] = '0';	
						}*/
						break;
					}
				}	
			}
			}			
		}
	}
	
/*	for (i = 2; i < MAX; i++) {
		printf("%d ", i);
		for(b = 2; b < 11; b++) {
			printf(" %c", happy[i][b-1]);	
		}	
		printf("\n");
	}*/
	
	scanf(" %d ", &t);
	for (s = 1; s <= t; s++) {
		fgets(vet, 105, stdin);
		r = strlen(vet);
		if (vet[r-1] == '\n') {
			r--;	
		}
		i = 0;
		j = 0;
		while (i < r) {
			k = 0;
			while (i < r && vet[i] != ' ') {
				k = (k*10) + vet[i] - '0';
				i++;
			}
			bases[j++] = k;
			i++;
		}
		r = 0;
		for (i = 2; i < MAX; i++) {
			q = 0;
			for (l = 0; l < j; l++) {
				if (happy[i][bases[l]-1] == '0') {
					q = 1;
					break;	
				}	
			}
			if (!q) {
				r = i;
				break;	
			}
		}	
		printf("Case #%d: %d\n", s, r);
	}
	
	return 0;	
}
