#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int c=0;c<t;++c){
        int n;
        cin >> n;
        int heights[2*n-1][n];
        unordered_map<int, int> umap;
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                cin >> heights[i][j];
            }
        }
        for(int i=0;i<2*n-1;i++){
            for(int j=0; j<n;j++){
                umap[heights[i][j]]++;
            }
        }
        vector<int> result;
        for(auto test : umap){
            if(test.second%2==1){
                result.push_back(test.first);
            }
        }
        sort(result.begin(), result.end());
        cout << "Case #" << c+1 << ":";
        for(int i=0;i<n;i++){
            cout << ' ' << result[i];
        }
        cout << endl;
    }
    return 0;
}
