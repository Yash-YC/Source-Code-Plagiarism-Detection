#include <iostream>
#include <cstdio>

using namespace std;

int T;
string S,ans;

int main(){
    freopen("ldata.in","r",stdin);
    freopen("ldata.out","w",stdout);
    cin >> T;
    for (int z = 1; z <= T; z++){
        cin >> S;
        ans = "";
        ans = S[0];
        for (int i = 1; i <= S.length(); i++){
            if (S[i] >= ans[0]){
                ans = S[i] + ans;
            }else
                ans = ans + S[i];
        }
        printf("Case #%d: %s\n",z,ans.c_str());
    }
    return 0;
}
