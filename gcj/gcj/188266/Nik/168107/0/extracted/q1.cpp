
/* Author :: Yash */
#include <vector>
#include <list>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <deque>
#include <fstream>
#include <stack>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class A, class B> A cvt(B x) {stringstream s;s<<x;A r;s>>r;return r;}

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define PP pop()
#define EM empty()
#define INF 1000000000
#define PF push_front
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define V(x) vector< x >
#define Debug false
#define PRINT(x)        cout << #x << " " << x << endl
#define LET(x,a) 	    __typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define PRESENT(c,x) 	((c).find(x) != (c).end())
#define SZ(x) 		x.size();
#define CPRESENT(c,x) 	(find(c.begin(),c.end(),x) != (c).end())
#define D(N) 		int N
#define S(N)		scanf("%d",&N)

typedef pair<int,int>  PI;
typedef pair<int,PI>   TRI;
typedef V( int )       VI;
typedef V( PI  )       VII;
typedef V( string )    VS;
typedef long long      LL;

bool Bases[12][10000000];
bool Process[12][10000000];

/* Bases
 * 0 -- Happy
 * 1 -- UnHappy.
 */

/* Process
 * 0 -- UnProcessed
 * 1 -- Processed
 */


void Pre() {
	
	Bases[3][2] = Bases[3][12] = Bases[3][22] = 1;
	Process[3][2] = Process[3][12] = Process[3][22] = 1;
		
	Bases[5][4] = Bases[5][23] = Bases[5][33] = 1;
	Process[5][4] = Process[5][23] = Process[5][33] = 1;

	Bases[6][32] = 1;
	Process[6][32] = 1;

	Bases[7][2] = Bases[7][34] = Bases[7][13] = Bases[7][23] = Bases[7][63] = Bases[7][44] = 1;
	Process[7][2] = Process[7][34] = Process[7][13] = Process[7][23] = Process[7][63] = Process[7][44] = 1;

	Bases[8][4] = Bases[8][5] = Bases[8][32] = Bases[8][24] = Bases[8][64] = 1;
	Process[8][4] = Process[8][5] = Process[8][32] = Process[8][24] = Process[8][64] = 1;

	Bases[9][55] = Bases[9][58] = Bases[9][45] = Bases[9][75] = 1;
	Process[9][55] = Process[9][58] = Process[9][45] = Process[9][75] = 1;

	
	//4, 16, 37, 58, 89, 145, 42, 20, 4
	Bases[10][4] = Bases[10][16] = Bases[10][37] = Bases[10][58] = Bases[10][89] = Bases[10][145] = Bases[10][42] = Bases[10][20] = 1;
	Process[10][4] = Process[10][16] = Process[10][37] = Process[10][58] = Process[10][89] = Process[10][145] = Process[10][42] = Process[10][20] = 1;

}

#define UP 100000

int Convert(int t,int base) {

	string ans = "";
	while (t >= base) {
		ans += (t % base) + '0';
		t /= base;
	}
	ans += t + '0';reverse(ALL(ans));
       return cvt<int>(ans);
}

bool Solve(int t,int base) {

	// Check whether it is happy or not.
	
	if(t == 1) return false;
	if ( Process[base][t] )	{
		return Bases[base][t];
	}

	int x = t, r = 0, y;
	while( x ) {
		y = x % 10;
		r += y*y;
		x /= 10;
	}
	y = Convert(r,base);

	y = Solve(y,base);
	Process[base][t] = 1;
	Bases[base][t] = y;

	return y;
}


int main() {
	
	Pre();
	int kases; scanf("%d",&kases);
	int total;
	REP(case1,kases) {

		VI bases;

		while (true) {
		
			scanf("%d",&total);bases.PB(total);
			if(getchar() == '\n') break;
		}
	
		FOR(i,2,1000000) {

			int flag = 0;
			REP(j,bases.size()) {
				if (bases[j] == 2 || bases[j] == 4) ++flag;
				else {
					flag += !Solve(Convert(i,bases[j]),bases[j]);
				}
			}
			if(flag == bases.size()) {

				cout << "Case #" << case1+1 << ": " << i << endl;
				break;
			}	
		}
	}	
	return 0;
}


