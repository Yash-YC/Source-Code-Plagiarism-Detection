#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

unsigned int converttobase (unsigned int num, unsigned int base)
{
  unsigned int result = 0;
  unsigned int divisor = 1;
  while (divisor <= num) divisor *= base;
 
  while (divisor > 0)
  { 
    unsigned int digit = num / divisor; 
    result *= 10;
    result += digit;
    num -= (digit * divisor);
    divisor /= base;
  }

  return result;
}
    

unsigned int squaresum (unsigned int num)
{
    unsigned int result = 0;
    while (num > 0)
    {
       unsigned int digit = num % 10;
       result += (digit * digit);
       num /= 10;
    } 

   return result;
}

bool ishappy (unsigned int num, unsigned int base)
{
  unsigned int ss = num;
  std::vector<int> v;
  v.reserve(5);
  do
  {
    v.push_back(ss);
    ss = converttobase(ss, base);
    ss = squaresum(ss);
  } while (ss != 1 && find(v.begin(), v.end(), ss) == v.end());

  return ss == 1;
}

int main(void)
{
   unsigned int T;
   std::vector<int> v;
   v.reserve(9);
   std::string s;
   std::cin >> T; 
   std::cin.ignore();
   for (int c = 1; c <= T; c++)
   {
      // read all of the next line into v
      bool allhappy = false;
      unsigned int K = 1;
      unsigned int base = 2;
      std::getline(std::cin, s);
      std::istringstream is(s);
      int k;
      while (is >> k) v.push_back(k);
      while (!allhappy)
      {
        K++;
        allhappy = true;
        for (int i = 0; i < v.size() && allhappy; i++)
           allhappy &= ishappy(K, v[i]);
      }
      std::cout << "Case #" << c << ": " << K << std::endl;
      v.clear();
   }
}

