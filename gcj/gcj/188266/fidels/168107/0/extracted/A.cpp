#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 16777216

int dsum2(int n, int b) {
	int RES = 0;

   while (n > 0) {
	   RES += (n%b)*(n%b);
		n /= b;
	}
	return RES;
}

int ish[MAX][16];

int fill(int n, int b) {
   if (ish[n][b] == -1) {
		ish[n][b] = 0;
	   ish[n][b] = fill(dsum2(n, b), b);
	}
	return ish[n][b];
}

int main() {

int i, j, N, n, B, b[16], tmp;
char in[256];

memset(ish, -1, sizeof(ish));
for (j=2; j<=10; j++) {
	ish[1][j] = 1;
   for (i=2; i<MAX; i++) {
      fill(i, j);
	}
}

scanf("%d\n", &N);

for (n=1; n<=N; n++) {
   gets(in);
	B = tmp = 0;
	for (i=0; in[i]!='\0'; i++) {
	   if (in[i] == ' ') {
		   b[B++] = tmp; tmp = 0;
		} else {
		   tmp = tmp*10 + in[i]-'0';
		}
	}
	b[B++] = tmp;

   for (j=2; j<MAX; j++) {
   	for (i=0; i<B; i++) {
	      if (ish[j][b[i]] != 1) break;
   	}
		if (i == B) {printf("Case #%d: %d\n", n, j); break;}
	}
}

return 0;
}
