#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

typedef unsigned long long ll;
const ll one = 1;

bool isHappy(const ll num, const ll b)
{
  ll n = num;
  ll sum = 0, r = 0;
  set<ll> allChecked;
  do {
    while (n > 0) {
      r = n % b;
      n = n / b;
      sum += r*r;
    }
    if (sum == one || sum == b) return true; // sum = b means digits of 1 0
    if (allChecked.count(sum) > 0) return false;
    allChecked.insert(sum);
    n = sum;
    sum = 0;
  } while (true);
  return false;
}

ll findMin(vector<ll> &nums)
{
  ll i = 1;
  while (true) {
    ++i;
    bool happy = true;
    for (int j = 0; j < nums.size(); j++) {
      if (! isHappy(i, nums[j])) {
        happy = false; break;
      }
    }
    if (happy) return i;
  }
  return i;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <input file>\n";
    return 1;
  }
  ifstream fin(argv[1]);
  if (!fin) {
    cerr << "could not open " << argv[1] << endl;
    return 1;
  }

  int T;
  fin >> T >> ws;
  vector<ll> nums;
  char buf[1000];
  for (int i = 0; i < T; i++) {
    memset(buf, 0, 1000);
    nums.clear();
    fin.getline(buf, 1000);
    stringstream ss;
    ss << buf;
    while (! ss.eof()) {
      ll x;
      ss >> x;
      nums.push_back(x);
    }
    fin >> ws;
    cout << "Case #" << i+1 << ": " << findMin(nums) << endl;
  }
}
