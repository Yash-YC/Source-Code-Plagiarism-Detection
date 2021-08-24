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

#define MAXN 1000000

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

int t;

int mask[MAXN];
bool visit[MAXN][13];
int primero[1030];

int visitar(int i, int b) {
	visit[i][b] = true;
	int tmp = 0;
	int ii=i;
	while (ii>0) {
		int u = ii% (b);
		tmp += (u*u);
		ii/= (b);	
	}	
	int ans = 0;
	if (tmp==1) {
		ans = (1 << (b) );
		mask[i] |= ans;
		return ans;		
	}
	else if (visit[tmp][b]) {
		ans = (mask[tmp] & (1<<b)); 
		mask[i] |= ans;
		return ans;		
	}
	else if (!visit[tmp][b]) {
		ans = visitar(tmp,b);
		mask[i] |= ans;
		return ans;	
	}
}

int main () {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n = 500000;
	forn(i,1030) primero[i] = 0;
	
	forn(i,n) { mask[i] = 0; forn(j,13) visit[i][j] = false;}
	
	
	
	forsn(i,2,n) forsn(b,2,12) if (!visit[i][b]) {
		mask[i] |= visitar(i,b);
	}
	
//int test = visitar(68,10);
	
//	while (test) {
//		cout << test%2;
//		test/=2;	
//	}
//	cout << endl;
	
	cin >> t;
	char c;
	c = getchar();
	forn(rep,t) {
		int actual = 0;
		
		c = getchar();
		while (c!='\n' && c!=EOF) {
			if ((c!=' ') &&  (c!= '1')) actual |= (1<<((int)c - 48));
			else if (c=='1') { actual |= (1<<10); c = getchar();}
	//		cout << (int )c << endl;
			c = getchar();
		}
		forsn(i,2,n) if ((actual | mask[i]) == mask[i]) {
			cout <<"Case #" << rep+1 << ": " << i << endl;
			break;	
		}

	}
	
	return 0;
}
