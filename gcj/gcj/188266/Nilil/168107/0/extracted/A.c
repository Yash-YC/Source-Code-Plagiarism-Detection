#include <stdio.h>
#define MAX 600000
#define sqr(a) ((a)*(a))
int k,f[11][MAX*2],cal(int i);

int main(void)
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    int t_case,t0,i,j,n,base[10];

    for (k=2;k<=10;++k)
    {
        f[k][1]=1;
        for (i=2;i<=MAX;++i)
            f[k][i]=cal(i);
    }


    scanf("%d",&t_case);
    for (t0=1;t0<=t_case;++t0)
    {
        n=0;
        do
        {
            scanf("%d",&base[n]);++n;
        }while (getchar()!='\n');
        for (i=2;i<=MAX;++i)
        {
            for (j=0;j<n;++j)
                if (f[base[j]][i]<0)
                    break;
            if (j==n)
            {
                printf("Case #%d: %d\n",t0,i);break;
            }
        }
    }

    fclose(stdin);fclose(stdout);
    return 0;
}

int cal(int i)
{
    if (f[k][i]==2)
        return f[k][i]=-1;
    if (f[k][i])
        return f[k][i];
    int s=0,i0=i;
    while (i)
    {
        s+=sqr(i%k);i/=k;
    }
    if (s==1)
        return f[k][i0]=1;
    f[k][i0]=2;
    return f[k][i0]=cal(s);
}
