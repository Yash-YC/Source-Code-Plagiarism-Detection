#include <stdio.h>
#include <string.h>

static int seen[11][1000];


void markhappy(int b, int n0) {
	int sum = 0, n;
	n = n0;
	do {
		int q = n / b;
		int r = n % b;
		sum = r*r;
		
		while (q > 0) {
			r = q % b;
			q = q / b;
			sum += r*r;
		}
		if (n<1000) {
//			printf ("%d %d is happy\n", b, n0);
			seen[b][n] = 2;
		}
		n = sum;
	} while (sum > 1);
}


bool ishappy(int b, int n0) {
	int sum = 0, n;
	n = n0;
//	printf ("is happy base %d n=%d\n", b, n);
	do {
		//if (n >= 1000)			printf(" - %d\n", n);
		if (n < 1000 && seen[b][n]) {
			if (seen[b][n]-1)
				markhappy(b, n0);
			return seen[b][n]-1;
			}
		int q = n / b;
		int r = n % b;
		sum = r*r;
		
//		printf("%d", r);
		while (q > 0) {
			r = q % b;
//			printf("%d", r);
			q = q / b;
			sum += r*r;
		}
		if (n < 1000)
			seen[b][n] = (sum==1)+1;
//		printf("\n");
//		printf ("happy sum b %d n %d : %d\n", b, n, sum);
		n = sum;
		if (n >= 1000)
			printf("bad! %d %d\n", b, n);
	} while (sum > 1);
	if (n0 < 1000)
		markhappy(b, n0);
	return 1;
}
int happy(int n, int bases[]) {
	int i, j, b;
	
	int q = 2;
	while (1) {
		for (i=0; i < n; ++i) {
			b = bases[i];
			if (!ishappy(b, q))
				break;
		}
		if (i==n) {
//		printf("%d\n", q);
			return q;
			}
		q++;
	}
}


int main() {
	int n;
	scanf("%d\n", &n);
	int bases[10];
	for (int c=0; c < n; c++) {
		int i = 0;
		char buf[256], *s = buf;
		fgets(buf, 256, stdin);
		i = sscanf(buf, "%d %d %d %d %d %d %d %d %d %d\n", bases, bases+1, bases+2, bases+3, bases+4,bases+5, bases+6, bases+7, bases+8, bases+9);
		scanf("\n");
		printf ("Case #%d: %d\n", c+1, happy(i, bases));
		fflush(stdout);
	}

}