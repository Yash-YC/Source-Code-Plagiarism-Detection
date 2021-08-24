#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

bool ok( int n, const vector<int> &base ) {
	set<int> s;
	for(int i=0;i<base.size();++i) {
		s.clear();
		int x = n;
		while(s.find(x)==s.end()) {
			if( x == 1 ) break;
			s.insert(x);
			int y = 0;
			while(x>0) {
				int mod = x % base[i];
				y += mod * mod;
				x /= base[i];
			}
			x = y;
		}
		if( x != 1 ) return false;
	}
	return true;
}

int main() {
	int tn;
	cin >> tn;
	string s; int x;
	getline(cin,s);
	for(int cc=1;cc<=tn;++cc) {
		getline(cin,s);
		stringstream in(s);
		vector<int> base;
		while(in>>x) if(x!=2&&x!=4) base.push_back(x);
		int i = 1;
		while(++i) if( ok( i, base ) ) break;
		printf("Case #%d: %d\n", cc, i);
	}
}

