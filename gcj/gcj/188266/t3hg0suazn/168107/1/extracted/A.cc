#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

typedef pair<int,int> pii;

map< pii, int> happy;

inline int f(int n, int b){
	int n_ = 0;
	while(n){
		n_ += (n%b) * (n%b);
		n/=b;
	}
	return n_;
}

int ishappy(int n, int b){
	pii nb(n,b);
	map< pii, int>::iterator it = happy.find(nb); 
	if(it!=happy.end())
		return it->second;

	bool res = ishappy(f(n,b),b);
	happy[nb]=res;
	return res;
}

int main(){
	//gotta do some stuff before f becomes decreasing
	vector<int> chain;
	for(int b=2; b<=10; b++){
		happy[pii(1,b)]=1;
		for(int n=1; n<=1000; n++){
			chain.clear();
			int cur = n;
			while(happy.find( pii(cur, b) )== happy.end()){
				chain.push_back(cur);
				happy[pii(cur,b)]=0;
				cur = f(cur,b);
			}
			if(happy[pii(cur,b)]==1)
				for(int i=0; i<chain.size(); i++)
					happy[pii(chain[i],b)]=1;
		}
	}
	int T; cin >> T; 
	string str;
	getline(cin,str);
	for(int t=0; t<T; t++){
		getline(cin, str);
		istringstream in(str);
		vector<int> base; 
		int b;
		while(in >> b)
			base.push_back(b);
		int n=2;
		for(;; n++){
			bool superhappy=1;
			for(int i=0; i<base.size(); i++)
				if(!ishappy(n,base[i])){
					superhappy=0;
					break;
				}
			if(superhappy)
				break;
		}

		cout << "Case #" << (t+1) << ": " << n << "\n";
	}
}
