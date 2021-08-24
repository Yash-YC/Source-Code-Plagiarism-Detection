#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <assert.h>

using namespace std;
using namespace boost;

const double EPSILON = 1e-7;

long long comb(int n, int k){
  if(k>n)return 0;
  long long ret(1);
  for(long long i=n-k+1;i<=n;++i){
    ret *= i;
  }
  for(;k>0;--k){
    ret /= k;
  }
  return ret;
}

double solve(int C, int N){
  double ret(0);
  vector<vector<double> > pss(1);
  pss[0].resize(C+1, 0);
  pss[0][0] = 1;
  for(int t=1;;++t){
    pss.resize(t+1);
    pss.back().resize(C+1, 0);
    for(int m=0;m!=C;++m){
      for(int k=0;k<=N;++k){
	if(N-m <= k && k <= C-m){
	  const double pk = comb(C-m, k)/((double)(comb(C, N)))*comb(m, N-k);
	  const double p = pk*pss[t-1][m];
	  const int nm = min(C, m + k);
	  if(nm==C){
	    ret += t*p;
	  }
	  pss[t][nm] += p;
	}
      }
    }
    double e(0);
    for(int i=0;i!=C;++i){
      e += pss[t][i];
    }
    if(e < EPSILON){
      return ret;
    }
  }
}

int main(int argc, char* argv[]){
  int T;
  cin >> T;
  for(int i=0;i!=T;++i){
    int C, N;
    cin >> C >> N;
    cout << "Case #" << i+1 << ": " << solve(C, N) << endl;
  }
  
  return 0;
}
