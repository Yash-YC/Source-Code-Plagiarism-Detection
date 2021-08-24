#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;


typedef long long int64;
int64 C[50][50];

int64 binomial(int a, int b) {
    if ( b < 0 || b > a ) return 0;
    return C[a][b];
}

const int MAXSTEPS = 1000;
int K, N;
double memo[50][MAXSTEPS+1];
bool bio[50][MAXSTEPS+1];
double calc(int imam, int steps) {
    if ( imam == K ) return 0.0;
    if ( steps == MAXSTEPS ) return 0.0;

    double &ret = memo[imam][steps];
    if ( bio[imam][steps] ) return ret;

    bio[imam][steps] = 1;
    ret = 1.0;
    for ( int novih=0; novih<=N; ++novih ) {
        if ( imam+novih > K ) continue;
        ret += double(binomial(imam, N-novih)) * binomial(K-imam, novih) / binomial(K, N) * calc(imam+novih, steps+1);
    }
    return ret;
}

int main(void) { 
    cin.sync_with_stdio(0);

    C[0][0] = 1;
    for ( int i=1; i<50; ++i ) {
        C[i][0] = C[i][i] = 1;
        for ( int j=1; j<i; ++j )
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    int CASES; cin >> CASES;
    for ( int tt=1; tt<=CASES; ++tt ) { // caret here
        cin >> K >> N;
        memset(bio, 0, sizeof bio);
        for ( int imam=K-1; imam>=0; --imam ) {
            for ( int steps=MAXSTEPS; steps>=0; --steps )
                calc(imam, steps);
        }

        printf("Case #%d: %.7f\n", tt, calc(0, 0));
    }

    return 0;
} 
