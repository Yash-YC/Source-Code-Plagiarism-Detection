#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

typedef long long int LL;

LL nt[50][50];
double pr[30000][50];

void solve(int a){
     double res=0.0;
     int c,n;
     cin>>c>>n;
     for(int a=0;a<=c;a++)pr[1][a]=0.0;
     pr[1][n]=1.0;
     res +=1.0 * pr[1][c];
     if(n==c)goto dupa;
     
     for(int x=2;x<30000;x++){
             for(int u=1;u<=c;u++)pr[x][u]=0.0;
             for(int u=n;u<=c;u++){
                     for(int k = u-n; k<=u;k++){
                             double ww = pr[x-1][k] * (double)(nt[c-k][u-k])/(double)(nt[c][n]);
                             ww*=(double)(nt[k][n-u+k]);
                             pr[x][u]+=ww;
                             }
                     }
             res+=(double)(x)*(pr[x][c]- pr[x-1][c]);
             }
     
     
     
     dupa:
     cout<<"Case #"<<a<<": ";
     printf("%5f\n", res);
     }


int main(){
    freopen("C_small.in", "r",  stdin);
    freopen("C_small.out", "w", stdout);
    
    
    for(int a=0;a<=40;a++)for(int b=0;b<=40;b++)nt[a][b]=0;
    nt[0][0]=1;
    for(int a=1;a<=40;a++){
            nt[a][0] =1;
            for(int b=1;b<=a;b++)nt[a][b] = nt[a-1][b-1] + nt[a-1][b];
            }
    int t;
    cin>>t;
    for(int a=1;a<=t;a++)solve(a);
    return 0;
}
