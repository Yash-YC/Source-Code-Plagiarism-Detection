#include <vector>
#include <string>
#include <list>
#include <map>
#include <utility>
#include <cmath>
#include <algorithm>
#include <sstream>
#include<iostream>
using namespace std;

map <int,double> IsFound;
int T;
int C,N;
long long CAp(int c,int k)
{
	if(k > c) return 0;
	long long res = 1;
	int p = c;
	for(int q = 1;q <= k;q++)
	{
		res *= p--;
		res /= q;
	}
	return res;
}
double find(int k,int n,int m)
{	
	if(k == n) return 0.0;
	if(IsFound.find(k) != IsFound.end()) return IsFound[k];
	long long probefore = CAp(n,m);
	long long proafter = CAp(k,m);
	double nowpro = (double)proafter / probefore;
	double res = 0.0;
	for(int q = 1;q <= m;q++)
	{
		if(q + k > n) break;
		double tmp = (double)(CAp(k,m - q) * CAp(n - k,q)) / probefore;
		res += tmp * find(k + q,n,m);
	}
	return IsFound[k] = (res + 1)/(1 - nowpro);

}

int main()
{
	freopen("..\\C-small-attempt0.in","r",stdin);
	freopen("..\\C-small-attempt0.out","w",stdout);
    scanf("%d",&T);
	for(int i = 1;i <= T;i++)
	{
		scanf("%d%d",&C,&N);
		IsFound.clear();
		printf("Case #%d: %.7f\n",i,find(0,C,N));
	}
	return 0;
}