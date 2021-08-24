#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int rep(string a,int b){
  set<string> st;
  st.insert(a);
  
  do{
    string s;
    long sum=0;

    for(int i=0;i<a.size();i++){
      sum+=(a[i]-'0')*(a[i]-'0');
    }

    for(;sum>0;sum/=b){
      s+=(sum%b)+'0';
    }
   
    reverse(s.begin(),s.end());
    a=s;
    
    if(st.count(s))return 0;
    st.insert(s);
    
  }while(atoi(a.c_str())!=1);
  
  return 1;
}
int di(string a,int b){
  for(int i=0;i<a.size();i++)
    if(a[i]-'0'>=b)return 0;
  return 1;
}
string aba(long a,int b){
  string s;
  for(;a>0;a/=b)s+=(a%b)+'0';
  reverse(s.begin(),s.end());
  return s;
}
typedef struct KKK{
  int flag[10];
}K;

int main(){
  int T;
  map<long,K> mpa;
  
  cin>>T;
  cin.ignore();

  for(int x=1;x<=T;x++){
    char str[128],*s;
    gets(str);
    for(long p=2;;p++){
      s=str;
      int n;
      for(;n=strtol(s,&s,10),n;){
        if( (di(aba(p,n),n) && rep(aba(p,n),n)) ){
          ;
        }else break;
      }
      if(n==0){
        printf("Case #%d: %ld\n",x,p);
        break;
      }
    }
  }
    
    
  return 0;
}