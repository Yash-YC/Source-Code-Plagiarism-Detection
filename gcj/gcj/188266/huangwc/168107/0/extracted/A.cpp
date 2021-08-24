#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

bool B[100];

bool isLucky(int num, int base) {
    memset(B, 0, sizeof(B));   
//cout << "num = " << num << " base = " << base << endl;
    while(true) {
        if(num < 100)
            if(B[num]) return num == 1;
            else B[num] = true;    
//cout << "num = " << num << " base = " << base << endl;
        int tmp = 0;
        while(num) {
            int x = num % base;
            tmp += x * x;
            num /= base;
//cout << x;
        }
//cout << endl;
        num = tmp;
    }
}


int main(int argc, char* argv[]) {
    
    if(argc == 1) return 0;
    string inpath = argv[1];
    string outpath = inpath.substr(0, inpath.find_last_of('.')) + ".out";
    freopen(inpath.c_str(), "r", stdin);
    freopen(outpath.c_str(), "w", stdout);
    
    
    
    
    string buf;
    
    int T;
    cin >> T >> ws;
    for(int c = 1; c <= T; ++c) {
        getline(cin, buf);
        istringstream is(buf);
        vector<int> bs;
        int tmp;
        while(is >> tmp)
            bs.push_back(tmp);
        sort(bs.begin(), bs.end(), greater<int>());
        int ans = 1;
        while(++ans) {
//            cout << "ans = " << ans << endl;
//            system("pause");
            int cnt;
            for(cnt = 0; cnt < bs.size(); ++cnt)
                if(!isLucky(ans, bs[cnt])) break;
            if(cnt == bs.size()) break;
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
}

