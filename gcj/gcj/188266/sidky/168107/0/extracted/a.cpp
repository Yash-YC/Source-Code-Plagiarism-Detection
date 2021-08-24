#include <iostream>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

#define	sz(v)	(int)v.size()
#define	rep(i,n)	for((i)=0;(i) < (n); (i)++)
#define	rab(i,a,b)	for((i)=(a);(i) <= (b); (i)++)
#define	Fi(N)		rep(i,N)
#define	Fj(N)		rep(j,N)
#define	Fk(N)		rep(k,N)

int get(int num, int base)
{
	int	t = 0;

	while(num)
	{
		int	x = num % base;
		t += x * x;
		num /= base;
	}
	return t;
}

bool ishappy(int num, int base)
{
	set <int>	s;

	while(s.find(num) == s.end())
	{
		if(num == 1) return true;
		s.insert(num);
		num = get(num,base);
	}
	return false;
}

int main()
{
	int	T,cs;
	int	base[100];
	int	tbase;

	scanf("%d",&T);
	while(getchar() != '\n');

	rab(cs,1,T)
	{
		tbase = 0;

		while(true)
		{
			char	c = getchar();
			if(c == '\n' || c == (char)EOF) break;
			else ungetc(c,stdin);

			scanf("%d",&base[tbase++]);
		}

		int	i;

		for( i = 2; ;i++)
		{
			int	j;

			for(j = 0; j < tbase; j++)
			{
				if(!ishappy(i,base[j]))
					break;
			}

			if(j >= tbase) break;
		}

		printf("Case #%d: %d\n",cs,i);
	}
	return 0;
}
