#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

double F[41];
int N, C;
double comb[42][42];

bool read(){
	scanf("%d%d", &C, &N);
	return true;
}

int caso = 1;

void process(){
	F[C] = 0;
	int l;
	for(int i = C-1; i >= N; i--){
		l = min(N, C-i);
		F[i] = 1.0;	
		for(int j = 1; j <= l; j++){
			F[i] += (comb[C-i][j]*comb[i][N-j]/comb[C][N])*F[i+j];
		}
		//printf("%lf %lf\n", comb[i][N],comb[C][N]);
		F[i] /= (1.0 - (comb[i][N]/comb[C][N]));
	}
	printf("Case #%d: %.7lf\n", caso++, 1 + F[N]);
}

int main(){
	int casos;
	
	freopen("data2.in","r", stdin);
	freopen("data.out","w", stdout);
	
	scanf("%d", &casos);
	
	comb[0][0] = 1;
	for(int i= 1; i <= 40; i++){
		comb[i][0] = 1;
		comb[i][1] = i;
		comb[i][i] = 1;
		for(int j = 2; j < i; j++){
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}
	while(casos--){
		read();
		process();
	}
	
	return 0;
}