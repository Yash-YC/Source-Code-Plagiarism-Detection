
#include <cassert>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

//const int dr[] = {-1, 0, 1, 0};
//const int dc[] = {0, 1, 0, -1};

int dr[4][4];
int dc[4][4];
int pos[4][4];

int south[32][32];
int west[32][32];
int start[32][32];

struct pqitem {
    int r, c, pos;
    long long T;
    
    inline bool operator <(const pqitem &rhs) const {
        return T > rhs.T;
    }
};

int N, M;
long long best[32][32][4];
priority_queue <pqitem> pq;

void setMove(int _pos, int _dir, int _dr, int _dc, int _npos) {
    dr[_pos][_dir] = _dr;
    dc[_pos][_dir] = _dc;
    pos[_pos][_dir] = _npos;
}

void push(int r, int c, int pos, long long T) {
    if (r < 0 || r >= N || c < 0 || c >= M)
        return;
    if (best[r][c][pos] > T) {
        best[r][c][pos] = T;
        pq.push((pqitem) {r, c, pos, T});
//        printf("push(%d, %d, %d, %lld)\n", r, c, pos, T);
    }
}

long long wait(int r, int c, long long T, int dir) {    
    long long nT = T - start[r][c];
    nT %= (south[r][c] + west[r][c]);
    nT += (south[r][c] + west[r][c]);
    nT %= (south[r][c] + west[r][c]);
//    printf("south = %d, west = %d\n", south[r][c], west[r][c]);
//    printf("r = %d, c = %d, dir = %d, T = %lld, nT = %lld\n", r, c, dir, T, nT);
    if (dir == 3) { // south
        if (nT < south[r][c])
            return 1;
        else
            return south[r][c] + west[r][c] - nT + 1;
    } else if (dir == 1) {
        if (nT >= south[r][c])
            return 1;
        else
            return south[r][c] - nT + 1;
    } else
        assert(false);
}

void solve(int cas) {
    while (!pq.empty())
        pq.pop();
    
    scanf("%d %d", &N, &M);
    fprintf(stderr, "N = %d, M = %d\n", N, M);
    fflush(stderr);
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < M; ++c) {
            scanf("%d %d %d", &south[r][c], &west[r][c], &start[r][c]);
            start[r][c] %= (south[r][c] + west[r][c]);
        }
        
    memset(best, 0x3f, sizeof(best));
    push(N - 1, 0, 0, 0);
    while (!pq.empty()) {
        pqitem crnt = pq.top();
        pq.pop();
        if (crnt.T > best[crnt.r][crnt.c][crnt.pos])
            continue;
//        printf("%d %d %d %lld\n", crnt.r, crnt.c, crnt.pos, crnt.T);
        for (int dir = 0; dir < 4; ++dir)
            if (dc[crnt.pos][dir] == 0 && dr[crnt.pos][dir] == 0) {
                push(crnt.r, crnt.c, pos[crnt.pos][dir], wait(crnt.r, crnt.c, crnt.T, crnt.pos ^ pos[crnt.pos][dir]) + crnt.T);
            } else {
                push(crnt.r + dr[crnt.pos][dir], crnt.c + dc[crnt.pos][dir], pos[crnt.pos][dir], crnt.T + 2);
            }
    }
    printf("Case #%d: %lld\n", cas, best[0][M - 1][2]);
}

int main() {
    setMove(0, 0, 0, 0, 3);
    setMove(0, 1, 0, 0, 1);
    setMove(0, 2, 1, 0, 3);
    setMove(0, 3, 0, -1, 1);
    
    setMove(1, 0, 0, 0, 2);
    setMove(1, 1, 0, 1, 0);
    setMove(1, 2, 1, 0, 2);
    setMove(1, 3, 0, 0, 0);
    
    setMove(2, 0, -1, 0, 1);
    setMove(2, 1, 0, 1, 3);
    setMove(2, 2, 0, 0, 1);
    setMove(2, 3, 0, 0, 3);
    
    setMove(3, 0, -1, 0, 0);
    setMove(3, 1, 0, 0, 2);
    setMove(3, 2, 0, 0, 0);
    setMove(3, 3, 0, -1, 2);
    
    int tst;
    scanf("%d", &tst);
    for (int cas = 0; cas < tst; ++cas) {
        solve(cas + 1);
    }
    return 0;
}