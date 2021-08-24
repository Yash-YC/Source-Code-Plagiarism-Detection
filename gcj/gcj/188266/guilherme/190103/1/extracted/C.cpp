#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define all(v) (v).begin(),(v).end()
#define rall (v).rbegin(),(v).rend()

#define _foreach(it,b,e) for(__typeof__(b) it=(b);it!=(e);++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3ll;

long double ans[55];
int c,n;
long double escolhe(int a,int b)
{
  long double ret=1;
  if(b==0)return 1;
  if(b==a)return 1;
  for(int i=1;i<=a;i++)
    {
      ret=ret*i;
    }
  for(int i=1;i<=b;i++)
    {
      ret=ret/i;
    }
  for(int i=1;i<=a-b;i++)
    ret=ret/i;
  // printf("%d %d %lf\n",a,b,ret);

  return ret;
}

double solve (int a)
{
  // printf("%d\n",a);
  if(ans[a]<0)
    {
      double ret=0;
      for(int i=0;i<=min(a,n);i++)
	{
	  if(a+n-i==a)break;
	  if(a+n-i>c)continue;
	  
	  ret+=(1+solve(a+n-i))*(escolhe(a,i)*escolhe(c-a,n-i))/escolhe(c,n);
	}
      double t=1;
      if(n<=a)
	{
	  //printf("%lf\n,ret",ret);
	  t = escolhe(a,n)/escolhe(c,n);
	  ans[a]=ret/(1-t);
	  ans[a]+=t/(1-t);
	  //printf("%lf\n",t);
	}
      else
	{
	  ans[a] = ret;
	}    
    }
		       
  return ans[a];
}
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      scanf("%d %d",&c,&n);
      for(int i=0;i<c;i++)
	ans[i]=-1;
      ans[c]=0;
      printf("Case #%d: %.7lf\n",pp,solve(0));
      //ees printf("Case #%d: %.7lf\n",pp,solve(c-1));
    }
  return 0;
}
