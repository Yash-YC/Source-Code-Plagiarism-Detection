#include<queue>
#include<cstdio>
#include<cstdlib>

#define MAXN 25
#define INFTY 0x7FFFFFFFFFFFFFFFll

using namespace std;

long long mod(long long a, long long b) {
	return (a%b+b)%b;
}

int N, M;

bool valid(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

long long nextgreen(int S1, int S2, int T, long long t, bool ns) {
	if(ns) {
		if(mod(t-T,S1+S2) < S1) {
			return t;
		} else {
			return t + (S1+S2 - mod(t-T,S1+S2));
		}
	} else {
		if(mod(t-T,S1+S2) >= S1) {
			return t;
		} else {
			return t + (S1 - mod(t-T,S1+S2));
		}
	}
}

int main() {
	long long dist[MAXN][MAXN][4]; // 0 = sw, 1 = nw, 2 = ne, 3 = se
	int S1[MAXN][MAXN], S2[MAXN][MAXN], T[MAXN][MAXN];
	FILE *fin = fopen("B.in","r"), *fout = fopen("B.out","w");
	int C;
	fscanf(fin,"%d",&C);
	for(int cc = 1; cc<=C; cc++) {
		for(int i = 0; i<MAXN; i++)
			for(int j = 0; j<MAXN; j++)
				for(int k = 0; k<4; k++)
					dist[i][j][k]=INFTY;
		fscanf(fin,"%d%d",&N,&M);
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<M; j++) {
				fscanf(fin,"%d%d%d",&S1[i][j],&S2[i][j],&T[i][j]);
			}
		}
		dist[N-1][0][0]=0;
		priority_queue< pair< pair<long long,int>,pair<int,int> > > pq;
		pq.push(make_pair(make_pair(0ll,0),make_pair(N-1,0)));
		while(!pq.empty()) {
			pair< pair<long long,int>,pair<int,int> > p = pq.top();
			pq.pop();
			if(p.first.first > dist[p.second.first][p.second.second][p.first.second]) continue;
			int r = p.second.first, c = p.second.second, d = p.first.first, k = p.first.second;
			if(p.first.second == 0) {
				if(valid(r,c-1)) {
					if(dist[r][c][0]+2 < dist[r][c-1][3]) {
						dist[r][c-1][3] = dist[r][c][0] + 2;
						pq.push(make_pair(make_pair(dist[r][c][0]+2,3),make_pair(r,c-1)));
					}
				}
				if(valid(r+1,c)) {
					if(dist[r][c][0]+2 < dist[r+1][c][1]) {
						dist[r+1][c][1] = dist[r][c][0] + 2;
						pq.push(make_pair(make_pair(dist[r][c][0]+2,1),make_pair(r+1,c)));
					}
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][0],true) + 1 < dist[r][c][1]) {
					dist[r][c][1] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][0],true) + 1;
					pq.push(make_pair(make_pair(dist[r][c][1],1),make_pair(r,c)));
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][0],false) + 1 < dist[r][c][3]) {
					dist[r][c][3] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][0],false) + 1;
					pq.push(make_pair(make_pair(dist[r][c][3],3),make_pair(r,c)));
				}
			} else if(p.first.second == 1) {
				if(valid(r-1,c)) {
					if(dist[r][c][1]+2 < dist[r-1][c][0]) {
						dist[r-1][c][0] = dist[r][c][1] + 2;
						pq.push(make_pair(make_pair(dist[r][c][1]+2,0),make_pair(r-1,c)));
					}
				}
				if(valid(r,c-1)) {
					if(dist[r][c][1]+2 < dist[r][c-1][2]) {
						dist[r][c-1][2] = dist[r][c][1] + 2;
						pq.push(make_pair(make_pair(dist[r][c][1]+2,2),make_pair(r,c-1)));
					}
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][1],true) + 1 < dist[r][c][0]) {
					dist[r][c][0] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][1],true) + 1;
					pq.push(make_pair(make_pair(dist[r][c][0],0),make_pair(r,c)));
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][1],false) + 1 < dist[r][c][2]) {
					dist[r][c][2] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][1],false) + 1;
					pq.push(make_pair(make_pair(dist[r][c][2],2),make_pair(r,c)));
				}
			} else if(p.first.second == 2) {
				if(valid(r-1,c)) {
					if(dist[r][c][2]+2 < dist[r-1][c][3]) {
						dist[r-1][c][3] = dist[r][c][2] + 2;
						pq.push(make_pair(make_pair(dist[r][c][2]+2,3),make_pair(r-1,c)));
					}
				}
				if(valid(r,c+1)) {
					if(dist[r][c][2]+2 < dist[r][c+1][1]) {
						dist[r][c+1][1] = dist[r][c][2] + 2;
						pq.push(make_pair(make_pair(dist[r][c][2]+2,1),make_pair(r,c+1)));
					}
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][2],true) + 1 < dist[r][c][3]) {
					dist[r][c][3] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][2],true) + 1;
					pq.push(make_pair(make_pair(dist[r][c][3],3),make_pair(r,c)));
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][2],false) + 1 < dist[r][c][1]) {
					dist[r][c][1] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][2],false) + 1;
					pq.push(make_pair(make_pair(dist[r][c][1],1),make_pair(r,c)));
				}
			} else if(p.first.second == 3) {
				if(valid(r+1,c)) {
					if(dist[r][c][3]+2 < dist[r+1][c][2]) {
						dist[r+1][c][2] = dist[r][c][3] + 2;
						pq.push(make_pair(make_pair(dist[r][c][3]+2,2),make_pair(r+1,c)));
					}
				}
				if(valid(r,c+1)) {
					if(dist[r][c][3]+2 < dist[r][c+1][0]) {
						dist[r][c+1][0] = dist[r][c][3] + 2;
						pq.push(make_pair(make_pair(dist[r][c][3]+2,0),make_pair(r,c+1)));
					}
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][3],true) + 1 < dist[r][c][2]) {
					dist[r][c][2] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][3],true) + 1;
					pq.push(make_pair(make_pair(dist[r][c][2],2),make_pair(r,c)));
				}
				if(nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][3],false) + 1 < dist[r][c][0]) {
					dist[r][c][0] = nextgreen(S1[r][c],S2[r][c],T[r][c],dist[r][c][3],false) + 1;
					pq.push(make_pair(make_pair(dist[r][c][0],0),make_pair(r,c)));
				}
			}
		}
		fprintf(fout,"Case #%d: %lld\n",cc,dist[0][M-1][2]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
