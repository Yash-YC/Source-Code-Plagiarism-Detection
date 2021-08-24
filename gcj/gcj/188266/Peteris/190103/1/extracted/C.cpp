#include <functional> 
#include <algorithm> 
#include <iostream> 
#include <complex> 
#include <cstring> 
#include <numeric> 
#include <sstream> 
#include <fstream>
#include <limits> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <queue> 
#include <map> 
#include <set> 
using namespace std; 

template <class T, bool B> struct cmp_ { inline static bool cmp(T a, T b) { return a < b; } };  
template <class T> struct cmp_<T, false> { inline static bool cmp(T a, T b) { return a != b; } };  
#define FOR(i, b, e) for (typeof(b) i = (b); cmp_< typeof(b), numeric_limits< typeof(b) >::is_specialized >::cmp(i, e); ++i)

#define MAX 42
int C, N;
double ev[MAX];
long long Cm[MAX][MAX];

long long c(int n, int k)
{
	if (Cm[n][k] != -1) return Cm[n][k];
	return Cm[n][k] = c(n-1,k) + c(n-1,k-1);
}

int main()
{
ifstream fin("in.in");
ofstream fout("out.out");
int T;
fin >> T;
FOR(tc, 0, T)
{
	fin >> C >> N;

	FOR(i, 0, 41) FOR(j, 0, 42) Cm[i][j] = -1;
	FOR(i, 0, 41) Cm[i][0] = Cm[i][i] = 1;
	FOR(i, 0, 2) Cm[1][i] = 1;

	ev[C] = 0;
	double S, P;
	for (int t = C - 1; t >= N; --t)
	{
		S = 0;
		for (int k = 1; k <= C - t && k <= N; ++k) if (N - k <= t) S += (double)c(C-t,k) / c(C,N) * c(t,N-k) * (1 + ev[t + k]);
		P = (double)c(C-t,0) / c(C,N) * c(t,N);
		ev[t] = (S + P) / (1 - P);
	}
	ev[0] = ev[N] + 1;
	fout << "Case #" << tc + 1 << ": " << ev[0] << endl;
}

	return 0;
}
