#include <iostream>
#include <strstream>
#include <set>
#include <vector>

using namespace std;

typedef vector<unsigned short> DigitVector;

unsigned sumOfDigitSquaresInBase(unsigned number, unsigned short base)
{
  unsigned res = 0;

  while(number >= base)
  {
    unsigned modulo = number % base;
    res += modulo * modulo;
    number = number / base;
  }

  res += number * number;

  return res;
}

int main()
{
  int T = 0;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    DigitVector bases;

    char sep = 0;
    do
    {
      unsigned short base;
      cin >> base;

      bases.push_back(base);

      cin.get(sep);
    }
    while(sep != '\n' && !cin.eof());

    unsigned number;
    for (number = 2; ; ++number)
    {
      DigitVector::const_iterator itBase;
      for (itBase = bases.begin(); itBase != bases.end(); ++itBase)
      {
        unsigned sum = number;
        set<unsigned> prevSums;
        while (sum != 1 && prevSums.find(sum) == prevSums.end())
        {
          prevSums.insert(sum);
          sum = sumOfDigitSquaresInBase(sum, *itBase);
        }

//        std::cout << "base " << *itBase << " size of prevSums " << prevSums.size() << endl;

        if (sum != 1)
          break;
      }


      if (itBase == bases.end())
        break;
    }

    cout << "Case #" << (i + 1) << ": " << number << endl;
  }
  
  return 0;
}

