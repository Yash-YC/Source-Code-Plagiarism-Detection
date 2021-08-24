#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
using namespace std;

int cases;
int n,m;
int g[20][20],r[20][20],off[20][20];

int vis[20][20][4];

typedef struct {
	int y; int x; int c; int t;
} state;

bool operator<(state s1, state s2) {
	return s1.t>s2.t;
}

int fixTime(state s, int dir) {
	int cyc=g[s.y][s.x]+r[s.y][s.x];
	int g2=g[s.y][s.x], r2=r[s.y][s.x], off2=off[s.y][s.x];
	int t2 = (s.t-off2)%cyc;
	if (t2<0) { t2+=cyc; }
	if (dir==0) { // vertical
		if (t2<g2) return s.t;
		else return s.t+(cyc-t2);
	} else if (dir==1) { // horizontal
		if (t2>=g2) return s.t;
		else return s.t+(g2-t2);
	}
}

bool check(state s) {
	if (vis[s.y][s.x][s.c]==-1 || s.t<vis[s.y][s.x][s.c]) {
		vis[s.y][s.x][s.c]=s.t;
		return true;
	} else {
		return false;
	}
}

int main() {
	ifstream fin("B-small-attempt1.in");
	FILE *fout=fopen("B-small-attempt1.out","w");
	fin >> cases;
	for (int c=1;c<=cases;c++) {
		fin >> n >> m;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				fin >> g[i][j] >> r[i][j] >> off[i][j];
				off[i][j]%=g[i][j]+r[i][j];
			}
		}

		/*state ss=(state){0,0,0,0};
		//cerr << fixTime(ss,0) << endl;
		cerr << fixTime(ss,1) << endl;
		return 0;*/

		memset(vis,-1,sizeof(vis));
		priority_queue<state> q;
		q.push((state){n-1,0,0,0});
		vis[n-1][0][0]=0;
		while (!q.empty()) {
			state s=q.top(); q.pop();
			if (s.y<0 || s.x<0 || s.y>=n || s.x>=m) continue; //off-board

			//char ch; printf("%d %d %d @ %d\n",s.y,s.x,s.c,s.t); scanf("%c",&ch);
			if (s.y==0 && s.x==m-1 && s.c==3) {
				fprintf(fout,"Case #%d: %d\n",c,s.t);
				break;
			}

			state s2;
			int t2;
			if (s.c==0) {
				s2=(state){s.y,s.x,2,fixTime(s,0)+1}; if (check(s2)) q.push(s2); //up
				s2=(state){s.y+1,s.x,2,s.t+2}; if (check(s2)) q.push(s2); //down
				s2=(state){s.y,s.x,1,fixTime(s,1)+1}; if (check(s2)) q.push(s2); //right
				s2=(state){s.y,s.x-1,1,s.t+2}; if (check(s2)) q.push(s2); //left
			} else if (s.c==1) {
				s2=(state){s.y,s.x,3,fixTime(s,0)+1}; if (check(s2)) q.push(s2); //up
				s2=(state){s.y+1,s.x,3,s.t+2}; if (check(s2)) q.push(s2); //down
				s2=(state){s.y,s.x+1,0,s.t+2}; if (check(s2)) q.push(s2); //right
				s2=(state){s.y,s.x,0,fixTime(s,1)+1}; if (check(s2)) q.push(s2); //left
			} else if (s.c==2) {
				s2=(state){s.y-1,s.x,0,s.t+2}; if (check(s2)) q.push(s2); //up
				s2=(state){s.y,s.x,0,fixTime(s,0)+1}; if (check(s2)) q.push(s2); //down
				s2=(state){s.y,s.x,3,fixTime(s,1)+1}; if (check(s2)) q.push(s2); //right
				s2=(state){s.y,s.x-1,3,s.t+2}; if (check(s2)) q.push(s2); //left
			} else if (s.c==3) {
				s2=(state){s.y-1,s.x,1,s.t+2}; if (check(s2)) q.push(s2); //up
				s2=(state){s.y,s.x,1,fixTime(s,0)+1}; if (check(s2)) q.push(s2); //down
				s2=(state){s.y,s.x+1,2,s.t+2}; if (check(s2)) q.push(s2); //right
				s2=(state){s.y,s.x,2,fixTime(s,1)+1}; if (check(s2)) q.push(s2); //left
			}
		}
	}
    return 0;
}
