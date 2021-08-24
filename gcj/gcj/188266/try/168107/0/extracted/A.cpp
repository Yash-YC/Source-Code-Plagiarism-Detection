#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAXB 9
#define MAXD 1000
#define LIMIT 1000000
using namespace std;

int base[MAXB+1],digit[MAXD+1];
char line[MAXD+1],mark[MAXD+1],*ptr;
int n;

char check(int b,int k)
{
    int i,l;
    memset(mark,0,sizeof(mark));
    l=0;
    while(k!=0)
    {
        digit[l++]=k%b;
        k=k/b;
    }
    while(1)
    {
        k=0;
        for(i=0;i<l;i++)
        {
            k=k+digit[i]*digit[i];
        }
        if(k==1)
        {
            return 1;
        }
        if(mark[k]==0)
        {
            mark[k]=1;
        }
        else
        {
            return 0;
        }
        l=0;
        while(k!=0)
        {
            digit[l++]=k%b;
            k=k/b;
        }
    }
    return 0;
}

char check(int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(check(base[i],k)==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i,k,t;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    gets(line);
    sscanf(line,"%d",&t);
    for(k=0;k<t;k++)
    {
        gets(line);
        ptr=strtok(line," \n");
        n=0;
        while(ptr!=NULL)
        {
            base[n++]=atoi(ptr);
            ptr=strtok(NULL," \n");
        }
        for(i=2;i<=LIMIT;i++)
        {
            if(check(i)==1)
            {
                break;
            }
        }
        printf("Case #%d: %d\n",k+1,i);
    }
    /*
    freopen("k.out","w",stdout);
    for(int i=1;i<=511;i++)
    {
        n=0;
        for(int j=0;j<MAXB-1;j++)
        {
            if((i&(1<<j))!=0)
            {
                base[n++]=j+2;
            }
        }
        int k;
        for(k=2;k<=LIMIT;k++)
        {
            if(check(k)==1)
            {
                break;
            }
        }
        printf("%d: %d\n",i,k);
    }
    */
    return 0;
}
