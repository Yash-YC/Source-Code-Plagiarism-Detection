#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct trip {
	int x, y, z;
};

int C, N, M;
int S[20][20];
int W[20][20];
int D[20][20];
int T[20][20];
bool v[20][20][4];
trip nv[1600];
int nvc;
int vc;
int a[20][20][4];
inline void fill(int nx, int ny, int nz, int c) {
	if(v[nx][ny][nz]) return;
	if(a[nx][ny][nz]==-1 || c<a[nx][ny][nz]) {
		a[nx][ny][nz]=c;
	}
}

int main() {
	freopen("B.in","r",stdin);
	FILE *out = fopen("B.out","w");
	scanf("%d",&C);
	for(int t=0;t<C;t++) {
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				scanf("%d%d%d",&S[i][j],&W[i][j],&T[i][j]);
				D[i][j] = S[i][j] + W[i][j];
				//T contains stage of intersection i at t=0
				T[i][j] = T[i][j] % D[i][j];
				if(T[i][j])
					T[i][j] = D[i][j] - T[i][j];
			}
		}
		memset(a,255,6400);
		memset(v,0,6400);
		a[N-1][0][2]=0;
		int cx = N-1;
		int cy = 0;
		int cz = 2;
		int vc = 0;
		do {
			int cc = a[cx][cy][cz];
			int ct = (a[cx][cy][cz] + T[cx][cy]) % D[cx][cy];
			int ns=ct-S[cx][cy];
			switch(cz) {
				case 0: //NW
					//move E to z=1
					fill(cx,cy,1,ns<0 ? 1-ns+cc : 1+cc);		
					//move S to z=2
					fill(cx,cy,2,ns<0 ? 1+cc : 1+D[cx][cy]-ct+cc);
					//move W
					if(cy!=0) {
						fill(cx,cy-1,1,cc+2);
					}
					//move N
					if(cx!=0) {
						fill(cx-1,cy,2,cc+2);
					}
					break;
				case 1: //NE
					//move W to z=0
					fill(cx,cy,0,ns<0 ? 1-ns+cc : 1+cc);		
					//move S to z=3
					fill(cx,cy,3,ns<0 ? 1+cc : 1+D[cx][cy]-ct+cc);
					//move E
					if(cy!=M-1) {
						fill(cx,cy+1,0,cc+2);
					}
					//move N
					if(cx!=0) {
						fill(cx-1,cy,3,cc+2);
					}
					break;
				case 2: //SW
					//move E to z=3
					fill(cx,cy,3,ns<0 ? 1-ns+cc : 1+cc);		
					//move N to z=0
					fill(cx,cy,0,ns<0 ? 1+cc : 1+D[cx][cy]-ct+cc);
					//move W
					if(cy!=0) {
						fill(cx,cy-1,3,cc+2);
					}
					//move S
					if(cx!=N-1) {
						fill(cx+1,cy,0,cc+2);
					}
					break;
				case 3: //SE
					//move W to z=2
					fill(cx,cy,2,ns<0 ? 1-ns+cc : 1+cc);		
					//move N to z=0
					fill(cx,cy,1,ns<0 ? 1+cc : 1+D[cx][cy]-ct+cc);
					//move E
					if(cy!=M-1) {
						fill(cx,cy+1,2,cc+2);
					}
					//move S
					if(cx!=N-1) {
						fill(cx+1,cy,1,cc+2);
					}
					break;
			}
			
			v[cx][cy][cz] = 1;
			vc++;
			//find next node to visit
			int min=~(1<<31);
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					for(int k=0;k<4;k++) {
						if(!v[i][j][k] && a[i][j][k]!=-1 && a[i][j][k]<min) {
							min = a[i][j][k];
							cx=i;
							cy=j;
							cz=k;	
						}
					}
				}
			}
		} while(vc<M*N*4);
		
		fprintf(out,"Case #%d: %d\n",t+1,a[0][M-1][1]);
	}
	fclose(out);
	return 0;
}