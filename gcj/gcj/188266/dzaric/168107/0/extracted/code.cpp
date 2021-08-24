/* 
 * File:   code.cpp
 * Author: dzaric
 *
 */

#include <cmath>
#include <algorithm>
#include <iostream>
//#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;

vector<int> happy[11];

vector<int> toVector(int base,int n){
    vector<int> ret;
    if(n==0){
        ret.push_back(0);
        return ret;
    }
    while(n){
        ret.push_back(n%base);
        n/=base;
    }
    //least significant at [0]
    return ret;
}

int fromVector(int base,const vector<int>& n){
    int ret=0;
    for(int i=n.size()-1;i>=0;i--){
        ret*=base;
        ret+=n[i];
    }
    return ret;
}

vector<int> add(int base,const vector<int>& a,const vector<int>& b){
    return toVector(base,fromVector(base,a)+fromVector(base,b));
}
vector<int> mulDigit(int base,int a,int b){
    return toVector(base,a*b);
}

string toString(vector<int> n){
    string ret="";
    for(int i=0;i<n.size();i++){
        ret+=('0'+n[i]);
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

bool isHappy(int base,int n){
    vector<int> num=toVector(base,n);
    //cout<<n<<" -> "<<toString(num)<<endl;
    int k=0;
    while(++k<=100){
        vector<int> s;
        s.push_back(0);

        for(int i=0;i<num.size();i++){
            //cout<<toString(s)<<"+="<<toString(mulDigit(base,num[i],num[i]));
            s=add(base,s,mulDigit(base,num[i],num[i]));
            //cout<<" = "<<toString(s)<<endl;
        }
        //cout<<"\t"<<toString(s)<<endl;
        int nn=fromVector(base,s);
        if(nn==1){
            return true;
        }
        if(nn<n){
            return binary_search(happy[base].begin(),happy[base].end(),nn);
        }
        num=s;
    }
    return false;
}


void generateHappy(){
    for(int base=2;base<=10;base++){
        for(int n=2;n<=100000;n++){
            if(isHappy(base,n)){
                happy[base].push_back(n);
            }
        }
        //cout<<"Base "<<base<<":"<<endl;
        //for(int i=0;i<happy[base].size();i++){
        //    cout<<happy[base][i]<<" ";
        //}
        //cout<<endl<<endl;
    }
}


void solveCases(){
    int tcases;
    string s;
    getline(cin,s);
    istringstream sin(s);
    sin>>tcases;
    for(int tcase=1;tcase<=tcases;tcase++){
        getline(cin,s);
        istringstream line(s);
        vector<int> b;
        int x;
        while(line>>x){
            b.push_back(x);
            //cout<<x<<" ";
        }
        for(int i=0;i<happy[b[b.size()-1]].size();i++){
            int k=1;
            for(int j=0;j<b.size()-1;j++){
                k+=binary_search(happy[b[j]].begin(),happy[b[j]].end(),happy[b[b.size()-1]][i]);
            }
            if(k==b.size()){
                cout<<"Case #"<<tcase<<": "<<happy[b[b.size()-1]][i]<<endl;
                break;
            }
        }
//        cout<<endl;

    }
    
}


int main(int argc, char** argv) {
    generateHappy();
    solveCases();
    return (EXIT_SUCCESS);
}

