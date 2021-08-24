#include<cstdio>
#include<cstring>
#define L 100

using namespace std;

double opt[L],C[L][L];
int i,j,n,c,T,I=0;
double p;

int main(){
	memset(C,0,sizeof C);
	for (i=0;i<100;++i)
	    for (j=0;j<=i;++j)
	        if (j==i || !j) C[i][j]=1;
	        else C[i][j]=C[i-1][j]+C[i-1][j-1];
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&c,&n);
		opt[c]=0;
		for (i=c-1;i>=0;--i){
			opt[i]=0;
			p=0;
		    for (j=0;j<n;++j)
		        if (j<=i && i+n-j<=c){
					p+=C[i][j]*C[c-i][n-j]/C[c][n];
					opt[i]+=C[i][j]*C[c-i][n-j]/C[c][n]*(opt[i+n-j]);
				}
			opt[i]/=p;
			opt[i]+=1/p;
		}
		printf("Case #%d: %.10lf\n",++I,opt[0]);
	}
}
