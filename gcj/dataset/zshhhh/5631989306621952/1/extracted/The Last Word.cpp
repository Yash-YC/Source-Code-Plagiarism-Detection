#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int i=0;i<t;++i){
        string s;
        cin >> s;
        string s2="";
        s2+=s[0];
        for(int j=1;j<s.length();j++){
            if(s[j]>=s2[0]){
                s2=s[j]+s2;
            }else{
                s2=s2+s[j];
            }
        }
        cout << "Case #" << i+1 << ": " << s2 << endl;
    }
    return 0;
}
