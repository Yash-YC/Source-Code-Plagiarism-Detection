#define INPUT "D:\\code\\gcj09\\C-small-attempt0.in"
#define OUTPUT INPUT ".out.txt"

#include <vector>
#include <string>
#include <cassert>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;
int GI() { int t; scanf("%d", &t); return t; }

int C, N;
double nCr[50][50];
double dp[51][51][51];
bool seen[51][51][51];
// -> 1; -> same state
// 1/1/2 = 2
double go (int C, int N, int a = 0)
{
	int b = C - a;
	if (!b) return 0;
	double &res = dp[C][N][a];
	if (seen[C][N][a]) return res; seen[C][N][a] = 1;

	res = 0;
	double sameState = 0;
	for (int a2 = a; a2 <= C; ++ a2)
	{
		int delA = a2 - a;
		double choice = nCr[b][delA] * (N-delA >= 0 ? nCr[a][N-delA] : 0);
		if (a2 != a)
		res += (1 + go (C, N, a2)) * choice;
		else sameState = choice, res += choice;
	}

	res /= nCr[C][N];
	res /= 1 - sameState/nCr[C][N];
 // E = p*(E+1) + v
 // E=v/1-p
	return res;
}

int main()
{
	assert (freopen(INPUT, "r", stdin));
	assert (freopen(OUTPUT, "w", stdout));
	
	nCr[0][0] = 1;
	for (int n = 1; n < 50; ++ n) 
	{
		for (int r = 0; r <= n; ++ r)
		{
			nCr[n][r] = nCr[n-1][r] + (r ? nCr[n-1][r-1] : 0);
		}
	}
	
	for (int kase = 0, kases = GI(); kase < kases; ++ kase)
	{
		cout << "Case #" << kase+1 << ": ";
		C = GI(); N = GI();
		printf ("%.9lf\n", go(C,N));
	}
	
//	system("pause");
	return 0;
}