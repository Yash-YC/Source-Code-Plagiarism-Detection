#include <iostream>
using namespace std;

double c[50][50]={0};
double f[100]={0};
int i,j,k,n,m,ncase,t;
double temp;
void predo()
{
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for (i=1; i<50; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (j=1; j<i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    return;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    predo();
    scanf("%d",&ncase);
    for (t=1; t<=ncase; t++)
    {
        scanf("%d%d",&n,&m);
        f[0] = 0;
        for (i=1; i<=n; i++)
        {
            temp = c[n][m];
            for (j=1; j<=i; j++)
                temp+=c[i][j]*c[n-i][m-j]*f[i-j];
            f[i] = temp/(c[n][m]-c[i][0]*c[n-i][m]);
        }
        printf("Case #%d: %.6lf\n",t,f[n]);
    }
}
