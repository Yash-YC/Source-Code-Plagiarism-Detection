#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#define ld long double
#define ll long long int
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define fi(a,b,c) for(int a=b;a<c;a++)
#define fd(a,b,c) for(int a=b;a>c;a--)
using namespace std;
string s,t;
vector<string> sa;
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>s;
      ll N=2<<(s.length());
      for(ll j=0;j<(ll)N;j++){
         t="";
         for(int k=0;k<s.length();k++){
            if((j & ( 1 << k )) >> k){
               t.push_back(s[k]);
            }else{
               t=s[k]+t;
            }
         }
         sa.push_back(t);
      }
      sort(sa.begin(),sa.end());
      cout<<"Case #"<<i+1<<": "<<sa[N-1]<<endl;
      sa.clear();s.clear();t.clear();
   }
}

