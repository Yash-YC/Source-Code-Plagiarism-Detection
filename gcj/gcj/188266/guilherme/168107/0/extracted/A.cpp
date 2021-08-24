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

int ok[100000][500];
int foi[100000][500];
int lista[100];
int eh(int a,int b)
{
  foi[a][b]++;
  //printf("%d %d\n",a,b);
  if(ok[a][b]==-1)
    {
      //printf("oi\n");
      if(foi[a][b]==2)
	{
	  // printf("oi\n");
	  ok[a][b]=0;
	  return 0;
	}
      int x=0;
      int c=a;
      int y;
      int ret;
      while(c>0)
	{
	  y=c%b;
	  x+=y*y;
	  c=c/b;
	}
      //    printf("oi %d %d\n",a,x);
      ret=eh(x,b);
      ok[a][b]=ret;
    }
  return ok[a][b];
}
int main ()
{
  int tt;
  for(int i=2;i<100000;i++)
    for(int j=0;j<500;j++)
      {
	ok[i][j]=-1;
	ok[1][j]=1;
      }
  scanf("%d ",&tt);
  char buf[555];
  
  for(int pp=1;pp<=tt;pp++)
    {
      fgets(buf,555,stdin);
      stringstream o(buf);
      int a,qte=0;
      while(o >> a)
	{
	  lista[qte++]=a;
	  // printf("%d\n",a);
	}
      int ret=2;
      /* for(int i=0;i<qte;i++)
	printf("%d\n",lista[i]);*/
      while(1)
	{
	  // printf("%d\n",ret);
	  int flag=1;
	  for(int i=0;i<qte;i++)
	    if(eh(ret,lista[i])==0){flag=0;break;}
	  if(flag)break;
	  ret++;
	}
      // printf("%d\n",eh(6,7));
      printf("Case #%d: %d\n",pp,ret);
    }

  return 0;
}
