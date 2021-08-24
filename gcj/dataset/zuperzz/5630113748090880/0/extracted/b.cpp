#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(int argc, char * argv[]) {
    int t;
    cin >> t;
    int n;

    for (int i=1; i<=t; ++i) {
        cin >> n;
        unordered_map<int, int> freq;
        for (int j=0; j < 2*n-1; ++j) {
            int x; 
            for (int k=0; k < n; ++k) {
                cin >> x;
                if(freq.count(x)==0) freq.insert(make_pair(x,1));
                else freq.at(x)++;
            }
        }
        
        vector<int> row;
        for (auto it = freq.begin(); it!=freq.end(); ++it) {
            if (it->second % 2 != 0) row.push_back(it->first);
        }

        sort(row.begin(),row.end());
        cout << "Case #" << i << ":";
        for (auto it=row.begin(); it != row.end(); ++it) {
            cout << " " << *it;
        }
        cout << endl;
    }

}
