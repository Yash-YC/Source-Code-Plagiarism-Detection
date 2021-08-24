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
const int size = 200;
int next[11][1000000];
void Solve()
{
	int T;
	cin >> T;
	char s[100000];
	gets(s);
	
	for(int b = 2;b < 11;++b)
		for(int i = 0;i < 1000000;++i)
		{
			int r = 0;
			for(int k = i;k > 0;k /= b)
				r += (k % b) * (k % b);
			next[b][i] = r;
		}

	for(int t = 0;t < T;++t)
	{
		gets(s);
		istringstream in(s);
		int a;

		int d[11];
		memset(d,0,sizeof(d));
		for(;in >> a;)
			d[a] = 1;
		int res; 
		bool use[size];
		//int r = 0;
		for(int i = 2;;++i)
		{
			
			for(int j = 2;j < 11;++j)
			{
				if(d[j])
				{
					int base = j;
					memset(use,0,sizeof(use));
					int b = i;
					for(int j = 0;;++j)
					{
						if(j > 10)
						{
							if(use[b] == 1) break;
							use[b] = 1;
							//r = max(r,b);
						}
						if(b >= 1000000)
						{
						int f = 0;
						for(int z = b;z > 0;z /= base)
							f += (z % base) * (z % base);
						b = f;
						}else 
						b = next[base][b];
					}
					if(!use[1]) goto end;
				}
			}
			res = i; break;
end:;
		}
		//cout << r << endl;
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