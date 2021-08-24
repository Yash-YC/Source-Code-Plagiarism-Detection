#include <iostream>
#include <string>

using namespace std;

string lastWord(string s) {
    string out = s.substr(0,1);
    for (auto it = s.begin()+1; it != s.end(); ++it) {
        if (*it < out.front()) out.push_back(*it);
        else out = *it + out;
    }
    return out;
}

int main(int argc, char * argv[]) {
        int t;
        cin >> t;
        string s;
        for (int i=1; i <= t; i++) {
            cin >> s;
            cout << "Case #" << i << ": " << lastWord(s) << endl;
        }
        return 0;
}
