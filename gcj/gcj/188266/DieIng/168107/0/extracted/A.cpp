#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string num;
vector<int>bas;

int change(int v,int bases) {
	int dig[100] = {0},head = 0;
	int Time = 1000;
	while(Time--) {
		int sum = 0;
		head = 0;
		while(v) {
			dig[head++] = v % bases;
			v /= bases;
			sum += dig[head - 1];
		}
		if(sum == 1)return 1;
		for(int i = 0;i < head;++i) {
			v += dig[i] * dig[i];
		}
	}
	return 0;
}

int check(int v) {
	for(int i = 0;i < bas.size();++i) {
		if(change(v,bas[i]))continue;
		else return 0;
	}
	return 1;
}

int solve() {
	istringstream ss(num);
	int bases;
	while(ss>>bases)bas.push_back(bases);
	int ret = 2;
	while(1) {
		if(check(ret)) {
			return ret;
		} else ret++;
	}
}

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,cas = 1;
	cin>>T;
	getchar();
	while(T--) {
		bas.clear();
		getline(cin,num);
		cout<<"Case #"<<cas++<<": "<<solve()<<endl;
	}
	return 0;
}


