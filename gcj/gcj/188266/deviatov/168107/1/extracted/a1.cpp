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

vector <string> csv2sa (string csv, char comma)
{
	int n = 0;
	int i = 0, ib = 0;

	if (csv.size () == 0) 
	{
		vector <string> ret0;
		ret0.resize (0);
		return ret0;
	}

	for (i = 0; i < csv.size (); i ++)
	{
		if (csv [i] == comma) n ++;
	}
	if (csv [csv.size () - 1] != comma) 
		n ++;
    
	vector <string> ret;
	ret.resize (n);
	for (n = 0, ib = 0; n < ret.size (); n ++)
	{
		for (i = ib; (i < csv.size ()) && (csv [i] != comma); i ++);
		ret [n] = csv.substr (ib, i - ib);
		ib = i + 1;
	}
	return ret;
}

string trim (string s)
{
	while (s.size () > 0 && isspace (s [0])) 
		s = s.substr (1);
	while (s.size () > 0 && isspace (s [s.size () - 1]))
		s = s.substr (0, s.size () - 1);
	return s;
}

int gcd (int a, int b)
{
	int c = 0;
	do
	{
		c = a % b;
		a = b;
		b = c;
	}
	while (c > 0);
	return a;
}

char s [100]= {0};

#define NN 12000000

int last_sum [NN][10] = {0};
int base = 0;

int rec (int cur, int dp)
{
	if (last_sum [cur][base - 1] != -1)
		return last_sum [cur][base - 1];
	int sum = 0;
	int i = 0;
	int ic = cur;
	while (cur > 0)
	{
		sum += (cur % base) * (cur % base);
		cur /= base;
	}
	if (sum == ic)
	{
		last_sum [ic][base - 1] = sum;
		return sum;
	}
	if (dp > 3000)
	{
		last_sum [ic][base - 1] = -2;
		return -2;
	}
	if (sum >= NN)
		return -2;
	last_sum [ic][base - 1] = rec (sum, dp + 1);
	return last_sum [ic][base - 1];
}

void gen_last_sum ()
{
	int i = 0, j = 0;
	for (i = 0; i < NN; i ++)
	{
		for (j = 0; j < 10; j ++)
			last_sum [i][j] = -1;
	}
	for (j = 2; j <= 10; j ++)
	{
		base = j;
		for (i = 1; i < NN; i ++)
			rec (i, 0);
	}
}

int main ()
{
	FILE* fin, *fout;

	fin = stdin;
	fout = stdout;

	int i = 0, n = 0;
	fscanf (fin, "%d\n", &n);

	gen_last_sum ();

	for (i = 0; i < n; i ++)
	{
		fgets (s, 100, fin);
		string s1 (s);
		vector <string> d1 = csv2sa (trim (s1), ' ');
		vector <int> d2 (d1.size ());
		int j = 0, k  = 0;
		for (j= 0; j < d1.size (); j ++)
		{
			sscanf (d1 [j].data (), "%d", &d2 [j]);
		}

		/*int ans = 1;
		for (j = 0; j < d1.size (); j ++)
		{
			int d = gcd (ans, d2 [j]);
			ans *= d2 [j];
			ans /= d;
		}*/

		for (j = 2; j < NN; j ++)
		{
			for (k = 0; k < d2.size (); k ++)
			{
				if (last_sum [j][d2 [k] - 1] != 1)
					break;
			}
			if (k >= d2.size ())
				break;
		}


		fprintf (fout, "Case #%d: %d\n", i + 1, j);
	}

	fclose (fin);
	fclose (fout);

	return 0;
}

