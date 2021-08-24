#include <stdio.h>
#include <stdlib.h>

int main () {
	int i, j, k, l, m, n, c, o, p, q, r, s, t;
	double resp;
	scanf("%d", &t);
	for (s = 1; s <= t; s++) {
		scanf("%d %d", &c, &n);	
		
		if (c != n) {
			resp = ((double) c /(double) n)*((double) c -(double) n) + (double) 1.0;
			printf("Case #%d: %.7lf\n", s, resp);
		} else {
			printf("Case #%d: 1.0000000\n", s, resp);
		}
	}		
	return 0;	
}
