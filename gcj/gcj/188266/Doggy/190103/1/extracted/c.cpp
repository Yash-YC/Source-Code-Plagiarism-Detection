#include <cstdio>
using namespace std;

double a[100][100];
double f[100];
int C,c,n;

int gmin(int a,int b) {
    return (a<b)?(a):(b);
}    

int main() {
    a[0][0]=1;
	for (int i=1;i<=40;i++) {
		a[i][0]=1;
		for (int j=1;j<=i;j++) a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
 	scanf("%d",&C);
  	for (int x=1;x<=C;x++) {
  	    scanf("%d%d",&c,&n);
  	    for (int p=1;p<=c-n;p++) {
  	        double tmp=0;
  	        for (int j=1;j<=gmin(n,p);j++) {
  	            tmp=tmp+a[p][j]/a[c][n]*a[c-p][n-j]*(f[p-j]+1);
  	        }    
  	        double x=a[p][0]/a[c][n]*a[c-p][n];
  	        f[p]=(tmp+x)/(1-x);
  	    }    
  	    printf("Case #%d: %0.7lf\n",x,f[c-n]+1);
   	}    	
}    
