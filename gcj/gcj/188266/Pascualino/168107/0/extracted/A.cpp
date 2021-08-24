#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;
#define st first
#define fin second.first
#define INF 2000000000

typedef long long ll;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;


vector<vector<short> > memo;
bool is_happy(int N,int b){
     int c=0;
     int N0=N;
     if(N==1) return 1;
     if(memo[N][b]!=-1) return memo[N][b];
     memo[N][b]=0;
     while(N!=0){
                 c += (N%b)*(N%b);
                 N/=b;
     }
     //cout << "*" << c << endl;
     if(c==1) return memo[N0][b]=1;
     else if(memo[c][b]!=-1) return memo[N0][b]=memo[c][b];
     else return memo[N0][b]=is_happy(c,b);
}

int main(){
    memo = vector<vector<short> > (1000000,vector<short>(11,-1));
    int T;
    cin >> T;
    string s1;
    getline(cin,s1);
    for(int t=1;t<=T;t++){
    string s;
    
    getline(cin,s);
    vector<int> base;
    stringstream ss;
    ss.str(s);
    int n;
    while(ss >> n) base.push_back(n);
    
    bool v;
    for(int i=2;i<1000000;i++){
            v=1;
            for(int j=0;j<base.size();j++) if(!is_happy(i,base[j])) v=0;
            if(v){cout << "Case #" << t << ": " << i << endl;
            break; }
    }
    if(!v) cout << "NO!" << endl;
}
	cin >> memo[0][0];}





























