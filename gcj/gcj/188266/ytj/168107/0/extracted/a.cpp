#include<iostream>
#include<sstream>
#include<vector>
#include<set>
using namespace std;

vector<int> a;

void init(){
	a.clear();
	string s;
	getline(cin,s);
	istringstream fin(s);
	for(int aa;fin>>aa;a.push_back(aa));
}

bool work(int k,int m){
	set<int>a;
	while(k!=1){
		if(a.count(k))return 0;
		a.insert(k);
		int i=k;k=0;
		while(i){
			k+=(i%m)*(i%m);
			i/=m;
		}
	}
	return 1;
}

bool check(int k){
	for(int i=0;i<a.size();i++)
		if(!work(k,a[i]))return 0;
	return 1;
}

int solve(){
	int k=2;
	while(!check(k))k++;
	return k;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++){
		init();
		cout<<"Case #"<<i<<": "<<solve()<<endl; 
	}
}
