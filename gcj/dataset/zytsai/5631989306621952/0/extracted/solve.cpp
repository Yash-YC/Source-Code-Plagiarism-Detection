#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
   int T;
   cin >> T;
   do {
      string S = "", buf;
      cin >> S;
      for (int i = 0, len = S.length(); i < len; ++i) {
         if (i == 0) buf = S[0];
         else if (S[i] >= buf[0]) buf = S[i] + buf;
         else buf = buf + S[i];
         //cout << "   " << buf << endl;
      }
      cout << "Case #" << T << ": " << buf << endl;
   } while (--T > 0);
   return 0;
}