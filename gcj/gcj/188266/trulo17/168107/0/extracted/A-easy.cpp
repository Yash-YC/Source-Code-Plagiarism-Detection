#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
#include<sstream>
#include<set>
using namespace std;
set<int> S;
bool isHappy(int x,int y){
    //cout<<"Esto "<<x<<" "<<y<<endl;
    /*if(x<y){
        return x==1;
    }*/
    if(x==1)return 1;
    S.insert(x);
    int x2=0;
    while(x){
        int mod=x%y;
        x2+=mod*mod;
        x/=y;
    }
    if(S.find(x2)!=S.end())return 0;
    return isHappy(x2,y);
}

void procesa(int test){
    cout<<"Case #"<<test<<":";
    string s;
    getline(cin,s);
    istringstream in(s);
    vector<int> v;
    int x;
    while(in>>x){
        v.push_back(x);
    }
    int ret=2;
    //for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
    //cout<<endl;
    while(1){
        bool ok=1;
        for(int i=0;i<v.size();++i){
            S.clear();
            if(!isHappy(ret,v[i])){
                ok=0;
                break;
            }
        }
        if(ok)break;
        //cout<<ret<<endl;
        ++ret;
    }
    cout<<" "<<ret<<endl;
   // for(int i=
}
int main(){
    //cout<<isHappy(91,9)<<endl;
    //cout<<isHappy(91,10)<<endl;
    int N;
    cin>>N;
    string s;
    getline(cin,s);
    int test=1;
    while(N--){
        procesa(test++);
    }
}
