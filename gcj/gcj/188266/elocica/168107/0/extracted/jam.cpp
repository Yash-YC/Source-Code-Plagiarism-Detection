#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <valarray>
#include <algorithm>
#include <map>
using namespace std;

long long k,n,m,a;

unsigned long long getNrLen(long long nr){
  unsigned long long digits = 1;
  while ( nr / 10 != 0){
    digits++;
    nr = nr/10;
  }
  return digits;
}

long long decToX(__int64 nr, __int64 base){
  __int64 result = 0;
  __int64 pos = 0;
  __int64 tmp;
  while (nr > 0){
    tmp = nr% base;
    nr = nr/base;
    result +=tmp*pow((double)10,(double)pos);
    pos++;
  }
  return result;
}

long long xToDec(__int64 nr, __int64 base){
  int pos = 0;
  long long result = 0;
  while (nr > 0){
    result+= (nr % 10)*pow(double(base), double(pos));
    nr/=10;
    pos++;
  
  }
  return result;
}



long long add(long long nr1, long long nr2, long base){
  long long d1 = xToDec(nr1, base);
  long long d2 = xToDec(nr2, base);
  return decToX(d1+d2, base);

}

long long mult(long long nr1, long long nr2, long base){
  long long d1 = xToDec(nr1, base);
  long long d2 = xToDec(nr2, base);
  return decToX(d1*d2, base);

}

bool happy(long long nr, int base, long long& result){
  long long tmp;
  result=0;
  //if (nr / 10 == 0){
  //  return nr == 1;
  //}
  //else
  {
    while (nr > 0){
      result=add(result, mult(nr%10, nr%10, base), base);
      nr/=10;
    }
    if (result == 1) return true;
    else return false;
    //else return happy(result, base);
  }

}

int main()
{
  ifstream f("A-small.in");
  ofstream g("result.out");


  f>>k;

  vector<vector<int> > bases;
  map <long long, map<int,bool> > happyNrs;

  //for (long long z=0; z<k; z++){
    int n=2, lastn=11;
    int i = -1, j = 0;
    
    string s;
    char tmps[255];
    bases.resize(k);
    f.getline(tmps,255);
    for (int i=0; i<k; i++){
      //f>>n;
      f.getline(tmps,255);
      s = tmps;

      
      while (s.size() > 0){
        int r = sscanf(s.c_str(), "%ld",&n);
        if (n ==10) r = 2;
        s= s.substr(min((int)r+1, (int)s.size()-1), s.size()-r);
        bases[i].push_back(n);
      }

    }

    for (long long i=0; i<bases.size(); i++){
      bool ok = false;
      long long nr = 2;
      while (!ok){
        ok = true;

        
        for (int j=0; j<bases[i].size(); j++){
          bool tmpok = false;
          long long tmpresult = decToX(nr,bases[i][j]);
          map<long long,bool> found;
          long long oldres =0;
          while (tmpresult!= 0 && !tmpok){
            tmpok=happy(tmpresult, bases[i][j], tmpresult);
            if (found.find(tmpresult) ==  found.end()) {
              found[tmpresult]=true;
            }
            else break;
          }
          ok = (ok && tmpok);
          if (!ok) break;
        }
        if (!ok) nr++;
      }
      g<<"Case #"<<i+1<<": "<<nr<<endl;

    }





    

  //}

  g.close();
  f.close();
  return 0;
}
