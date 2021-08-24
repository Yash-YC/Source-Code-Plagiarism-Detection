#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int MAX = 100000;

VVI happy;
VI answer;

int findnext(int num, int base)
{
  int value = 0;
  int k = num;
  while (k > 0)
    {
      int digit = k % base;
      value += digit*digit;
      k /= base;
    }
  return value;
}

int main()
{
  happy.resize(11);
  for (int base = 2; base <= 10; base++)
    {
      happy[base].resize(MAX);
      for (int k = 1; k < MAX; k++) happy[base][k] = -1;

      happy[base][1] = 1;
      for (int k = 2; k < MAX; k++)
	{
	  int num = k;
	  set<int> seq;
	  while (seq.count(num) == 0 && happy[base][num] < 0)
	    {
	      seq.insert(num);
	      num = findnext(num, base);
	    }
	  if (happy[base][num] >= 0)
	    happy[base][k] = happy[base][num];
	  else
	    happy[base][k] = 0;
	}
    }

  int T;
  cin >> T;
  string s;
  getline(cin, s);

  for (int c = 0; c < T; c++)
    {
      string s;
      getline(cin, s);
      istringstream iss(s);

      VI app(11);
      for (int i = 2; i <= 10; i++) app[i] = false;

      while (true)
	{
	  int base;
	  iss >> base;
	  if (!iss) break;
	  //cout << "getting base = " << base << endl;
	  app[base] = true;
	}

      int ans = 2;
      while (ans < MAX)
	{
	  bool ok = true;
	  for (int i = 2; i <= 10; i++)
	    if (app[i] && happy[i][ans] == 0)
	      {
		ok = false;
		break;
	      }
	  if (ok) break;
	  ans++;
	}

      if (ans == MAX) 
	{
	  cout << "MAX not enought" << endl;
	}     
      else
	{
	  cout << "Case #" << c+1 << ": " << ans << endl;
	}

    }

  return 0;
}
