#define ONLINE_JUDGE
//#define GenerateTest

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>
#include <list>
#include <sstream>
#include <hash_set>
#include <hash_map>

//#include "BigInteger\cbignum.h"

using namespace std;
#pragma comment(linker, "/STACK:64777216")

typedef long long LL;
const int size = 500;
void Solve()
{
	int T;
	cin >> T;
	char s[100000];
	gets(s);
	for(int t = 0;t < T;++t)
	{
		gets(s);
		istringstream in(s);
		int a;

		vector<int> d;
		for(;in >> a;)
			d.push_back(a);
		int res; 
		bool use[size];
		for(int i = 2;;++i)
		{
			
			for(int j = 0;j < d.size();++j)
			{
				int base = d[j];
				//if(d[j])
				{
					memset(use,0,sizeof(use));
					int b = i;
					for(int j = 0;;++j)
					{
						if(j > 5)
						{
							if(use[b] == 1) break;
							use[b] = 1;
						}
						int f = 0;
						for(int z = b;z > 0;z /= base)
							f += (z % base) * (z % base);
						b = f;
					}
					if(!use[1]) goto end;
				}
			}
			res = i; break;
end:;
		}
		printf("Case #%d: %d\n",t + 1, res);
	}
}

int main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);

	freopen("output.txt", "wt", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	
#ifdef GenerateTest
	
	freopen("output.txt", "wt", stdout);

#endif

	clock_t start = clock();
#endif

	Solve();	

#ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout <<"\n\nTime: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
#endif
	return 0;
}