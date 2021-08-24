#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;


int nxt(int n, int base){
	int ret=0;
	while(n>0){
		int rem = n%base;
		ret += rem*rem;
		n /= base;
	}
	return ret;
}

bool cac[10000][11];

bool is_happy(int a, int base){
	a = nxt(a,base);
	for(int i=0;i<1000;++i){
		a=nxt(a,base);
	}
	return a==1;
}


bool happy(int a, int base){
	return cac[nxt(a,base)][base];
}


int main(){

	for(int n=0;n<10000;++n) for(int b=2;b<=10;++b) cac[n][b] = is_happy(n,b);
	
	int T;
	cin >> T;
	char buf[1000];
	cin.getline(buf,sizeof(buf));
	
	for(int cas=1;cas<=T;++cas){

		cin.getline(buf,sizeof(buf));
		vector<int> bases;
		istringstream ss(buf);
		int bas;
		while(ss >> bas) bases.push_back(bas);
		int ret=2;
		for(; ; ++ret){
				bool ok=true;
				for(int i=0;i<bases.size();++i){
					if(!happy(ret,bases[i])){
						ok = false;
						break;
					}
				}
				if(ok) break;
		}
		printf("Case #%d: %d\n",cas,ret);

	}
}









/*
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};


int pos(int x, int y){
	if(x%2 == 0 && y%2==0) return 0;
	if(x%2==1 && y%2==0) return 1;
	if(x%2==1 && y%2==1) return 2;
	return 3;
}


long long time(int x, int y, int dx, int dy, long long t,int S, int W, int T){
	int p1=pos(x,y);
	int p2=pos(x+dx,y+dy);
	if(p2<p1) swap(p1,p2);
	if(p1==0&&p2==1 ||

		p1==2
}
*/