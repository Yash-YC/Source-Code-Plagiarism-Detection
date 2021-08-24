#include<set>
#include<sstream>
#include<stdio.h>
#include<string>
using namespace std;
int base[20];
int f[100010][20];
bool check(int num,int base)
{
    int sum;
    set <int> mark;
    while (num!=1 && f[num][base]==0 && mark.find(num)==mark.end())
    {
        mark.insert(num);
        sum=0;
        while (num)
        {
            sum+=(num%base)*(num%base);
            num/=base;
        }
        num=sum;
    }
    if (num==1 || f[num][base]==1)
    {
        set <int>::iterator p;
        for (p=mark.begin();p!=mark.end();p++) 
            f[*p][base]=1;
        return true;
    }
    else
    {
        set <int>::iterator p;
        for (p=mark.begin();p!=mark.end();p++) 
            f[*p][base]=-1;
        return false;
    }
}
int main()
{
    for (int i=2;i<=10;i++)
        for (int j=2;j<=100000;j++)
            if (f[j][i]==0)
            check(j,i);
    int t,tt;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
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
        for (int i=2;i<=100000;i++)
        {
            bool ok=true;
            for (int j=1;j<=n;j++)
                if (f[i][base[j]]==-1)
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