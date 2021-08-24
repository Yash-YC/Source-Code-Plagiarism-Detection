#include<stdio.h>
double c[50][50];
void init()
{
    int i,j;
    c[0][0]=1;
    c[0][1]=c[1][1]=1;
    for(i=2;i<=40;i++)
    {
        c[0][i]=c[i][i]=1;
        for(j=1;j<i;j++) c[j][i]=c[j][i-1]+c[j-1][i-1];
    }
}
double get(int n,int m)
{
    if(n>m) return 0;
    return c[n][m];
}
double f[100];
int main()
{
    init();
    int ncase,nc,i,j,N,C;
    double sum;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&ncase);
    for(nc=1;nc<=ncase;nc++)
    {
        scanf("%d%d",&C,&N);
        f[C]=0;
        for(i=C-1;i>=0;i--)
        {
            sum=1;
            for(j=1;j<=N;j++)
            {
                if(j+i>C) break;
                //printf("%lf %lf %lf %lf\n",get(N-j,i),get(j,C-i),get(N,C),f[i+j]);
                sum+=get(N-j,i)*get(j,C-i)/get(N,C)*f[i+j];
            }
            //printf("%lf\n",sum);
            f[i]=sum/(1-get(N,i)*get(0,C-i)/get(N,C));
        }
        printf("Case #%d: %.7lf\n",nc,f[0]);
    }
    return 0;
}