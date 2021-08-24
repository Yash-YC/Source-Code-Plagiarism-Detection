#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    fstream in("B-small-attempt0.in", ios::in);
    fstream out("rank.out", ios::out);
    int t;
    in >> t;
    for(int cas = 1; cas <= t; cas++) {
        int n, temp;
        in >> n;
        vector<int> h(2500, 0);
        for(int i = 0; i < (2*n-1) * n; i++) {
            in >> temp;
            h[temp-1]++;
        }
        vector<int> ans;
        for(int i = 0; i < h.size(); i++) {
            if(h[i] % 2 == 1) {
                ans.push_back(i+1);
            }
        }
        sort(ans.begin(), ans.end());
        out << "Case #" << cas <<": ";
        for(int i = 0; i < ans.size(); i++) {
            out << ans[i] << " ";
        }
        out << endl;
    }
    return 0;
}
