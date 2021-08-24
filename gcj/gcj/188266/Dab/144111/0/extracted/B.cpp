#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <list>
#include <map>
#include <cmath>

using namespace std;


struct State {
	int x, y, c;
	long long t;
	State(int x, int y, int c, long long t): x(x), y(y), c(c), t(t) {};
	bool operator<(const State &s) const {
		if(t != s.t) return t > s.t;
		if(x != s.x) return x < s.x;
		if(y != s.y) return y < s.y;
		return c < s.c;
	}
};

map<State, long long> g;

int N, M;

long long S[20][20], W[20][20], T[20][20]; 

long long getWait(int dir, int x, int y, long long time) {

	long long t = T[x][y], s = S[x][y], w = W[x][y];

	if(t > 0) t = t-((t/(w+s))+1)*(w+s);
	
	time-=t;		
	time%=(w+s);

	long long result;

	if(dir == 0) {
		if(time < s) result =  0;
		else result =  w+s-time;		
	} else {
		if(time >= s)  result =  0;
		else result =  s-time;;
	}	

	return result;

}

void solve() {
	cin >> N >> M;
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			cin >> S[x][y] >> W[x][y] >> T[x][y];
		}
	}	

	g.clear();
	priority_queue<State> Q;
	Q.push(State(0, N-1, 0, 0));

	while(!Q.empty()) {
		State c = Q.top();
		
		Q.pop();
		State d = c;
		d.t = 0;
		if(c.x < 0 || c.y < 0 || c.x >= M || c.y >= N) continue;		
		if(g.find(d) != g.end()) continue;

		g[d] = c.t;

		if(c.x == M-1 && c.y == 0 && c.c == 2) {
			cout << c.t;
			return;
		}


		long long w0 = getWait(0, c.x, c.y, c.t);
		long long w1 = getWait(1, c.x, c.y, c.t);

		if(c.c == 0) {
			Q.push(State(c.x-1, c.y, 1, c.t+2));
			Q.push(State(c.x, c.y+1, 3, c.t+2));
			Q.push(State(c.x, c.y, 3, c.t+1+w0));
			Q.push(State(c.x, c.y, 1, c.t+1+w1));			
		}
		if(c.c == 1) {
			Q.push(State(c.x+1, c.y, 0, c.t+2));
			Q.push(State(c.x, c.y+1, 2, c.t+2));
			Q.push(State(c.x, c.y, 2, c.t+1+w0));
			Q.push(State(c.x, c.y, 0, c.t+1+w1));			
		}
		if(c.c == 2) {
			Q.push(State(c.x+1, c.y, 3, c.t+2));
			Q.push(State(c.x, c.y-1, 1, c.t+2));
			Q.push(State(c.x, c.y, 1, c.t+1+w0));
			Q.push(State(c.x, c.y, 3, c.t+1+w1));			
		}
		if(c.c == 3) {
			Q.push(State(c.x-1, c.y, 2, c.t+2));
			Q.push(State(c.x, c.y-1, 0, c.t+2));
			Q.push(State(c.x, c.y, 0, c.t+1+w0));
			Q.push(State(c.x, c.y, 2, c.t+1+w1));			
		}

	}
}


int main() {		
	int C;
	cin >> C;
	for(int i = 1; i <= C; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}