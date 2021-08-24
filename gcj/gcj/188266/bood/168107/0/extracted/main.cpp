#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

using namespace std;
#define PROBLEM "A"
#define SCALE "small"
#define IN_FILE PROBLEM"-"SCALE".in"
#define OUT_FILE PROBLEM"-"SCALE".out"
int N;
map<int, bool> happy[11];
int bases[600];

bool is_happy(int n, int base)
{
	if(happy[base].find(n)!=happy[base].end()) return happy[base][n];
	int s=n;
	vector<int> all;
	map<int, bool> path;
	all.push_back(n);
	do {
		int m=s,d;
		path[s]=true;
		s=0;
		while(m>0) {
			d=m%base;
			m/=base;
			s+=d*d;
		};
		if(happy[base].find(s)!=happy[base].end()) {
			if(happy[base][s]) s=1;
			else s=n;
		}
		if(path.find(s)==path.end() && s!=1) {
			all.push_back(s);
		} else break;
	} while(1);
	bool r=false;
	if(s==1) r=true;
	for(int i=0;i<all.size();i++) happy[base][all[i]]=r;
	return r;
}

int main()
{
	freopen(IN_FILE, "r", stdin);
	freopen(OUT_FILE, "w", stdout);

	cin>>N;

	string line;
	getline(cin, line);
	for(int i=1;i<=N;i++)
	{
		getline(cin, line);
		istringstream is(line);
		int k=0;
		while(is) {
			is>>bases[k];
			k++;
		}
		k--;
		int min=2;
		while(1) {
			int j;
			for(j=0;j<k;j++)
				if(!is_happy(min, bases[j]))
					break;
			if(j>=k) break;
			min++;
		}
		printf("Case #%d: %d\n", i, min);
	}
	return 0;
}
