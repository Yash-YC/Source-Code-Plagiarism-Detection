#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int ca = 1; ca <= T; ++ca)
    {
        string inp;
        cin >> inp;
        int n = inp.length();
        string dp[10000];
        dp[0] = string("") + inp[0];
        for(int i = 1; i < n; ++i)
        {
            dp[i] = max(inp[i] + dp[i-1], dp[i-1] + inp[i]);
        }
        cout << "Case #" << ca << ": " << dp[n-1] << endl;
    }
    return 0;
}


