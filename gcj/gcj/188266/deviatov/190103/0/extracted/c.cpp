#define _USE_MATH_DEFINES

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

double C (double n, double k)
{
	double ans = 1;
	for (int i = 0; i < k; i ++)
	{
		ans *= (n - i);
		ans /= (i + 1);
	}
	return ans;
}

double get_ans (int n, int k)
{
	double ans = 0;
	int r = 0;
	for (r = k; r < n; r ++)
	{
		ans += 1./(1. - C (r, k) / C (n, k));
	}
	return ans;
}

int main ()
{
	FILE* fin, *fout;

	fin = stdin;
	fout = stdout;

	int i = 0, n = 0;
	fscanf (fin, "%d", &n);

	for (i = 0; i < n; i ++)
	{
		int k = 0, c = 0;

		fscanf  (fin, "%d%d", &c, &k);

		double ans = 1+get_ans (c, k);

		fprintf (fout, "Case #%d: %.9lf\n", i + 1, ans);
	}

	fclose (fin);
	fclose (fout);

	return 0;
}
