#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
map<pair<int,int>, bool> m;

string tobase(int v, int base) {
  string t;
  while (v) {
    int m = v % base;
    v /= base;
    t += (char)(m+'0');
  }
  return t;
}

int cnt = 0;
bool is_happy(int v, int base) {
  pair<int,int> p = make_pair(v,base);
  if (m.find(p)!=m.end()) return m[p];
  m[p] = false;
  int ans = true;

  string s = tobase(v, base);
  if (s != "1") {
    int t = 0; 
    for (int i = 0; i < s.length(); ++i) t+=(s[i]-'0')*(s[i]-'0');
    ans = (t == 1) || is_happy(t, base);
  }

  m[p] = ans;
  return ans;
}


int main() {
  int N;string t;
  cin>>N;cin.ignore();
  for (int k = 1; k <= N; ++k) {
    cout<<"Case #"<<k<<": ";
    getline(cin, t);
    stringstream ss(t);
    vector<int> v;
    int tt;
    while(ss>>tt) v.push_back(tt);
    for (int i = 2; ; ++i) {
      int j;
      for (j = 0; j <v.size(); ++j)
      if (!is_happy(i, v[j])) break;
      if (j == v.size()) {cout<<i<<endl;break;}
    }
  }
}
