#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double c[45][45],F[1005][45];

void init()
{
	for(int i = 0 ; i < 41 ; i++) {
		c[i][0] = 1.0;
		c[i][i] = 1.0;
	}
	for(int i = 2 ; i < 41 ; i++) {
		for(int j = 1 ; j < i ; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
} 

int main() {
	init();
/*	
	for(int i = 0 ; i < 10; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			 printf("%0.0lf ",c[i][j]);
		}
		printf("\n");
	}
*/	

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t = 0 ; t < T ; t++) {
		int N,C; 
		memset(F,0,sizeof(F));
		scanf("%d%d",&C,&N);
		F[1][N] = 1.0;
		for(int i = 1 ; i < 1000 ; i++) {
			for(int j  = N ; j < C ; j++) {
				for(int k = 0 ; k <= min(N,C - j) ; k++) {
					F[i + 1][j + k] += F[i][j] * (c[C - j][k] * c[j][N - k] )/ c[C][N];
				}
			}
		}
/*		
		for(int i  = 0 ; i < 10 ; i++) {
			for(int j = 0 ; j <= C ; j++) {
				printf("%0.6lf ",F[i][j]);
			}
			printf("\n");
		}
*/		
		double Ans = 0.0;
		for(int i = 0 ; i < 1000 ; i++) {
			Ans += F[i][C] * i;
		}
		
		printf("Case #%d: %0.6lf\n",t + 1,Ans); 
		
	}
}
