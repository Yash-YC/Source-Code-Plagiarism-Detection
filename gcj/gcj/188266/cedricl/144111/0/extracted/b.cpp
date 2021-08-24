#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cassert>

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
//typedef pair<pair<int,int>,int> pii;

using namespace std;

int n, m;
int s[30][30];
int w[30][30];
int t[30][30];
int dist[30][30][4];

struct cmp : public binary_function<pair<pair<int,int>,int>, pair<pair<int,int>,int>, bool> {
	bool operator()(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y) {
		if (dist[x.first.first][x.first.second][x.second] != dist[y.first.first][y.first.second][y.second])
			return dist[x.first.first][x.first.second][x.second] < dist[y.first.first][y.first.second][y.second];
		return x < y;
	}
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dijkstra(){//0 for SW, 1 for NW, 2 for NE, 3 for SE
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = 0x7fffffff;
	dist[n-1][0][0] = 0;
	set<pair<pair<int,int>,int>,cmp> q;
	q.insert(make_pair(make_pair(n-1,0),0));
	//cout << "n = " << n << ", m = " << m << endl;
	while (!q.empty()){
		pair<pair<int,int>,int> v = *(q.begin());
		q.erase(v);
		int x = v.first.first;
		int y = v.first.second;
		int pos = v.second;
		//cout << x << " " << y << " " << pos << " " << dist[x][y][pos] << endl;
		if (x == 0 && y == m-1 && pos == 2) return dist[x][y][pos];
		int newdist = dist[x][y][pos]+2;
		if ((pos == 0 || pos == 1) && y > 0){
			if (dist[x][y-1][3-pos] > newdist){
				q.erase(make_pair(make_pair(x,y-1),3-pos));
				dist[x][y-1][3-pos] = newdist;
				q.insert(make_pair(make_pair(x,y-1),3-pos));
			}
		}
		if ((pos == 2 || pos == 3) && y < m -1){
			if (dist[x][y+1][3-pos] > newdist){
				q.erase(make_pair(make_pair(x,y+1),3-pos));
				dist[x][y+1][3-pos] = newdist;
				q.insert(make_pair(make_pair(x,y+1),3-pos));
			}
		}
		if ((pos == 0 || pos == 3) && x < n -1){
			if (dist[x+1][y][(5-pos)%4] > newdist){
				q.erase(make_pair(make_pair(x+1,y),(5-pos)%4));
				dist[x+1][y][(5-pos)%4] = newdist;
				q.insert(make_pair(make_pair(x+1,y),(5-pos)%4));
			}
		}
		if ((pos == 1 || pos == 2) && x > 0){
			if (dist[x-1][y][(5-pos)%4] > newdist){
				q.erase(make_pair(make_pair(x-1,y),(5-pos)%4));
				dist[x-1][y][(5-pos)%4] = newdist;
				q.insert(make_pair(make_pair(x-1,y),(5-pos)%4));
			}
		}
		//int newdist = dist[x][y][pos]+1;
		int next_ns = dist[x][y][pos], next_we = dist[x][y][pos];
		int mod = s[x][y]+w[x][y];
		int rem = ((next_ns + mod - t[x][y]) % mod);
		if (rem < s[x][y]){
			//cout << "we " << next_we << " " << (s[x][y]-rem) << endl;
			next_we += s[x][y]-rem;
		}
		else {
			//cout << "ns " << next_ns << " " << (mod-rem) << endl;
			next_ns += mod - rem;
		}
		next_ns += 1; next_we+=1;
		//cout << next_ns << " " << next_we << endl;
		if (dist[x][y][(5-pos)%4] > next_ns){
			q.erase(make_pair(make_pair(x,y),(5-pos)%4));
			dist[x][y][(5-pos)%4] = next_ns;
			q.insert(make_pair(make_pair(x,y),(5-pos)%4));
		}
		if (dist[x][y][3-pos] > next_we){
			q.erase(make_pair(make_pair(x,y),3-pos));
			dist[x][y][3-pos] = next_we;
			q.insert(make_pair(make_pair(x,y),3-pos));
		}
	}
	return -1;
}

int main(){
	int c; cin >> c;
	for (int zzz = 1; zzz <= c; zzz++){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> s[i][j] >> w[i][j] >> t[i][j];
				t[i][j] %= (s[i][j]+w[i][j]);	
			}
		}
		//cout << n << " " << m << endl;
		cout << "Case #" << zzz << ": " << dijkstra() << endl;
	}
	return 0;
}
