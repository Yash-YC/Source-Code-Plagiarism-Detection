#include <iostream>
using namespace std;

short can[12000000][11]={0};
int t,ncase,i,j,n,temp,len;
int a[100]={0};
char s[1000]={0};
bool checkwin(int x, int y)
{
    if (x==10 && y==2)
        x=10;
    if (can[y][x]==1)
        return true;
    if (can[y][x]==-1)
        return false;
    can[y][x] = -1;
    int temp,tempy;
    temp = 0;
    tempy = y;
    while (tempy>0)
    {
        temp+=(tempy%x)*(tempy%x);
        tempy/=x;
    }
    if (checkwin(x,temp))
    {
        can[y][x] = 1;
        return true;
    }
    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    for (i=2; i<=10; i++)
        can[1][i] = 1;
    for (i=2; i<=10; i++)
        for (j=2; j<12000000; j++)
        {
            if (i==10 && j==68)
            {
                j=68;
            }
            checkwin(i,j);
        }
    scanf("%d",&ncase);
    gets(s);
    for (t=1; t<=ncase; t++)
    {
        n = 0;
        gets(s);
        len = strlen(s);
        i = 0;
        while (i<len)
        {
            while ( i<len && !(s[i]>='0'&&s[i]<='9') )
                i++;
            if (i==len)
                break;
            temp = 0;
            while (i<len && (s[i]>='0'&&s[i]<='9') )
            {
                temp = temp*10+s[i]-'0';
                i++;
            }
            a[n++] = temp;
        }
        for (i=2; i<12000000; i++)
        {
            for (j=0; j<n; j++)
                if (can[i][a[j]]!=1)
                    break;
            if (j==n)
                break;
        }
        printf("Case #%d: %d\n",t,i);
    }
    return 0;
}
