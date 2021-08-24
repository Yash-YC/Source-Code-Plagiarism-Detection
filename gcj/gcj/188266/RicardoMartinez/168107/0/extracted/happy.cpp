#include "iostream"
#include "set"
#include "vector"
#include "sstream"

using namespace std;

int sz;

inline int conver(int c, const int b) {
   int nc = 0;
   while (c > 0) {
      nc = 10*nc + c % b;
      c /= b;
   }
   return nc;
}

bool happy(int c, const int b) {
   if (c == 1 || b == 2 || b == 4) return true;

   set<int> seen;
   while (true) {
      int nc = conver(c, b);

      if (seen.find(nc) != seen.end()) return 0;
      seen.insert(nc);

      c = 0;
      while (nc > 0) {
         c += (nc % 10) * (nc % 10);
         nc /= 10;
      }

      if (c == 1) 
         return 1;
   }
}

bool valid(int c, const vector<int> &bases) {
   for (int i = 0; i < sz; i++) 
      if (!happy(c, bases[i]))
         return 0;
   return 1;
}

int main() {
   int T; cin >> T;
   int v;
   int res;
   string str; getline (cin, str);
   for (int C = 1; C <= T; C++) {
      getline (cin, str);
      vector<int> bases;
      stringstream ss(str);
      while (ss >> v) bases.push_back(v);
      sz = bases.size(); 
      res = -1;
      for (int c = 2; res == -1; c++)
         if (valid(c, bases)) 
            res = c;
      cout << "Case #" << C << ": " << res << endl;
   }
}

