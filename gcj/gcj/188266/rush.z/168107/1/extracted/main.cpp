#include <stdio.h>
#include <string.h>

using namespace std;
//int arr[100000];
bool res[10000][9];
int lenNum;
bool ishappy(int num , int base)
{
    int hash[10000] ={0};

    int idx = 0;
    int tmp, total;
    total = 0;
    while (num)
    {
        tmp = num % base;
        total += tmp * tmp;
        num /=base;
    }
    //printf("ttttt\n");
    while (1)
    {
        num = total;
        //printf("%d\n",num);
        if (num ==1) return true;
        if (hash[num]) break;

        hash[num] = 1;
        total = 0;
        while (num)
        {
            tmp = num % base;
            total += tmp * tmp;
            num /=base;
        }
    }
    return false;
}
int can(int num , int base)
{
    int idx = 0;
    int total = 0;
    int tmp;
    while (num)
    {
        tmp = num % base;
        total += tmp * tmp;
        num /=base;
    }
    //printf("ttttt\n");
    while (1)
    {
        num = total;

        if (num <10000) return res[num][base-1];
        total = 0;
        while (num)
        {
            tmp = num % base;
            total += tmp * tmp;
            num /=base;
        }
    }
}
int main()
{
    int T;
    char strin[100];
    int base[10];
    int ncase,len, i,j,cnt, total,min;

    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    gets(strin);

    for (j = 1; j <9; j ++)
        res[1][j] = true;
    for (i = 2; i < 10000; i ++)
    {
        //res[i][0] = true;
        for (j = 1; j <10; j ++)
            if (ishappy(i,j+1))
                res[i][j] = true;
            else
                res[i][j] = false;
    }

    //printf("gogo");
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
                if (!can(min, base[i]))
                {
                    isOK = false;
                    break;
                }
            if (isOK)
                break;
            //printf("%d \n",min);
            min++;

           //break;

        }
        printf("Case #%d: %d\n", ncase, min);
    }

    return 0;
}
