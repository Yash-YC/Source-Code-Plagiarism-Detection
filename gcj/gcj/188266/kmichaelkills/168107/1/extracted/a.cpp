#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <memory>
#include <cctype>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define FOR( i , n ) for (int i = 0; i < n ; i++ )
#define debug(x) cout << #x" = " << x << "\n"
#define FORIT( i , c ) for ( __typeof((c).begin())  i  = (c).begin() ; (i) != (c).end() ; (i)++ )



bool happy[11][5000];
int c;

bool h(int b, int n){
     
     int N = n;
     int sq = 0;
     while(N>0){
       int a = N%b;
       sq = sq+a*a;
       N/=b;
     }
     if (sq==1) return true;
     c++;
     if (c>20) return false;     
     return h(b,sq);
}

bool h2(int b, int n){
     int N= n;
     int sq = 0;
     while(N>0){
       int a = N%b;
       sq = sq+a*a;
       N/=b;
     }
     return happy[b][sq];
}

int resp[1<<9];


int main() {
  int ca;
  FOR(i,(1<<9))
  resp[i]=-1;  
  /*FOR(i,11)
   FOR(j,2000000)
     happy[i][j]=0;
  for(int b=2;b<=10;b++)
   for(int j= 2;j<2000000;j++)
    { c=0;
           happy[b][j]=h(b,j);
    }
  cout<<"s";
  */
  
  for(int j = 1;j < 5000 ; j++ )
   for(int b=2;b<=10;b++)
    {c=0;
           happy[b][j]=h(b,j);
    }

/*  bool us[11];
  FOR(i,11)
   us[i]=0;
  int B2= 2+3+4+5+6+7+8+9+10;
  int foram = 0;
  for(int j= 2;j<2000000;j++)
   {
   int u = 0;
   int B=B2;
   for(int b=2;b<=10;b++)
    if (h2(b,j)) {u++;B-=b;}
   
   if(u==8) if(!us[B]) {foram++;us[B]=true;cout<<B<<endl;}  
   if(foram==8) {cout<<j;break;}
  }
*/
//11814500
  for(int j = 2; j < 11814485 ; j++ ){
   int u = 0;
   for(int b=2;b<=10;b++)
     if(h2(b,j)){u += (1<<(b-2));}
  // cout<<u<<endl;
   if(resp[u]<0) resp[u]=j;
    
  }
  
  //cout<<h2(2,3)<<endl;
  
 // FOR(l,(1<<7))
 //  if(resp[3+ l*4]>0) cout << "ddd";
  //cout<<"as";
  cin>>ca;
  string s;
  getline(cin,s);
  FOR(cas, ca)
    {
     getline(cin,s);
     stringstream ss(s);
     int B;
     int v =0;
     while(ss>>B) {v+=(1<<(B-2));}
     int ret = 888888888;
     FOR(l,(1<<9))
      if((l&v) == v)
         if(resp[l]<ret&&resp[l]>0) ret = resp[l];     
     cout<<"Case #"<<cas+1<<": "<<ret<<endl;
      
    }
 return 0;
}
