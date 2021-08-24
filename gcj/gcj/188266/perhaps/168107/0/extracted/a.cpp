#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int check(int x,int y){
    int a=0;
    int z;
    for(int i=0;i<200;i++){
        while(y>0){
            z=y%x;
            y/=x;
            a=a+z*z;
        }
        y=a;
        a=0;
        if(y==1)return(1);
    }
    return(0);
}
int main(){
    int i,j;
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    int t,top;
    int q[100];
    cin>>t;
    char s[10000];
    gets(s);
    for(i=1;i<=t;i++){
        gets(s);
        istringstream is(s);
        top=0;
        while(is>>q[top]){
            top++;
        }
        int flag=0;
        for(j=2;!flag;j++){
            flag=1;
            for(int k=0;k<top;k++){
                if(!check(q[k],j)){
                    flag=0;break;
                }
            }
        }
        cout<<"Case #"<<i<<": "<<j-1<<endl;
    }
    return(0);
}


