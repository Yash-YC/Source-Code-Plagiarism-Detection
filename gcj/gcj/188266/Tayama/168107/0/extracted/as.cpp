#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>

#define REP(i,e) for(int i=0;i<(int)(e);i++)
#define FOR(i,b,e) for(int i=(int)(b);i<(int)(e);i++)
#define FORC(i,b,e,c) for(int i=(int)(b);i<(int)(e)&&(c);i++)
#define ALL(c) (c).begin(), (c).end()
#define EACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef vector<string> vstring;
typedef vector<double> vdouble;

template<class T>void pp(T v,int n){ REP(i,n)cout<<v[i]<< ' ' ; cout << endl;}
template<class T>void pp(T v){ EACH(it,v) cout << *it << ' ' ; cout << endl; }
template<class T>T& ls(T& a,T b){ if(b<a) a=b; return a;}
template<class T>T& gs(T& a,T b){ if(b>a) a=b; return a;}

const int N=11;
const int L=1000000;
bool result[N][L];

vint to_s(int n,int b){
  vint res;
  while(n) res.push_back(n%b), n/=b;
  return res;
}

bool ishappy(int n,int b){
  static bool done[L];
  memset(done,false,sizeof done);
  
  while(!done[n]){
    done[n]=true;
    int t=0;
    while(n) t+=(n%b)*(n%b), n/=b;
    n=t;
  }

  return n==1;
}

int main(){
  FOR(i,2,N) FOR(j,1,L) result[i][j]=ishappy(j,i);
  

//   FOR(j,2,L){
//     FOR(i,2,N) if(!result[i][j]) goto end2;
//     cout << "Max " << j << endl;
//   end2:;
//   }
  
  int Case; string s;
  cin >> Case; getline(cin,s);
  REP(C,Case){
    getline(cin,s);

    istringstream sin(s);
    vint v; int t;
    while(sin >> t) v.push_back(t);

    FOR(i,2,L){
      REP(j,v.size()) if(!result[v[j]][i]) goto end;
      printf("Case #%d: %d\n",C+1, i); break;
    end:;
    }

    //assert("NOT FOUND!"  && false);

  }
}
