#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int func (int n, int base, int l) ;

int nm_t;
int ** nm_a;
int * nm_s;
char c;
int main () {
	int i,j,k,h,flag;
	char ass[100];
	char base[10];
	scanf ("%d\n",&nm_t);
	nm_a = (int **)malloc(nm_t * sizeof(int *));
	for (i=0,k=0; i<nm_t; i++) {
		nm_a[i] = (int *) malloc(10* sizeof (int));
		flag = 0;
		for (j=0; j<9; j++) {
			h = 0;
			base[0] = '\0';
			for (; ;) {
				c = getchar ();
				if (c == ' ')
					break;
				else if (c == '\n') {
					flag = 1;
					break;
				}
				base[h] = c;
				h++;
			}
			base[h] = '\0';
			nm_a[i][j] = atoi (base);
	//		printf ("hai %d\n", nm_a[i][j]);
			if (flag == 1)
				break;
	
		}
		nm_a[i][j+1] = -1;
	}

	for (i = 0; i<nm_t; i++ ) {
		for(h=2; ; h++) {
			for (j=0; nm_a[i][j] != -1; j++) {
				if (nm_a[i][j]==2)
					continue;
				if ( (flag = func(h,nm_a[i][j], 0) )!= 1)
					break;
			}
			if (flag == 1) {
				printf ("Case #%d: %d\n", i+1, h);
				break;
			}
		}
	}

}

int func (int n, int base, int l) {
	int i = base,j = 0;
	while (n != 0) {
		j = j + (n%base) * (n%base);
		n = n / base;
	}
	if (j == 1)
		return 1;
	else if (l == 9000)
		return 0;
	return func (j, base, l+1);
}
