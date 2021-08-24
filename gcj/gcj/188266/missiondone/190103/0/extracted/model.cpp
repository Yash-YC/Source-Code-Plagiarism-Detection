#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<algorithm>
#include <map>

using namespace std;
#define SZ(v) ((int)v.size())
#define FOR(i,b,e) for(int i = b;i < e; ++i)
#define REP(i,v) FOR(i,0,SZ(v))
typedef vector<int> VI; 
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<char> VC;
typedef long long int64;
typedef unsigned long long uint64;
const double pi=acos(-1.0);
const double eps=1e-11;
#define zero(x) memset(&x, 0, sizeof x);

double jc(int j,int c){
	if (j>c) return 0;
	double s=1;
	for(int i=j+1;i<c+1;++i){
		s*=i;
		s/=(i-j);
	}
	return s;		
}

double jc2(int c,int m,int n){
//jc(C,i-1)/jc(C,N);
	double s=1;
	if (c>m) return 0;

	for(int i=m+1;i<n+1;++i){
		s/=i;
		s*=(i-c);
	}

	return s;
}
//double jcc(int an,j,ni,cj,i1,n){
//(n[i-1+j])*jc(j,N-i+1)*jc(C-j,i-1)/jc(j,N)
//	double s=an;
	

//}

int main(){
	freopen("C-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	

	int T,C,N;
	cin>>T;
	double n[100];
	FOR(k,0,T){
		cin>>N;
		cin>>C;
		n[N]=0;
		for(int i=N;i>C;--i){
			double p=double(i-1)/N;
//			double d=1-jc(C,i-1)/jc(C,N);
			double d=1-jc2(C,i-1,N);
			double s=0;
			FOR(j,1,C+1){
				if (i-1+j<=N)
					s+=(n[i-1+j])*jc(j,N-i+1)/jc(j,N)*jc(C-j,i-1);
			}
			s+=1;
			n[i-1]=s/d;
			
		}

		
		cout<<"Case #"<<k+1<<": ";
		printf("%.7lf",n[C]+1);
		cout<<endl;
	}
	return 0;

}