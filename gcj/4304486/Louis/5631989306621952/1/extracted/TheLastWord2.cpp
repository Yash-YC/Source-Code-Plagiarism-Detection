#include <cstdio>
#include <cstring>

int N;
char out[20005];
char inp[10005];

int main(){
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
    int totalCase;
    char ma;
    scanf("%d", &totalCase);
    for(int cases = 1; cases <= totalCase; ++cases){
        scanf("%s", &inp);
        int L = 9999, R = 10001;
        N = strlen(inp);
        ma = out[10000] = inp[0];
        for(int i = 1; i < N; ++i){
            if(inp[i] >= ma){
                out[L--] = inp[i];
                ma = inp[i];
            }
            else
                out[R++] = inp[i];
        }
        printf("Case #%d: ", cases);
        for(int i = L+1; i < R; ++i)
            printf("%c", out[i]);
        printf("\n");
    }
    return 0;
}
/*
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE
*/
