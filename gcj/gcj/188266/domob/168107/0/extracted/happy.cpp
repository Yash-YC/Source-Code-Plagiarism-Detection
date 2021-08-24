/* CodeJam solution happy in C++ by domob.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

typedef std::vector<int> basesArr;
typedef std::map<int, int> happyMap;

static basesArr bases;
static happyMap happyKnown[11];


/* Test if a number is happy in a given base.  */

static bool
isHappy (const int num, const int base)
{
  if (num == 1)
    return true;

  happyMap& hash (happyKnown[base]);

  happyMap::iterator inMap = hash.find (num);
  if (inMap != hash.end ())
    {
      // Already reached in series?
      if (inMap->second == -1)
        return false;

      // Already known.
      return inMap->second;
    }

  hash[num] = -1;

  int digsqsum = 0;
  int mynum = num;
  while (mynum > 0)
    {
      const int dig = mynum % base;
      digsqsum += dig * dig;
      mynum /= base;
    }

  const bool result = isHappy (digsqsum, base);
  hash[num] = result;

  return result;
}


/* Solve a single case.  */

static int
solve_case ()
{
  bases.clear ();

  char c;
  int offs;
  while (true)
    {
      c = getc (stdin);
      if (c == '\n')
        break;
      if (c == ' ')
        continue;

      if (c == '1')
        {
          offs = 10;
          c = getc (stdin);
        }
      else
        offs = 0;

      bases.push_back (offs + (c - '0'));
    }

  int res;
  for (res = 2; ; ++res)
    {
      for (basesArr::iterator i = bases.begin (); i != bases.end (); ++i)
        if (!isHappy (res, *i))
          goto continueOuter;

      break;
continueOuter:;
    }

  return res;
}


/* Main routine, handling the different cases.  */

int
main ()
{
  int n;

  scanf ("%d\n", &n);
  for (int i = 1; i <= n; ++i)
    printf ("Case #%d: %d\n", i, solve_case ());

  return EXIT_SUCCESS;
}
