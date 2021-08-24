#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXVALUE 1000000

using namespace std;

FILE *fp_r, *fp_w;
char p[MAXVALUE][11];
int t;

int go(int a, int b) {
	if (a == 1) return 1;
	if (p[a][b] == -2) {
		p[a][b] = 2;
		return 2;
	}
	if (p[a][b] != -1) return p[a][b];

	p[a][b] = -2;
	int num = a, sum = 0;
	while(num > 0) {
		sum += (num % b) * (num % b);
		num /= b;
	}
	p[a][b] = go(sum, b);

	return p[a][b];
}

int main() {
	fp_r = fopen("a.in", "r");
	fp_w = fopen("a.out", "w");

	for(int i = 0; i < MAXVALUE; ++i) for(int j = 0; j < 11; ++j) p[i][j] = -1;

	for(int i = 2; i < MAXVALUE; ++i) {
		for(int j = 2; j < 11; ++j) {
			p[i][j] = go(i, j);
		}
	}
/*
	int flag[512];
	memset(flag, 0, sizeof(flag));

	for(int i = 2; i < MAXVALUE; ++i) {
		int f = 0;
		for(int j = 2; j < 11; ++j) {
			if (p[i][j] == 1) f |= (1 << (j-2));
		}
		flag[f] = 1;
	}

	for(int i = 1; i < 512; ++i) {
		if (flag[i] == 1) continue;
		for(int j = 1; j < 512; ++j) {
			if (flag[j] == 0) continue;
			if ((j & i) == i) {
				flag[i] = 1;
				break;
			}
		}
	}

	for(int i = 1; i < 512; ++i) {
		if (flag[i] == 0) {
			printf("ERROR - %d\n", i);
		}
	}
*/
	char str[1000];
	fscanf(fp_r, "%d", &t);
	fgets(str, 1000, fp_r);
	for(int i = 0; i < t; ++i) {		
		vector<int> v;
		int n;

		fgets(str, 1000, fp_r);
		v.clear();
		int len = strlen(str);
		sscanf(str, "%d", &n);
		v.push_back(n);
		for(int j = 0; j < len; ++j) {
			if (str[j] == ' ') {
				sscanf(str + j + 1, "%d", &n);
				v.push_back(n);
			}
		}

		fprintf(fp_w, "Case #%d: ", i+1);
		for(int j = 2; j < MAXVALUE; ++j) {
			bool b = true;
			for(int k = 0; k < v.size(); ++k) {
				if (p[j][v[k]] != 1) {
					b = false;
					break;
				}
			}

			if (b) {
				fprintf(fp_w, "%d\n", j);
				break;
			}
		}
	}

	fclose(fp_w);
	fclose(fp_r);	

	return 0;
}