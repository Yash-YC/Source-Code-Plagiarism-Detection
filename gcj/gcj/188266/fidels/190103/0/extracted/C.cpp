#include <iostream>
#include <cstdio>
using namespace std;

#define MAXC 64
#define MAXT 256
#define MAXN 64

#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )

int N, C;
double p[MAXC][MAXT];

double prob(int c, int n, int nn) {
	if (n > nn || C - c < nn - n) return 0.0;
	else if (nn == 0) {
	   if (n == 0) return 1.0;
		else return 0.0;
	} else {
	   return prob(c-1, n-1, nn-1)*((double)c)/((double)(C - (N-nn))) + prob(c, n, nn-1)*((double)(C-c-(N-nn)))/((double)(C-(N-nn)));
	}
}

/*double prob(int c, int n) {
	double RES = 1.0;

   for (int i=0; i<n; i++) {
	   RES *= ((double)(c-i))/((double)(C-i));
	}
	
	for (int i=0; i<N-n; i++) {
	   RES *= ((double)(C-c-i))/((double)(C-n-i));
	}

	return RES;
}*/

double fill_p(int c, int t) {
   if (p[c][t] < 0.0) {
		p[c][t] = 0.0;
		for (int i=MAX(0, N - (C-c)); i<=MIN(c, N); i++) {
		   p[c][t] += prob(c, i, N)*fill_p(c-i, t-1);
		}
	}
	return p[c][t];
}

int main() {

int i, j, k, T, t;
double RES;

cin >> T;

for (t=1; t<=T; t++) {

cin >> C;
cin >> N;

for (i=1; i<MAXC; i++) {
   for (j=1; j<MAXT; j++) {
	   p[i][j] = -1.0;
	}
}

p[0][0] = 1.0; 
for (i=1; i<MAXC; i++) p[i][0] = 0.0;
for (j=1; j<MAXT; j++) p[0][j] = 0.0;

RES = 0.0;
for (i=0; i<MAXT; i++) {
   RES += i*fill_p(C, i);
}

printf("Case #%d: %.7lf\n", t, RES);

}

return 0;
}
