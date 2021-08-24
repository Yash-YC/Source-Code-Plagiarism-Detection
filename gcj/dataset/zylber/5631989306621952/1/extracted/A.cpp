#include <iostream>
#include <vector>
#include <cstdio>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
using namespace std;

int main()
{
#ifdef ACMTUYO
  freopen("A-large (1).in", "r", stdin);
  freopen("A-large (1).out", "w", stdout);
#endif

	int T;
  cin >> T;
  forn(tc,T)
  {
    string S;
    cin >> S;
    
    string result = "";
    for(int i=0; i<(int) S.size(); i++)
    {
      string r = S[i] + result;
      result = result + S[i];
      if(r>result) result = r;
    }
    cout << "Case #" << tc+1 << ": " << result << "\n";
  }
}
