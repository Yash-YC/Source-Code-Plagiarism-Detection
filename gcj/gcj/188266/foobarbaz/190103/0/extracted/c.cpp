#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;

int64 INF = 1000*1000*1001;

double ht[128][128], pt[128][128];

int N, C;


void put(int a, int b, vector<double>& nu, vector<double>& den)	{
	if (a < b)	{
		nu.PB(0.0);
		den.PB(1.0);
		return;
	}
	if (b > a - b)	b = a - b;
	FOR (i, 0, b)	{
		nu.PB(a - i);
		den.PB(i+1);
	}
}

double p(int i, int j)	{
	if (pt[i][j] != -1.0)	return pt[i][j];
	//adding j - i to a set of size i
	//if (i == j && i < N)	return p[i][i] = 0.0;
	
	int add = j - i;
	//(C - i choose add) * (i choose N - add)
	//return pt[i][j] = choose(C - i, add) * choose(i, N-add) / choose(C, N);
	
	vector<double> nu, den;
	put(C-i, add, nu, den);
	put(i, N-add, nu, den);
	put(C, N, den, nu);
	
	SORT(nu);
	SORT(den);
	assert(nu.SZ == den.SZ);
	double ret = 1.0;
	FOR (t, 0, nu.SZ)	{
		ret *= nu[t] / den[t];
	}
	return pt[i][j] = ret;
	
}

double h(int i, int j)	{
	if (i >= j)	return 0.0;
	if (ht[i][j] != -1.0)	return ht[i][j];
	
	double ret = 1.0;
	for (int k = i+1; k <= i+N && k <= j; k++)	{
		ret += p(i, k) * h(k, j);
		//cout << "doing " << k << ", " << j << endl;
	}
	ret /= 1.0 - p(i, i);
	return ht[i][j] = ret;
}

int main(void)	{
	int T;
	cin >> T;
	FOR (nc, 1, T+1)	{
		cin >> C >> N;
		FOR (i, 0, 128)	FOR (j, 0, 128)	ht[i][j] = pt[i][j] = -1.0;
		cout << "Case #" << nc << ": ";
		printf("%0.7lf\n", h(0, C));
		/*
		FOR (i, 0, C+1)	{
			FOR (j, 0, C+1)	cout << ht[i][j] << "\t";
			cout << endl;
		}
		*/
	}
}
