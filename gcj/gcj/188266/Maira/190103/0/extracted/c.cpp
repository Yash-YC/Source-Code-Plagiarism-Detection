#include <cstdio>
#include <cstring>
#include <cmath>

#include <algorithm>

#define EPS 1e-6

using namespace std;

long long comb[50][50];
int nums[50];

int primos[7] = {2,3,5,7,11,13,17};

int C, N;
long long tot;
double a[50][50];
double b[50];

void read() {
	scanf("%d%d", &C, &N);
}

void criarSistema() {
	for (int i = 0; i <= C; i++) {
		for (int j = 0; j <= C; j++) {
			a[i][j] = 0.0;
		}
		b[i] = 0.0;
	}
	tot = comb[C][N];
	
	long long num;
	int extra;
	for (int i = 0; i < C; i++) {
		a[i][i] = 1.0;
		for (int j = max(i,N); (j-i) <= N && j <= C; j++) {
			extra = j-i;
			num = comb[i][N-extra]*comb[C-i][extra];
			
			a[i][j] -= ((double)num)/tot;
			
		}
		
		b[i] = 1.0;
	}
	
	a[C][C] = 1.0;
	b[C] = 0.0;
	/*
	for (int i = 0; i <= C; i++) {
		for (int j = 0; j <= C; j++) {
			printf("%.2lf ", a[i][j]);
		}
		
		printf("    %.2lf\n", b[i]);
	}
	printf("\n");
	*/
}

void trocar(int linha1, int linha2) {
	double temp;
	for (int j = 0; j <= C; j++) {
		temp = a[linha1][j];
		a[linha1][j] = a[linha2][j];
		a[linha2][j] = temp;
	}
}

int cmpEPS(double a, double b) {
	if (fabs(a - b) < EPS) {
		return 0;
	} else if (a - b < -EPS) {
		return -1;
	} else {
		return 1;
	}
}

void elimGauss() {
	double mult;
	for (int i = 0; i <= C; i++) {

		if (cmpEPS(a[i][i],0) == 0) {
			for (int d = i+1; d <= C; d++) {
				if (cmpEPS(a[d][i],0) != 0) {
					trocar(i, d);
					break;
				}
			}			
		}
		
		if (cmpEPS(a[i][i],0) != 0) {
			for (int d = i+1; d <= C; d++) {
				mult = -a[d][i]/a[i][i];
			
				for (int j = i+1; j <= C; j++) {
					a[d][j] = a[d][j] + mult*a[i][j];
				}
				a[d][i] = 0;
				
				b[d] = b[d] + mult*b[i];
			}
		}
	}
	/*
	for (int i = 0; i <= C; i++) {
		for (int j = 0; j <= C; j++) {
			printf("%.2lf ", a[i][j]);
		}
		
		printf("    %.2lf\n", b[i]);
	}
	printf("\n");
	*/
	
	bool calcula;
	for (int i = C; i >= 0; i--) {
		
		if (cmpEPS(a[i][i],0) != 0) {
			for (int j = i+1; j <= C; j++) {
				if (cmpEPS(a[i][j],0) != 0) {
					b[i] -= b[j]*a[i][j];
				}
			}
			
			b[i] /= a[i][i];
		}
	}
}

void process() {
	criarSistema();
	
	elimGauss();
	
	printf("%lf\n", b[0]);
}

void calcComb(int a, int b) {
	if (b > a/2) {
		comb[a][b] = comb[a][a-b];
	} else {
		for (int i = 0; i < b; i++) {
			nums[i] = a-i;
		}
		
		int p, val;
		for (int i = b; i >= 2; i--) {
			val = i;
			for (int j = 0; j < 7; j++) {
				p = primos[j];
				
				while (val%p == 0) {
					for (int k = 0; k < b; k++) {
						if (nums[k]%p == 0) {
							nums[k]/=p;
							break;
						}
					}
					
					val /= p;
				}
			}
		}
		
		long long res = 1;
		for (int i = 0; i < b; i++) {
			res *= nums[i];
		}
		
		comb[a][b] = res;
	}
}

void preprocess() {
	memset(comb, 0, sizeof(comb));
	for (int i = 0; i <= 40; i++) {
		for (int j = 0; j <= i; j++) {
			calcComb(i,j);
		}
	}
	/*
	for (int i = 0; i <= 40; i++) {
		for (int j = 0; j <= i; j++) {
			printf("comb de %d %d -> %lld\n", i, j, comb[i][j]);
		}
	}
	*/
}

int main() {
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	
	preprocess();
	
	int casos;
	scanf("%d", &casos);
	
	for (int i = 1; i <= casos; i++) {
		printf("Case #%d: ", i);
		read();
		process();
	}
	
	return 0;
}
