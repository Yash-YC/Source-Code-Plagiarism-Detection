#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>
#include <iomanip>
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
uint32_t temp;

double ans;
int i, j, k;
int nCases;
int n, c;
double cardsCollected;
double cardsRemaining;
double num;
double total;
int deckBought;
bool done;

int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  fstream inFile(argv[1], fstream::in);
  fstream outFile("output.txt", fstream::out);

  inFile >> nCases;
  for0n(i, nCases) {
    ans = 0.0;
    deckBought = 0;
    cardsCollected = 0;

    inFile >> c >> n;
    num = (double)n;
    total = (double)c;
    cardsRemaining = c;

    if (n == c) {
      ans = 1.0;
    } else {
      // Get the first pack.
      ans = 1.0;
      cardsRemaining -= num;
      cardsCollected = num;

      done = false;
      while (!done) {
        // Expected cards per extra deck bought.
        double expected = num * (cardsRemaining/total);
#if 0
          ans += (1.0/expected);
          cardsRemaining -= 1.0;
          cardsCollected += 1.0;
#endif
        if (expected < 1.0) {
          if (cardsRemaining >= 1.0) {
            cout << "Buy " << (1.0/expected) << " packs for a card" << endl;
            ans += (1.0/expected);
            cardsRemaining -= 1.0;
            cardsCollected += 1.0;
          } else {
            ans += ((1.0/expected) * cardsRemaining);
            cardsRemaining = 0.0;
            cardsCollected = total;
          }
        } else {
          if (expected < cardsRemaining) {
            cout << "Buy a pack for " << expected << " cards" << endl;
            ans += 1.0;
            cardsRemaining -= expected;
            cardsCollected += expected;
          } else {
            // We just need a partial pack.
            // We shouldn't get here?
            cout << "We shouldn't get here?" << endl;
            ans += expected;
            cardsRemaining -= expected;
            cardsCollected += expected;
          }
        }
        if (cardsCollected >= total) {
          done = true;
        }
        cout << cardsRemaining << " cardsRemaining" << endl;
      }
    }


    outFile.precision(7);
    outFile.setf(ios::fixed,ios::floatfield);
    cout.precision(7);
    cout.setf(ios::fixed,ios::floatfield);
    cout << "Case #" << i+1 << ": " << ans << endl;
    outFile << "Case #" << i+1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
