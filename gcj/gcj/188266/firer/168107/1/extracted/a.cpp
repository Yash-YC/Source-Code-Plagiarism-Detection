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
#define rall(v) (v).rbegin(),(v).rend()
#define _foreach(it, b, e) for(__typeof__(b) it = (b); it != (e); ++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3fll; // sao dois L's!!!
const double eps = 1e-9;

// em caso de emergencia
#define _inline(f...) inline f() __attribute__((always_inline)); f

int hap[15][30000000]; // happy = 1, not happy = 2
//bool seen[15][1000000];

bool ishap(int n, int b)
{
  if(hap[b][n] != 0)
    return hap[b][n] == 1 ? true : false;
  hap[b][n] = 2;
  int s = 0;
  int nn = n;
  while(nn > 0)
    {
      int x = nn % b;
      s += x * x;
      nn /= b;
    }
  if(ishap(s, b))
    hap[b][n] = 1;
  return (hap[b][n] == 1) ? true : false;
}

char buf[1000];
vector<int> bs;

int main()
{
  int ntests;
  scanf(" %d ", &ntests);

  for(int i=0; i<15; ++i)
    hap[i][1] = 1;

  for(int test = 1; test <= ntests; ++test)
    {
      fgets(buf, 1000, stdin);
      istringstream ss(buf);
      bs.clear();
      int asdf;
      while(ss >> asdf)
	bs.push_back(asdf);
      
      for(int i=2; i<30000000; ++i)
	{
	  bool flag = false;
	  for(int j=0; j<int(bs.size()); ++j)
	    if(!ishap(i, bs[j]))
	      {
		flag = true;
		break;
	      }
	  if(!flag)
	    {
	      printf("Case #%d: %d\n", test, i);
	      break;
	    }
	}
    }
  return 0;
}
