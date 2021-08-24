#include <cstdio>
#include <cctype>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
const int MAXN=44,NS=1,EW=0;
int T,N,M;
int vert[MAXN][MAXN],horiz[MAXN][MAXN],start[MAXN][MAXN];
long long dp[MAXN][MAXN],dp2[MAXN][MAXN];
inline bool valid(int x,int y) {return (x>=0 && x<N && y>=0 && y<N);}
inline void checkmin(ll &x,ll y) {if (y<x) {x=y;}}

inline ll mytime(int r,int c,ll starttime,int dir) {
	if (dir==NS) {
		int st=(starttime-start[r][c]+vert[r][c]+horiz[r][c])%(vert[r][c]+horiz[r][c]);
		if (st<vert[r][c]) {return starttime;}
		return starttime-st+vert[r][c]+horiz[r][c];
	}	else {
		int st=(starttime-start[r][c]+vert[r][c]+horiz[r][c])%(vert[r][c]+horiz[r][c]);
		if (st>=vert[r][c]) {return starttime;}
		return starttime-st+vert[r][c];
	}
}

inline void update() {
	memset(dp2,63,sizeof(dp2));
	for(int i=(N<<1)-1;i>=0;i--) {
		for(int j=0;j<(M<<1);j++) {
			checkmin(dp2[i][j],dp[i][j]);
			//up
			if (i>0) {
				if ((i&1)==0) {
					checkmin(dp2[i-1][j],dp[i][j]+2);
				}	else {
					checkmin(dp2[i-1][j],mytime(i>>1,j>>1,dp[i][j],NS)+1);
				}
			}
			//down
			if (i&1) {
				checkmin(dp2[i+1][j],dp[i][j]+2);
			}	else {
				checkmin(dp2[i+1][j],mytime(i>>1,j>>1,dp[i][j],NS)+1);
			}
			//right
			if (j&1) {
				checkmin(dp2[i][j+1],dp[i][j]+2);
			}	else {
				checkmin(dp2[i][j+1],mytime(i>>1,j>>1,dp[i][j],EW)+1);
			}
			//left
			if (j>0) {
				if (j&1) {
					checkmin(dp2[i][j-1],mytime(i>>1,j>>1,dp[i][j],EW)+1);
				}	else {
					checkmin(dp2[i][j-1],dp[i][j]+2);
				}				
			}
		}
	}
	memcpy(dp,dp2,sizeof(dp));
}

inline void solve() {
	memset(dp,63,sizeof(dp));
	dp[(N<<1)-1][0]=0;
	for(int i=0;i<MAXN*MAXN*4;i++) {
		update();
	}
}

int main() {
	scanf("%d\n",&T);
	for(int t=1;t<=T;t++) {
		memset(dp,63,sizeof(dp));
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				scanf("%d %d %d",&vert[i][j],&horiz[i][j],&start[i][j]);
				start[i][j]%=(vert[i][j]+horiz[i][j]);
			}
		}
		solve();
		printf("Case #%d: %lld\n",t,dp[0][M*2-1]);
	}
	return 0;
}