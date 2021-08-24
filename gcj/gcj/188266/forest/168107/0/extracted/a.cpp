#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <set>
#include <queue>
#include <sstream>
#include <list>
#include <map>
#include <cmath>

#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FIR(k) FOR(i,0,k)
#define FJR(k) FOR(j,0,k)
#define FI FIR(n)
#define FJ FJR(n)
#define ALL(v) v.begin(), v.end()
#define LL long long

typedef vector<int> VI;
typedef pair<int, int> PI;

#define UP_LIMIT 200

set<int> u;

struct Happy {
	int base;
	int happy[UP_LIMIT];

	void init(int base) {
		this->base = base;
		FIR(UP_LIMIT) happy[i] = 2;
		happy[1] = 1;

		FOR(i, 2, UP_LIMIT) {
			u.clear();
			happy[i] = go(i);
		}
	}

	int ok(int n) {
		return happy[ dig_sq(n) ];
	}

	int next_ok(int cur) {
		for (++cur; !ok(cur); ++cur);
		return cur;
	}

	int dig_sq(int n) {
		int s = 0;
		while (n) {
			int d= n%base;
			s += d*d;
			n/=base;
		}

		return s;
	}

	int go(int sum) {
		if (sum < UP_LIMIT && happy[sum] != 2) return happy[sum];
		if (u.count(sum)) return happy[sum] = 0;
		u.insert(sum);

		return go(dig_sq(sum));
	}
};

Happy h[11];
int a[11];
int next_ok[11];

int main() {
freopen("A-small-attempt0.in", "rt", stdin);
freopen("A-small-attempt0.out", "w", stdout);	

	for (int i = 2; i <= 10; ++i)
		h[i].init(i);

	int q1 = h[2].ok(3);
	int q2 = h[3].ok(3);
	
	int cases; cin >> cases;
	string s;
	getline(cin, s);

	FOR(tc, 0, cases) {
		getline(cin,s);
		istringstream iss(s);
		int t = 0, u;
		while (iss >> u) a[t++] = u;

		FIR(t) {
			int b = a[i];
			next_ok[b] = h[b].next_ok(1);
		}

		
		do {
			bool found = true;
			FOR(i, 1, t) if (next_ok[ a[0] ] != next_ok[ a[i] ]) {found = false; break;}
			if (found) break;

			int b = a[0];
			FOR(i, 1, t) if (next_ok[ b ] > next_ok[ a[i] ]) b = a[i];
			next_ok[b] = h[ b ].next_ok(next_ok[ b ]);

		} while (true);
		printf("Case #%d: %d\n", tc+1, next_ok[ a[0] ]);
	}
}
