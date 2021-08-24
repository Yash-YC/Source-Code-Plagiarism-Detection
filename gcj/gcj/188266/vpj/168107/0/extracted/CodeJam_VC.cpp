#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define fr(i, n) for(i = 0; i < (n); i++)
#define fr2(i, s, n) for(i = (s); i < (n); i++)

typedef long long ll;
#define mp make_pair
typedef vector<int> VI;
typedef vector<string> VS;
typedef istringstream ISS;
typedef ostringstream OSS;
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

const int MAX = 1000;

VI bases;
bool v[MAX + 100];

void read(ifstream &fin)
{
 int n;
 string ln;

 getline(fin, ln);

 ISS is(ln);

 bases.clear();

 while(is >> n)
  bases.pb(n);
}

inline int sq(int x)
{
 return x * x;
}

bool check(int n, int b)
{
 _cl(v);

 while(n > 1)
 {
  if(n < MAX)
  {
   if(v[n])
    return false;

   v[n] = true;
  }

  int i = n;
  n = 0;

  for(; i > 0; i /= b)
   n += sq(i % b);
 }

 return true;
}

void proc(ofstream &fout)
{
 int i, j;

 for(i = 2; true; ++i)
 {
  fr(j, sz(bases)) if(!check(i, bases[j]))
   break;

  if(j == sz(bases))
   break;
 }

 fout << i << endl;
}

int main()
{
 int i;
 int NT;

 ifstream fin("input.txt");
 ofstream fout("output.txt");
 string ln;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  read(fin);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  proc(fout);
 }

 return 0;
}
