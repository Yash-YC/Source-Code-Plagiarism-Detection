#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

LL choose[64][64];
double E[64];

int main(){
	//compute n choose k
	memset(choose,0,sizeof(choose));
	for(int n=0; n<=40; n++){
		choose[n][0]=choose[n][n]=1;
		for(int k=1; k<n; k++)
			choose[n][k]=choose[n-1][k-1]+choose[n-1][k];
	}

	int T, C, N; 
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &C, &N);
		memset(E,0,sizeof(E));

		for(int k=C-1; k>=0; k--){
			E[k]=1.;
			for(int i=1; i<= min(N,C-k); i++)
				E[k]+= (double)(choose[C-k][i]*choose[k][N-i])/choose[C][N] * E[k+i];
			E[k]/= (1-(double)(choose[k][N])/choose[C][N]);
		}

		printf("Case #%d: %.7f\n", t+1, E[0]);
	}
}
