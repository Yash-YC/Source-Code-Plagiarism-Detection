#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())

#define for0n(i,n) for(i=0;i<n;i++)
#define for1n(i,n) for(i=1;i<=n;i++)
#define forn(i,j,n) for(i=j;i<n;i++)

const int inf = 2100000000;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

uint32_t my32;
uint64_t modArr[3][3];
char line[50000];

int i, j, k, l, ans, ans2;
int nCases;
int d, n;
vector<int> bases;



int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  fstream inFile(argv[1], fstream::in);
  fstream outFile("output.txt", fstream::out);

  inFile >> nCases;
  cout << nCases << endl;
  for0n(i,nCases) {
    ans = 0;
    cout << "Case " << i + 1 << ": " ;
    memset(line, 0, sizeof(line));
    bases.clear();

    //inFile.getline(line, 50000);
    int curBase;
    char c;

    while(1) {
      inFile >> curBase;
      cout << curBase << " " << endl;
      bases.push_back(curBase);

      inFile.get(c);
      if (c == '\n')
        break;
    }
    cout << endl;

    // Start considering numbers.
    bool doneAll = false;
    bool done = false;
    bool allHappy = false;
    int value = 0;
    int oldvalue = 0;
    ans = 1;
    vector<int>::iterator it;
    set<int> tried;

    while (!doneAll) {
      ans++;
      tried.clear();
      allHappy = true;

      //cout << "Try " << ans << endl;
      for (it = bases.begin();
           it != bases.end();
           it++) {
        tried.clear();
        //cout << " with " << *it << endl;
        int temp = ans;
        value = ans;
        done = false;
        while (!done) {
          // Convert number to base... Get each digit separately.
          tried.insert(value);
          temp = value;
          value = 0;
          while (temp != 0) {
            value += ((temp%(*it)) * (temp%(*it)));
            //cout << " " << temp%(*it) << " " << ((temp%(*it)) * (temp%(*it))) <<  endl;
            temp /= *it;
          }
          //cout << value << endl;
          if (value==1) {
            //cout << ans << " happy with base " << *it << endl;
            done = true;
          //} else if ((value == ans) || (value == oldvalue)){
          } else if (tried.find(value) != tried.end()) {
            // endless loop...
            //cout << ans << " fails on base " << *it << endl;
            done = true;
            allHappy = false;
          } else {
            // Do again.
          }
        }

        if (allHappy && (it == bases.end())) {
          //cout << "** All happy" << endl;
          doneAll = true;
          break;
        } else if(!allHappy) {
          //cout << "someone unhappy" << endl;
          break;
        }
      } 
      if (allHappy) {
        doneAll = true;
      }
    }

    outFile << "Case #" << i+1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
