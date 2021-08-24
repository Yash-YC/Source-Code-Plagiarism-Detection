#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <map>
#include <sstream>
using namespace std;
map<int, int> mm;
vector<map<int, int> > memo;
int func(int base, int num){
	int sum=0;
	//cout << base << " " << num << endl;
	if(memo[base-2].find(num) != memo[base-2].end()){
		return memo[base-2][num];
	}
	while(num){
		sum += (num%base)*(num%base);
		num = num/base;
	}
	if(mm.find(sum) != mm.end()){
		for(map<int, int>::iterator i = mm.begin(); i != mm.end(); i++){
			memo[base-2][(*i).first] = 0;
		}
		return 0;
	}
	if(sum == 1){
		for(map<int, int>::iterator i = mm.begin(); i != mm.end(); i++){
			memo[base-2][(*i).first] = 1;
		}
		return 1;
	}
	mm[sum] = 1;
	return func(base, sum);
	
}

int main(){
	int n;
	for(int i = 2; i <= 10; i++) memo.push_back(map<int, int>());
	cin >> n;
	stringstream ss;
	string str;
	getline(cin, str);
	for(int nn = 1; nn <= n; nn++){
		getline(cin, str);
		ss.str("");
		ss.clear();
		ss.str(str);
		int b;
		vector<int> data;
		while(ss >> b){
			data.push_back(b);
		}
		int num=2, f=0;
		memo.clear();
		for(int i = 2; i <= 10; i++) memo.push_back(map<int, int>());
		while(1){
			f=0;
			for(int i = 0; i < data.size(); i++){
				mm.clear();
				f+=func(data[i], num);
			}
			if(f == data.size()){
				break;
			}
			num++;
		}
		cout << "Case #" << nn << ": " << num << endl;
	}
}
