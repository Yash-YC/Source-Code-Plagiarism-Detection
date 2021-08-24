#include<set>
#include<sstream>
#include<stdio.h>
#include<string>
using namespace std;
int base[20];
char f[12][12000010];
int b[12000010];
bool check(int num,int base)
{
    int sum;
    int tot=0;
    while (num!=1 && f[base][num]==0)
    {
        f[base][b[++tot]=num]=1;
        sum=0;
        while (num)
        {
            sum+=(num%base)*(num%base);
            num/=base;
        }
        num=sum;
    }
    if (num==1 || f[base][num]==2)
    {
        for (int i=1;i<=tot;i++)
            f[base][b[i]]=2;
        return true;
    }
    else
        return false;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out2","w",stdout);
    for (int i=2;i<=10;i++)
    {
        for (int j=2;j<=12000000;j++)
            if (f[i][j]==0)
            check(j,i);
    }
    int t,tt;
    scanf("%d",&t);
    getchar();
    for (tt=1;tt<=t;tt++)
    {
        char s[1010];
        gets(s);
        stringstream ss(s);
        int n=0,temp;
        while (ss>>temp)
            base[++n]=temp;
        for (int i=2;i<=12000000;i++)
        {
            bool ok=true;
            for (int j=1;j<=n;j++)
                if (f[base[j]][i]==1)
                {
                    ok=false;
                    break;
                }
            if (ok) 
            {
                printf("Case #%d: %d\n",tt,i);
                break;
            }
        }
    }
    
}