#include <set>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 44;

int s[MAXN][MAXN];
int w[MAXN][MAXN];
int t[MAXN][MAXN];

struct Node
{
	int i, j;
	long long dis;
	Node(int i, int j, long long dis) : i(i), j(j), dis(dis){}
	bool operator<(const Node &a) const
	{
		if (a.dis == dis) {
			if (a.i == i) {
				return j < a.j;
			}
			return i < a.i;
		}
		return dis < a.dis;
	}
};

long long mind[MAXN][MAXN];
int n, m;

void update(set<Node> &st, int i, int j, long long dd)
{
	if (mind[i][j] == -1) {
		mind[i][j] = dd;
	}
	else {
		if (mind[i][j] <= dd) return;
		st.erase(st.find(Node(i, j, mind[i][j])));
		mind[i][j] = dd;
	}
	st.insert(Node(i, j, mind[i][j]));
}

bool isvalid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

long long getnn(int r, int c, long long now)
{
	long long next = now;
	next %= (w[r][c] + s[r][c]);
	if (next >= t[r][c]) {
		if (now < t[r][c] + s[r][c]) {
			return now + 1;
		}
		else {
			return now + t[r][c] + w[r][c] + s[r][c] - next + 1;
		}
	}
	else {
		int endtime = (t[r][c] + s[r][c]) % (w[r][c] + s[r][c]);
		if (endtime > t[r][c])  {
			return now + t[r][c] - next + 1;
		}
		else {
			if (next < endtime) {
				return now + 1;
			}
			else {
				return now + t[r][c] - next + 1;
			}
		}
	}
}

long long getss(int r, int c, long long now)
{
	int tt = t[r][c];
	t[r][c] = (t[r][c] + s[r][c]) % (s[r][c] + w[r][c]);
	swap(s[r][c], w[r][c]);
	long long res = getnn(r, c, now);
	swap(s[r][c], w[r][c]);
	t[r][c] = tt;
	return res;
}

long long run()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d %d %d", s[i] + j, w[i] + j, t[i] + j);
			t[i][j] %= (s[i][j] + w[i][j]);
		}
	}
	n *= 2;
	m *= 2;
	set<Node> st;
	st.insert(Node(n - 1, 0, 0));
	int di = 0, dj = m - 1;
	memset(mind, -1, sizeof(mind));
	mind[n - 1][0] = 0;
	while (1) {
		int x = st.begin()->i, y = st.begin()->j;
		long long d = st.begin()->dis;
		st.erase(st.begin());
		if (x == di && y == dj) return d;
		int hldr = x / 2;
		int hldc = y / 2;
		int nx, ny;
		if (x % 2 == 0) nx = x - 1;
		else nx = x + 1;
		ny = y;
		if (isvalid(nx, ny)) update(st, nx, ny, d + 2);

		if (y % 2 == 0) ny = y - 1;
		else ny = y + 1;
		nx = x;
		if (isvalid(nx, ny)) update(st, nx, ny, d + 2);

		long long nextd = getnn(hldr, hldc, d);
		if (x % 2 == 0) nx = x + 1;
		else nx = x - 1;
		ny = y;
		update(st, nx, ny, nextd);

		nextd = getss(hldr, hldc, d);
		if (y % 2 == 0) ny = y + 1;
		else ny = y - 1;
		nx = x;
		update(st, nx, ny, nextd);
	}
	return -1;
}

int main()
{
	freopen("Bin.txt", "r", stdin);
	freopen("Bout.txt", "w", stdout);
	int c;
	scanf("%d", &c);
	for (int i = 1; i <= c; ++i) {
		printf("Case #%d: %d\n", i, run());
	}
	return 0;
}