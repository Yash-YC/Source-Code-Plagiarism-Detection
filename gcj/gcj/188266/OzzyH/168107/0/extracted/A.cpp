#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream fin("A-small.in",ios::in);
ofstream fout("A-small.out",ios::out);

int maxi;
set<int>* mem;

void doall() {
	for (int i=2; ; i++) {
		bool works = true;
		for (int j=2; j<=10; j++) {
			int temp = i;
			for (int k=0; k<20 && temp!= 1; k++) {
				int sum = 0;
				while (temp != 0) {
					sum += (temp%j)*(temp%j);
					temp /= j;
				}
				temp = sum;
			}
			if (temp != 1) works = false;
			else mem[j].insert(i);
		}
		if (works) {
			maxi = i;
			break;
		}
	}
}

void function() {
	vector <int> nums;
	string st;
	ws(fin); getline(fin, st);
	int n;
	for (int i=0; i<st.length(); i++) {
		if (st[i]!=' ' && st[i]!='0') {
			n = st[i] - 48;
			nums.push_back(n);
		}
	}
	for (int j=0; j<nums.size(); j++)
		if (nums[j]==1)
			nums[j] = 10;
	if (n==1) n=10;
	for (int i=2; i<=maxi; i++) {
		bool good = true;
		for (int j=0; j<nums.size(); j++) {
			if (mem[nums[j]].count(i) < 1) {
				good = false;
				break;
			}
		}
		if (good) {fout<<i; return;}
	}
	fout<<maxi;
}

int main() {
	mem = new set<int> [11];
	doall();
	int go;
	cin>>go;
	int N;
	fin>>N;
	for (int i=1; i<=N; i++) {
		fout<<"Case #"<<i<<": ";
		function();
		fout<<endl;
	}
	return 0;
}