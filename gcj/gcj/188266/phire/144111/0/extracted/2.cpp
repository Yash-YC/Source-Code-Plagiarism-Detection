#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;
typedef long long ll;
#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i)
#define INF 987654321

int s[10][10];
int w[10][10];
int t[10][10];
int n,m;
bool visited[4][4];
int dirs[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

bool ok(int i, int j) {
	return i >= 0 && i < 2*n && j >= 0 && j < 2*m && !visited[i][j];
}

int normalizeTime(int t, int i, int j) {
	return t % (s[i][j] + w[i][j]) + s[i][j] + w[i][j];
}

int cost(int i, int j, int di, int dj, int tt) {
	bool we = (j != dj);
	int ii = i >> 1, jj = j >> 1;
	int dii = di >> 1, djj = dj >> 1;
	if (ii != dii || jj != djj)
		return 2;
	tt = normalizeTime(tt, ii, jj);
	int res = 1;
	if (tt >= t[ii][jj] && tt < t[ii][jj] + s[ii][jj]) {
		if (we)
			res += t[ii][jj] + s[ii][jj] - tt;
	}
	else if (tt < t[ii][jj]) {
		if (!we)
			res += t[ii][jj] - tt;
	}
	else {
		if (!we)
			res += w[ii][jj] - (tt - t[ii][jj] - s[ii][jj]);
	}
	return res;
}

int dfs(int i,int j, int tt) {
	int di,dj;
	int res = INF;
	if (i == 0 && j == 2*m-1)
		return 0;
	visited[i][j] = true;
	for (int k=0;k<4;k++) {
		di = i + dirs[k][0];
		dj = j + dirs[k][1];
		if (ok(di,dj)) {
			int tc = cost(i,j,di,dj,tt);
			res = min(res,tc + dfs(di,dj,tt + tc));
		}
	}
	visited[i][j] = false;
	return res;
	
}
int solve() {
	memset(visited,0,sizeof(visited));
	return dfs(2*n-1,0,0);
}

int main() {
	int cases;
	cin >> cases;
	for (int c=1;c<=cases;c++) {
		cin >> n >> m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				cin >> s[i][j] >> w[i][j] >> t[i][j];
				t[i][j] = normalizeTime(t[i][j], i, j);
			}
		cout << "Case #" << c << ": " << solve() << endl;
	}
	return 0;
}
