#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; scanf("%d", &T);
    for( int kase = 1; kase <= T; ++kase ){
        string s; cin >> s;
        deque< char > ans;
        for( int i = 0; i < s.size(); ++i ){
            if( ans.empty() )
                ans.push_back( s[ i ] );
            else{
                if( s[ i ] >= ans.front() )
                    ans.push_front( s[ i ] );
                else
                    ans.push_back( s[ i ] );
            }
        }
        printf("Case #%d: ", kase);
        for( int i = 0; i < ans.size(); ++i )
            printf("%c", ans[ i ]);
        puts("");
    }
    return 0;
}
