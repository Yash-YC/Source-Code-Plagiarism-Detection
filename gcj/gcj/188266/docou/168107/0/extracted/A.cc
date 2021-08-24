#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cassert>

using namespace std;

typedef pair<pair<int,int>, int> triple;

int sq_sum(int n, int base) {
  int temp = 0;
  
  while (n > base-1) {
    temp+= (n%base)*(n%base);
    n = n/base;
  }
  temp+= (n*n);
  return temp;
}

bool happy(int n, int base) {
  //cout << "*" <<  n << " " << base << endl;
  set<int> t;
  if (n==1) return true;
  t.insert(n);
  
  int l = sq_sum(n,base);
  if (l==1) return true;
  set<int>::iterator p;
  p = t.find(l);
  while (p==t.end()) {
    t.insert(l);
    l = sq_sum(l,base);
    if (l==1) return true;
    p = t.find(l);
  }
  return false;
}


//bool happy(int n, int base) {
//set<int> seen
int main() {


  //cout << sq_sum(82,10) << endl;
  // cout << sq_sum(3,2) << endl;
  // cout << sq_sum(2,2) << endl;
  // if (happy(82,10)) cout << "This worked" << endl;

  int N;
  cin >> N;

  vector<int> bases;
  string temp;
  getline(cin,temp);
  for (int i10=0;i10<N;i10++) {
    string temp;
    getline(cin,temp);
    bases.resize(0);
    istringstream in1(temp);
    while (!in1.eof()) {
      int i;
      in1>> i;
      bases.push_back(i);
    }
    bool done = false;
    
    int n=2;
    while (!done) {
      int j;
      //cout << n << endl;
      for (j=0;j<bases.size();j++) {
	if (!happy(n,bases[j])) {
	  //cout << n << " NOT happy for " << bases[j] << endl;
	  
	  break;
	  
	} else {
	  //cout << n << " happy for " << bases[j] << endl;
	}
      }
      if (j==bases.size()) done = true;
      else n++;
    }
    cout << "Case #"<<(i10+1) <<": " << n << endl;
  
  }


  //}

}
