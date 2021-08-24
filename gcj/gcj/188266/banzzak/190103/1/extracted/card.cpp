#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

#define N 41

#define P 100000

int n;
int m;


double p[P][N+1];
double edge[N+1][N+1];
int com[N+1][N+1];

void init(){
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			com[i][j]=0;
			edge[i][j]=0;
		}	
	}
	for(int i=0;i<P;i++){
		for(int j=0;j<=N;j++){
			p[i][j]=0;
		}
	}

}

void input(){
	cin >> n >> m ;
	com[0][0]=1;	
	for(int i=1;i<=n;i++){
		com[i][0]=1;
		for(int j=1;j<=i;j++){
			com[i][j] = com[i-1][j] + com[i-1][j-1];
		}
	}
}

void process(){
	for(int i=0;i<n;i++){
		for(int j=i;j<=min(n,i+m);j++){			
			edge[i][j] = com[i][m-j+i] * com[n-i][j-i];
			edge[i][j] /=com[n][m] ;
		}
	}

	int i=0;

	p[0][0]=1;

	for(int i=0;i<P;i++){
		for(int j=0;j<=n;j++){
			for(int k=j;k<=n;k++){
				p[i+1][k]+=p[i][j] * edge[j][k];
			}
		}		
	}



}

void output(){
	double ans=0;
	for(int i=0;i<P;i++){
		ans += p[i][n]*i;
	}
	
	if (ans < 0.000001)
		cout << 0 <<endl;
	else
		cout << ans <<endl;


}

int main(){
	int t=0,i=0;
	cin >> t;
	while(t--){
		i++;
	init();
	input();
	cout <<"Case #"<<i <<": ";
	process();	
	output();	
	}
	return 0;
}
