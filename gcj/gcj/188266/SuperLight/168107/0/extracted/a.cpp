#include <stdio.h>
#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>

using namespace std;

#define infile ".in"
#define outfile ".out"
#define FOR(i, n) for (int i = 0; i <(n); i++)
#define DFOR(i, n) for (int i = (n) - 1; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()
#define LL long long
#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLR(a, b) memset((a), (b), sizeof(a))
#define SS stringstream
#define PII pair<int, int>
#define VPII vector < PII >

void init(){
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);
}

#define maxn 30000000

int base[10], bcount;
bool hap[maxn][11];
bool used[maxn][11];
//LL ans[maxn][11];
set<int> s;

bool happy(int x, int b){
	int X = x;
	if(X<maxn) if(used[x][b]) return hap[x][b];

	s.clear();
	s.insert(x);
	while(true){
		int y = x;
		int t = 0;
		while(y){
			int z = y%b;
			t += SQR(z);
			y/=b;
		}
		if(t==1) {
			if(X<maxn) {used[X][b] = hap[X][b] = true;}
			return true;
		}
		if(s.find(t)!=s.end()){
			if(X<maxn) {used[X][b] = true; hap[X][b] = false;}
			return false;
		}
		s.insert(t);
		x = t;
	}
}

void solvecase(){
	//CLR(hap, 0);
//	FOR(i, 11)if(i>=2)  hap[1][i] = true;

	for(int i=2;;i++){
		bool f = true;
		FOR(j, bcount) if(!happy(i, base[j])) {f = false; break;}
		if(f) {printf("%d", i); return;}
	}	
}

void generatetests(){
	printf("1023\n");
	for(int i=1; i<=(1<<10)-1; i++){
		FOR(j, 9)if((i & (1<<j))!=0) printf("%d ", j+2);
		printf("\n");
	}
}

void solve(){
	//generatetests();
	//return;
	CLR(used, 0);
	
	char buf[1000];
	int tests;
	scanf("%d\n",&tests);
	FOR(q, tests){
		printf("Case #%d: ", q+1);
		cerr<<q<<endl;
		gets(buf);
		string s(buf);
		SS ss(s);
		bcount=0;
		int x;
		while(ss>>x) base[bcount++] = x;
		solvecase();
		printf("\n");
	}


}

int main(){
	init();
	solve();
	return 0;
}