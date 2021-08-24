#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
int T[1000000], tt=1;

int count(int a, int n){
	if (T[a]==tt) return -1;
	T[a]=tt;
	if (a==1) return a;
	int x =0,aa=a;
	while (a!=0){
		x+=(a%n)*(a%n);
		a/=n;
	}
	return count(x, n);
}

int main(){
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int t; cin>>t;
	string s;
	getline(cin,s);
	for (int o=0; o<t; o++)
	{
		getline(cin, s);
		istringstream in(s);
		int l=0, x, a[5], res= 2;
		while (in>>x)
			a[l++]=x;
		for (;;res++)
		{
			bool f=true;
			for (int i=0; i<l&&f; i++){
				tt++;
				int m=count(res, a[i]);
				if (m!=1)
					f=false;
			}
			if(f) break;
		}
		cout<<"Case #"<<o+1<<": "<<res<<"\n";
	}
	return 0;
}