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
int A[2509];
int N,n;
int a;
vector<int> v;
int main(){
   cin>>n;
   for(int i=0;i<n;i++){

      memset(A,0,sizeof(A));
      v.clear();
      cin>>N;
      for(int j=0;j<N*(2*N-1);j++){
         cin>>a;
         A[a]^=1;
      }
      for(int k=0;k<2509;k++){
         if(A[k]){
            v.push_back(k);
         }
      }
      sort(v.begin(),v.end());
      cout<<"Case #"<<i+1<<": ";
      for(int k=0;k<N;k++){
         cout<<v[k]<<' ';
      }
      cout<<endl;
   }
}

