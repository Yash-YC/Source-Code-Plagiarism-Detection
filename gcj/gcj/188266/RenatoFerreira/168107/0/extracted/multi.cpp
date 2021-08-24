#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <utility>

#define REP(i, a, b) for (typeof(a) i = a; i < b; i++)
#define FOR(i, k) REP(i, 0, k)

#define all(x) x.begin(), x.end()

#define mp make_pair
#define pb push_back

#define watch(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long LL;
typedef pair < int, int > PII;
typedef vector < int > VI;
typedef vector < string > VS;

VI b;
map < int, bool > memo;

int mpow(int a, int b){
	if (b == 1) return a;
	if (b == 0) return 1;
	if (b % 2 == 0) return mpow(a, b / 2) * mpow(a, b / 2);
	return a * mpow(a, b - 1);
}

int g(int x, int b){
	int ans = 0;
	if (x == 0) return ans;

	int i = 0;
	int t = x;

	while (t > 0){
		ans += mpow(10, i) * (t % b);
		t /= b;
		i++;
	}

	return ans;
}

bool f(int x, int b){
	//printf("f(x = %d)\n", x);
	if (x == 1) return true;
	if (memo.count(x)) return false;
	
	memo[x] = true;

	int nn = 0;
	while (x > 0){
		nn += mpow(x % 10, 2);
		x /= 10;
	}

	return f(g(nn, b), b);
}

int solve(){
	REP(x, 2, 900900900){
		bool ok = true;
		//watch(x);
		FOR(i, (int) b.size()){
			//watch(i);
			memo.clear();
			ok &= f(g(x, b[i]), b[i]);
		}

		if (ok){/*printf("ok, %d\n", x);*/return x;}
	}

	return -1;
}

int main(){
	int t;
	scanf("%d", &t);

	FOR(tt, t){
		stringstream ss;
		string s;
		getline(cin, s);
		if (s == "") {tt--;continue;}
		ss << s;
		int num;
		while (ss >> num) b.pb(num);

		printf("Case #%d: %d\n", tt + 1, solve());

		b.clear();
	}

	return 0;
}
