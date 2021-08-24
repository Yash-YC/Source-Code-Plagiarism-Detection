#include<iostream>
#include <sstream>
#include<conio.h>
using namespace std;

int sqr[10]={0,1,4,9,16,25,36,49,64,81},c=0;
int F[100001][11]={0};

int base(int n, int k)
{
    int x=0,p=1;
    while (n>=k)
    {
          x=(n%k)*p+x;
          n=n/k;
          p*=10;
    }
    x=n*p+x;
    return x;
}


int sum(int n,int k)
{
    int s=0;
    while (n>0)
    {
          s+=sqr[n%10];
          n/=10;
    }
    //printf("Base 10 Sum :%d %d\n",s,base(s,k));
    return base(s,k);
}

int check(int n,int k)
{
    while (c<100 && n!=1 && n>0)
    {
          n=sum(n,k);
          //printf("sum : %d\n",n);
          //getch();
          c++;
    }
    return n;
}

int main()
{
    freopen("A2.in","r",stdin);
    freopen("A2.out","w",stdout);
    int i,j,k,a[20],T,l,tp,FL;
    char str[100];
    
    for (i=2;i<100000;i++)
    {
        for (j=2;j<11;j++)
        {
            k=base(i,j);
            c=0;
            if (check(k,j)==1)
               F[i][j]=1;
            //printf("Base %d %d %d %d\n",i,j,k,F[i][j]);
            //getch();
        }
    }
    scanf("%d\n",&T);
    for (i=1;i<=T;i++)
    {
        gets(str);
        istringstream in(str);
        k=0;
        while (in>>tp)
              a[k++]=tp;
        for (j=2;;j++)
        {
            FL=1;
            for (l=0;l<k && FL==1;l++)
                if (F[j][a[l]]==0)
                   FL=0;
            if (FL==1)
            {
               printf("Case #%d: %d\n",i,j);
               break;
            }
        }
    }
}
