#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <conio.h>
#include <climits>
#include <queue>

using namespace std;

#define dv(vectName) for(int ii=0;ii<vectName.size();ii++) cout<<vectName[ii]<<' '; cout<<endl;
#define d1da(arrayName,size) for(int ii=0;ii<size;ii++) cout<<arrayName[ii]<<' '; cout<<endl;
#define d2da(arryName,row,col) for(int ii=0;ii<row;ii++){ for(int jj=0;jj<col;jj++) cout<<arryName[ii][jj]<<' '; cout<<endl; } cout<<endl; 

#define miii map<int,int>::iterator
#define mici map<int,char>::iterator
#define mcii map<char,int>::iterator
#define vii vector<int>::iteartor

#define pb(vectName,value) vectName.push_back(value);
#define mi(mapName,keyType,valType,key,val) mapName.insert(pair<keyType,valType>(key,val));



fstream inp("a-small.in",ios::in);
fstream out("a-small.out",ios::out);


vector<int> convert(int num,int base){
    vector<int> answer;
    while(num){
               answer.push_back(num%base);
               num/=base;
    }
    return answer;
}

int sos(vector<int> num){
    int answer=0;
    for(int i=0;i<num.size();i++){
            answer+=(num[i]*num[i]);
    }
    return answer;
}


vector<int> parse(string s){
            int num=0;
            vector<int> answer;
            for(int i=0;i<s.length();i++){
                    if(s[i]!=' '){
                               (num*=10)+=(s[i]-'0');
                    }
                    else{
                         answer.push_back(num);
                         num=0;
                    }
            }
            answer.push_back(num);
            return answer;
}


bool ishappy(int n,const int base){
     //cout<<"\nnumber is "<<n<<"and checking happiness in base"<<base;     
     bool answer=true;
     int visited[100000]={0};
     //memset(visited,0,1000000*sizeof(int));
     int num=n;
     visited[num]=1;
     //cout<<"\nnumber is "<<n<<"and checking happiness in base"<<base;     
     for(int j=1;j<=100;j++){
                 vector<int> c = convert(num,base);
                 //cout<<"\n"<<num <<"in this base is ";
                 //dv(c);
                 num=sos(c);
                 //cout<<"and sos is "<<num;
                 //getch();
                 if(num==1) return true;
                 if(visited[num]==1) return false;                                  
                 visited[num]=1;
                 
     }
     
     
}

void solve(int testCaseNo){
     string input;  
     if(testCaseNo==1)getline(inp,input);   
     getline(inp,input);
     vector<int> bases = parse(input);
     
     //dv(bases);
     bool done=false;
     int i=0;
     for(i=2;!done;i++){
             done=true;
             //cout<<"\ni = "<<i<<"and bases.size = "<<bases.size();
             for(int j=0;j<bases.size();j++){
                     if(! ishappy(i,bases[j]) ){
                          done=false;
                          break;
                     }
             }
     }
     out<<"Case #"<<testCaseNo<<": "<<i-1<<endl;
}




int main(void){
    int T;
    inp>>T;
    for(int i=1;i<=T;i++)
            solve(i);
    getch();
    return 0;
}
