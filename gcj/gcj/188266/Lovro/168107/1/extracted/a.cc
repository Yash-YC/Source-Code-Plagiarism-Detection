#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )

int next(int x, int base) {
    int ret = 0;
    while ( x > 0 ) {
        int d = x%base;
        ret += d*d;
        x /= base;
    }
    return ret;
}

const int MAXMEMO = 20000000;
int memo[MAXMEMO+1][11];

bool ishappy(int x, int base) {
    int &ret = memo[x][base];
    if ( ret != -1 ) return ret;
    ret = 1;
    
    static set<int> seen; seen.clear();
    do {
        if ( seen.find(x) != seen.end() ) {
            ret = 0;
            break;
        }
        seen.insert(x);
        x = next(x, base);
    } while ( x != 1 );
    return ret;
}

int memo2[1<<15];

int main(void) {
    cin.sync_with_stdio(0);
    memset(memo, -1, sizeof memo);
    memset(memo2, -1, sizeof memo2);

    for ( int b=2; b<=10; ++b ) 
        for ( int x=1; x<=1000; ++x )
            ishappy(x, b);
    
    // int cnt = 0;
    // for ( int x=2; x<=20000000; ++x ) {
    //     cnt += ishappy(x, 3);
    // }
    // cerr << cnt << "\n";
    // return 0;

    string s;
    getline(cin, s);
    int CASES = atoi(s.c_str());
    for ( int tt=1; tt<=CASES; ++tt ) { // caret here
        getline(cin, s);
        istringstream iss(s);
        vector<int> bases;
        int b, m = 0;
        while ( iss >> b ) {
            bases.push_back(b);
            m |= 1<<b;
        }

        int& ans = memo2[m];
        if ( ans == -1 ) {
            for ( int x=2;; ++x ) {
                bool ok = 1;
                foreach(it, bases) {
                    if ( !ishappy(next(x, *it), *it) ) {
                        ok = 0;
                        break;
                    }
                }
                if ( ok ) {
                    ans = x;
                    break;
                }
            }
        }
        cout << "Case #" << tt << ": " << ans << "\n";
    }

    return 0;
} 
