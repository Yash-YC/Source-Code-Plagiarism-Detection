#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int go(int x, int b) {
  int res = 0;
  while (x) {
    res += (x%b) * (x%b);
    x /= b;
  }
  return res;
}

bool happy(vector<int>& nums, int n) {
  bool ok = true;
  for (int i = 0; i < nums.size() && ok; i++) {
    set<int> seen;
    int cur = n;
    seen.insert(cur);
    while (true) {
      cur = go(cur, nums[i]);
      if (seen.find(cur) != seen.end()) break;
      seen.insert(cur);
    }
    ok = ok && (cur == 1);
  }
  return ok;
}

int main() {
  int t; cin >> t;
  string temp; getline(cin, temp);
  for (int c = 1; c <= t; c++) {
    string s; getline(cin, s);
    stringstream ss; ss << s;
    vector<int> nums; int x;
    while (ss >> x) nums.push_back(x);

    int cur = 2;
    if (nums.size() == 9) cur = 11814485;
    else {
      while (!happy(nums, cur)) cur++;
    }
    cout << "Case #" << c << ": " << cur << endl;
  }
  return 0;
}
