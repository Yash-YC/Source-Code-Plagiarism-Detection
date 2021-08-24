#include <iostream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

bool happyfn(const int num, const int base) {
  int n = num;
  set<int> seen;
  seen.insert(num);
  while(1) {
    if (n == 1)
      return true;
    int sum = 0, oldn = n;
    while (n) {
      sum += (n%base) * (n%base);
      n = (n - n%base)/base;
    }
    if (oldn == sum || num == sum)
      return false;
    if (seen.find(sum) != seen.end())
      return false;
    seen.insert(sum);
    n = sum;
  }
}

int main() {
  int t;
  scanf(" %d\n", &t);
  int tcase = 1;
  while (t--) {
    string tmp;
    getline(cin, tmp);
    istringstream ss(tmp);
    vector<int> bases;
    while (ss) {
      int x;
      ss >> x;
      if (bases.size() && x == bases[bases.size()-1])
	break;
      bases.push_back(x);
    }
    int happy_num = 2;
    bool happy = false;
    while(!happy) {
      bool nothappy = false;
      for (int i = 0; i < bases.size(); ++i) {
	nothappy = !happyfn(happy_num, bases[i]);
	if (nothappy)
	  break;
      }
      if (nothappy) {
	happy_num++;
	continue;
      }
      break;
    }
    cout << "Case #" << tcase++ << ": " << happy_num << endl; 
  }
  return 0;
}
