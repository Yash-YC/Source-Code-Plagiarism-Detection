// 打表的程序 
#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std; 
const int limit=1000000;
short v[limit+10];
vector <int> g[10000];
int S[50];
char st[100000];
int ans[2100];
void dfs(int k,int base)
{
    
    if (v[k]&(1<<base)) return ;

    v[k]|=(1<<base);
//        printf("-%d %d\n",k,v[k]);
    if (k>=10000) return; 
    for (vector <int>::iterator p=g[k].begin();p!=g[k].end();p++) dfs(*p,base);
}
int main()
{
//   freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int a[50];
    int b[11][50];
    memset(ans,0,sizeof(ans));
    memset(v,0,sizeof(v));
        memset(b,0,sizeof(b));
    for (int base=2;base<=10;base++)
    {
        memset(a,0,sizeof(a));
        a[1]=1;int s=1;

        memset(g,0,sizeof(g));

        for (int i=2;i<=limit;i++)
        {
            int j=1;
            while (a[j]==base-1) a[j]=0,j++,s-=(base-1)*(base-1);
            a[j]++;
            s=s-(a[j]-1)*(a[j]-1)+a[j]*a[j];
            //printf("%d %d\n",s,i);
            g[s].push_back(i);
            if (s>9999) printf("?");
        }
        memcpy(b[base],a,sizeof(a));
        dfs(1,base);
        S[base]=s;
    }
    int left=8;
    int tests=511;
    for (int t0=1;t0<=tests;t0++)
    {
  //      gets(st);
    //    istringstream is(st);

/*        int x=0,t;
        while (is>>t) 
        {
              x|=(1<<t);
        }*/
        int x=t0*4;
        printf("Case #%d: ",t0);
        for (int i=2;i<=limit;i++)
        {
            if ((x&v[i])==x) 
            {
                               printf("%d\n",i);
                               break;
            }
        }
    }

    for (int i=limit+1;;i++)
    {
//        if (i%10000000==0) printf("?");
        int x=0;
        for (int base=2;base<=10;base++)
        {
            int j=1;
            while (b[base][j]==base-1) b[base][j]=0,j++,S[base]-=(base-1)*(base-1);
            b[base][j]++;
            S[base]=S[base]+2*b[base][j]-1;//(b[base][j]-1)*(b[base][j]-1)+b[base][j]*b[base][j];
            if (v[S[base]]&(1<<base)) x|=(1<<base);
        }
        for (int p=504;p<=511;p++)
          if (ans[p*4]==0&&(x&(p*4))==p*4) 
          {
                   ans[p]=i,left--;
                   printf("Case #%d: %d\n",p,i);
          }
        if (left==0) break;
    }
    return 0;
}
