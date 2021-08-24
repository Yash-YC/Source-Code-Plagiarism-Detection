#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    fstream in("A-small-attempt0.in", ios::in);
    fstream out("word.out", ios::out);
    int t;
    in >> t;
    for(int cas = 1; cas <= t; cas++) {
        string s;
        in >> s;

        string ans;
        ans.insert(ans.begin(), s[0]);

        for(int i = 1; i < s.length(); i++) {
            if(s[i] >= ans[0]) {
                ans.insert(ans.begin(), s[i]);
            }
            else {
                ans.insert(ans.end(), s[i]);
            }
        }

        out << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}

