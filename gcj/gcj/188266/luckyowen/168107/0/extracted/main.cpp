#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
template <class T> void out(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
#define OUT(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  LL long long
#define  eps 1e-8
const int maxn = 100005,INF = 0x7fffffff;

int n,m;
bool flag[maxn*10];
int num[maxn],cp;
void change(int r,int x)
{
    cp=0;
    while(x)
    {
        num[cp++]=x%r;
        x/=r;
    }
}
int solve()
{
    int ans=0;
    for(int i=0;i<cp;i++)
       ans+=num[i]*num[i];
    return ans;
}
int r[15];
char str[100];
bool line;
inline void get(int &w)
{
  char c;int sum=0;bool flag=0;
  while((c=getchar())==' ') {} ;
  if(c=='-')  flag=1;
  else sum=c-'0';
  while((c=getchar())!=' '&&c!=10)
  {
    sum*=10;sum+=c-'0';
  }
  if(c==10) line=1;
  if(flag) w=-sum;
  else w=sum;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
//    change(3,10);
//    out(num,cp);
    cin>>T;int pre=0,c;
    getchar();
    for(t=1;t<=T;t++)
    {
//         OUT(t);
         c=0;line=0;
         while(!line) get(r[++c]);
//         out(r,c);
         for(i=2;i<maxn;i++)
         {
             bool ok=0;
             for(j=1;j<=c;j++)
             {
                 x=i;y=1;ok=0;
                 while(y<1005)
                 {
                     change(r[j],x);
                     x=solve();
                     if(x==1)  {ok=1;break;}
                     y++;
                 }
                 if(!ok)  break;
             }
             if(j>c) {printf("Case #%d: %d\n",t,i);break;}
         }
    }
    return 0;
}
