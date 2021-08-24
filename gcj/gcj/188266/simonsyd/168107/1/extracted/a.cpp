#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<sstream>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int MAXI = 200001;
bool seen[12][MAXI];
int happy[12][MAXI];

int run(int base, int at) {
    if(at < MAXI) {
	if(happy[base][at]) return 1;
	if(seen[base][at]) return 0;
	seen[base][at] = true;
    }
    // cout << " base=" << base << " at=" << at << endl;
    int next = 0;
    int use = at;
    while(use > 0) {
	int tmp = use % base;
	next += tmp * tmp;
	use /= base;
    }
    // cout << " next=" << next << " h=" << run(base, next) << endl;
    if(at < MAXI) {
	return (happy[base][at] = run(base, next));
    }
    return run(base, next);
}

vi bases;

bool check(int ans) {
    for(int i = 0; i < bases.size(); ++i) {
	if(!run(bases[i], ans)) return false;
	// if(!happy[bases[i]][ans]) return false;
	// cout << bases[i] << " ans=" << ans << endl;
    }
    return true;
}

int ansz[1 << 10];

int main() {
    int T;
    cin >> T;
    memset(seen, 0, sizeof(seen));
    memset(happy, 0, sizeof(happy));
    for(int i = 2; i <= 10; ++i) {
	seen[i][1] = 1;
	happy[i][1] = 1;
    }
    for(int i = 2; i <= 10; ++i) {
	for(int z = 1; z < MAXI; ++z) {
	    run(i, z);
	    // cout << " base=" << i << " z=" << z << " h=" << happy[i][z] << endl;
	}
    }
    for(int b = 1; b < (1 << 9); ++b) {
	bases.clear();
	for(int i = 0; i < 9; ++i) {
	    if((1 << i) & b) {
		bases.push_back(i + 2);
	    }
	    int ans = 2;
	    for(int b2 = 1; b2 < (1 << 9); ++b2) {
		if((b2 & b) == b2) {
		    ans = max(ans, ansz[b2]);
		}
	    }
	    while(!check(ans)) {
		ans++;
	    }
	    ansz[b] = ans;
	}
    }
    string line;
    getline(cin, line);
    for(int tt = 1; tt <= T; ++tt) {
	getline(cin, line);
	istringstream ssn(line);
	int tmp;
	bases.clear();
	int b = 0;
	while(ssn >> tmp) {
	    bases.push_back(tmp);
	    b |= 1 << (tmp - 2);
	}
	/*
	int ans = 2;
	while(!check(ans)) {
	    ans++;
	}
	*/
	cout << "Case #" << tt << ": " << ansz[b] << endl;
    }
    return 0;
}

