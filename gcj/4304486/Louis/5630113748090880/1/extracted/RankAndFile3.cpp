#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

void solve(int cases){
    int N, x;
    set<int> s;
    scanf("%d", &N);
    for(int i = 0; i < 2*N-1; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%d", &x);
            set<int>::iterator it = s.find(x);
            if(it != s.end())
                s.erase(s.find(x));
            else
                s.insert(x);
        }
    }
    printf("Case #%d:", cases);
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
        printf(" %d", *it);
    printf("\n");
}

int main(){
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    int totalCase;
    scanf("%d", &totalCase);
    for(int cases = 1; cases <= totalCase; ++cases){
        solve(cases);
    }
    return 0;
}
/*
2
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
3
1 2 3
2 3 5
3 5 6
2 3 4
3 4 6
*/
