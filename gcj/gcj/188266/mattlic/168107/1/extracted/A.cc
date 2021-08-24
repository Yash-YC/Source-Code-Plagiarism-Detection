
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

#define unsigned unsigned long long
#define COUT(x) cout << x << endl
#define forall(v, zero, end) for(unsigned v = zero; v < end; v++)

#define MAX 100000
int buffer[9][MAX];


using namespace std;

unsigned test(unsigned base, unsigned i)
{
  if (base == 0)
    return 42;

  assert(i > 0);
  if (i < MAX && buffer[base-2][i] != 0)
    return buffer[base-2][i];

  if (i == 1)
    return 1;

  unsigned s = 0;
  unsigned i_ = i;
  while (i_ >= 1)
  {
    assert(base != 0);
    unsigned m = i_ % base;
    s +=  m*m;
    i_ /= base;
  }

  if (i < MAX)
    buffer[base-2][i] = s;

  unsigned ret = test(base, s);
  if (i < MAX)
    buffer[base-2][i] = ret;
  return ret;
}

int main(int argc, char* argv[])
{
  ifstream input(argv[1]);

//     COUT(test(7, 143));
//     COUT(test(7, 143));
//     COUT(test(7, 143));
//     return 0;

  unsigned C;
  input >> C;
  char useless;
  input >> useless;

  forall(c, 0, C)
  {
    std::vector<unsigned> bases;
    string line;
    getline(input, line);
    stringstream ss(line);
    while (!ss.eof())
    {
      unsigned b;
      ss >> b;
      bases.push_back(b);
    }

    unsigned ret = 2;
    bool move = true;
    while(move)
    {
      move = false;
      forall(i, 0, bases.size())
      {
	unsigned b = bases[i];
	while (test(b, ret) != 1)
	{
	  move = true;
	  ret++;
	}
      }

      bool ok = true;
      for(unsigned i = 0; i <  bases.size(); i++)
      {
	if (test(bases[i], ret) != 1)
	  ok = false;
      }

      if (ok)
	break;
    }

    std::cout << "Case #" << (c+1) << ": " << ret << std::endl;
  }
}
