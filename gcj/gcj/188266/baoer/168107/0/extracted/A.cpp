#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

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
    map <int, bool> my;
    my.clear();
    my[x] = true;
    int temp;
    while(temp = func(x, b))
    {
        if(my[temp])
            return false;
        else if(temp == 1)
            return true;
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
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-s.out","w",stdout);
    int i,j,k,t;
    int base[10],n;
    char ch,x;

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
        for(j=2; ;j++)
        {
            for(k=0; k<n; k++)
            {
                if(!Juage(j, base[k]))
                    break;
            }
            if(k == n)
                break;
        }
        printf("Case #%d: %d\n", i, j);
    }

    return 0;
}