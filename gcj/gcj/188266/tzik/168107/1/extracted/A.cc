

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct solver
{
  int base;
  map<int,bool> table;
  //set<int> cache;

  solver(int b):base(b)
  {
    table[1] = true;
  }

  int next(int n)
  {
    int res = 0;
    while(n)
    {
      res += (n % base) * (n % base);
      n /= base;
    }
    return res;
  }

  bool happy(int n)
  {
    map<int,bool>::iterator itr = table.find(n);

    //cout << "Checking " << n << " (" << base << ") ->" << next(n) << endl;

    //if(n==1)
      //return true;

    if(itr!=table.end())
      return itr->second;

    table[n] = false;
    //table.insert(make_pair(n,false));
    if(happy(next(n)))
      table[n] = true;
    return table[n];
  }
};

int main(int,char**)
{
  int T;
  cin >> T;

  {
    string line;
    getline(cin,line);
  }

  solver s[] = {0,1,2,3,4,5,6,7,8,9,10};

  for(int t=0;t<T;++t)
  {
    cout << "Case #" << (t+1) << ": ";

    string line;
    getline(cin,line);
    istringstream in(line);

    vector<int> base;
    {
      int i = 0;
      while(in >> i)
	base.push_back(i);
    }

    int c = 2;
    while(true)
    {
      for(vector<int>::iterator itr=base.begin(),end=base.end();itr!=end;++itr)
	if(!s[*itr].happy(c))
	{
	  //cout << c << "[" << s[*itr].base << "] miss" << endl;
	  goto next;
	}
      cout << c;
      break;
    next:
      ++c;
    }

    cout << "\n";
  }

  return 0;
}
