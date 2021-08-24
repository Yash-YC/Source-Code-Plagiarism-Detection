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
#define rng(x, b) (0 <= (x) && (x) < (b))

const int _my[] = {-1, 1, 0, 0};
const int _mx[] = {0, 0, -1, 1};
const int dir[] = {0, 0, 1, 1};

const int INF = 1 << 29;

int R, C;
int T[50][50];
int L[50][50][2];
int cyc[50][50];
int t[50][50][2][2];
bool v[50][50][2][2];

void read(ifstream &fin)
{
 int r, c;

 fin >> R >> C;

 fr(r, R) fr(c, C)
 {
  fin >> L[r][c][0] >> L[r][c][1] >> T[r][c];
  cyc[r][c] = L[r][c][0] + L[r][c][1];
  T[r][c] %= cyc[r][c];
 }
}

int getmt(int r, int c, int mt, int d)
{
 if(T[r][c] > mt)
 {
  if(T[r][c] <= L[r][c][1])
  {
   if(d == 1)
    return mt + 1;
   else
    return T[r][c] + 1;
  }

  int f = T[r][c] - L[r][c][1];

  if(d == 0)
  {
   if(mt < f)
    return mt + 1;
   else
    return T[r][c] + 1;
  }
  else
  {
   if(mt < f)
    return f + 1;
   else
    return mt + 1;
  }
 }

 int t0 = (mt - T[r][c]) % cyc[r][c];
 int t1 = mt - t0;

 if(d == 0)
 {
  if(t0 >= L[r][c][0])
   return t1 + cyc[r][c] + 1;
  else
   return mt + 1;
 }
 else
 {
  if(t0 < L[r][c][0])
   return t1 + L[r][c][0] + 1;
  else
   return mt + 1;
 }
}

void proc(ofstream &fout)
{
 int r, c, rr, cc;
 int i;

 _cl(v);

 fr(r, R) fr(c, C) fr(rr, 2) fr(cc, 2)
  t[r][c][rr][cc] = INF;

  t[R - 1][0][1][0] = 0;

 while(true)
 {
  int mt = INF;
  int mr = -1, mc = -1, mrr = -1, mcc = -1;

  fr(r, R) fr(c, C) fr(rr, 2) fr(cc, 2)
  {
   if(!v[r][c][rr][cc] && mt > t[r][c][rr][cc])
   {
    mt = t[r][c][rr][cc];
    mr = r, mc = c;
    mrr = rr, mcc = cc;
   }
  }

  r = mr, c = mc, rr = mrr, cc = mcc;

  if(r == -1)
   break;

  v[r][c][rr][cc] = true;

  fr(i, 4)
  {
   int nrr = rr + _my[i];
   int ncc = cc + _mx[i];
   int nr = r + _my[i];
   int nc = c + _mx[i];

   if(rng(nrr, 2) && rng(ncc, 2))
   {
    t[r][c][nrr][ncc] = min(t[r][c][nrr][ncc], getmt(r, c, mt, dir[i]));
   }
   else
   {
    if(_mx[i] == 0)
     nrr = !rr;
    else
     ncc = !cc;

    if(rng(nr, R) && rng(nc, C))
     t[nr][nc][nrr][ncc] = min(t[nr][nc][nrr][ncc], mt + 2);
   }
  }
 }

 fout << t[0][C - 1][0][1] << endl;
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
