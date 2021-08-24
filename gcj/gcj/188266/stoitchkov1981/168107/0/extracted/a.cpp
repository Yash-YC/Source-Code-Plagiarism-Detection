#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int get_square (int data, int base) {
  int res = 0;
  while (data) {
    int last = data%base;
    data = data/base;
    res += last * last;
  }
  return res;
}

int three (int base) {
  return base * base * base;
}

vector<bool> find_happy (int base) {
  vector<bool> v1 (100000, 1), v2 (100000, 0);
  v1[1] = 1;
  v2[1] = 1;

  for (int i = 2; i < 100000; ++i) {
    if (!v2[i]) {
      set<int> myset;
      int j = i;
      while (j != 1 && myset.find (j) == myset.end ()) {
        v2[j] = 1;
        myset.insert (j);
        j = get_square (j, base);
      }
      
      if (j != 1)
        for (set<int>::iterator it = myset.begin (); it != myset.end (); ++it) {
          v1[*it] = 0;
        }
    }
  }
  return v1;
}

int main () {
  vector<bool> v[11];
  for (int i = 3; i <= 10; ++i)
    if (i!=4)
      v[i] = find_happy (i);
  int T;
  string s;
  getline (cin, s);
  istringstream (s) >> T;
  for (int no = 1; no <= T; ++ no) {
    getline (cin, s);
    vector<int> vb;
    int temp, pos = 0, nextpos;
    while ((nextpos = s.find (" ", pos))!=string::npos) {
      string temps = s.substr (pos, nextpos - pos);
      istringstream (temps) >> temp;
      if (temp != 2 && temp != 4)
        vb.push_back (temp);
      pos = nextpos + 1;
    }
    string temps = s.substr (pos, s.size () - pos);
    istringstream (temps) >> temp;
    if (temp != 2 && temp != 4)
      vb.push_back (temp);
    int i;
    for (i = 2; i < 100000; ++i) {
      bool is_happy = true;
      for (int j = 0; j < vb.size (); ++j)
        if (!v[vb[j]][i]) {
          is_happy = false;
          break;
        }
      if (is_happy)
        break;
    }
    cout << "Case #" << no << ": " << i << "\n";
  }
}
