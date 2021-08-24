#include <stdio.h>
#include <memory.h>
double c[50][50];
double f[50];
void init()
{
     memset(c,0,sizeof(c));
     c[0][0]=0;
     for (int i=1;i<=40;i++)
     {
         c[i][i]=c[i][0]=1;
         for (int j=1;j<i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
     }
}
int main()
{
    freopen("c2.in","r",stdin);
    freopen("c2.out","w",stdout);
    init();
//    memset(f,0,sizeof(f));
    int tests,N,C;
    scanf("%d",&tests);
    for (int t0=1;t0<=tests;t0++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int tt=0;
        memset(f,0,sizeof(f));
        f[n]=0;
        for (int i=n-1;i>=k;i--)
        {
                  f[i]=1;   
                   double tmp;               
                  for (int x=0;x<=k;x++)      
                  {           
                      if (x==0) tmp= c[i][k-x]*c[n-i][x]/c[n][k];
                      else f[i]+=f[i+x]*(c[i][k-x]*c[n-i][x]/c[n][k]);
                  }
                              
                  f[i]=f[i]/(1-tmp);
              }
        printf("Case #%d: %.6f\n",t0,f[k]+1);
    }
}
