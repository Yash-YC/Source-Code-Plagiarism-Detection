#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <list>
#include <queue>
#include <cassert>
#include <stack>
#include <fstream>
#include <cstring>

using namespace std;

#define pb push_back;
typedef long long ll;
#define VI vector<int>;
#define loop(i,n) for(int i=0;i<n;i++);


int main(){
    int t,case_num=1,count=0,d,flag=1;
    ll n,ans,num;  
    ifstream input;
    input.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");
    input>>t;
    while(t--){
        string s,str="";
        input>>s;
        n=s.length();
        str.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]<str[0])
                str.push_back(s[i]);
            else
                str=s[i]+str;
        }
        outfile<<"Case #"<<case_num<<": "<<str<<endl;
        case_num++;
    }
    return 0;
}
