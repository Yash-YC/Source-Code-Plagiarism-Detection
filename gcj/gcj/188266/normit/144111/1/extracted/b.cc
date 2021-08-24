#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <queue>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

int s[50][50];
int w[50][50];
int t[50][50];

ll visited[50][50][5];
int n,m;

struct Point
{
	Point(int a, int b, int c, ll d) {
		x = a;
		y = b;
		state = c;
		cost = d;
	}
	int x;
	int y;
	int state;
	ll cost;

	bool operator < (const Point &p) const {
		// min queue
		return cost > p.cost;
	}
	
};

void try_push(priority_queue<Point> &q, int x, int y, int ss, ll cost)
{
	Point np(x,y,ss,cost);
//	cout << "Hey~ " << visited[x][y][ss] << " " << cost << endl;
	if(visited[x][y][ss] == -1 || visited[x][y][ss] > cost)  {
//		cout << "asdfa" << endl;
		q.push(np);
	}
}

ll intersect_ew(int x, int y, ll cost)
{
	if(x < 0 || y < 0 || x >= m || y >= n) return -1;

	ll sw = s[y][x]+w[y][x];

	ll cycle = (cost - t[y][x]) / sw;
	cycle = t[y][x] + cycle * sw;

	// now e-w
	if(cycle + s[y][x] <= cost) return cost;
	// noe n-s
	else return cycle+s[y][x];

}

ll intersect_ns(int x, int y, ll cost)
{
	if(x < 0 || y < 0 || x >= m || y >= n) return -1;

//	if(cost < t[y][x]) return t[y][x];

	ll sw = s[y][x]+w[y][x];

	ll cycle = (cost - t[y][x]) / sw;
	cycle = t[y][x] + cycle * sw;

	// now n-s
	if(cycle + s[y][x] > cost) return cost;
	// now e-w
	else return cycle+sw;
	}

void process(int kase)
{
	cout << "Case #" << kase << ": ";
	scanf("%d %d",&n,&m);
	REP(i,n) {
		REP(j,m) {
			scanf("%d %d %d",&s[i][j], &w[i][j], &t[i][j]);
			t[i][j] %= (s[i][j]+w[i][j]);
			if(t[i][j] > 0) t[i][j] -= (s[i][j]+w[i][j]);
		}
	}

	REP(i,50) 
		REP(j,50) 
			REP(k,5) visited[i][j][k] = -1;

	priority_queue<Point> q;

	q.push(Point(0,n,3,0LL));

	while(!q.empty()) {
		Point p = q.top();
		q.pop();
		if(visited[p.x][p.y][p.state] != -1) continue;
		visited[p.x][p.y][p.state] = p.cost;

//		cout << p.x << " " << p.y << " " << p.state << " " << p.cost << endl;

		if(p.x == m && p.y == 0) {
			cout << p.cost << endl;
			break;
		}

		ll next;
		if(p.state == 0) { 
			try_push(q,p.x,p.y,1,(ll)p.cost+2LL);
			try_push(q,p.x,p.y,2,(ll)p.cost+2LL);
			// left
			next = intersect_ew(p.x-1,p.y, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x-1, p.y, 1, next+1LL);
			// down
			next = intersect_ns(p.x-1,p.y, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x,p.y+1, 2, next+1LL);
		}
		else if(p.state == 1) {
			try_push(q,p.x,p.y,0,(ll)p.cost+2LL);
			try_push(q,p.x,p.y,3,(ll)p.cost+2LL);
			// right
			next = intersect_ew(p.x, p.y, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x+1,p.y, 0, next+1LL);
			// down 
			next = intersect_ns(p.x, p.y, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x,p.y+1, 3, next+1LL);
		}
		else if (p.state == 2) {
			try_push(q,p.x,p.y,0,(ll)p.cost+2LL);
			try_push(q,p.x,p.y,3,(ll)p.cost+2LL);
			// left
			next = intersect_ew(p.x-1, p.y-1, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x-1,p.y, 3, next+1LL);
			// up 
			next = intersect_ns(p.x-1, p.y-1, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x,p.y-1, 0, next+1LL);
		}
		else if (p.state == 3) {
			try_push(q,p.x,p.y,1,(ll)p.cost+2LL);
			try_push(q,p.x,p.y,2,(ll)p.cost+2LL);
			// right
			next = intersect_ew(p.x, p.y-1, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x+1,p.y, 2, next+1LL);
			// up 
			next = intersect_ns(p.x, p.y-1, p.cost);
//			cout << "next : " << next << endl;
			if(next >= 0) try_push(q,p.x,p.y-1, 1, next+1LL);
		}
	}

}

int main()
{
	int kase;
	scanf("%d",&kase);
	REP(i,kase) {
		process(i+1);
	}
	return 0;
}
