#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int T;
long base[10];
long minhappy;
char str[1000];
int index,numbers;

long calculate(long basenumber,long happy)
{
     long sum=0,later;
     while(happy!=0)
     {
         later=happy%basenumber;
         sum+=later*later;
         happy=happy/basenumber;
     }
     return sum;
}

bool testhappy(long basenumber,long happy)
{
     set<long> SET;
     set<long>::iterator it;
     long result;
     SET.clear();
     for(;;)
     {
         result=calculate(basenumber,happy);
         if(result == 1)
             return true;
         it=SET.find(result);
         if(it != SET.end())
             return false;
         else
         {
             SET.insert(result);
             happy=result;
         }
     }
}

int main()
{
    int i,j,k;
    bool flag;
    freopen("A-small.in","r",stdin);freopen("A-small.out","w",stdout);
    scanf("%d\n",&T);
    for(i=1;i<=T;i++)
    {
        gets(str);
        for(j=0;j<10;j++)
            base[j]=0;
        j=1;index=0;
        while(str[index])
        {
            if(str[index] == ' ')
            {
                index++;j++; 
                continue;
            }
            base[j]=base[j]*10+str[index]-'0';
            index++;
        }
        minhappy=1;
        numbers=j;
        do{
            minhappy++;flag=true;
            for(j=1;j<=numbers && flag;j++)
                flag=testhappy(base[j],minhappy);
            
        }while(flag == false);
        printf("Case #%d: %ld\n",i,minhappy);
    }
    fflush(stdout);
    return 0;
}
