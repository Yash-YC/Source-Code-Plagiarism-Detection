#include<iostream>
#include<map>
using namespace std;
int a[11];
int num;
char str[30];
map<int,bool> p;
map<int,bool>::iterator it;
int c=0;
bool f(int t,int base){
     c++;
     if(c>1000)return false;
     it=p.find(t);
     if(it!=p.end())return false;
     int k=t;
     int temp=0;
     while(k){
              temp=temp+(k%base)*(k%base);
              k=k/base;
              }
     if(temp==1)return true;
     else return f(temp,base);
     }
int solve(){
     int i=2;
     while(1){
              int j;
              bool pp=true;
              p.clear();
              for(j=0;j<num;j++){
                                 c=0;
                                 if(!f(i,a[j])){
                                                pp=false;
                                                break;
                                                }
                                 }
              if(pp)return i;
              else i++;
              }
     }
int main(){
    int t;
    scanf("%d",&t);
    int count=1;
    gets(str);
    while(t--){
               gets(str);
               int l=strlen(str);
               int i;
               num=0;
               for(i=0;i<l;){
                             a[num]=str[i]-'0';
                             if(i+1<l&&str[i+1]!=' '){
                                                   a[num]=a[num]*10+str[i+1]-'0';
                                                   i=i+3;
                                                   }
                             else i=i+2;
                             num++;
                             }
               //for(i=0;i<l-1;i=i+2)a[num++]=str[i]-'0';
               //a[num++]=str[l-1]-'0';
               printf("Case #%d: %d\n",count,solve());
               count++;
               }
    return 0;
}
