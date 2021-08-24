#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker,"/STACK:64000000")

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;

template<class T>T abs(T x) { return (x>0) ? x : -x; }
template<class T>T sqr(T x) { return x*x;            }

double c[50][50];

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	for (int i=0; i<50; i++)
		for (int j=0; j<50; j++) {
			if (i<j) continue;
			if (j==0) {
				c[i][j]=1;
				continue;
			}
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	int tn;
	cin>>tn;
	for (int tst=1; tst<=tn; tst++) {
		int N,n;
		cin>>N>>n;
		vector<double> a(N+1);
		for (int i=1; i<=N; i++) {
			a[i]=1;
			for (int t=1; t<=min(i,n); t++)
				a[i]+=1./c[N][n]*c[i][t]*c[N-i][n-t]*a[i-t];
			a[i]/=1.-1./c[N][n]*c[N-i][n];
		}
		printf("Case #%d: %.10lf\n",tst,a[N]);
	}

	return 0;
}
