#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
#include <time.h>
#define MAX 600000

using namespace std;

char f[600001][11];

int func(int x, int b)
{
    int re = 0, temp;
    while(x)
    {
        temp = x % b;
        re += temp * temp;
        x/=b;
    }
    return re;
}

bool Juage(int x, int b)
{
    int rec = x;
    map <int, bool> my;
    my.clear();
    my[x] = true;
    int temp;
    while(temp = func(x, b))
    {
        if(temp == 1)
            return true;
        
        if(temp<rec)
        {
            if(f[temp][b] == '1')
            return true;
            else
            return false;
        }
        
        if(my[temp])
            return false;
        else
        {
            my[temp] = true;
            x = temp;
        }
    }
    return false;
}

int main(void)
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int i,j,k,t;
    int base[10],n;
    char ch,x;

    for(i=2; i<= 10; i++)
    {
        f[0][i] = '0';
        f[1][i] = '1';
    }

    for(i=2; i<= MAX; i++)
    {
        for(j=2; j<=10; j++)
        {
            if(Juage(i,j))
                f[i][j] = '1';
            else
                f[i][j] = '0';
        }
    }

    scanf("%d",&t);

    for(i=1; i<=t; i++)
    {
        for(j=0;;j++)
        {
            scanf("%d%c",&base[j],&ch);
            if(ch == '\n')
            {
                j++;
                break;
            }
        }
        n = j;
        for(j=2; j<=MAX; j++)
        {
            for(k=0; k<n; k++)
            {
                if(f[j][base[k]]=='0')
                    break;
            }
            if(k == n)
                break;
        }
        printf("Case #%d: %d\n", i, j);
    }

    return 0;
}