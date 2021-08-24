#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<string>
#include<iterator>
#include<vector>
#include<set>
using namespace std;
typedef unsigned long long ull;
int f(char c){
	c = tolower(c);
	return isdigit(c) ? c - '0' : c-'a' + 10;
}
ull next(ull value,int base){
	char s[128];
	_ui64toa(value,s,base);
	ull x = 0;
	for(int i=0;s[i];++i){
		x += f(s[i])*f(s[i]);
	}
	return x;
}
bool ok(ull value,int base){
	set<ull>s;
	for(;;){
		if(s.count(value))return false;
		if(value == 1)return true;
		s.insert(value);
		value = next(value,base);
	}
}
ull solve(const vector<int>&v){
	for(ull i=2;;++i){
		for(int j=0;j<v.size();++j){
			if(ok(i,v[j])==false)goto next;
		}
		return i;
next:;
	}
	return 0;
}
int main(){
	int k;
	string line;
	getline(cin,line);
	stringstream(line) >> k;
	for(int i=1;i<=k;++i){
		getline(cin,line);
		stringstream ss(line);
		vector<int>v;
		v.assign(std::istream_iterator<int>(ss),std::istream_iterator<int>());
		cout << "Case #" << i << ": ";
		cout << solve(v);
		cout << endl;
	}
}