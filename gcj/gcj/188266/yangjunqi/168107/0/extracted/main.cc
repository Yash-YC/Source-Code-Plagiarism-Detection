#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>
#include <iostream>

using namespace std;

bool is_happy(int i, int jz, set<int>& data_set ) 
{
  
  if (i == 1)
    return true;
 
  else {
    int sum = 0;
    int flag = i;
    while (true) {

      int temp = i % jz;
      sum += (temp * temp);
      i = i / jz;
      if (i < jz) {
        sum += (i*i);
         break;
      }
    }
    if (data_set.find(sum) != data_set.end())
      return false;
    else 
      data_set.insert(sum);

    
    
    is_happy(sum, jz, data_set);
  }

}

int sovle()
{
  vector<int> jinzhi;
  string line;
  
  getline(cin, line, '\n');

  stringstream converter;
  converter << line;
  while (!converter.eof()) {
    int i;
    converter >> i;
    jinzhi.push_back(i);
  }
  int result = 2;
  bool flag = true;
  while (true) {
    flag = true;
    for (vector<int>::iterator beg = jinzhi.begin();
      beg != jinzhi.end(); ++beg) {
        set<int> num_set;
        if (!is_happy(result, *beg, num_set)) {
          flag = false;
          break;
        }
    }
    if (flag)
      return result;
    ++result;
  }
}

int main()
{
  freopen("A-small-attempt0.in","r",stdin);
  freopen("output.txt","w",stdout);
  int Test;
  string input;
  getline(cin, input);
  stringstream strs;
  strs << input;
  strs >> Test;
  // cin >> 
  
  for (int i = 0; i < Test; i++) {    
    cout << "Case #"<< i + 1 <<": " << sovle() << endl;   
  }
  /*set<int> temp;
  is_happy(82, 10, temp);*/
  return 0;

  

}