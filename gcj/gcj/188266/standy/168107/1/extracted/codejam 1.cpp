#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <cmath>
#include <numeric>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#define MST(G, x) memset(G,x,sizeof(G))
#define FOR(i, a, b) for(i=a; i<b; i++)
#define _FOR(i, a, b)  for(i=a; i>=b; i--)
#define Max 1000
#define Inf 12000000

using namespace std;

bool vst[Max];
bool ok[11][Max];
int base[13];

bool solve(int k, int n)
{  
   if(ok[k][n])  return 1;
   
   if(vst[n])  return 0;
   
   vst[n] = 1;
   
   int tmp = 0;
   while(n > 0)
     tmp += (n%k)*(n%k), n /= k;
   
   if(solve(k, tmp))  ok[k][tmp] = 1;// cout <<  "k  " << k << "  n  " << tmp << endl;
   
   return ok[k][tmp];
       
}

void Init()
{
   int i, j;

   FOR(i, 2, 11)
   {
      MST(vst, 0);
      ok[i][1] = 1;
      
      FOR(j, 2, Max)
        if(solve(i, j))  ok[i][j] = 1;// cout << endl;  
   }
}



int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("1Large.out", "w", stdout);

    Init();
    
    int i, j, k; 
    int N, T, cas = 0;
    
    cin >> T;
    getchar();
    
    while(T --)
    {
       char ch;
       MST(base, 0);
       N = 0;
       while(ch = getchar(), ch != '\n')
       {
          if(ch == ' ')  N ++;
          
          else
            base[N] = base[N]*10 + ch - '0';  
       }
       
       N ++;
       
       FOR(i, 2, Inf)
       {
          FOR(j, 0, N)
          {
             if(base[j] == 2 || base[j] == 4)
               continue ;
               
             int tmp = 0;
             int n = i;
             k = base[j];
             while(n > 0)
               tmp += (n%k)*(n%k), n /= k; 
               
          //   cout << k << "  " << tmp << endl;
             
             if(!ok[k][tmp])  break;
          }

          if(j == N)
          {
             printf("Case #%d: %d\n", ++cas, i);
             break;  
          }    
       } 
    }
    
    
    
                 
  //  while(1);
    return 0;
}


/*

5 10 9 8 7 6     2662657
6 10 9 8 7 6 5   11814485
7 10 9 8 7 6 5 4  11814485
8 10 9 8 7 6 5 4 3   11814485
9 10 9 8 7 6 5 4 3 2

*/
