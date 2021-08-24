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

VI bad[10];

int check(int num,int base,int cnt){
	VI ap;
	ap.clear();
	int s=0;
	int ans=1;
	int bound=2*base*base;
	while(num!=1){
		if (num<bound)
			REP(i,bad[cnt]){
				if (num==bad[cnt][i]) {ans=0;break;}
			}
		if (ans==0) break;

		ap.push_back(num);
		s=0;
		while (num>0){
			s+=(num%base)*(num%base);
			num/=base;
		}
		num=s;
		bool f=false;
		REP(i,ap)
			if (ap[i]==num) {f=true;break;}
		if (f) {ans=0;break;}
	}
	
	if (ans==0){
		REP(i,ap)
			if (ap[i]<bound) bad[cnt].push_back(ap[i]);
	}
	return ans;

}
int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	

	int T;
	cin>>T;
	char ch[1000];
	cin.getline(ch,1000);
	int base[10],nbase;

	FOR(k,0,T){
		FOR(i,0,10)
			bad[i].clear();
		cin.getline(ch,1000);
		string st=ch;
		istringstream sin(st);
		nbase=0;
		while (sin>>base[nbase]){
			++nbase;
		}
		int s=1;
		bool f=true;
		while (f){
			f=false;
			++s;
			FOR(i,0,nbase){
				if (check(s,base[i],i)==0) {f=true;break;}
			}
			
		}
		cout<<"Case #"<<k+1<<": "<<s<<endl;
	}
	return 0;

}