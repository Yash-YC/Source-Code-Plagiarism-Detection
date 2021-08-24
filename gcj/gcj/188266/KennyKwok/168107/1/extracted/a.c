#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define FGETS(s,n,p)	s[0] = 0; fgets(s,n,p)
#define FOR(i,a,b)	for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i,a,b)	for (int i(a), _b(b); i >= _b; --i)
#define REP(i,n)	for (int i(0), _n(n); i < _n; ++i)
#define REPD(i,n)	for (int i((n)-1); i >= 0; --i)
#define FILL(a,c)	memset(&a, c, sizeof(a))

typedef unsigned long long	ull;
typedef long long		ll;

template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }

#define maxhz 100000
int hz = maxhz;
int h[11][maxhz];	// 0: unknown, 1: happy, -1: badlisted

#include <math.h>

int is_happy(unsigned long long value, unsigned int base)
{
//printf(" %llu", value);
	if (value >= maxhz || h[base][value] == 0)
	{
		if (value <= 1)
		{
			int result = (value == 1? 1: 0);
			h[base][value] = (result == 1? 1: -1);
			return result;
		}
		else
		{
			unsigned long long v = value;
			unsigned long long nv = 0;
if (value < maxhz)
{
			h[base][value] = -1;	// Assume unhappy first!
}
			do
			{
				nv += pow(v % base, 2);
				v /= base;
			} while (v > 0);
			int result = is_happy(nv, base);
if (value < maxhz)
{
			h[base][value] = (result == 1? 1: -1);
}
			return result;
		}
	}
	else if (h[base][value] == 1)
	{
		return 1;	// TRUE;
	}
	return 0;	// FALSE;
}
int xis_happy(unsigned long long value, unsigned int base)
{
	unsigned long long v = value;
	ull nv;
printf("v:(%llu, %d)", v, base);
	while (v >= base)
	{
/*
		if (v < hz)
		{
			if (h[v] == -1) return 0;
			if (h[v] == 1) return 1;
		}
*/
		{
unsigned long long ov = v;
			nv = 0;
			do
			{
				nv += pow(v % base, 2);
				v /= base;
			} while (v > 0);
//printf(" >>>%llu(%llu)", v, nv);
			if (ov == nv) break;
			v = nv;
		}
printf(" >>>%llu", v);
	}
	int happy = (v == 1? 1: 0);
printf(" = %d\n", happy);
	return happy;
}

/*
void gen_happy(int max)
{
	for (int i = 0; i < max; i++)
	{
		is_happy
	}
}
*/

int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int N;

memset(h, 0, sizeof(h));
for (int i = 0; i <= 10; i++)
{
	h[i][0] = -1;
	h[i][1] = 1;
}
//gen_happy(100000);
/*
for (int i = 1; i < 100; i++)
{
	is_happy(i, 10);
}
*/

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &N);
	REP(c,N)
	{
		int bz, b[10];

//	Data preparaion put here
		FGETS(buf, 4096, in);
		{
			int ptr = 0;
			bz = 0;
			for (int i = 0; i < 10; i++)
			{
				int n = 0;
				b[bz] = 0;
				sscanf(buf+ptr, "%d%n", &b[bz], &n);
				ptr += n;
				if (n == 0) break;
				bz++;
			}
		}
/*
if (1)
{
printf("%d", bz);
for (int i = 0; i < bz; i++)
{
	printf(" %d", b[i]);
}
printf("\n");
}
*/
		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here

unsigned long long i = 3;
for (;;i++)
{
	int good = 1;
	for (int j = 0; j < bz; j++)
	{
//printf("(%llu, %d)", i, b[j]);
		if (!is_happy(i, b[j]))
		{
			good = 0;
//printf("\n");
			break;
		}
//printf("\n");
	}
	if (good)
	{
		printf("%llu\n", i);
		break;
	}
}


	}
	return 0;
}
