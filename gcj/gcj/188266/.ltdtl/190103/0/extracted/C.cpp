#include <map>     
#include <set>     
#include <cmath>    
#include <cstdio>   
#include <vector>     
#include <string>     
#include <sstream>    
#include <iostream>    
#include <algorithm>     
using namespace std;     
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)     
#define FORE(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)     
#define SET(x, v) memset(x, v, sizeof (x))     
#define sz size()     
#define cs c_str()     
#define pb push_back     
#define mp make_pair    
 
typedef long long ll;
double cach[42][42];
bool chk[42][42];
double comb[42][42];
int C,N;
double doit(int A, int B) {
	if(B==0) return 0.0;
	double& ret = cach[A][B];
	if(chk[A][B]) return ret;
	chk[A][B] = 1;
	ret = 0.0;
	FOR(k,0,N) {
		// k out of A
		// N-k out of B
		if(A>=k && B>=N-k) {
			double v = doit(A + N-k, B - (N-k)) + 1.0;
			ret += v * comb[A][k] * comb[B][N-k] / comb[C][N];
		}
	}	
	if(A>=N) {//k = N
		double p = comb[A][N] / comb[C][N];
		ret = (p + ret) / (1.0 - p);
	}
	return ret;
}
int main() {
	SET(comb, 0);
	comb[0][0] = 1.0;
	FOR(i,0,42) {
		comb[i][0] = 1.0;
		comb[i][i] = 1.0;
		FOR(j,0,i) 
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}

	int T, e = 0;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&C,&N);
		if(C<N) {
			printf("Case #%d: %.8lf\n",++e, 1.0);
			continue;
		}
		SET(chk, 0);
		SET(cach, 0);
		double ans = doit(0, C);
		printf("Case #%d: %.8lf\n", ++e, ans);
	}
	return 0;
}

