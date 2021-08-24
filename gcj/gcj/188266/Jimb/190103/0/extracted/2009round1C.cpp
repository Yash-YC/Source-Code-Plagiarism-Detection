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

double noUniqueChance(int have, int total, int draw)
{
	double r=1;
	for (int i=0; i<draw; i++)
	{
		r *= (have - i) / (double)(total-i);
	}
	return r;
}

bool bcache[41][41][41][41];
double dcache[41][41][41][41];

double chanceOf(int numNew, int have, int total, int draw)
{
	if (total == 0)
		return 0;
	if (numNew < 0)
		return 0;
	if (numNew > draw)
		return 0;
	if (bcache[numNew][have][total][draw])
		return dcache[numNew][have][total][draw];
	double r;
	if (numNew == 0) 
	{
		r = noUniqueChance(have, total, draw);
	} else {
		r = (total-have)/(double)(total) * chanceOf(numNew-1, have, total-1, draw-1) +
			(have)/(double)(total) * chanceOf(numNew, have-1, total-1, draw-1);
	}
	bcache[numNew][have][total][draw] = true;
	dcache[numNew][have][total][draw] = r;
	return r;
}

char *doC(char **&toks)
{
	static char buf[16384];
	double r=0;
	int N = atoi(*toks++);
	int C = atoi(*toks++);
	double cur[40];
	double cur2[40];
	if (N == C)
		return "1";

	memset(cur, 0, sizeof(cur));
	cur[C] = 1.0;
	for (int i=2; ; i++)
	{
		memset(cur2, 0, sizeof(cur2));
		for (int j=C; j<N; j++)
		{
			// j is how many unique we have
			double v = noUniqueChance(j, N, C);
			for (int k=0; k<=MIN(C, N-j); k++)
			{
				cur2[j+k] += cur[j] * chanceOf(k, j, N, C);
			}
		}
		double d = cur2[N] * i;
		r += d;
		if (d < 1e-20*r && i > 10000)
			break;
		memcpy(cur, cur2, sizeof(cur));
	}

	sprintf(buf, "%1.7f", r);
	return buf;
}
