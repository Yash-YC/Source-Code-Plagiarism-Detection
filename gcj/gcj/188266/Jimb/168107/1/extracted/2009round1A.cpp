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

int nb;
#define MAXN 100000000
U8 bcache[11][MAXN];

bool isHappy(int n, int base)
{
	assert(n < MAXN);
	if (bcache[base][n])
		return bcache[base][n]==2;
	int n2=n;
	int r=0;
	while (n2)
	{
		int v = n2 % base;
		n2 /= base;
		r += v*v;
	}
	bcache[base][n] = 1; // Not happy if we loop
	if (isHappy(r, base))
		bcache[base][n] = 2;
	return bcache[base][n]==2;
}

static bool b=true;
char *doA(char **&toks)
{
	static char buf[16384];
	nb=0;
	char *s = *toks++;
	char *s2;
	if (b)
	{
		memset(bcache, 0, sizeof(bcache));
		b = false;
		for (int i=0; i<11; i++)
		{
			bcache[i][0] = 1;
			bcache[i][1] = 2;
		}
	}
	int bases[10];
	while (s2 = strtok(s, " "))
	{
		s = NULL;
		bases[nb++] = atoi(s2);
	}
	for (int i=2; ; i++)
	{
		bool bGood=true;
		for (int j=0; j<nb; j++)
		{
			if (!isHappy(i, bases[j]))
				bGood=false;
		}
		if (bGood)
		{
			sprintf(buf, "%d", i);
			return buf;
		}
	}
}
