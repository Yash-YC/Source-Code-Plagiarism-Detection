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

const int size = 2001;
vector<int> prev[size];

int solution(int nTest) {
	printf("Case #%d: ", nTest + 1);
	int n;
	scanf("%d", &n);
	vi d(n - 1);
	int flag = 0;
	For(i, 0, n) {
		prev[i].clear();
	}
	For(i, 0, n - 1) {
		scanf("%d", &d[i]);
		d[i]--;
		prev[d[i]].pb(i);
	}
	For(i, 0, n - 1) {
		For(j, i + 1, d[i]) {
			if(d[j] > d[i]) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			break;
		}
	}
	if(flag) {
		puts("Impossible");
		return 1;
	}
	int up = 1000 * 1000 * 1000;
	vi mx(n-1);
	For(i, 0, n - 1) {
		mx[i] = up;
	}
	vi res(n);
	for(int i = n - 1; i >= 0; i--) {
		For(j, 0, sz(prev[i])) {
			int u = prev[i][j];
			res[u] = mx[u];
			int dy = res[i] - res[u];
			int dx = i - u;
			for(int k = u + 1; k < i; k++) {
				lint t = k - u;
				int s = t * dy / dx + res[u];
//				if(dy % dx == 0) {
					s--;
//				}
				mx[k] = min(mx[k], s);
			}
		}
	}
	For(i, 0, sz(res)) {
		printf("%d ", res[i]);
	}
	printf("\n");


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
