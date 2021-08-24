#include<stdio.h>

double cache[50][50][50];
double pcache[50][50];
void init()
{
    for(int i=0;i<48;i++)
        for(int j=0;j<48;j++)
            for(int k=0;k<48;k++)
                cache[i][j][k]=pcache[i][j]=-2.;
}
double bi(int n, int c)
{
    if(c<0 || n<0)
        return 0.;
    if(c==0)
        return 1.;
    if(n<c)
        return 0.;
    if(pcache[n][c]>-1.)
        return pcache[n][c];
    pcache[n][c]=bi(n-1,c)+bi(n-1,c-1);
    return pcache[n][c];
}

double pr(int n, int c, int hs, int m)
{
    return bi(n-hs,m)*bi(hs,c-m)/bi(n,c);
}

double exp(int n, int c, int hs)
{
    if(hs==n)
        return 0;
    if(cache[n][c][hs]>-1.)
        return cache[n][c][hs];
    cache[n][c][hs]=0;
    
    double selfp=pr(n,c,hs,0);
    for(int i=1;i<=c && i<=n-hs;i++)
        cache[n][c][hs]+=pr(n,c,hs,i)*exp(n,c,hs+i);
    cache[n][c][hs]++;
    cache[n][c][hs]/=1-selfp;
    return cache[n][c][hs];

}

int main()
{
    freopen("C1.in","r",stdin);
    freopen("C1.out","w",stdout);
    //freopen("A2.in","r",stdin);
    //freopen("A2.out","w",stdout);
    init();
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        int n,c;
        scanf("%d%d",&n,&c);
        double ans=exp(n,c,0);
        printf("Case #%d: %.10lf\n",cs,ans);
    }
}

