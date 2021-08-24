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
	fin = fopen("A-small-attempt0.in", "r");
	fout = fopen("A-small-attempt0.out", "w");
	int t;
	fscanf(fin, "%d", &t);
	for (int r = 1; r <= t; ++r) {
		fscanf(fin, "%s", &s);
		res[0] = s[0];
		int len = 1;
		char last = res[0];
		stack<char> head;
		for (int i = 1; i < strlen(s); ++i) {
			if (s[i] >= last) {
				head.push(s[i]);
				last = s[i];
			} else if (s[i] < last) {
				res[len++] = s[i];
			}
		}
		res[len] = '\0';
		fprintf(fout, "Case #%d: ", r);
		while (!head.empty()) {
			fprintf(fout, "%c", head.top());
			head.pop();
		}
		fprintf(fout, "%s\n", res);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}