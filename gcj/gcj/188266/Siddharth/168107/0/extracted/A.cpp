
//Murugan Thunai !
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>  
using namespace std;

#define pb push_back
#define mp make_pair
#define v(x) vector< x >
#define sz size()
#define FOR(i, first, last) for (int i = (first); i != (last); ++i)
#define FORZ(i,n) FOR(i,0,n)
#define FORO(i,o) FORZ(i,((o).sz))
#define FOREACH(itr, x) for(__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr++)
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define ss stringstream
#define dbg(x) (cerr << #x << ": " << x<<'\n')
#define GI ({int t ; scanf("%d",&t);t;})
#define CLR(x, v) memset(x, v, sizeof(x));
typedef long long ll;
typedef unsigned long long ull;
typedef v(int) vi;
typedef v(vi) vvi;
typedef v(string) vs;
typedef v(vs) vvs;
typedef pair<int,int> ii;
typedef v(ii) vii;
char line[10000];
set<ii> vis;
map<ii, int>memo;
int isHappy(int num, int base)
{
  ii pp(num, base);
  if(vis.count(pp))
    return memo[pp];
  vis.insert(pp);
  if(num == 1)
    return memo[pp] = 1;
  int dum = num;
  int sum = 0;
  while(dum)
  {
    sum += (dum%base)*(dum%base);
    dum /= base;
  }
  return memo[pp] = isHappy(sum, base);
}
int main()
{
  //dbg(isHappy(91, 9));
  int T = GI;getchar();
  //dbg(T);
  FORZ(testcase, T)
  {
    printf("Case #%d: ", testcase  +1);
    scanf("%[^\n]", line);
    getchar();
    //dbg(line);
    stringstream S(line);
    vi bases;
    int tmp;
    while(S >> tmp)
      bases.push_back(tmp);
    map<int,int>dic;
    for(int i = 2;; i++)
    {
      int ok = 1;
      FORO(j, bases)
      {
        if(!isHappy(i, bases[j]))
        {
          ok = 0;
          break;
        }
      }
      if(ok)
      {
        printf("%d\n", i);
        break;
      }
    }
    //FORO(i, bases)dbg(bases[i]);
  }
	return 0;
}
//Powered by Siddharth
