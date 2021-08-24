 #include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define foru(i,a,b) for(i=(a);i<=(b);i++)
#define ford(i,a,b) for(i=(a);i>=(b);i--)

int n,m;

long long c[50][50];
double f[100];

void prepare(){
	int i,j,k;
	c[0][0]=1;
	c[1][0]=1;
	c[1][1]=1;
	foru(i,2,40) {
		c[i][0]=1;
		c[i][i]=1;
		foru(j,1,i-1) c[i][j]=c[i-1][j-1] + c[i-1][j];
	}
}

double p[50];

double pp(int a, int b) {
	if (b<0) return 0;
	if (b>a) return 0;
	return c[a][b];
}

double gailv(int have , int select , int add) {
	return   double(pp(have , select - add) * pp(n-have , add)) / double(c[n][select]);
}

int main(){
    freopen("c.in","r",stdin);
	freopen("output.txt","w",stdout);
    int i,j,k,test,cases=0;
    scanf("%d",&test);
    prepare();
    while (test){
		test--;
		scanf("%d%d",&n,&m);	
		cases++;
		printf("Case #%d: ",cases);
		
		foru(i,0,n) f[i]=0;
		
		double p0;
		ford(i,n-1,0) {
			foru(j,0,n-i) p[j]=gailv( i , m , j);
	//		printf("%d : ",i);
	//		foru(j,0,n-i) printf("%lf   ",p[j]);
	//		printf("\n");
			
			double ans=0;
			foru(j,1,n-i) ans+=(f[i+j]+1) * p[j];
			f[i] = (ans  + p[0]) / (1-p[0]);
		}
		printf("%.7lf\n",f[0]);
	}
    return 0;
}
    
 
