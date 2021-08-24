#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

#define INF 0x3f3f3f3f

int bases[3];
int count;

int transform(int a, int base){
  int temp = a;
  int result = 0;
  while (temp){
    int temp2 = temp % base;
    result = result + temp2 * temp2;
    temp = (temp - temp2) / base;
  }
  return result;
}

bool naiveTrans(int a, int base){
  set<int> num;
  num.insert(a);
  int next = transform(a, base);
  while (next != 1){
    if (num.find(next) != num.end())
      return false;
    num.insert(next);
    next = transform(next, base);
  }
  return true;
}

bool naiveHappy(int a){
  for (int i = 0; i < count; ++i)
    if (!naiveTrans(a, bases[i]))
      return false;
  return true;
}

int naiveFindHappy(){
  for (int i = 2; i < INF; ++i)
    if (naiveHappy(i))
      return i;
  return -1;
}

int main(){
  int n; cin>>n;
  string str;
  getline(cin, str);
  for (int i = 1; i <= n; ++i){
    getline(cin, str);
    stringstream ss(str);
    int b;
    count = 0;
    while (ss>>b)
      bases[count++] = b;

    cout<<"Case #"<<i<<": "<<naiveFindHappy()<<endl;
  }
}
