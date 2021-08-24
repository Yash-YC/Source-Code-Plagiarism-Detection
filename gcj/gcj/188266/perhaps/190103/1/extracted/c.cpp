#include<iostream>
using namespace std;
double f[100][100];
double g[100];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,t,n,c;
    memset(f,0,sizeof(f));
    for(i=0;i<=40;i++)
        f[i][0]=f[i][i]=1;
    for(i=1;i<=40;i++)
        for(j=1;j<i;j++)
            f[i][j]=f[i-1][j-1]+f[i-1][j];
    memset(g,0,sizeof(g));
    cin>>t;
    for(int ii=1;ii<=t;ii++){
        cin>>n>>c;
        memset(g,0,sizeof(g));
        for(i=1;i<=n-c;i++){
            g[i]=1;
            for(j=1;j<=c&&i-j>=0;j++)
                g[i]+=f[i][j]/f[n][c]*f[n-i][c-j]*g[i-j];
            g[i]/=(1-f[n-i][c]/f[n][c]);
        }
        printf("Case #%d: %.5f\n",ii,g[n-c]+1);
    }
    return(0);
}
