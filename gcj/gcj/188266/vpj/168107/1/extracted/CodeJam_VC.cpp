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
int pre[2 << 11];

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
 int t = 1 << 9;
 pre[0] = 2;

 /*
 for(int m = 1; m < t; ++m)
 {
  int s;

  fr(i, 9)
   if((1 << i) & m)
    s = m - (1 << i);

  for(i = pre[s]; true; ++i)
  {
   fr(j, 9)
    if((1 << j) & m)
     if(!check(i, j + 2))
      break;

   if(j == 9)
    break;
  }

  pre[m] = i;

  fout << m << ' ' << i << endl;
  cout << m << ' ' << i << endl;
 }
 */

 int m = 0;

 fr(i, sz(bases))
  m |= 1 << (bases[i] - 2);

 fout << pre[m] << endl;
}

int main()
{
 int i;
 int NT;
 int n, m;

 ifstream fin("input.txt");
 ofstream fout("output.txt");
 ifstream data("data.txt");
 string ln;

 fr(i, (1 << 9) - 1)
 {
  data >> n >> m;
  pre[n] = m;
 }

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
