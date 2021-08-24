#include<cstdio>
#include<cstring>

using namespace std;

int T,test;
int i,j,k;
int s,n;
double q,p,o;
double c[45][45];
double f[100],g[100];

int main(){
    memset(c,0,sizeof(c));
    for(i=0;i<=40;++i)
        c[i][0]=c[i][i]=1;
    for(i=2;i<=40;++i)
        for(j=1;j<i;++j) c[i][j]=c[i-1][j]+c[i-1][j-1];    
    scanf("%d",&T);
    for(test=1;test<=T;++test){
        scanf("%d%d",&s,&n);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        f[0]=1;
        for(i=0;i<s;++i){
            p=1.-c[i][n]/c[s][n];
//            printf("%.5lf  %.5lf\n",f[i],p);
            for(j=1;j<=n;++j){
                q=c[i][n-j]*c[s-i][j]/c[s][n];
                f[i+j]+=f[i]*q/p;
            }
        }        
        for(i=0;i<s;++i){
            p=1.-c[i][n]/c[s][n];
//            printf("%.5lf  %.5lf\n",f[i],p);
            for(j=1;j<=n;++j){
                q=c[i][n-j]*c[s-i][j]/c[s][n];
                if(q>0) g[i+j]+=(1/q+g[i])*f[i]*q/p/f[i+j];
            }
        }        
        printf("Case #%d: %.7lf\n",test,g[s]);
    }   
}
