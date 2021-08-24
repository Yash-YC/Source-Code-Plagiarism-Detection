
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int hap(int x, int b)
{
	int xx, y, z;
	set<int> foi;

	//printf("h %d %d\n", x, b);

	while(x != 1 && (foi.find(x) == foi.end()))
	{
		foi.insert(x);
		y = 0;
		xx = x;
		while(xx)
		{
			z = xx % b;
			xx /= b;
			y += z*z;
		}
		x = y;
		//printf("  x=%d s=%d\n", x, foi.size());
	}

	if(x == 1) return 1;
	return 0;
}

char buf[1024*256];

int main(void)
{
	vector<int> bas;
	int x;
	int i, j;

	int nc, ca;

	gets(buf);
	sscanf(buf, "%d", &nc);
	for(ca=1; ca<=nc; ca++)
	{
		printf("Case #%d: ", ca);

		gets(buf);
		bas.clear();
		for(char* s = strtok(buf, " "); s; s = strtok(NULL, " "))
		{
			sscanf(s, "%d", &x);
			bas.push_back(x);
		}

		for(i=2;; i++)
		{
			for(j=0; j<bas.size(); j++)
			{
				if(!hap(i, bas[j])) break;
			}
			if(j==bas.size()) break;
		}

		printf("%d\n", i);
	}

	return 0;
}
