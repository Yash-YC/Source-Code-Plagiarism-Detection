#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int c,n;

long double dp[100];

long double binom(int a, int b) {
    if(b>a && b<0 )cout<<"fdsfsd"<<endl;
    long double ret = 1.0;
    int i;
    for(i=0;i<b;++i) {
	ret *= (long double)(a-i);
	ret /= (long double)(i+1.0);
    }
    return ret;
}

long double f(int m) {
    //cout<<"ffds "<<m<<endl;
    if(dp[m] > -0.5)return dp[m];
    if(m>=c) {
	dp[m] = 0.0;
	return 0.0;
    }
    if(m>=c)cout<<"fdsf"<<endl;
    long double ret = 0.0;
    int p = c-m;
    int i,j;
    long double den = 1.0;
    //for(i=0;i<n;++i) {
    //den *= (long double)(c-i);
    //}
    den = binom(c,n);
    for(i=1;i<=p && i<=n;++i) {
// 	long double prob = 1.0;
// 	for(j=0;j<i;++j) {
// 	    prob *= (long double)(p-j);
// 	    if(c-j>0)prob /= (long double)(c-j);
// 	}
// 	if(n-i>m)prob=0.0;
// 	else {
// 	    for(j=0;j<n-i;++j) {
// 		prob *= (long double)()
// 	    }
// 	}
	long double nom = 0.0;
	if(p>=i && m>=n-i) {
	    nom = binom(p,i)*binom(m,n-i);
	    //if(nom/den > 1.0 || nom/den <0)cout<<"fdfsd"<<endl;
	    if(nom>0.0)ret = ret + (nom/den)*(f(m+i) + 1.0);
	}
    }
    i = 0;
    long double nom = 0.0;
    if(p>=i && m>=n-i){
	nom = binom(p,i)*binom(m,n-i);
	long double prob = nom/den;
	ret += prob;
	ret = ret / (1.0-prob);
    }
    dp[m] = ret;
    return ret;
}

int main() {
    int T,t;
    fin>>T;
    int i;
    for(t=1;t<=T;++t) {
	//cout<<t<<endl;
	fin>>c>>n;
	//cout<<c<<" "<<n<<endl;
	for(i=0;i<100;++i)dp[i] = -1.0;
// 	cout<<"fdsfs"<<endl;
	long double ret = f(0);
//	for(i=0;i<=c;++i)cout<<i<<" "<<dp[i]<<endl;
	fout.setf(ios::floatfield,ios::fixed);
	fout.precision(8);
	fout<<"Case #"<<t<<": "<<ret<<endl;
    }
    return 0;
}
