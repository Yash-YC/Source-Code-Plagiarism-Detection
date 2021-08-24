#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int base[15];
int n;
FILE *in=fopen("bas.in","r");

void readline()
{
    int c,c2;
    char ch;
    int num=0;
    n=0;
    while (1)
    {
        fscanf(in,"%c",&ch);
        if (isdigit(ch))
        {
            num*=10;
            num+=(ch-'0');
            continue;
        }
        else
        {
            base[n]=num;
            n++;
            num=0;
        }
        if (ch=='\n')break;
    }
    return;
}
int sum[100005][15];
bool flag[100005];


int main()
{
    freopen("bas.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d\n",&tests);
    for (c=2;c<=100000;c++)
    {
        for (c2=2;c2<=10;c2++)    
        {
            int num=c;
            int s=0;
            while(num)
            {
                s+=(num%c2)*(num%c2);
                num/=c2;
            }
            sum[c][c2]=s;
        }
    }
    int testn=1;
    while(tests)
    {
        tests--;
        printf("Case #%d: ",testn);
        testn++;
        readline();
        for (c=2;;c++)
        {
            int num;
            for (c2=0;c2<n;c2++)
            {
                num=c;
                memset(flag,0,sizeof(flag));
                while(num>1)
                {
                    if (flag[num])break;
                    flag[num]=1;
                    num=sum[num][base[c2]];
                }
                if (num>1)break;
            }
            if (c2<n)continue;
            printf("%d\n",c);
            break;
        }
    }
//    system("pause");
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
