#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int N, M;
int C;

int S[30][30], W[30][30], T[30][30];

struct state_t {
    state_t(int l, int c, int t) : l(l), c(c), t(t) { }
    state_t() { }
    int l, c;
    int t;
    bool operator<(const state_t& s) const {
        return t<s.t or (t==s.t and (l<s.l or (l==s.l and c<s.c)));
    };
};

set<state_t> states;

int ts(int l, int c, int t) {
    int k = (t-T[l][c])%(W[l][c]+S[l][c]);
    if(k<0) k+=W[l][c]+S[l][c];
    if(k < S[l][c]) return 0;
    return W[l][c]+S[l][c] - k;
}

int tw(int l, int c, int t) {
    int k = (t-T[l][c])%(W[l][c]+S[l][c]);
    if(k<0) k+=W[l][c]+S[l][c];
    if(k >= S[l][c]) return 0;
    return S[l][c] - k;
}

int main(void) {
    scanf("%d", &C);
    for(int t=0;t<C;++t) {
        states.clear();
        scanf("%d%d", &N, &M);
        for(int i=0;i<N;++i) for(int j=0;j<M;++j) {
            scanf("%d%d%d", &S[i][j], &W[i][j], &T[i][j]);
        }

        int resp = -1;
        states.insert(state_t(0, 0, 0));
        while(1) {
            state_t s = *states.begin();
            if(s.l==N*2-1 and s.c==M*2-1) {
                resp = s.t;
                break;
            }
            states.erase(states.begin());
            int l = s.l/2;
            int c = s.c/2;
            if(s.l < N*2-1) {
                if(s.l%2==1) {
                    states.insert(state_t(s.l+1, s.c, s.t+2));
                } else {
                    states.insert(state_t(s.l+1, s.c, s.t+ts(l, c, s.t)+1));
                }
            }
            if(s.c < M*2-1) {
                if(s.c%2==1) {
                    states.insert(state_t(s.l, s.c+1, s.t+2));
                } else {
                    states.insert(state_t(s.l, s.c+1, s.t+tw(l, c, s.t)+1));
                }
            }

        }
        printf("Case #%d: %d\n", t+1, resp);

    }
    return 0;
}
