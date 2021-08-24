#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#define mp(a,b) make_pair(a,b)

using namespace std;

int  N, M;
int S[30][30], W[30][30], T[30][30];
long long dist[60][60];

bool read(){
	
	scanf("%d%d", &N, &M);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d%d%d", &S[i][j], &W[i][j], &T[i][j]);
			T[i][j] %= (S[i][j] + W[i][j]);
			T[i][j] -= (S[i][j] + W[i][j]);
		}
	}
	
	return true;
}

int caso = 1;

void process(){
	priority_queue< pair< long long, pair<int,int> > > heap;
	int i, j;
	long long dista, ntime, timeAtual;
	int myInteri, myInterj;
	heap.push( make_pair(0, make_pair( 2*N-1, 0)));
	
	for(i = 0; i <= 2*N; i++)
		for( j = 0; j <= 2*M; j++)
			dist[i][j] = 0x6363636363636363LL;
	dist[2*N-1][0] = 0;
	
	while(!heap.empty()){
		i = heap.top().second.first;
        j = heap.top().second.second;
		dista = -heap.top().first;
		heap.pop();
		
		//printf("%d %d %d\n", i, j, dista);
		if(dist[i][j] < dista)
			continue;
			
		if(i == 0 && j == 2*M-1){
			printf("Case #%d: %I64d\n", caso++, dista);
			return;
		}
		if(i%2 != 0){
			if(i < 2*N-1 && dist[i+1][j] > dist[i][j] + 2){
				dist[i+1][j] = dist[i][j] + 2;
				heap.push(mp(-dist[i+1][j], mp(i+1,j)));
			}
		}else{
			if(i > 0 && dist[i-1][j] > dist[i][j] + 2){
				dist[i-1][j] = dist[i][j] + 2;
				heap.push(mp(-dist[i-1][j], mp(i-1,j)));
			}
		}
		if(j%2 != 0){
			if(j < 2*M-1 && dist[i][j+1] > dist[i][j] + 2){
				dist[i][j+1] = dist[i][j] + 2;
				heap.push(mp(-dist[i][j+1], mp(i, j+1)));
			}
		}else{
			if(j > 0 && dist[i][j-1] > dist[i][j] + 2){
				dist[i][j-1] = dist[i][j] + 2;
				heap.push(mp(-dist[i][j-1], mp(i, j-1)));
			}
		}
		
		
		myInteri = i / 2;
		myInterj = j / 2;
		timeAtual = (dista - T[myInteri][myInterj])%(S[myInteri][myInterj] + W[myInteri][myInterj]);
		if(timeAtual < S[myInteri][myInterj]){
			ntime = dista + 1;
		//	printf("oi at = %I64d , %I64d av\n", timeAtual, ntime);
		}else{
			ntime = dista - timeAtual + S[myInteri][myInterj] + W[myInteri][myInterj] + 1;
			//printf("dista = %lld, T  = %d, S = %d, W = %d\n", dista,T[myInteri][myInterj],S[myInteri][myInterj],W[myInteri][myInterj]);
			//printf("xau at = %I64d , %I64d av\n", timeAtual, ntime);
		}
		
		if(i%2 == 0){
			if(i < 2*N-1 && dist[i+1][j] > ntime){
				dist[i+1][j] = ntime;
			//	printf("botei %d,%d,%d\n", i+1,j,ntime);
				heap.push(mp(-ntime, mp(i+1,j)));
			}
		}else{
			if(i > 0 && dist[i-1][j] > ntime){
			//	printf("botei %d,%d,%d\n", i-1,j,ntime);
				dist[i-1][j] = ntime;
				heap.push(mp(-ntime, mp(i-1,j)));
			}
		}
				
		if(timeAtual >= S[myInteri][myInterj]){
			ntime = dista + 1;
		}else{
			ntime = dista - timeAtual + S[myInteri][myInterj] + 1;
		}
		//printf("%d rua\n", ntime);
		if(j%2 == 0){
			if(j < 2*M-1 && dist[i][j+1] > ntime){
			// printf("botei %d,%d,%d\n", i,j+1,ntime);
				dist[i][j+1] = ntime;
				heap.push(mp(-ntime, mp(i, j+1)));
			}
		}else{
			if(j > 0 && dist[i][j-1] > ntime){
			//printf("botei %d,%d,%d\n", i,j-1,ntime);
				dist[i][j-1] = ntime;
				heap.push(mp(-ntime, mp(i, j-1)));
			}
		}
		
	}
}

int main(){
	int casos;
	
	freopen("data2.in","r", stdin);
	freopen("data.out","w", stdout);
	
	scanf("%d", &casos);
	
	while(casos--){
		read();
		process();
	}
	
	return 0;
}