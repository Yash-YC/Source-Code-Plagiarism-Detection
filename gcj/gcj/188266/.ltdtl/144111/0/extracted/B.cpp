#include <map>     
#include <set>     
#include <cmath>    
#include <cstdio>   
#include <vector>     
#include <string>     
#include <sstream>    
#include <iostream>    
#include <algorithm>     
using namespace std;     
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)     
#define FORE(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)     
#define SET(x, v) memset(x, v, sizeof (x))     
#define sz size()     
#define cs c_str()     
#define pb push_back     
#define mp make_pair    
 
typedef long long ll;

int N,M;
int minp[22][22][4];
int chk[22][22][4];
int S[22][22], W[22][22], t[22][22];
const int SOUTH = 1, WEST = 2;
void try_update(int x, int y, int z, int v) {
	// valid check first:
	if(x>=0 && y>=0 && x<N && y<M) {
		//printf("\t (%d, %d, %d) %d\n",x,y,z,v);
		if(minp[x][y][z] == -1) minp[x][y][z] = v;
		else if(minp[x][y][z] > v)
			minp[x][y][z] = v;
	}
}
int wait_for(int flag, int x, int y, int v) {
	v%= (S[x][y] + W[x][y]);
	if(flag == SOUTH) {
		if(v < t[x][y]-W[x][y]) return 0;
		if(t[x][y]<=v && v<t[x][y] + S[x][y]) return 0;
		return (t[x][y] + S[x][y] + W[x][y] - v) % (S[x][y] + W[x][y]);
	}
	else {
		if(t[x][y]-W[x][y]<=v && v<t[x][y]) return 0;
		if(t[x][y]+S[x][y]<=v) return 0;

		return (t[x][y] + S[x][y] - v) % (S[x][y] + W[x][y]);
	}
}
int main() {
	int e = 0, T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		FOR(i,0,N) {
			FOR(j,0,M) {
				scanf("%d%d%d",&S[i][j],&W[i][j],&t[i][j]);
				t[i][j] %= (S[i][j] + W[i][j]);
			}
		}
		SET(chk, 0);
		SET(minp, -1);
		// end point: [0][M-1][3]
		int x = N-1, y = 0, z = 0;
		minp[N-1][0][0] = 0; //starting point=
		chk[x][y][z] = 1;
		while(!chk[0][M-1][3]) {
			// move from (x,y,z)
			int v = minp[x][y][z];
			int ext = 0;
			//printf("%d, %d, %d, %d\n",x,y,z,v);
			switch(z) {
				case 0:
					try_update(x, y-1, 2, v+2);
					try_update(x+1, y, 1, v+2);
					
					ext = wait_for(SOUTH, x, y, v);
					try_update(x, y, 1, v + ext + 1);
					ext = wait_for(WEST, x, y, v);
					try_update(x, y, 2, v + ext + 1);

					break;
				case 1:
					try_update(x, y-1, 3, v+2);
					try_update(x-1, y, 0, v+2);

					ext = wait_for(SOUTH, x, y, v);
					try_update(x, y, 0, v + ext + 1);
					ext = wait_for(WEST, x, y, v);
					try_update(x, y, 3, v + ext + 1);
					break;
				case 2:
					try_update(x, y+1, 0, v+2);
					try_update(x+1, y, 3, v+2);

					ext = wait_for(SOUTH, x, y, v);
					try_update(x, y, 3, v + ext + 1);
					ext = wait_for(WEST, x, y, v);
					try_update(x, y, 0, v + ext + 1);
					break;
				case 3:
					try_update(x, y+1, 1, v+2);
					try_update(x-1, y, 2, v+2);

					ext = wait_for(SOUTH, x, y, v);
					try_update(x, y, 2, v + ext + 1);
					ext = wait_for(WEST, x, y, v);
					try_update(x, y, 1, v + ext + 1);
					break;
				default://wtf
					break;
			}
			int mini = 2147483647, px=-1, py, pz;
			FOR(i,0,N)
				FOR(j,0,M)
					FOR(k,0,4)
						if(!chk[i][j][k] && (minp[i][j][k]!=-1 && mini > minp[i][j][k])) {
							mini = minp[i][j][k];
							px = i, py = j, pz = k;
						}
			x = px;
			y = py;
			z = pz;
			chk[x][y][z] = 1;
		}
		printf("Case #%d: %d\n",++e, minp[0][M-1][3]);
	}
	return 0;
}

