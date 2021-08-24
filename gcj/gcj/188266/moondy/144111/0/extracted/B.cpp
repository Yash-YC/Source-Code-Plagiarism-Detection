#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long LL;

const int MOD = 1000;
const LL INF = 10000000000000000LL;
const int MAXN = 100;

set<pair<LL, int> > v;
LL w[MAXN][MAXN], s[MAXN][MAXN], t[MAXN][MAXN], dis[MAXN][MAXN];
int n, m;
bool reach[MAXN][MAXN];

void update(int x, int y, LL cur) {

//	if (x == 1 && y == 1) printf("(1, 1) = %lld\n", cur);

	if (reach[x][y]) return;
	if (v.find(make_pair(dis[x][y], x * MOD + y)) != v.end()) {
		v.erase(v.find(make_pair(dis[x][y], x * MOD + y)));
	}
	dis[x][y] = cur;
	v.insert(make_pair(dis[x][y], x * MOD + y));
}

LL west_east(int x, int y, LL cur) {
	x /= 2, y /= 2;
	if (cur < t[x][y]) {
		if (cur >= t[x][y] - w[x][y]) return 0;
		else return t[x][y] - w[x][y] - cur;
	}
	cur -= t[x][y];
	cur %= (s[x][y] + w[x][y]);
	if (cur >= s[x][y]) return 0;
	return s[x][y] - cur;
}

LL north_south(int x, int y, LL cur) {
	x /= 2, y /= 2;
	if (cur < t[x][y]) {
		if (cur >= t[x][y] - w[x][y]) return t[x][y] - cur;
		else return 0;
	}
	cur -= t[x][y];
	cur %= (s[x][y] + w[x][y]);
	if (cur >= s[x][y]) return s[x][y] + w[x][y] - cur;
	return 0;
}

void add(int x, int y) {

	reach[x][y] = true;
	// left-up
	if (x % 2 == 0 && y % 2 == 0) {
		int xx = x - 1, yy = y;
		if (xx >= 0) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);			
		}
		xx = x, yy = y - 1;
		if (yy >= 0) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);
		}
		xx = x, yy = y + 1;
		if (yy < 2 * m) {
			LL tmp = west_east(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
		xx = x + 1, yy = y;
		if (xx < 2 * n) {
			LL tmp = north_south(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
	}
	
	// right-up
	if (x % 2 == 0 && y % 2 == 1) {
		int xx = x - 1, yy = y;
		if (xx >= 0) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);			
		}
		xx = x, yy = y + 1;
		if (yy < 2 * m) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);
		}
		xx = x, yy = y - 1;
		if (yy >= 0) {
			LL tmp = west_east(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
		xx = x + 1, yy = y;
		if (xx < 2 * n) {
			LL tmp = north_south(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}	
	}
	
	// left-down
	if (x % 2 == 1 && y % 2 == 0) {
		int xx = x + 1, yy = y;
		if (xx < 2 * n) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);			
		}
		xx = x, yy = y - 1;
		if (yy >= 0) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);
		}
		xx = x, yy = y + 1;
		if (yy < 2 * m) {
			LL tmp = west_east(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
		xx = x - 1, yy = y;
		if (xx >= 0) {
			LL tmp = north_south(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
	}
	
	// right-down
	if (x % 2 == 1 && y % 2 == 1) {
		int xx = x + 1, yy = y;
		if (xx < 2 * n) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);			
		}
		xx = x, yy = y + 1;
		if (yy < 2 * m) {
			if (dis[xx][yy] > dis[x][y] + 2)
				update(xx, yy, dis[x][y] + 2);
		}
		xx = x, yy = y - 1;
		if (yy >= 0) {
			LL tmp = west_east(x, y, dis[x][y]);
//			printf("(%d, %d) -> (%d, %d), tmp = %lld\n", x, y, xx, yy, tmp);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
		xx = x - 1, yy = y;
		if (xx >= 0) {
			LL tmp = north_south(x, y, dis[x][y]);
			if (dis[xx][yy] > dis[x][y] + 1 + tmp)
				update(xx, yy, dis[x][y] + 1 + tmp);
		}
	}
}

void solve() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%lld %lld %lld", &s[i][j], &w[i][j], &t[i][j]);
			t[i][j] %= (s[i][j] + w[i][j]);	
		}
	memset(reach, false, sizeof(reach));
	v.clear();
	for (int i = 0; i < 2 * n; i++)
		for (int j = 0; j < 2 * m; j++)
			dis[i][j] = INF;
	dis[2 * n - 1][0] = 0;
	add(2 * n - 1, 0);
	while (true) {
		LL cur = v.begin() -> first;
		int x = v.begin() -> second / MOD, y = v.begin() -> second % MOD;
		
//		printf("dis[%d][%d] = %lld\n", x, y, dis[x][y]);
		
		if (x == 0 && y == 2 * m - 1) {
			printf("%lld\n", cur);
			return;
		}
		v.erase(v.begin());
		add(x, y);
	}
}

int main() {

	int test;
	scanf("%d", &test);
	for (int i = 1; i <= test; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}

