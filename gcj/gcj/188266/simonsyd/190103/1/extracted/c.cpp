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

int N, C;

ld choose(int n, int c) {
    ld ans = 1;
    while(c > 0) {
	ans *= n;
	ans /= c;
	--c;
	--n;
    }
    return ans;
}

ld denom;

ld cc[64];
ld dp(int at) {
    if(at == C) return 0;
    ld& ret = cc[at];
    if(ret >= 0) return ret;
    ret = 0;
    ld P = 0;
    for(int i = 1; i <= N && (at + i) <= C; ++i) {
	// has at different kinds of cards
	// k = (C - at) cards are to be owned
	// i of the cards will be new
	// j = (N - i) of the cards are old
	// probability is
	// (k choose i) * (at choose j) / (C choose N)
	int k = C - at;
	int j = N - i;
	ld p = choose(k, i) * choose(at, j) / denom;
	ret += p * (dp(at + i) + 1);
	P += p;
    }
    // Q = probability of repeats
    ld Q = 1 - P;
    ret = (ret + Q) / P;
    /*
    for(int i = 0; i < N && (at + i) <= C; ++i) {
	int k = C - at;
	int j = N - i;
	ld p = choose(k, i) * choose(at, j) / denom;
	//ret += p * dp(at + i) / P + p / (P * P);
    }
    */
    // cout << " at=" << at << " ret=" << ret << " P=" << P << " Q=" << Q << endl;
    return ret;
}

int main() {
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; ++tt) {
	cin >> C >> N;
	for(int i = 0; i < 64; ++i) cc[i] = -1;
	denom = choose(C, N);
	ld ans = 1 + dp(N);
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}

