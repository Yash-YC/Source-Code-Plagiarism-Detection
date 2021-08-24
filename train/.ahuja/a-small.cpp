#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <assert.h>
#include <stack>
//#include <cstdLL>
#include <bitset>
#include <iomanip> // for std::setprecision()

using namespace std;

//typedef LL_fast64_t Li;
//typedef LL_fast32_t ll;
//typedef LL_fast8_t ii;
typedef long long LL;
typedef long l;

#define arjun main()
#define FOR(i,x,y) for(LL i = (x) ; i <= (y) ; ++i)
//typedef makepair mpr;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mpr(x,y) make_pair(x,y);

//const ll arrsz=2*10e9+1;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

//usage use a>=b>=0;
//Ifa≥b,then a mod b <a/2.
/**
 *If d divides both a and b, and d = ax + by for some integers x and y, then necessarily
 *d = gcd(a, b).
**/
LL findgcd(LL a,LL b) {
  if(b==0) return a;
  return findgcd(b,a%b);
}

/**
 * find the min of two numbers!
 */

LL minm (LL a, LL b) {
  return !(b<a)?a:b;     // or: return !comp(b,a)?a:b; for version (2)
}

/**
 * If p is prime, then for every 1 ≤ a < p,
 * pow(a,p−1) ≡ 1 (mod p). ---> (pow(a,p−1)-1)%p ==0
 */

LL primetest(LL a)
{
  for (size_t i = 2; i <= sqrt(a); i++) {
    if(a%i == 0) {
      return i;
    }
  }
  return 0;
}



/**
 * program for sorting an array in descending order
 * end here is the number of elements not the index
 */

LL* sort_descending(LL* array,LL start,LL end){
    sort(array+start,array+end+1,std::greater<LL>());
    return array;
}

/**
 *function similar to inbuilt max,finds maximum of two numbers
 */

LL maxm (LL a, LL b) {
    return !(b>a)?a:b;     // or: return !comp(b,a)?a:b; for version (2)
}

/**
 *function that calculates nCk using the property (n-1)C(k-1) + (n-1)Ck ,using dp
 */
LL nCk_dp_array[60][60] = {{0}};
LL nCk_dp_for_non_fixed_n_k (LL n, LL k) {
    nCk_dp_array[0][0] = 1;
    for (size_t i = 0; i <= n; i++) {
      for (size_t j = 0; j <=i; j++) {
        if (j == 0 || j==i) {
          nCk_dp_array[i][j] = 1;
        }
        else
        {
          nCk_dp_array[i][j] = nCk_dp_array[i-1][j-1]+nCk_dp_array[i-1][j];
        }
      }
    }
    return nCk_dp_array[n][k];
}

LL modular_exponential(LL base,LL exponent,LL modulus)
{
    LL result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

LL binary_decimal(LL n,int a) /* Function to convert binary to decimal.*/
{
    LL decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*(LL)pow(a,i);
        ++i;
    }
    return decimal;
}

LL primetest2(LL a,LL num,LL power)
{
  LL x;
  if(power>16)
  {
    x = 10000000000000000;
  }
  else x = pow(num,power)+a;
  for (size_t i = 2; i <= sqrt(a); i++) {
    if((a%i+modular_exponential(num,power,i))%i == 0) {
      return i;
    }
  }
  return 0;
}


template <typename Iter>
bool next(Iter begin, Iter end)
{
    if (begin == end)      // changed all digits
    {                      // so we are back to zero
        return false;      // that was the last number
    }
    --end;
    if ((*end & 1) == 0)   // even number is treated as zero
    {
        ++*end;            // increase to one
        return true;       // still more numbers to come
    }
    else                   // odd number is treated as one
    {
        --*end;            // decrease to zero
        return next(begin, end);   // RECURSE!
    }
}

int arjun
{
  LL t;
  cin>>t;
  LL count = 1;
  while(t--)
  {
    std::string s;
    cin>>s;
    LL x = s.length();
    std::string ans = "";
    ans+=s[0];
    for (size_t i = 1; i < x; i++) {
      if(s[i]>ans[i-1])
      {
        if(s[i]>=ans[0])
          ans = s[i]+ans;
        else ans+=s[i];
      }
      else ans+=s[i];
    }
    std::cout <<"Case #"<<count<<": "<< ans << std::endl;
    count++;
  }
  return 0;
}
