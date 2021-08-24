#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int N,M;

int S[22][22];
int W[22][22];
int T[22][22];

struct Sit {
	int i,j;
	int posicao;
	// 2 3
	// 0 1
	
	int d;
	
	bool operator <(const Sit & outro) const {
		return d > outro.d;
	}
};

bool marc[22][22][4];
int dist[22][22][4];

priority_queue<Sit> heap;
void tenta1(int i, int j, int posicao, int d) {
	//print("tentando... dist[%d][%d][%d] = %d\n", i,j,posicao,d);
	if (i >= 0 && j >= 0 && i <= N && j <= M) {
		if (!(i==0 && posicao == 2) &&
			!(i==0 && posicao == 3) &&
			!(j==0 && posicao == 1) &&
			!(j==0 && posicao == 3) &&
			!(i==N && posicao == 0) &&
			!(i==N && posicao == 1) &&
			!(j==M && posicao == 0) &&
			!(j==M && posicao == 2)
			) {
			
			if (!marc[i][j][posicao]) {
				if (dist[i][j][posicao] == -1 || dist[i][j][posicao] > d) {
					dist[i][j][posicao] = d;
					Sit s;
					s.i = i;
					s.j = j;
					s.d = d;
					s.posicao = posicao;
					//printf("tenta1 -> dist[%d][%d][%d] = %d\n", i,j,posicao,d);
					heap.push(s);
				}
			}
			
		}
	}
}

void tenta2(int i, int j, int posicao, int d, bool vert) {
	if (i >= 0 && j >= 0 && i <= N && j <= M) {
		if (!(i==0 && posicao == 2) &&
			!(i==0 && posicao == 3) &&
			!(j==0 && posicao == 1) &&
			!(j==0 && posicao == 3) &&
			!(i==N && posicao == 0) &&
			!(i==N && posicao == 1) &&
			!(j==M && posicao == 0) &&
			!(j==M && posicao == 2)
			) {
			
			if (!marc[i][j][posicao]) {
				
				int d2;
				int s,w,t;
				if (posicao == 0) {
					s = S[i][j];
					w = W[i][j];
					t = T[i][j];
				} else if (posicao == 1) {
					s = S[i][j-1];
					w = W[i][j-1];
					t = T[i][j-1];
				} else if (posicao == 2) {
					s = S[i-1][j];
					w = W[i-1][j];
					t = T[i-1][j];
				} else { //if (posicao == 3) {
					s = S[i-1][j-1];
					w = W[i-1][j-1];
					t = T[i-1][j-1];
				}
				
				int diferenca;
				int passos;
				if (d < t) {
					diferenca = t-d;
					passos = diferenca/(s+w);
					if (diferenca%(s+w)) {
						passos++;
					}
					t -= (s+w)*passos;
				}
				
				if (d >= t+(s+w)) {
					diferenca = d-t;
					passos = diferenca/(s+w);
					t += (s+w)*passos;
				}
				
				if (d < t+s) {
					// livre para vertical
					if (vert) {
						d+= 1;
					} else {
						d = t+s+1;
					}
				} else {
					// livre para horizontal
					if (vert) {
						d = t+s+w+1;
					} else {
						d+=1;
					}
				}
				
				if (dist[i][j][posicao] == -1 || dist[i][j][posicao] > d) {
					dist[i][j][posicao] = d;
					Sit s;
					s.i = i;
					s.j = j;
					s.d = d;
					s.posicao = posicao;
					//printf("tenta2 -> dist[%d][%d][%d] = %d\n", i,j,posicao,d);
					heap.push(s);
				}
				
			}
			
		}
	}
}

int process() {
	scanf("%d %d", &N, &M);
	for (int i = 0 ; i < N ; i++) {
		for (int j = 0 ; j < M ; j++) {
			scanf("%d%d%d", &S[i][j], &W[i][j], &T[i][j]);
		}
	}
	
	memset(marc, false, sizeof(marc));
	memset(dist, -1, sizeof(dist));
	while (!heap.empty()) {
		heap.pop();
	}
	
	Sit s;
	s.i = s.j = s.posicao = s.d = 0;	
	dist[0][0][0] = 0;
	heap.push(s);
	
	while (!heap.empty()) {
		s = heap.top();
		heap.pop();
		
		if (!marc[s.i][s.j][s.posicao]) {
			marc[s.i][s.j][s.posicao] = true;
			if (s.i == N && s.j == M && s.posicao == 3) {
				//printf("achou\n");
				break;
			}
			
			//printf(" marc[%d][%d][%d], dist %d\n", s.i,s.j,s.posicao, dist[s.i][s.j][s.posicao]);
			
			if (s.posicao == 0) {
				tenta1(s.i, s.j, 1, s.d+2);
				tenta1(s.i, s.j, 2, s.d+2);
			}
			
			if (s.posicao == 1) {
				tenta1(s.i, s.j, 0, s.d+2);
				tenta1(s.i, s.j, 3, s.d+2);
			}
			
			if (s.posicao == 2) {
				tenta1(s.i, s.j, 0, s.d+2);
				tenta1(s.i, s.j, 3, s.d+2);
			}
			
			if (s.posicao == 3) {
				tenta1(s.i, s.j, 1, s.d+2);
				tenta1(s.i, s.j, 2, s.d+2);
			}
			
			
			
			if (s.posicao == 0) {
				tenta2(s.i, s.j+1, 1, s.d, false);
				tenta2(s.i+1, s.j, 2, s.d, true);
			}
			
			if (s.posicao == 1) {
				tenta2(s.i, s.j-1, 0, s.d, false);
				tenta2(s.i+1, s.j, 3, s.d, true);
			}
			
			if (s.posicao == 2) {
				tenta2(s.i-1, s.j, 0, s.d, true);
				tenta2(s.i, s.j+1, 3, s.d, false);
			}
			
			if (s.posicao == 3) {
				tenta2(s.i-1, s.j, 1, s.d, true);
				tenta2(s.i, s.j-1, 2, s.d, false);
			}
			
		}
		
		
	}
	
	return dist[N][M][3];
}

int main() {
	
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int i = 0 ; i < T ; i++) {
		printf("Case #%d: %d\n", i+1, process());
	}
	
	return 0;
}
