#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vec;
int N;
char out[20005];
char inp[10005];

void rec(int len, int L, int R){
    if(len == N){
        int idx = 0;
        char tmp[20005];
        for(int i = L+1; i < R; ++i)
            tmp[idx++] = out[i];
        tmp[idx] = NULL;
        vec.push_back(string(tmp));
        return;
    }
    out[L] = inp[len];
    rec(len+1, L-1, R);
    out[R] = inp[len];
    rec(len+1, L, R+1);
    return;
}

int main(){
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    int totalCase;
    scanf("%d", &totalCase);
    for(int cases = 1; cases <= totalCase; ++cases){
        scanf("%s", &inp);
        N = strlen(inp);
        vec.clear();
        out[10000] = inp[0];
        rec(1, 9999, 10001);
        sort(vec.begin(), vec.end());
        cout << "Case #" << cases << ": " << vec[vec.size()-1] << "\n";
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
