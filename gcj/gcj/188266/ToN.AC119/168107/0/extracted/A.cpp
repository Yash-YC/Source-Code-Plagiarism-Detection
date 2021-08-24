#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define MAXM 1024000
#define MAXB 16

int n, data[MAX], mem[MAXM][MAXB], use[MAXM][MAXB];
char str[MAX];

int is_happy(int n, int b) {
	int nn, tmp, sum = 0;

	if(n >= MAXM) {
		printf("%d: %d\n", n, b);
		return 0;
	}

	if(mem[n][b] != -1)return mem[n][b];
	if(use[n][b])return 0;
	use[n][b] = 1;

	nn = n;
	while(n > 0) {
		tmp = n % b;
		sum += tmp * tmp;
		n /= b;
	}
	//printf("%d: %d\n", nn, sum);

	if(nn != sum)
		mem[nn][b] = is_happy(sum, b);
	else mem[nn][b] = (sum == 1);
	return mem[nn][b];
}

void find_ans() {
	int i, j, tmp, len;
	char ch;

	gets(str);
	len = strlen(str);
	for(n = 0, j = 0; j < len; n++, j++) {
		sscanf(str + j, "%d", &data[n]);
		tmp = data[n];
		while(tmp > 0) {
			tmp /= 10;
			j++;
		}
	}

	/*printf("%d\n", n);
	for(i = 0; i < n; i++) {
		if(i > 0)printf(" ");
		printf("%d", data[i]);
	}
	printf("\n");*/

	/*for(i = 1; i <= 1000; i++) {
		if(is_happy(i, 10))
			printf("%d\n", i);
	}*/

	for(i = 2; ; i++) {
		for(j = 0; j < n; j++)
			if(!is_happy(i, data[j]))
				break;
		//printf("%d: %d\n", i, data[j]);
		if(j == n) {
			printf("%d", i);
			return;
		}
	}
}

int main(int argc, char *argv[])
{
	int i, j, t;

	for(i = 0; i < MAXM; i++)
		for(j = 0; j < MAXB; j++)
			mem[i][j] = -1;

	gets(str);
	sscanf(str, "%d", &t);
	for(i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		find_ans();
		printf("\n");
	}

	return 0;
}
