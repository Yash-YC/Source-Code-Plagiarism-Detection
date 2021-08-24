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
#define eps 0.0000001
#define vint vector<int>
#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)
#define mp make_pair
#define I(M) (typeof((M).begin()))
#define pb push_back

typedef long long ll;
typedef long double ld;

using namespace std;

//lowest time to get to intersection x,y, CORNER :
//0,1,2,3 : kiri atas,kanan ats,kanan bawh, kiri bwh
ll mini[50][50][4];

long long beg[50][50];
long long bisa[50][50][2];//0 => bisa atas-bwh 1 ==> bisa kiri-kanan

typedef pair< ll, pair<int, pair<int,int> > > viiii;

priority_queue< viiii, vector<viiii>, greater<viiii> > pq;

int row, col;

void ins(int abc,int def,int ghi,ll jkl) {
	if (mini[abc][def][ghi] <= jkl) return;
	mini[abc][def][ghi] = jkl;
	pq.push(mp(jkl,mp(abc,mp(def,ghi))));
	return;
	}

ll lowwait(int abc,int def,int ghi,ll jkl) {
	ll hu = (jkl - beg[abc][def] + (bisa[abc][def][0] + bisa[abc][def][1])) % (bisa[abc][def][0] + bisa[abc][def][1]);
	if (hu < bisa[abc][def][0]) {
		if (ghi == 0) return jkl + 1LL;
		return jkl - hu + bisa[abc][def][0] + 1LL;
		}
	if (ghi == 1) return jkl + 1LL;
	return jkl - hu + (bisa[abc][def][0] + bisa[abc][def][1]) + 1LL;
	}

int y;

int main() {
	scanf("%d",&y);
	forn(z,y) {
	printf("Case #%d: ",z + 1);
	forn(i,50) forn(j,50) forn(k,4) mini[i][j][k] = inf * inf;

	scanf("%d%d",&row,&col);
	forn(i,50) forn(k,4) mini[i][0][k] = mini[0][i][k] = mini[col + 1][i][k] = mini[i][row + 1][k] = -1LL;
	
	//debug(mini[2][1][0]);
	ins(1,row,3,0);
	rep(i,1,row + 1) rep(j,1,col + 1) {
		scanf("%lld",&bisa[j][i][0]);
		scanf("%lld",&bisa[j][i][1]);
		scanf("%lld",&beg[j][i]);
		beg[j][i] %= (bisa[j][i][0] + bisa[j][i][1]);
		}
	
	while (!pq.empty()) {
		int a = pq.top().second.first,b = pq.top().second.second.first,c = pq.top().second.second.second,val = pq.top().first;
		pq.pop();
		//debug(a);
		//debug(b);
		//debug(c);
		//debug(val);
		if (val > mini[a][b][c]) continue;
		
		//normal movement
		int d;
		if (c == 0) {
			ins(a,b - 1,3,val + 2);
			ins(a - 1,b,1,val + 2);
			ins(a,b,3,lowwait(a,b,0,val));
			ins(a,b,1,lowwait(a,b,1,val));
			}
		if (c == 1) {
			ins(a,b - 1,2,val + 2);
			ins(a + 1,b,0,val + 2);
			ins(a,b,2,lowwait(a,b,0,val));
			ins(a,b,0,lowwait(a,b,1,val));
			}
		if (c == 2) {
			ins(a,b + 1,1,val + 2);
			ins(a + 1,b,3,val + 2);
			ins(a,b,1,lowwait(a,b,0,val));
			//debug(lowwait(a,b,0,val));
			ins(a,b,3,lowwait(a,b,1,val));
			}
		if (c == 3) {
			ins(a,b + 1,0,val + 2);
			ins(a - 1,b,2,val + 2);
			ins(a,b,0,lowwait(a,b,0,val));
			
			ins(a,b,2,lowwait(a,b,1,val));
			}
		}
	printf("%lld\n",mini[col][1][1]);
	}
	
	return 0;
	}

