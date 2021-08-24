#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool unhappy[20][1000];

int next(int i, int b)
{
  int n = 0;
  while (i)
    n += (i%b)*(i%b), i /= b;

  return n;
}

bool ishappy(int n, int b)
{
  int ns = n;
  while (n != 1 && (n >= 1000 || !unhappy[b][n]))
  {
    //printf("ishappy(%d, %d)\n", n, b);
    n = next(n, b);
  }

  return !unhappy[b][n];
}

void solve(int C)
{
  string line;
  getline(cin, line);
  istringstream sin(line);
  int base;
  vector<int> bases;

  while (sin >> base)
    bases.push_back(base);

  int n = 2;
  for (int n = 2; n < 12000000; n++)
  {
    //printf("%d\n", n);
    bool valid = true;
    for (int i = 0; i < (int)bases.size(); i++)
      if (!ishappy(n, bases[i]))
      { valid = false; break; }

    if (valid)
    {
      printf("Case #%d: %d\n", C, n);
      return;
    }
  }
}

int main()
{
  memset(unhappy, false, sizeof unhappy);

  unhappy[10][4] = true;
  unhappy[10][16] = true;
  unhappy[10][37] = true;
  unhappy[10][58] = true;
  unhappy[10][89] = true;
  unhappy[10][145] = true;
  unhappy[10][42] = true;
  unhappy[10][20] = true;

  unhappy[9][50] = true;
  unhappy[9][53] = true;
  unhappy[9][89] = true;
  unhappy[9][65] = true;
  unhappy[9][41] = true;
  unhappy[9][68] = true;
  unhappy[9][74] = true;

  unhappy[8][4] = true;
  unhappy[8][5] = true;
  unhappy[8][16] = true;
  unhappy[8][10] = true;
  unhappy[8][25] = true;
  unhappy[8][26] = true;
  unhappy[8][13] = true;
  unhappy[8][20] = true;
  unhappy[8][52] = true;


  unhappy[7][2] = true;
  unhappy[7][4] = true;
  unhappy[7][16] = true;
  unhappy[7][8] = true;
  unhappy[7][25] = true;
  unhappy[7][10] = true;
  unhappy[7][17] = true;
  unhappy[7][13] = true;
  unhappy[7][37] = true;
  unhappy[7][29] = true;
  unhappy[7][45] = true;
  unhappy[7][32] = true;


  unhappy[6][20] = true;
  unhappy[6][13] = true;
  unhappy[6][5] = true;
  unhappy[6][25] = true;
  unhappy[6][17] = true;
  unhappy[6][29] = true;
  unhappy[6][41] = true;
  unhappy[6][26] = true;

  unhappy[5][4] = true;
  unhappy[5][16] = true;
  unhappy[5][10] = true;
  unhappy[5][13] = true;
  unhappy[5][18] = true;

  unhappy[3][2] = true;
  unhappy[3][4] = true;
  unhappy[3][5] = true;
  unhappy[3][8] = true;
 
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 1; i <= n; i++)
    solve(i);
  return 0;
}
  
