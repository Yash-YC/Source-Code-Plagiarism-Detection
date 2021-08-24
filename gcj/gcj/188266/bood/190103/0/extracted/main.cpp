#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

using namespace std;
#define PROBLEM "C"
#define SCALE "small"
#define IN_FILE PROBLEM"-"SCALE".in"
#define OUT_FILE PROBLEM"-"SCALE".out"
int N;
int c,n;

bool is_equal(double a, double b)
{
	return (fabs(a-b)<1e-8);
}

double calc(double c, double n)
{
	int s=0;
	while(c>1.0 && c>0.0) {
		double c0=c,n0=n;
		c-=n;
		n=c/c0*n;
		s++;
	}
	double r=s;
	if(c>0.0 && n>0.0) r+=c/n;
	return r;
}

int main()
{
	freopen(IN_FILE, "r", stdin);
	freopen(OUT_FILE, "w", stdout);

	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>c>>n;
		double r = calc(c,n);
		printf("Case #%d: %.7f\n", i, r);
	}
	return 0;
}
