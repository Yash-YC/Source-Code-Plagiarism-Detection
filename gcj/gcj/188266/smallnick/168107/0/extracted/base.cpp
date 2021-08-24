#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

vector<int> d;
int b;

void convert(int x) {
  d.clear();
  while (x > 0) {
    d.push_back(x%b);
    x/=b;
  }
}
set<int> stack;
bool happy() {
  if (d.size() ==1 && d[0]==1) {
    return true;
  }
  int t=0;
  for(int i=0;i <d.size();i++) {
    t+=d[i]*d[i];
  }
  if (stack.find(t) != stack.end()) {return false;}
  stack.insert(t);
  convert(t);
  return happy();
}

int main() {
  int T;
  cin>>T;
  string l;
  getline(cin, l);
  for(int t=1;t<=T;t++) {
    getline(cin, l);
    istringstream s(l);
    int x;
    vector<int> base;
    while(s>>x) {
      base.push_back(x);
    }
    int i=2;
    while(true) {
      bool h=true;
      for(int j=0;j<base.size();j++) {
        b=base[j];
        convert(i);
        stack.clear();
        stack.insert(i);
        if (!happy()) {h=false; break;}
      }
      if (h) {
        printf("Case #%d: %d\n", t, i);
        break;
      }
      i++;
    }
  }
  return 0;
}
