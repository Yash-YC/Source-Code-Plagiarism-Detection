#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define forn(i,n) for(int i = 0; (i) < (int) (n); i++)
using namespace std;

int cant[5000];

int main()
{
#ifdef ACMTUYO
  freopen("B-small-attempt0 (1).in", "r", stdin);
  freopen("B-small-attempt0 (1).out", "w", stdout);
#endif

	int T;
  cin >> T;
  forn(tc,T)
  {
	int n;
	cin >> n;
	memset(cant, 0, sizeof(cant));
	for(int i=0; i<(2*n-1)*n; i++)
	{
		int a;
		cin >> a;
		cant[a]++;
	}
	
    cout << "Case #" << tc+1 << ":";
    forn(i, 5000) if(cant[i]%2) cout << " " << i;
    cout << "\n";
  }
}
