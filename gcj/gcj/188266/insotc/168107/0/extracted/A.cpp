#include <iostream>
using namespace std;
int re[101000][11];
int dfs(int i,int base){
    int ii=i,sum=0;
    re[i][base]=2;
    while(ii){
        sum+=(ii%base)*(ii%base);
        ii/=base;
    }
    if(sum==1)return re[i][base]=1;
    if(re[sum][base]==0)return re[i][base]=dfs(sum,base);
    if(re[sum][base]==1)return re[i][base]=1;
    if(re[sum][base]==2)return re[i][base]=2;
}
int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int cas,ca=1,i,j,a[11],n;
    for(i=2;i<=100000;i++){
        for(j=2;j<=10;j++){
            if(re[i][j]==0)dfs(i,j);
        }
    }
    cin>>cas;
    while(cas--){
        n=0;
        while(cin.peek()==' '||cin.peek()=='\n')getchar();
        while(1){
            while(cin.peek()==' ')getchar();
            if(cin.peek()=='\n'||cin.peek()==EOF)break;
            cin>>a[n];
            n++;
        }
        for(i=2;i<100000;i++){
            for(j=0;j<n;j++){
                if(re[i][a[j]]!=1)break;
            }
            if(j==n)break;
        }
        printf("Case #%d: %d\n",ca++,i);
    }
    return 0;
}
        
