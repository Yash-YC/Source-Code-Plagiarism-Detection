#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int t,c,n;

double C[41][41];
void comb(int lim) {
	int n,r;
	for (n=1;n<=lim;n++) {
		C[n][0]=1;
		for (r=1;r<=n-1;r++) {
			C[n][r]=C[n-1][r-1]+C[n-1][r];
		}
		C[n][n]=1;
	}
}

double dp[41];
double f(int x) {
	if (x==0) {
		if (n>=c) return 1;
		else return (f(n)+1);
	} else if (x==c) {
		return 0;
	} else {
		if (dp[x]!=-1) return dp[x];
		double r=0;
		for (int k=1;k<=n && x+k<=c;k++) {
			double p=C[c-x][k]*C[x][n-k]/C[c][n];
			r+=(f(x+k)+1)*p;
		}
		double p=C[x][n]/C[c][n];
		dp[x] = (r+p)/(1-p);
		return dp[x];
	}
}

int main() {
	ifstream fin("C-small-attempt0.in");
	FILE *fout=fopen("C-small-attempt0.out","w");
	comb(40);
	fin >> t;
	for (int test=1;test<=t;test++) {
		fin >> c >> n;
		for (int i=0;i<=c;i++) dp[i]=-1;
		fprintf(fout,"Case #%d: %.8lf\n",test,f(0));
	}
    return 0;
}
