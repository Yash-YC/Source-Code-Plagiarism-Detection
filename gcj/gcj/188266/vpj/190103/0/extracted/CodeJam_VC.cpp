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
#define fr(i, n) for(i = 0; i < (n); ++i)
#define fr2(i, s, n) for(i = (s); i < (n); ++i)

typedef long long ll;
#define mp make_pair
typedef vector<int> VI;
typedef vector<string> VS;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long double ld;
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

int C, N;
ld c[50][50];
ld p[50];

void read(ifstream &fin)
{
 fin >> C >> N;
}

void combinations()
{
 int i, j;

	for(i = 1; i <= C; i++)
	 c[i][0] = c[i][i] = 1;

	for(i = 2; i <= C; i++)
	 for(j = 1; j < i; j++)
	  c[i][j]=c[i - 1][j - 1] + c[i - 1][j];
}

void proc(ofstream &fout)
{
 _cl(p);

 combinations();

 for(int h = C - 1; h >= N; --h)
 {
  ld m = c[h][N] / c[C][N];
  m = 1 / (1 - m);

  p[h] = 1;

  int r = min(N, C - h);

  for(int i = 1; i <= r; ++i)
   p[h] += p[h + i] * c[h][N-i] * c[C-h][i] / c[C][N];

  p[h] *= m;
 }

 fout << setiosflags(ios::fixed) << setprecision(7) << p[N] + 1 << endl;
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
