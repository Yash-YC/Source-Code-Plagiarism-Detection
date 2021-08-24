// SAI [ 9 Aug 2009 ]
#include <stdint.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#include <InputReader.h>

class BaseN
{
private:
  std::string           _map;
  std::vector<uint64_t> _power;

public:
  BaseN(uint8_t b);
  ~BaseN();

  void initPower(uint32_t size);
  std::string convert(uint64_t num);
  uint64_t    convert(std::string num);
};

uint64_t expand(BaseN& b, std::string str);

int main(int argc, char * argv[])
{
  if (argc < 2) return 1;

  InputReader input(argv[1]);

  for (uint32_t i = 0; i < input.list.size(); i += 1)
  {
    InputReader::Entry * e = input.list.at(i);

    for (uint32_t num = 2; num < 0xffffffff; num += 1)
    {
      uint32_t result_count = 0;
      for (uint32_t j = 0; j < e->bases.size(); j += 1)
      {
        std::vector<uint32_t> rep;
        uint32_t base = e->bases.at(j);
        BaseN b(base);
        std::string str = b.convert(num);
        bool ok = false;
        //std::cout << "NUM " << num << std::endl;
        for (uint32_t k = 0; k < 0xffffffff; k += 1)
        {
          //std::cout << "base " << base << ", num " << str << std::endl;
          uint64_t n1 = expand(b, str);
          if (n1 == 1)
          {
            //std::cout << "ok" << std::endl;
            ok = true;
            break;
          }

          if (std::find(rep.begin(), rep.end(), n1) != rep.end())
          {
            //std::cout << "no ok " << n1 << " " << num << std::endl;
            break;
          }

          rep.push_back(n1);
          str = b.convert(n1);
        }
        //std::cout << "-------------- SIZE "  << e->bases.size() << std::endl;
        if (ok) result_count += 1;
      }
      //std::cout << "++++++++++ " << result_count << " " << e->bases.size()<< std::endl;
      if (result_count == e->bases.size())
      {
        std::cout << "Case #" << (i + 1) << ": " << num << std::endl;
        break;
      }
    }
  }

  return 0;
}

uint64_t 
expand(BaseN& b, std::string str)
{
  uint64_t ret = 0;
  for (int i = 0; i < str.length(); i += 1)
  {
    char ch = str.at(i);
    char tmp[2] = {ch, 0};
    uint64_t v = b.convert(tmp);
    ret += (v * v);
  }
  return ret;
}

BaseN::BaseN(uint8_t b)
{
  switch(b)
  {
    case  2: _map = "01"; break;
    case  3: _map = "012"; break;
    case  4: _map = "0123"; break;
    case  5: _map = "01234"; break;
    case  6: _map = "012345"; break;
    case  7: _map = "0123456"; break;
    case  8: _map = "01234567"; break;
    case  9: _map = "012345678"; break;
    case 10: _map = "0123456789"; break;
  }
}

BaseN::~BaseN()
{
}

void
BaseN::initPower(uint32_t size)
{
  if (_power.size() > 0) return;

  uint32_t base = _map.length();
  for(uint32_t i = 0; i < size; i += 1)
  {
    uint64_t p = pow(base, i);
    _power.push_back(p);
  }
}

typedef struct {
  uint32_t div;
  uint32_t rem;
}Result;

std::string
BaseN::convert(uint64_t num)
{
  uint32_t base = _map.length();


  std::stack<Result> stk;

  Result result;

  while (num >= base)
  {
    result.div = num / base;
    result.rem = num % base;

    num = result.div;
    stk.push(result);
  }

  if (num > 0)
  {
    result.div = 0;
    result.rem = num;
    stk.push(result);
  }

  std::string ret = "";
  while (stk.size() > 0)
  {
    Result r = stk.top();
    stk.pop();
    char tmp[2] = {0, 0};
    tmp[0] = _map.at(r.rem);
    ret.append(tmp);
  }

  return ret;
}

uint64_t
BaseN::convert(std::string num)
{
  uint32_t base = _map.length();

  std::vector<int> vList;
  for (uint32_t i = 0; i < num.length(); i += 1)
  {
    uint32_t v = 0;
    for (uint32_t j = 0; j < base; j += 1)
    {
      if (_map.at(j) == num.at(i))
      {
        v = j;
        break;
      }
    }
    vList.push_back(v);
  }

  if (_power.size() == 0)
    initPower(vList.size());

  uint64_t ret = 0;
  uint32_t len = vList.size() - 1;
  for(int32_t i = len; i >= 0; i -= 1)
  {
    ret += (vList.at(len - i) * _power.at(i));
  }
  return ret;
}

