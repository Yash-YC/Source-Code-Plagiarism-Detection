#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>


#define debug(x) cout << '>' << #x << ':' << x << '\n';
#define rep(X,Y,Z) for (int X = Y;X < Z;X++)
#define forn(X,Y) for (int X = 0;X < Y;X++)
#define sz(Z) Z.size()
#define all(W) W.begin(), W.end()
#define inf 2123123123LL
#define vint vector<int>
#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)
#define mp make_pair
#define I(M) (typeof((M).begin()))
#define pb push_back

typedef long long ll;
typedef long double ld;

using namespace std;

long long comb(int people,int need) {
	if (need < 0 || people < 0) return 0;
	if (need > people) return 0;
	long long fact1,fact2,fact3;
	fact1 = people;
	fact2 = (people - need);
	fact3 = need;
	if (fact3 > fact2) {
		long long fact4 = fact3;
		fact3 = fact2;
		fact2 = fact4;
		}
	//fact2 >= fact3
	long long answer = 1;
	for (long long i = fact1;i > fact2;i--) {
		answer *= i;
		}
	long long hitung = 1;
	for (long long i = 1;i <= fact3;i++) hitung *= i;
	answer /= hitung;
	return answer;
	}
	

long double chan[50][100000];
int n;
int boo;
long double eps = 0.0000001;; 
long double all;
long double hue = -1.0;
int a = 0;
long double kemun(int i,int depth,long double chance) {
	//debug(i);
	//debug(chance);
	if (chance < eps) return 0.0;
	if (chan[i][depth] > hue) {
		
		
		return chan[i][depth];
		}
	if (i == 0) return chance * depth;
	chan[i][depth] = 0.0;
	ld ret = 0;
	forn(j,i + 1) {
	
		long long jml = comb(i,j) * comb(n - i,boo - j);
		long double aaa = chance * (ld)jml / all;
		//debug(j);
		//debug(aaa);
		ret += kemun(i - j,depth + 1,aaa);
		}
	//debug(ret);
	chan[i][depth] = ret;
	return ret;
	}
		

int main() {
	int T;
	scanf("%d",&T);
	forn(z,T) {
		printf("Case #%d: ",z + 1);
		
		forn(i,50) forn(j,10000) chan[i][j] = -2.0;
		scanf("%d%d",&n,&boo);
		all = comb(n,boo);
		cout << kemun(n,0,1.0) << '\n';
		}
	
	return 0;
	}

