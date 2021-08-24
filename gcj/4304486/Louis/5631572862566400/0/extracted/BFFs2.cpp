#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[1005];
int out[1005], N, ma;
int G[1005][1005];

void rec(int len){
    if(len >= ma){
        bool yes = true;
        for(int i = 0; i < len; ++i){
            int L = (i-1+len)%len;
            int R = (i+1)%len;
            if(G[out[i]][out[L]] == 0 && G[out[i]][out[R]] == 0){
                yes = false;
                break;
            }
        }
        if(yes){
            ma = max(ma, len);
        }
        if(len == N)
            return;
    }
    for(int i = 1; i <= N; ++i){
        if(!visited[i]){
            visited[i] = true;
            out[len] = i;
            rec(len+1);
            visited[i] = false;
        }
    }
}

void RESET(){
    memset(G, 0, sizeof(G));
}

int main(){
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-attempt0.out", "w", stdout);
    int totalCase;
    scanf("%d", &totalCase);
    for(int T = 1; T <= totalCase; ++T){
        scanf("%d", &N);
        RESET();
        for(int i = 1; i <= N; ++i){
            int BFF;
            scanf("%d", &BFF);
            G[i][BFF]++;
        }
        ma = 2;
        rec(0);
        printf("Case #%d: %d\n", T, ma);
    }
    return 0;
}
/*
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
*/
