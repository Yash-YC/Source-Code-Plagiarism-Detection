#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int _a;

#define FOR(i , n) for(int i = 0 ; i < n ; i++)
#define FOT(i , a , b) for(int i = a ; i < b ; i++)
#define GETINT (scanf("%d" , &_a) , _a)
#define pb push_back
#define mp make_pair
#define s(a) (int(a.size()))
#define PRINT(a) cerr << #a << " = " << a << endl

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int , int> PII;

map< PII , bool > m;

bool find(PII in) {
  if(m.count(in)) return m[in];
  else {
    m[in] = false;
    int sum = 0;
    int cur = in.first;
    int base = in.second;
    while(cur > 0) {
      sum += ((cur % base) * (cur % base));
      cur /= base;      
    }
    m[in] = find(PII(sum, base));
  }
  return m[in];
}


int main() {
  m.clear();
  for(int i = 2; i <= 10; i++) m[PII(1, i)] = true;  
  int tests;
  scanf("%d\n", &tests);
  FOT(t, 1, tests+1) {
    string ss;
    getline(cin, ss);
    vi v;
    istringstream in(ss);
    int num;
    while(in >> num) {
      v.pb(num);
    }
    int out;
    for(int i = 2; ; i++) {
      bool good = true;
      FOR(j, s(v)) if(find(PII(i, v[j])) == false) {
        good = false;
        break;
      }
      if(good) {
        out = i;
        break;
      }
      //      cerr << i << ' ';
    }
    cout << "Case #" << t << ": " << out << endl;
  }
  return 0;
}
