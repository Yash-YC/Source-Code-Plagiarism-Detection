#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
char s[1001];
char res[1001];

int main()
{
	FILE *fin, *fout;
	fin = fopen("B-small-attempt0.in", "r");
	fout = fopen("B-small-attempt0.out", "w");
	int t;
	fscanf(fin, "%d", &t);
	//scanf("%d", &t);
	for (int r = 1; r <= t; ++r) {
		int n;
		fscanf(fin, "%d", &n);
		vector<bool> nums(2501, false);
		for (int i = 0; i < 2 * n * n - n; ++i) {
			int d;
			fscanf(fin, "%d", &d);
			nums[d] = !nums[d];
		}
		fprintf(fout, "Case #%d:", r);
		for (int i = 1; i <= 2500; ++i) {
			if (nums[i]) {
				fprintf(fout, " %d", i);
			}
		}
		fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}