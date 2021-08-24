#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 25,M = 25;

struct node {
	int x,y,p,d;
	node(int a,int b,int c,int e) : x(a),y(b),p(c),d(e) {}
	node() {};
	bool operator < (const node &a)const {
		return d > a.d;
	}
};

int ans[N][M][4],mk[N][M][4];;
int S[N][M],W[N][M],T[N][M];
int n,m;
int dir[4][4][3] = {
	{{0,0,1},{0,0,-1},{0,-1,-1},{1,0,1}},
	{{0,0,1},{0,0,-1},{-1,0,-1},{0,-1,1}},
	{{0,0,1},{0,0,-1},{0,1,-1},{-1,0,1}},
	{{0,0,1},{0,0,-1},{0,1,1},{1,0,-1}}
};

int check(int x,int y) {
	if(x >= 0 && x < n && y >= 0 && y < m)return 1;
	return 0;
}

int cal(node t,int x,int y,int to) {
	int d = t.d;
	int now = d + T[x][y];
	now %= (S[x][y] + W[x][y]);
	if(t.p == 0 || t.p == 2) {
		if(to == 0) {
			if(now < S[x][y]) {
				return 1;
			} else {
				return S[x][y] + W[x][y] - now + 1;
			}
		} else {
			if(now >= S[x][y]) {
				return 1;
			} else {
				return S[x][y] - now + 1;
			}
		}
	} else {
		if(to == 0) {
			if(now >= S[x][y]) {
				return 1;
			} else {
				return S[x][y] - now + 1;
			} 
		} else {
			if(now < S[x][y]) {
				return 1;
			} else {
				return S[x][y] + W[x][y] - now + 1;
			}
		}
	}
}

int solve() {
	memset(ans,0x7f,sizeof(ans));
	memset(mk,0,sizeof(mk));
	priority_queue<node>q;

	ans[n - 1][0][0] = 0;
	q.push( node (n - 1,0,0,0) );

	while(!q.empty()) {
		node t = q.top();
		q.pop();

		if(mk[t.x][t.y][t.p])continue;
		mk[t.x][t.y][t.p] = 1;

		if(t.x == 0 && t.y == m - 1 && t.p == 2){
			return t.d;
		}
		for(int i = 0;i < 4;++i) {
			int tx = t.x + dir[t.p][i][0],ty = t.y + dir[t.p][i][1],tp = t.p + dir[t.p][i][2],td;
			tp = (tp + 4) % 4;
			if(!check(tx,ty) || mk[tx][ty][tp])continue;
			if(i > 1)td = t.d + 2;
			else td = t.d + cal(t,tx,ty,i);
			if(ans[tx][ty][tp] > td) {
				ans[tx][ty][tp] = td;
				q.push( node(tx,ty,tp,td) );
			}
		}
	}
	return -1;
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int Tc;
	int cas = 1;
	scanf("%d",&Tc);
	while(Tc--) {
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;++i) {
			for(int j = 0;j < m;++j) {
				scanf("%d%d%d",&S[i][j],&W[i][j],&T[i][j]);
				T[i][j] %= (S[i][j] + W[i][j]);
				T[i][j] = (S[i][j] + W[i][j]) - T[i][j];
			}
		}
		printf("Case #%d: %d\n",cas++,solve());
	}
	return 0;
}

