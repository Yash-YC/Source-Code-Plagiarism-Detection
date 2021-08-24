#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <climits>
#include <ctime>
using namespace std;

#define NIL INT_MAX/2
#define inf 1e20
#define eps 1e-10

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=a; i<(b); ++i)
#define clr(x) memset(x,0,sizeof(x)) 

int cal(int n, int b) {
	int rec = 0, tmp;
	while(n) {
		tmp = n % b;
		rec += tmp * tmp;
		n /= b;
	}
	return rec;
}

bool mk[11][100000];
int mm[100000];
int sp;
int N = 100000;

bool dfs(int t, int i) {
	if(mk[i][t])return true;
	if(mm[t] == sp)return false;
	mm[t] = sp;
	int tmp = cal(t, i);
	if(dfs(tmp, i)) {
		mk[i][t] = true;
		return true;
	}
	return false;
}

void init() {
	for(int i = 2; i <= 10; i++)mk[i][1] = true;

	sp = 0;
	for(int i = 2; i <= 10; i++) {
		for(int j = 2, tmp; j < N; j++) {
			sp++;
			dfs(j, i);
		}
	}
}

int as[11][11][11];

int bases[15];
void solve() {
	string inp;
	getline(cin, inp);
	stringstream in(inp);

	int cnt = 0, tmp;
	while(in >> tmp) {
		bases[cnt++] = tmp;
	}

	for(int j = 2; j < N; j++) {
		bool flag = true;
		for(int i = 0; i < cnt; i++) {
			if(!mk[bases[i]][j]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			cout << j << endl;
			return;
		}
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	init();
	int cases, cnt = 1;
	cin >> cases;
	getchar();

	while(cases--) {
		printf("Case #%d: ", cnt++);
		solve();
	}
	return 0;
}

/*Powered By Lynn-Beta1*/