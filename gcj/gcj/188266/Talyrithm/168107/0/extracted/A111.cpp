#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int a[11][100000];
int b[10];

int dfs(int base,int mark)
{
    int sum,test;
    test=mark;sum=0;
    while(test!=0)
    {
        sum+=(test%base)*(test%base);
        test/=base;
    }
    if(a[base][sum]==1) return 1;
    else if(a[base][sum]==2)
    {
        a[base][sum]=0;
        return 0;
    }
    else if(a[base][sum]==0) return 0;
    if(sum==1) return a[base][sum]=1;
    else
    {
        a[base][sum]=2;
        return a[base][sum]=dfs(base,sum);
    }
}

void fo()
{
    int base,i;
    memset(a,0xff,sizeof(a));
    for(base=2;base<=10;base++)
    {
        for(i=2;i<100000;i++)
        {
            if(a[base][i]==-1) 
            {
                a[base][i]=2;
                a[base][i]=dfs(base,i);
            }
        }
    }
    
}

int main()
{
    int t,i,j,k,mark,count=1;
    char d[100];
    char err;
    FILE *p,*in;
    p=fopen("out.txt","w");
    in=fopen("A-small-attempt2.in","r");
    fo();
    fscanf(in,"%d",&t);
    fscanf(in,"%c",&err);
    while(t--)
    {
        fgets(d,100,in);i=0;
        for(j=0;d[j]!='\0';j++)
        {
            if(d[j]>'1'&&d[j]<='9')
            {
                 
                 b[i]=d[j]-48;
                 i++;
            }
            if(d[j]=='1') 
            {
                     b[i]=10;
                     i++;
                     break;;
            }
            
        }                            
        for(j=2;j<100000;j++)
        {
            mark=1;
            for(k=0;k<i;k++)
            {
                if(a[b[k]][j]==0)
                {
                    mark=0;
                }
            }
            if(mark==1)
            {
                fprintf(p,"Case #%d: %d\n",count,j);
                count++;
                break;
            }
        }
    }
    fclose(p);
    fclose(in);
    return 0;
}
