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
const int size = 1024;
double d[size][size];
int c,n;
		
vector<int> state;
double rec(int i,int mask)
{
	if(i >= size) return 0;
	if(mask == (1 << c) - 1) return 0;
	if(d[i][mask] != -1) return d[i][mask];
	double &res = d[i][mask];
	res = 0;
	for(int j = 0;j < state.size();++j)
	{
		res += (1.0 + rec(i + 1,mask | state[j])) / state.size(); 
	}
	
	return res;
}
void Solve()
{
	int T;
	cin >> T;
	for(int t = 0;t < T;++t)
	{
		cin >> c >> n;
		for(int i = 0;i < size;++i) 
			for(int j = 0;j < size;++j)
				d[i][j] = -1;
		state.clear();
		for(int i = 0;i < (1 << c);++i)
		{
			int kol = 0;
			for(int b = i;b > 0;b &= b - 1) ++kol;
			if(kol == n) state.push_back(i);
		}
		double res = rec(0,0);
		printf("Case #%d: %.10lf\n",t + 1, res);
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