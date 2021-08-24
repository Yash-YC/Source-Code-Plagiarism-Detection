#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<utility>
#include<sstream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<queue>
#include<stack>
#include<set>

#define all(v) v.begin(),v.end()
#define INFINITO (1LL<<62)

using namespace std;

int T,total,sobre;
double ans;
long long comb[50][50];
long double memo[50];

long long getComb(int i,int j){

  if( i < j) return 0;
  if( j == 0) return 1;

  if( comb[i][j]!=-1) return comb[i][j];
  
  return comb[i][j] = getComb(i-1,j-1) + getComb(i-1,j);
}

double proba(int num,int falt){

 return getComb(total-num,falt)/(long double)getComb(total,sobre)*getComb(num,sobre-falt);

}


long double expc(int num){

   if( num >= total ) return 0;
   if(memo[num]>0) return memo[num];
  
  double rsta = 1,frac;
 
   for(int i=1;i<=sobre;i++) rsta+=proba(num,i)*expc(num+i);
  
  frac = 1 - getComb(num,sobre)/(long double)getComb(total,sobre);
  
  return memo[num]  = rsta/frac ;
}




int main(){

 scanf("%d",&T);
 memset(comb,-1,sizeof(comb));
     for(int caso=1;caso<=T;caso++){
       
      
      cin>>total>>sobre;
      
       for(int i=0;i<=total;i++) memo[i]=-1;    
      ans = 1 + expc(sobre);
    cout<<"Case #"<<caso<<": "<<ans<<endl;  
   
   }
}


