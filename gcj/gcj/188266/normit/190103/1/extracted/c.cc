#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

ll combi[50][50];

double dy[100];
int c,n;

ll GetCombi(int a, int b)
{
	if(b == 0 || a == b) return 1;
	if(b > a || a < 0 || b < 0) return 0;

	ll &ret = combi[a][b];
	if(ret != -1) return ret;
	ret = 0;
	ret = GetCombi(a-1,b-1)+GetCombi(a-1,b);
	return ret;
}


void Calc(int i)
{
	if(i >= c) { dy[i] = 0; return; }
	double ret = 1.;

	for(int j=0; j <= n; ++j) {
		double p = (double)GetCombi(i,n-j) * (double)GetCombi(c-i,j) /
			(double)GetCombi(c,n);
		ret += p*dy[i+j];
	}
	dy[i] = ret;
}

void process(int kase)
{
	scanf("%d %d",&c,&n);
	printf("Case #%d: ",kase);

	REP(i,100) dy[i] = 0;

	for(int j=0; j < 10000; ++j) {
		for(int k=c-1; k >= 0; --k) Calc(k);
	}
	printf("%.7lf\n", dy[0]);
}

int main()
{
	int t;
	REP(i,50) REP(j,50) combi[i][j] = -1;

	scanf("%d",&t);
	REP(i,t) process(i+1);

	return 0;
}
