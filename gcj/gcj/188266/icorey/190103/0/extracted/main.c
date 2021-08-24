#include <stdlib.h>
#include <stdio.h>

int main(int c, char* argv[]) {
	FILE *f, *o;
	int a, T, N, C;
	double exp;

	f = fopen("C.in", "r");
	o = fopen("C.out", "w");

	fscanf(f, "%d\n", &T);

	for (a = 0; a < T; ++a) {
		fscanf(f, "%d %d\n", &C, &N);
		exp = 1 + (double)(C - N) * (double)C / (double)N;
		fprintf(o, "Case #%d: %lf\n", a+1, exp);
	}

	fclose(f); fclose(o);
}
