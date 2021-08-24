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

string str(int n, int b){
  string s;
  do{
    const int d = n%b;
    s += d + '0';
    n/=b;
  }while(n);
  reverse(s.begin(), s.end());
  return s;
}

int reduce(int n, int b){
  int t(0);
  while(n){
    const int d = n%b;
    t += d*d;
    n/=b;
  }
  return t;
}

bool is_happy(int n, int b){
  vector<int> h;
  while(1){
    if(n==1){
      return true;
    }
    n = reduce(n, b);
    if(find(h.begin(), h.end(), n)!=h.end()){
      return false;
    }
    h.push_back(n);
  }
}

int solve(const vector<int>& bs){
  for(int n=2;;++n){
    bool st(true);
    for(int i=0;i!=bs.size();++i){
      if(!is_happy(n, bs[i])){
	st = false;
	continue;
      }
    }
    if(st){
      return n;
    }
  }
}

int main(int argc, char* argv[]){
  const int buf_size = 1024;
  char buf[buf_size];
  int T;
  cin >> T;
  cin.getline(buf, buf_size);
  for(int i=0;i!=T;++i){
    vector<int> bs;
    cin.getline(buf, buf_size);
    string str = string(buf);
    tokenizer<> tk(str);
    for(tokenizer<>::iterator it=tk.begin(); it!=tk.end(); ++it){
      bs.push_back(lexical_cast<int>(*it));
    }
    cout << "Case #" << i+1 << ": " << solve(bs) << endl;
  }
  
  return 0;
}
