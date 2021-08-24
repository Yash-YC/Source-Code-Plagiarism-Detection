#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;
typedef unsigned long long ULL;
const int N = 10000;
int v[N];
char str[N];
char ans[N];
int main() {
    int T;
    freopen("/Users/vino/Downloads/A-small-attempt0.in", "r", stdin);
    freopen("/Users/vino/Downloads/A-small-attempt0.out", "w", stdout);
    cin >> T;
    int cas = 0;
    while (T--) {
        scanf("%s",str);
        int p = 2000,t = 2000;
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            if(i == 0) ans[p] = str[i];
            else if(ans[p] <= str[i]){
                ans[--p] = str[i];
            }else ans[++t] = str[i];
        }


        printf("Case #%d: ", ++cas);
        for(int i = p; i <= t; i++){
            printf("%c",ans[i]);
        }
        cout << endl;
    }


    return 0;
}