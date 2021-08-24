/*
 * a.cc
 *
 *  Created on: Sep 12, 2009
 *      Author: sandaru1
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>

using namespace std;

typedef vector<int> vi;
vi parseInt(string s) {stringstream ss(s);vi ans;while (!ss.eof()) {int temp; ss >> temp; ans.push_back(temp); } return ans;}
#define COPY(x,y) y.resize(x.size());copy(x.begin(),x.end(),y.begin())
#define pb push_back
#define SWAP(t,x,y) t temp=x;x=y;y=temp;
#define fr(i,s,e) for (int i = int(s); i < int(e); i++)
#define fr2(i,c) for (unsigned int i = 0; i < (c).size(); i++)
#define cl(a,val) memset(a,val,sizeof(a));

#define pi pair<int,int>

vi bases;

std::string itoa(int value, int base) {
	std::string buf;

	// check that the base if valid
	if (base < 2 || base > 16) return buf;

	enum { kMaxDigits = 35 };
	buf.reserve( kMaxDigits ); // Pre-allocate enough space.

	int quotient = value;

	// Translating number to string with base:
	do {
		buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
		quotient /= base;
	} while ( quotient );

	// Append the negative sign
	if ( value < 0) buf += '-';

	std::reverse( buf.begin(), buf.end() );
	return buf;
}

/*
 * NOTE : the commented code is used to generate "all.txt" file
 */
/*
map<pi,int> visited;

bool check(int num,int base) {
	if (num==1)
		return true;
	pi xx;
	xx.first = num;
	xx.second = base;
	if (visited.find(xx)!=visited.end()) {
		int x = visited[xx];
		if (x==0)
			return false;
		if (x==1)
			return true;
	}
	visited[xx] = 0;
	string nstr = itoa(num,base);
	int all = 0;
	fr2(i,nstr) {
		int x = nstr[i] - '0';
		all += x * x;
	}
	bool ans = check(all,base);
	if (ans) {
		cout << num << " " << base << endl;
		visited[xx] = 1;
	}
	return ans;
}
*/
bool can[12814485][11];

int getAns() {
	int cur = 1;
	bool ok;
	while(!ok) {
		cur++;
		ok = true;
		fr2(i,bases) {
			if (!can[cur][bases[i]]) {
//			if (!check(cur,bases[i])) {
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		return cur;
	}
	return -1;
}

int main() {
  int T;
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  ifstream all("all");
  cl(can,false);
  while(!all.eof()) {
	  int n,b;
	  all >> n >> b;
	  can[n][b] = true;
  }


  fin >> T;
  fin.ignore();

  fr(t,0,T) {
	char line[500];
	fin.getline(line,500);
	string l(line);
	bases.clear();
	bases = parseInt(l);
	int ans;
	ans = getAns();
    cout << "Case #" << t+1 << ": " << ans << endl;
    fout << "Case #" << t+1 << ": " << ans << endl;
  }

  return 0;
}
