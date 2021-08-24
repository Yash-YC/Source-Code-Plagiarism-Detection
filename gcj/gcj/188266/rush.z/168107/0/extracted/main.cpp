#include <stdio.h>
#include <string.h>

using namespace std;
int arr[10000];
int lenNum;
bool ishappy(int num , int base)
{
    int hash[10000] ={0};

    int idx = 0;
    while (num)
    {
        arr[idx++] = num % base;
        num /=base;
    }
    //printf("ttttt\n");
    while (1)
    {
        num = 0;
        for ( int i = 0; i < idx; i ++)
            num += arr[i] * arr[i];

        //printf("%d\n",num);
        if (num ==1) return true;
        if (hash[num]) break;

        hash[num] = 1;
        idx = 0;
        while (num)
        {
            arr[idx++] = num % base;
            num /=base;
        }
    }


    return false;
}

int main()
{
    int T;
    char strin[100];
    int base[10];
    int ncase,len, i,j,cnt, total,min;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    gets(strin);


    for (ncase = 1; ncase <=T; ncase ++)
    {
        gets(strin);
        len = strlen(strin);
        cnt = 0;
        total = 0;
        for ( i = 0; i < len; i ++)
        {
            if (strin[i] ==' ' )
            {
                base[cnt++] = total;
                total = 0;
            }
            else
            {
                total = total * 10 + strin[i]-'0';
            }
        }
        if (total > 0)
            base[cnt++] = total;
        min = 2;
        while (true)
        {
            bool isOK = true;
            for (i = 0; i < cnt; i ++)
                if (!ishappy(min, base[i]))
                {
                    isOK = false;
                    break;
                }
            if (isOK)
                break;
            //printf("%d \n",min++);
            min++;
           //break;

        }
        printf("Case #%d: %d\n", ncase, min);
    }

    return 0;
}
