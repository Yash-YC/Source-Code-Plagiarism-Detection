#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <sstream>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

vector<int> bases;

int visited[10000][10];

bool test(int ii, int jj)
{
//	cout << ii << " " << jj << endl;
	if(ii == 1) return true;
	int before_ii = ii;
	if(ii < 10000) {
		if(visited[ii][jj] == 2) return true;
		else if(visited[ii][jj] == 1) return false;
		visited[ii][jj] = 1;
	}
	int b = bases[jj];
	int sum = 0;
	while(ii) {
		int k = (ii % b);
		sum += k*k;
		ii /= b;
	}
	bool flag = test(sum,jj);
	if(before_ii < 10000) { 
		visited[before_ii][jj] = (int)flag+1; 
//		cout << ii << "," << jj << " becomes " << visited[ii][jj] << endl;
	}
	return flag;
}

void process(int kase)
{
	string str;

	bases.clear();
	cout << "Case #" << kase << ": ";
	getline(cin,str);

	REP(i,10000) REP(j,10) visited[i][j] = 0;

	stringstream sst(str);
	int b;
	while(sst >> b) {
		bases.pb(b);
	}
	int i=2;
	while(1) {
		bool flag = true;
		for(int j=0; j < bases.size(); ++j) {
			if(!test(i,j)) { flag = false; }
		}
		if(flag) { cout << i << endl; break; }
		++i;
	}
}

int main()
{
	int t;
	string str;
	cin >> t;
	getline(cin,str);

	REP(i,t) process(i+1);

	return 0;
}
