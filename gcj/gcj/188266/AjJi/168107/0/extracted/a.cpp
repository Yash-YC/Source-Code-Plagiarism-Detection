#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) for(int i=0;i<(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}

void printvec(vector<int> a)
{
 cout<<"Vecteur:  ";
 REP(i,a.size()) cout<<a[i]<<"  ";
 cout<<endl;
}

string tobase(long long int a,int b)
{
 string s;
 do
 {
   int t;
   char c;
   t =  a%b;
   if(t>=10) c='A'+t-10;
   else c=t+'0';
   s.PB(c);
   a/=b;
   if(a==0)break;     
 }while(true);   
 reverse(ALL(s));
 return s;    
       
}

bool ishappy(string x, int base)
{
     string s = x;
     int k = 0;
     while(k++<80) {
         long long int xx = 0LL;
         REP(i,s.size())
         {
                        xx+=(long long) (s[i]-'0') * (long long) (s[i]-'0');               
         }     
         if( xx == 1 ) return true;
         
         s = tobase(xx, base);
     }
     return false;
}

int main()
{
   
   freopen("small-a.in","r",stdin);
   freopen("small-a.out","w",stdout);
   
   int kk;
   string s;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&kk);
   REP(k,kk)
   {
            vector<int> bases;
            getline(cin,s);
            stringstream st;
            st<<s;
            int btmp;
            while(st>>btmp) bases.PB(btmp);
            
            for(int i = 2;;i++)
            {
                    bool ok = true;
                    REP(j,bases.size())
                    {
                      string num = tobase(i, bases[j]);
                      if(!ishappy(num, bases[j])) { ok = false; break; }      
                    }                    
                    if(ok) {
                           printf("Case #%d: %d\n",k+1,i); break;       
                    }
            }
            

            
                     
   }


    getchar();
    return 0;
}
