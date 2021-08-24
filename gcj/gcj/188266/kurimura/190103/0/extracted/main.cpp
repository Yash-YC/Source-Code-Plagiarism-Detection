#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<string>
#include<iterator>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
int C(int n,int k){
	int r = 1;
	for(int i=1;i<=n;++i){
		r *= k - i + 1;
		if(r%i)throw "";
		r /= i;
	}
	return r;
}
long double solve(int c,int n,long double p,int k,int step){
	if(k == c)return step*p;
	if(p < 0.0000000001L)return 0;
	long double r = 0;
	int nCc = C(n,c);
	for(int i=0;i<=n;++i){
		if(i > c-k)break;
		if(n-i > k)continue;
		int iCk  = C(n-i,k);
		int niCck= C(i,c-k);
		double r2 = solve(c,n,p * iCk * niCck / nCc,k+i,step+1);
		r += r2;
	}
	return r;
}
int main(){
	int k;
	int c,n;
	cin >> k;
	for(int i=1;i<=k;++i){
		cin >> c >> n;
		cout << "Case #" << i << ": ";
		cout << setprecision(20);
		cout << solve(c,n,1.0,0,0);
		cout << endl;
	}
}
