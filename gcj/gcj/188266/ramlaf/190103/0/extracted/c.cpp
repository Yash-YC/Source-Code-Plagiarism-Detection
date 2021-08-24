#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define MAXC 45

int t,c,n;

tint comb[MAXC][MAXC];
tint comb_(int n, int m) {
	if (n==0 || m==0 || n==m) return 1;			
	else if (comb[n][m] != -1) return comb[n][m];
	else {
		int tmp = comb_(n-1,m) + comb_(n-1,m-1);
		comb[n][m] = tmp;
		return tmp;
	}
}

int main () {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	cin >> t;
	forn(i,MAXC) forn(j,MAXC) comb[i][j] = -1;
	forn(i,MAXC) forn(j,i+1) if (comb[i][j]==-1) comb[i][j] = comb_(i,j);
	
//	cout << comb[40][20];
	forn(rep,t) {
		cin >> c >> n;	
		double f[MAXC];
		forn(i,c+1) f[i] = 0.0;
		f[c] = 1;
		for (int m = c-1; m>=n; m--) {
			double res = 0.0;
			int k = 1;
			while (k<= n && k<= c-m) {
				double tmp = (double) ( comb[m][n-k] * comb[c-m][k] ) /(double(comb[c][n]));
				res += tmp * f[m+k];
				k++;	
			}
			res += 1.0;
			f[m] = res / (double(1.0 - double(comb[m][n])/double(comb[c][n]) ) ) ;	
		}
		cout << "Case #" << rep+1 << ": " << f[n] << endl;
	}
	
	
	return 0;
}
