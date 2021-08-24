#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

int gut[100000][11];

void fill(){
     for(int a=2;a<100000;a++)for(int b=2;b<=10;b++){
             int t[7];
             for(int c=0;c<7;c++)t[c]=0;
             int g=0;
             int yyy = a;
             for(int it=0;it<100;it++){
                     for(int c=0;c<7;c++){t[c] = yyy%b; yyy/=b;}
                     if(t[0] ==1 && t[1] == 0 && t[2]==0 && t[3] ==0 && t[4] == 0 && t[5] == 0 && t[6] == 0){
                             g=1;break;
                             }
                     yyy =0;
                     for(int c=0;c<7;c++)yyy+=t[c]*t[c];
                     }
             if(g==1)gut[a][b]=1;
             else gut[a][b]=0;
     }
}

void solve(int tc){
     int res;
     char elo[200];
     gets(elo);
     string str="";
     for(int a=0;a< strlen(elo);a++)str+=elo[a];
     istringstream is(str);
     vector<int> bass;
     int bb;
     while(is>>bb){
                   bass.push_back(bb);
                   }
     for(int a=2;a<100000;a++)
     {
      int ok=1;
      for(int b=0;b<bass.size();b++){
              if(gut[a][bass[b]] == 0){ok=0;break;}
              }
      if(ok==1){res=a;break;}        
     }
     
     
     
     printf("Case #%d: %d\n", tc, res);
     }

int main(){
    freopen("A_small.in", "r",  stdin);
    freopen("A_small.out", "w", stdout);
    
    int t;
    fill();
    //cout<<"gut"<<endl;
    scanf("%i\n", &t);
    for(int a=1;a<=t;a++)solve(a);
    
    return 0;
}
