
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define unsigned unsigned long long
#define COUT(x) cout << x << endl
#define forall(v, zero, end) for(unsigned v = zero; v < end; v++)

using namespace std;
int main(int argc, char* argv[])
{
  ifstream input(argv[1]);

  unsigned C_;
  input >> C_;

  forall(c, 0, C_)
  {
    unsigned C, N;
    input >> C >> N;

    float x = N;
    unsigned n = 1;
    float rest;
    while (x < C)
    {
      rest = (float(float(C)-floor(x))/float(C)) * float(N);
      //      std::cout << rest << " "  << std::endl;
      x = x + rest;
      n++;
    }

    std::cout << "Case #" << (c+1) << ": " << float(n) - ((x - floor(x)) / rest) << std::endl;
  }
}
