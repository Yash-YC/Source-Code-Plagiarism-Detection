#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

namespace
{
   bool is_happy(int n, int b)
   {
      std::set<int> hist;
      while(n != 1 && hist.find(n) == hist.end())
      {
         hist.insert(n);
         int next = 0;
         while(n != 0)
         {
            int d = n % b;
            next += d * d;
            n /= b;
         }
         n = next;
      }
      return n == 1;
   }

   bool is_happy(int n, const std::vector<int> &bases)
   {
      for(std::vector<int>::const_iterator iter = bases.begin();iter != bases.end();++iter)
      {
         if(!is_happy(n, *iter))
         {
            return false;
         }
      }
      return true;
   }
}

int main(int argc, char **argv)
{
   (void)argc;
   (void)argv;
   int T;
   std::cin >> T;
   std::string line;
   std::getline(std::cin, line);
   for(int i = 0;i != T;++i)
   {
      std::vector<int> bases;
      std::getline(std::cin, line);
      std::istringstream is(line);
      int base;
      while(is >> base)
      {
         bases.push_back(base);
      }
      int j = 1;
      while(!is_happy(++j, bases))
      { }
      std::cout << "Case #" << (i + 1) << ": " << j << std::endl;
   }
   return 0;
}
