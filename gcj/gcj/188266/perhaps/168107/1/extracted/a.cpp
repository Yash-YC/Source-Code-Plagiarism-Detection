#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int ans[1000];
int main(){
    int i,j;
    freopen("a.out","r",stdin);
    char s[10000];
    for(i=1;i<=511;i++){
        cin>>s>>s>>ans[i];
    }
    fclose(stdin);
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    int t,q;
    cin>>t;
    gets(s);
    for(i=1;i<=t;i++){
        gets(s);
        istringstream is(s);
        int p=0;
        while(is>>q){
            p+=(1<<q);
        }
        p/=4;
        cout<<"Case #"<<i<<": "<<ans[p]<<endl;
    }
    return(0);
}


