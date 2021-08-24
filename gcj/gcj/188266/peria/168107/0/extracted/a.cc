#include <sstream>
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

vector<int> flag(100000, 0);

void initFlag(int b)
{
  for( int i = 0 ; i < flag.size() ; ++i ) {
    flag[i] = 0;
  }
  flag[1] = 1;
}

int isHappy(int num, int b)
{
  int sum = 0;

  if( flag[num] > 0 ) return flag[num];

  flag[num] = num; // Flag that means to be checked
  for( int n = num ; n > 0 ; n /= b ) {
    int d = n % b;
    sum += d * d;
  }
  return (flag[num] = isHappy(sum, b));
}

int smallHappy(void)
{
  set<int> bases;
  int base;
  string str;

  getline(cin, str);
  istringstream is(str);
  while( is >> base ) { bases.insert(base);}

  int num = 2;
#if 1
  while( true ) {
    set<int>::iterator p;
    bool happy = true;
    for( p = bases.begin() ; p != bases.end() ; ++p ) {
      initFlag(*p);
      if( isHappy(num, *p) != 1 ) {
        happy = false;
        break;
      }
    }
    if( happy ) {
      return num;
    }
    ++num;
  }
#else
  set<int>::iterator p;
  while( p != bases.end() ) {
    initFlag(*p);
    cout << "check(" << num << "," << *p << ")\n";
    if( isHappy(num, *p) == 1 ) {
      ++p;
    } else {
      ++num;
      p = bases.begin();
    }
  }
#endif
  return num;
}

int main(void)
{
  int t;
  string str;
  cin >> t;
  getline(cin, str); // Trimming
  for( int ca = 1 ; ca <= t ; ++ca ) {
    cout << "Case #" << ca << ": " << smallHappy() << "\n";
  }

  return 0;
}
