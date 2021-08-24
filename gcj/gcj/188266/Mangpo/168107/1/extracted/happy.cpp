#include<stdio.h>
#include<stdlib.h>
//1000000000
int ans[9000000][10],base[10],num[1000];

int find(int n,int b)
{   int i,c=0,m;
    if(n==1)
    {   ans[n][b]=1;
        return 1;
    }
    if(ans[n][b]!=0) return ans[n][b];
    ans[n][b]=-1;
    m=n;
    while(m>0)
    {   num[c]=m%b;
        m/=b;
        c++;
    }
    m=0;
    for(i=0;i<c;i++)
    {   m+=num[i]*num[i];
    }
    ans[n][b]=find(m,b);
    return ans[n][b];
}

int main()
{   int t,l,i,j,k,num,c,n,re;
    char s[20];
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d\n",&t);
    for(l=0;l<t;l++)
    {   gets(s);
        i=0;
        c=0;
        while(s[i]!='\0')
        {   if(s[i]==' ') i++;
            base[c]=s[i]-'0';
            i++;
            if(s[i]=='0') 
            {   base[c]=10;
                i++;
            }
            c++;
        }
        for(n=2;n<1000000000;n++)
        {   
            for(i=0;i<c;i++)
            {   re=find(n,base[i]);
                if(re==-1) break;
            }
            if(i==c) break;
        }
        //if(n==1000000000) printf("more");
        printf("Case #%d: %d\n",l+1,n);
    }
    //system("pause");
    return 0;
}
