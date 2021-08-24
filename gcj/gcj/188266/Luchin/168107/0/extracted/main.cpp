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

int num,ans,T;
string str,aux;
map<string,bool> mapita;

string transf(int num,int base){

string ans="";
//cout<<"El numero "<<num<<" se transforma en ";
    while( num ){
      
      int dig = num%base;
      //cout<<"dig es "<<dig<<endl;
      num/=base;
      ans = string(1,dig+'0') + ans;
     // cout<<ans<<endl;
    }
 // cout<<ans<<endl;
 return ans; 
}

bool puede(string cad,int base){

   if( mapita[cad] ) return false;
  
   mapita[cad] = true; 
   
   long long suma = 0;
    
    for(int i=0;i<cad.size();i++)
     suma+=(cad[i]-'0')*(cad[i]-'0');   
  
   if( suma == 1 ) return true;
   
   string ent = transf(suma,base); 
   return puede(ent,base); 

}


int main(){

 scanf("%d",&T);
 getchar(); 
 
   for(int caso=1;caso<=T;caso++){
   
     getline(cin,str);
     stringstream is(str);
     vector<int> bases;
      while(is>>num) bases.push_back(num); 
      
     for(int i=2;;i++){
     
       bool ok = true;
       
        for(int j=0;j<bases.size() && ok;j++){
          aux = transf(i,bases[j]);
          mapita.clear(); 
          if( puede(aux,bases[j]) == false) ok = false;        
        }
     
      
       if( ok == true ) {ans=i;break;}
      
     }
   
    cout<<"Case #"<<caso<<": "<<ans<<endl;  
   
   }
}


