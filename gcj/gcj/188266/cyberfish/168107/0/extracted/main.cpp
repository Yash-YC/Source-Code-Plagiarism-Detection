#/* to compile, run this file in a bash shell (with apparent dependencies met)
g++ -g -O3 -ffast-math -Wall -march=native -o bin $0 lib/gnuplot_i.c lib/mt19937ar.c -lm && ./bin
exit
*/

/*	
	Solution by Matthew Lai (cyberfish) 
	My solutions may use -
		Boost (http://www.boost.org)
		GNU MP Bignum Library (http://gmplib.org)
		MPFR Library (http://www.mpfr.org)
		Mersenne Twister reference implementation 
		    (http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/MT2002/CODES/mt19937ar.c, with the main() function removed)
		
	Code contains reference to Gnuplot (http://www.gnuplot.info) used for debugging, and an ANSI C interface for it (http://ndevilla.free.fr/gnuplot/)

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <climits>

//#include <gmp.h>
//#include <gmpxx.h>

#include "lib/gnuplot_i.h"

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>

using namespace std;

typedef unsigned long long int uint64;
typedef signed long long int int64;

template <class T>
T max(T &a, T &b) { return (a > b) ? a : b; }
template <class T>
T min(T &a, T &b) { return (a > b) ? b : a; }
template <class T>
T xchg(T &a, T &b) { T t = a; a = b; b = t; }

int read_int(); /* read an int on its own line */
const char *read_line(); /* read a line from cin, return a char*, and leak ;) */

template <class T>
void dbg_print_vector(const string &id, const vector<T> &v, int start_idx = 0, int end_idx = -1);

/* from Mersenne Twister */
void init_genrand(unsigned long s);
unsigned long genrand_int32(void);
double genrand_real(void); /* [0, 1] */

void gen_primes(int64 a, int64 b, vector<int64> &v); /* generate all primes [a, b] and store them in v */

string int_to_string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

uint64 zobrist[50][50];

set<uint64> seen; /* hashes */

bool is_happy(int64 num, int base) {

    if (num == 1) return true;
    
    /* break it down */
    vector<int> digits;
    int64 new_num = 0;
    while (num) {
        int this_digit = num % base;
        new_num += this_digit * this_digit;
        digits.push_back(this_digit);
        num /= base;
    }
    
    sort(digits.begin(), digits.end());
    
    uint64 hash = 0;
    
    for (size_t i = 0; i < digits.size(); ++i) {
        hash ^= zobrist[i][digits[i]];
    }
    
    if (seen.find(hash) != seen.end()) {
        return false;
    }
    
    seen.insert(hash);
    
    return is_happy(new_num, base);
}

void docase(int64 case_number) {

    vector<int> bases;
    
    string line;
    
    getline(cin, line);
    
    line = string(" ") + line + " ";
    
    for (int i = 2; i <= 10; ++i) {
        if (line.find(" "+int_to_string(i)+" ") != string::npos)
            bases.push_back(i);
    }
    
    int64 this_try = 2;
    
    while (true) {
        bool happy = true;
        for (int i = 0; i < bases.size(); ++i) {
            //cout << "c " << this_try << " " << bases[i] << endl;
            seen.clear();
            if (!is_happy(this_try, bases[i])) {
            //cout << "n " << this_try << " " << bases[i] << endl;
                happy = false;
                break;
            }
        }
        //cout << this_try << endl;
        if (happy) break;
        this_try++;
    }

    cout << "Case #" << case_number << ": " << this_try << endl;
}

int main() {	
	int64 numcases;
	numcases = read_int();
	
	for (int i = 0; i < 50; ++i) {
	    for (int r = 0; r < 50; ++r) {
	        zobrist[i][r] = genrand_int32();
	        zobrist[i][r] <<= 25;
	        zobrist[i][r] ^= genrand_int32();
	    }
	}
	
	for (int64 i = 0; i < numcases; ++i) {
	    docase(i+1);
	}
}




int read_int() {
    string t;
    getline(cin, t);
    return atoi(t.c_str());
}

const char *read_line() {
    string* t = new string;
    getline(cin, *t);
    return t->c_str();
}

template <class T>
void dbg_print_vector(const string &id, const vector<T> &v, int start_idx, int end_idx) {
    if (end_idx == -1) end_idx = v.size() - 1;
    
    cout << id << "[" << start_idx << "-" << end_idx << "] ";
    
    for (size_t i = (size_t) start_idx; i <= (size_t) end_idx; ++i) {
        cout << v[i] << " ";
    }
    
    cout << endl;
}

void gen_primes(int64 a, int64 b, vector<int64> &v) { /* do the sieve */
    vector<bool> isPrime(b+1); /* using the bitfield specialization */
    int64 limit = sqrt(b) + 1;
    for (size_t i = 0; i < isPrime.size(); ++i) {  
        isPrime[i] = true;
    }
    
    isPrime[0] = isPrime[1] = false;
    
    for (size_t i = 2; i < isPrime.size(); ++i) {
        if (isPrime[i]) {
            if (i >= a && i <= b) v.push_back(i);
            if (i <= limit) {
                for (size_t r = i; r < isPrime.size(); r += i) {
                    isPrime[r] = false;
                }
            }
        }
    }
}

