/*
 * C.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Sep 12, 2009
 */


#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double   	  ld;

const int OO = (int)1e8;	//Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

const int MAX = 55;
ll C[MAX][MAX] = {0};


void build_nCk() {
    lp(i, MAX) lp(j, MAX)
    	C[i][j] = (j == 0) ? 1 : ( (i == 0) ? 0 : C[i-1][j-1]+C[i-1][j]);
}
int c, n;
double p;

double  memo[50];
bool vis[50];

double go(int good)
{
	if(good == c )
		return 0.0;

	if(vis[good])
		return memo[good];

	//choices that add values
	double r1 = 0;
	for (int i = min(n, c-good); i >= 1; --i) {
		ll a = C[c-good][i]*C[good][n-i];
		r1 += a*(1/p)*(1+go(good+i) );
	}


	double r2 = C[good][n];

	double ret = (p*r1+r2) / (p-r2);

	vis[good] = 1;
	return memo[good] = ret;
}

int main()
{

	build_nCk();

	freopen("c.in", "rt", stdin);
	freopen("c.txt", "wt", stdout);

	int cases;
	cin>>cases;

	int cc = 1;
	while(cases--) {
		cin>>c>>n;
		p = C[c][n];

		cout.setf(ios::fixed);
		cout.precision(7);

		clr(vis, 0);
		double ans = go(0);

		cout<<"Case #"<<cc++<<": "<<ans<<"\n"<<flush;
	}

	return 0;
}
