#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define debug 1
#define cerr if(debug) cerr

#define For(i, a, b) for(int i = a; i < b; i++)
#define Rep(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define cp(a) cerr << "(" << #a << "," << a << ") "
#define cen cerr << endl

typedef long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 0x7fffffff;

const int Size = 1000 * 1000 + 1;
char buffer[Size];

int solution(int nTest) {
	printf("Case #%d: ", nTest + 1);

	int n;
	scanf("%d", &n);
	vi d, l;
	For(i, 0, n) {
		int t1, t2;
		scanf("%d", &t1);
		scanf("%d", &t2);
		d.pb(t1);
		l.pb(t2);
	}
	int D;
	scanf("%d", &D);
	vi dp(n);
	dp[0] = d[0];

	int res = 0;
	For(i, 0, n) {
		int mh = dp[i];
		res = max(res, d[i] + mh);
		For(j, i + 1, n) {
			if(d[j] > mh + d[i]) {
				break;
			}
			dp[j] = max(dp[j], min(d[j] - d[i], l[j]));
		}
	}
	if(res >= D) {
		puts("YES");
	}
	else {
		puts("NO");
	}

				





	return 1;
}

int main() {
	if(debug) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}


	int i = 0, n = 99999;
	scanf("%d", &n);
	while(i < n && solution(i)) {
		i++;
	}

	return 0;
}
