#include<bits/stdc++.h>

using namespace std;

main()
{   freopen("input.txt","r",stdin);
    freopen("BigA.txt","w",stdout);
    int T,c=1,i=0,j,k;
    string S,M,out;
    char tmp;
    cin>>T;
    while(c<=T){

        cin>>S;
        out=S;
        cout<<"Case #"<<c<<": ";
        c++;
        for(j=1;j<S.length();j++){
            if(out[0]<=out[j]){
                tmp=out[j];
                for(k=j;k>=1;k--){
                        out[k]=out[k-1];
                }
                out[0]=tmp;
            }
            //else
        }
        cout<<out<<endl;
    }
}
