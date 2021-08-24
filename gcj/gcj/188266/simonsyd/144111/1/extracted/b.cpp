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

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef unsigned long long ull;
typedef long double ld;

int C, R;

/*
 * block pos = topleft, topright, botright, botleft
 * direction = top, right, down, left
 */

int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0, 1, 0,-1};

int bdist[4][4] = { // block to block distance
    0, 2, 4, 2, // from topleft
    2, 0, 2, 4, // from topright
    4, 2, 0, 2, // from botright
    2, 4, 2, 0 // from botleft
};

int ballow[4][4] = { // can cross roads
    // top right down left
    1, 0, 0, 1, // from topleft
    1, 1, 0, 0, // from topright
    0, 1, 1, 0, // from botright
    0, 0, 1, 1, // from botleft
};

int bcross[4][4] = { // when crossing, which part of block ends up in
    // top right down left
     3,-1,-1, 1, // from topleft
     2, 0,-1,-1, // from topright
    -1, 3, 1,-1, // from botright
    -1,-1, 0, 2, // from botleft
};

// which traffic light are we talking about
// when we are at block r,c
int bdr[4] = {-1,-1, 0, 0};
int bdc[4] = {-1, 0, 0,-1};

ll encode(ll r, ll c, ll p) {
    return p + 5 * (r * 24 + c);
}

void decode(ll val, ll& r, ll& c, ll& p) {
    p = val % 5;
    val /= 5;
    c = val % 24;
    val /= 24;
    r = val;
}

ll ZS[24][24], ZW[24][24], ZT[24][24];

ll best[5 * 24 * 24];
ll shortest() {
    memset(best, -1, sizeof(best));
    ll ir = R, ic = 0, ip = 1;
    ll er = 0, ec = C, ep = 3;
    ll ini = encode(ir, ic, ip);
    ll end = encode(er, ec, ep);
    set<ii> pq;
    best[ini] = 0;
    pq.insert(ii(0, ini));
    while(!pq.empty()) {
	ll t = pq.begin()->first; // time now
	ll val = pq.begin()->second;
	pq.erase(pq.begin());
	if(val == end) break; // if reach target
	ll r, c, p;
	decode(val, r, c, p);
	// cout << " r=" << r << " c=" << c << " p=" << p << " t=" << t << endl;
	// cross the block
	for(ll np = 0; np < 4; ++np) {
	    ll nt = t + bdist[p][np];
	    ll nval = encode(r, c, np);
	    if(best[nval] != -1 && best[nval] <= nt) continue;
	    pq.erase(ii(best[nval], nval));
	    best[nval] = nt;
	    pq.insert(ii(nt, nval));
	}
	// make sure the traffic light exist
	ll zr = r + bdr[p];
	ll zc = c + bdc[p];
	if(zr < 0 || zc < 0 || zr >= R || zc >= C) continue;
	// cout << " zr=" << zr << " zc=" << zc << " ZS=" << ZS[zr][zc] << " ZW=" << ZW[zr][zc] << endl;
	for(ll k = 0; k < 4; ++k) {
	    if(!ballow[p][k]) continue;
	    // wait for next time to become green
	    // if k = 0, 2 then want north-south green in s minutes
	    // if k = 1, 3 then want east-west green in w minutes
	    ll phase = (t + ZS[zr][zc] + ZW[zr][zc] - ZT[zr][zc]) % (ZS[zr][zc] + ZW[zr][zc]);
	    ll nt = t + 1;
	    if(k == 0 || k == 2) {
		if(phase >= ZS[zr][zc]) {
		    nt += ZS[zr][zc] + ZW[zr][zc] - phase;
		}
	    } else {
		if(phase < ZS[zr][zc]) {
		    nt += ZS[zr][zc] - phase;
		}
	    }
	    ll nr = r + dr[k];
	    ll nc = c + dc[k];
	    ll np = bcross[p][k];
	    ll nval = encode(nr, nc, np);
	    if(best[nval] != -1 && best[nval] <= nt) continue;
	    pq.erase(ii(best[nval], nval));
	    best[nval] = nt;
	    pq.insert(ii(nt, nval));
	}
    }
    return best[end];
}

int main() {
    ll T;
    cin >> T;
    for(ll tt = 1; tt <= T; ++tt) {
	cin >> R >> C;
	for(ll r = 0; r < R; ++r) {
	    for(ll c = 0; c < C; ++c) {
		// stay green for s minutes
		// stay red for w minutes
		// phase offset is t minutes
		cin >> ZS[r][c] >> ZW[r][c] >> ZT[r][c];
		// only want phase difference
		ZT[r][c] %= (ZS[r][c] + ZW[r][c]);
	    }
	}
	ll ans = shortest();
	cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}

