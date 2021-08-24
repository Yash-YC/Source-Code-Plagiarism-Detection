#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

map<pair<int, int>, bool > memo;

char v[1000];
int sz;


void base(int a, int b) {
  int i = 0;
  while (a) {
    v[i] = (a%b); //+ '0';
    a/= b;
    i++;
  }
  sz = i;
}

int base10(string a, int b) {
  int k = 0;
  int p = 1;
  for (int i = 0; i < (int)a.size(); i++) {
    k += a[0]*p;
    p *= b;
  }
  return k;
}

bool checa(int a, int b) {
  pair<int,int> pa = make_pair(a,b);
  if (memo.find(pa) != memo.end()) return memo[pa];
  base(a,b);
  int sum = 0;
  for (int i = 0; i < sz; i++) {
    sum += v[i]*v[i];
  }
  bool r;
  if (sum == a || sum == 0) memo[pa] = false;
  if (sum == 1) return memo[pa] = true;
  return memo[pa] = checa(sum,b);
}

int main() {
  int k;
  scanf("%d",&k);
  getchar();
  for (int kk = 0; kk < k; kk++) {
    printf("Case #%d: ",kk+1);
    char ss[200];
    scanf(" %[^\n]s",ss);
    stringstream s(ss);
    int d;
    vector<int> bases;
    while (s >> d) bases.push_back(d);
    int i;
    for (i = 2;;i++) {
      bool ok = true;
      for (int j = 0; j < (int)bases.size(); j++) {
	if (!checa(i,bases[j])) {
	  ok = false;
	  break;
	}
      }
      if (ok) break;
    }
    cout << i << endl;
  }

  return 0;
}
