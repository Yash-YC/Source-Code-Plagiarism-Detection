// Using libUtil from libGlov (Game Library of Victory) available at http://bigscreensmallgames.com/libGlov
#include "utilUtils.h"
#include "utilFile.h"
#include "utilString.h"
#include "assert.h"
#include "utilArray.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include "utilRand.h"
#include <vector>
using namespace std;

int bases[10];
int nb;
#define MAXN 1000000
U8 bcache[10][MAXN];

bool isHappy(int n, int basei)
{
	assert(n < MAXN);
	if (bcache[basei][n])
		return bcache[basei][n]==2;
	int n2=n;
	int r=0;
	while (n2)
	{
		int v = n2 % bases[basei];
		n2 /= bases[basei];
		r += v*v;
	}
	bcache[basei][n] = 1; // Not happy if we loop
	if (isHappy(r, basei))
		bcache[basei][n] = 2;
	return bcache[basei][n]==2;
}

char *doA(char **&toks)
{
	static char buf[16384];
	nb=0;
	char *s = *toks++;
	char *s2;
	memset(bcache, 0, sizeof(bcache));
	while (s2 = strtok(s, " "))
	{
		s = NULL;
		bcache[nb][0] = 1;
		bcache[nb][1] = 2;
		bases[nb++] = atoi(s2);
	}
	for (int i=2; ; i++)
	{
		bool bGood=true;
		for (int j=0; j<nb; j++)
		{
			if (!isHappy(i, j))
				bGood=false;
		}
		if (bGood)
		{
			sprintf(buf, "%d", i);
			return buf;
		}
	}
}
