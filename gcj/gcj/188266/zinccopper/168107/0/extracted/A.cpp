#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
//const int MAXN=5000,MAXB=20;
//bool U[MAXN][MAXB];
//bool H[MAXN][MAXB];
int B[11],Bt;
int sqr(int x)
{
    return x*x;
}
bool S[1000];/*
bool InitHappy(int x)
{
     memset(S,0,sizeof(S));
     int y=0;
     while (true)
     {
           while (x!=0)
           {
                 y+=sqr(x%10);
                 x/=10;
           }
           x=y;
           y=0;
           if (S[x]) break; else S[x]=true;
     }
     return x==1;
}*/
bool Happy(int x,int base)
{
//     if (U[x][base]) return H[x][base];
//     U[x][base]=true;
     memset(S,0,sizeof(S));
     int y=0;
     while (true)
     {
           while (x!=0)
           {
                 y+=sqr(x%base);
                 x/=base;
           }
           x=y;
           y=0;
           if (S[x]) break; else S[x]=true;
     }
//     H[x][base]=(x==1);
     return x==1;
}
bool Check(int ans)
{
     for (int i=1;i<=Bt;i++)
         if (!Happy(ans,B[i]))
            return false;
     return true;
}
int main()
{
//    freopen("a.txt","r",stdin);
//    freopen("b.txt","w",stdout);
/*    for (int i=1;i<1000;i++)
        if (InitHappy(i))
           H[i]=true;*/
    int T;
    scanf("%d",&T);
    for (int Case=1;Case<=T;Case++)
    {
        Bt=0;
        while (true)
        {
               char c;
               scanf("%d%c",&B[++Bt],&c);
               if (c=='\n') break;
        }
        int ans=2;
        while (!Check(ans))
              ans++;
        printf("Case #%d: %d\n",Case,ans);        
    }
    return 0;
}
