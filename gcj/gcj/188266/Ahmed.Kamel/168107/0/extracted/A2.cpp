#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include<sstream>
#include<iostream>
#include<queue>
#include<set>
#include<map>

using namespace std;

#define clr(i,n) memset(i,n,sizeof(i))
#define fo(i,a) for(i=0;i<a;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz size()

typedef vector<int> vi;
typedef vector<string> vs;


//FILE *out=fopen("out.out","w");

int mask[5000000];
int RET[5000000],k,n,X;
map<int,bool> m;
long long hbest[1024];

long long base(long long n,int b)
{//printf("done*");
    long long ret=0;
    while(n)
    {
        ret*=10;//printf("%lld %d  *****\n",n,b);
        ret+=n%b;
        n/=b;
    }
    //printf("done*\n");
    return ret;
}

bool happy(long long h)
{//printf("%lld*\n",h);
    m.clear();
    long long x=h;
    while(1)
    {
        if(x==1)return 1;
        if(m[x])return 0;
        m[x]=1;
        long long y=0;
        while(x)
        {
            y+=(x%10)*(x%10);
            x/=10;
        }
        x=base(y,X);
    }
}

void solve(int ind,int mm,int l)
{
    if(ind==9)
    {
        if(RET[mm]==-1)
        {
            RET[mm]=k;
            if(l<4 && l!=0)n++;
        }
        return;
    }
    solve(ind+1,mm,l);
    if(mask[k]&(1<<ind))solve(ind+1,mm|(1<<ind),l+1);
    return;
}

int main()
{
    clr(RET,-1);
    n=0;
    k=2;
    while(n<129)
    {printf("%d %d\n",k,n);
        int j=0;
        mask[k]=0;
        for(int i=2;i<=10;i++)
        {
            X=i;
            long long h=base(k,i);
            //printf("%d: %lld\n",i,h);
            if(happy(h))
            {
                mask[k]|=(1<<j);
            }
            j++;
        }
        //printf("%d: ",k);
        //for(int i=0;i<8;i++)printf("%d",(bool)(mask[k]&(1<<i)));
        //printf("\n");
        if(RET[mask[k]]==-1)
            solve(0,0,0);
        k++;
    }
    //for(int i=0;i<512;i++)fprintf(out,"ret[%d]=%d;\n",i,RET[i]);
    freopen( "A-small-attempt1.in" , "r" , stdin );
    freopen( "A-small-attempt1.out" , "w" , stdout );
    
    int T;
    scanf("%d\n",&T);
    int i=1;
    while(T--)
    {
        int M=0;
        while(1)
        {
            int d,c;
            scanf("%d%c",&d,&c);
            M|=(1<<(d-2));
            if(c=='\n')break;
        }
        printf("Case #%d: %d\n",i,RET[M]);
        i++;
    }
    return 0;
}





/*


*/
























