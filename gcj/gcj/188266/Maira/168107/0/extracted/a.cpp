#include <cstdio>
#include <cstring>

#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int qtdBases;
int bases[15];

int hap[100000][10];

int res[1100];

char line[10000];
string lineString;

void read() {
	gets(line);
	lineString = string(line);
	
	istringstream s(lineString);
	
	qtdBases = 0;
	int b;
	while (s >> b) {
		bases[qtdBases++] = b;
	}
	/*
	for (int i = 0; i < qtdBases; i++) {
		printf("%d ", bases[i]);
	}
	printf("\n");
	*/
}

void process() {
	int mask = 0;
	
	for (int i = 0; i < qtdBases; i++) {
		mask += (1<<(bases[i]-2));
	}
	
	printf("%d\n", res[mask]);
}

int happy(int num, int b) {
	if (hap[num][b] == -1) {
		if (num == 1) {
			hap[num][b] = 1;
		} else {
			hap[num][b] = 2;
	
			int numAlt = num;
			long long novoNum = 0;
			int dig;
			
			//printf("vou calcular aqui em happy num %d base %d\n", num , b);
			
			while (numAlt != 0) {	
				dig = numAlt%b;
				novoNum += dig*dig;
				
				numAlt /= b;
			}
			
			
			int r = happy(novoNum, b);
			if (r == 1) {
				hap[num][b] = 1;
			} else {
				hap[num][b] = 0;
			}
		}
	}
	
	return hap[num][b];
}

void preprocess() {
	memset(res, -1, sizeof(res));
	memset(hap, -1, sizeof(hap));
	
	int mask;
	for (int i = 2; i <= 100000; i++) {
		mask = 0;
		for (int j = 2; j <= 10; j++) {
			if (happy(i,j) == 1) {
				mask += (1 << (j-2));
			}
		}
		
		//printf("mask de %d -> %d\n", i, mask);
		
		for (int j = 0; j < (1<<9); j++) {
			
			if (res[j] == -1 && ((mask & j) == j)) {
				res[j] = i;
			}
		}
	}
	/*
	int qtd;
	for (int i = 0; i < (1<<9); i++) {
		qtd = 0;
		for (int j = 0; j <= 8; j++) {
			if (((1<<j) & i) != 0) {
				qtd++;
			}
		}
	
		if (qtd <= 3) {
			printf("mask %d -> %d\n", i, res[i]);
		}
	}
	*/
}

int main() {
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	preprocess();
	
	int casos;
	scanf("%d ", &casos);
	
	for (int i = 1; i <= casos; i++) {
		printf("Case #%d: ", i);
		read();
		process();
	}
	
	return 0;
}
