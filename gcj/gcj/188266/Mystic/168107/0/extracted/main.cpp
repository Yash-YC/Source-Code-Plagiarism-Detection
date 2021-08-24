#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("file.out");

map <pair<int, int>, bool> happy;

bool isHappy(int num, int base) {
  if(happy.find(make_pair(num, base)) != happy.end())
    return happy.find(make_pair(num, base))->second;
  happy[make_pair(num, base)] = false;
  int res = 0;
  int n = num;
  while(n != 0) {
    int cur = n%base;
    res += cur*cur;
    n /= base;
  }
  if(isHappy(res, base))
    return happy[make_pair(num, base)] = true;
  else
    return happy[make_pair(num, base)] = false;
}

int main() {
  for(int base = 2; base < 11; base++)
    happy[make_pair(1, base)] = true;
  int T;
  fin >> T;
  string str;
  getline(fin, str);
  for(int i = 0; i < T; i++) {
    vector<int> bases;
    string str;
    getline(fin, str);
    istringstream input(str);
    int temp = 0;
    while(input >> temp)
      bases.push_back(temp);
    int result = 1;
    bool b = false;
    while(!b) {
      b = true;
      result++;
      //cout << result++ << endl;
      for(int j = 0; j < bases.size(); j++)
        b = b && isHappy(result, bases[j]);
    }
    fout << "Case #" << i+1 << ": " << result << endl;
  }
}
