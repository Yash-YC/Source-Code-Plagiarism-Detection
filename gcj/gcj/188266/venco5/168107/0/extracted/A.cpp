#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <sstream>
#include <iostream>
#include <iomanip>
#ifdef HOME_RUN
# include <debug.hpp>
# include <dump.hpp>
# include <cassert>
#else
# define TR(x) do{}while(0)
# ifdef assert
#  indef assert
# endif
# define assert(x) do{}while(0)
#endif
using namespace std;

#define ALL(C) (C).begin(), (C).end()
#define forIter(I,C) for(typeof((C).end()) I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;

inline istream& skip_endl(istream& in)
{
    string s;
    getline(in, s);
    forIter( i, s ) assert(isspace(*i));
    return in;
}

inline string get_str()
{
    string ret;
    getline(cin, ret);
    return ret;
}

map<string, int> str_index;
int get_index(const string& s)
{
    return str_index.insert(make_pair(s, str_index.size())).first->second;
}
int get_str_index()
{
    return get_index(get_str());
}

int b_min[512] = {
 2, 2, 3, 3, 2, 2, 3, 3, 5, 5, 
 23, 23, 5, 5, 23, 23, 6, 6, 79, 79, 
 6, 6, 79, 79, 49, 49, 79, 79, 49, 49, 
 79, 79, 7, 7, 143, 143, 7, 7, 143, 143, 
 7, 7, 143, 143, 7, 7, 143, 143, 49, 49, 
 2207, 2207, 49, 49, 2207, 2207, 49, 49, 2207, 2207, 
 49, 49, 2207, 2207, 8, 8, 27, 27, 8, 8, 
 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 
 216, 216, 3879, 3879, 216, 216, 3879, 3879, 1975, 1975, 
 3879, 3879, 1975, 1975, 3879, 3879, 1001, 1001, 5719, 5719, 
 1001, 1001, 5719, 5719, 1001, 1001, 5719, 5719, 1001, 1001, 
 5719, 5719, 47089, 47089, 47089, 47089, 47089, 47089, 47089, 47089, 
 48769, 48769, 58775, 58775, 48769, 48769, 58775, 58775, 3, 3, 
 3, 3, 3, 3, 3, 3, 27, 27, 27, 27, 
 27, 27, 27, 27, 415, 415, 707, 707, 415, 415, 
 707, 707, 415, 415, 1695, 1695, 415, 415, 1695, 1695, 
 125, 125, 143, 143, 125, 125, 143, 143, 125, 125, 
 143, 143, 125, 125, 143, 143, 2753, 2753, 37131, 37131, 
 2753, 2753, 37131, 37131, 37131, 37131, 37131, 37131, 37131, 37131, 
 37131, 37131, 27, 27, 27, 27, 27, 27, 27, 27, 
 27, 27, 27, 27, 27, 27, 27, 27, 4977, 4977, 
 10089, 10089, 4977, 4977, 10089, 10089, 4977, 4977, 23117, 23117, 
 4977, 4977, 23117, 23117, 6393, 6393, 35785, 35785, 6393, 6393, 
 35785, 35785, 6393, 6393, 128821, 128821, 6393, 6393, 128821, 128821, 
 569669, 569669, 569669, 569669, 569669, 569669, 569669, 569669, 569669, 569669, 
 569669, 569669, 569669, 569669, 569669, 569669, 7, 7, 13, 13, 
 7, 7, 13, 13, 7, 7, 23, 23, 7, 7, 
 23, 23, 44, 44, 79, 79, 44, 44, 79, 79, 
 49, 49, 79, 79, 49, 49, 79, 79, 7, 7, 
 167, 167, 7, 7, 167, 167, 7, 7, 7895, 7895, 
 7, 7, 7895, 7895, 49, 49, 6307, 6307, 49, 49, 
 6307, 6307, 49, 49, 7895, 7895, 49, 49, 7895, 7895, 
 97, 97, 219, 219, 97, 97, 219, 219, 219, 219, 
 219, 219, 219, 219, 219, 219, 608, 608, 3879, 3879, 
 608, 608, 3879, 3879, 3879, 3879, 3879, 3879, 3879, 3879, 
 3879, 3879, 34527, 34527, 48041, 48041, 34527, 34527, 48041, 48041, 
 34527, 34527, 120407, 120407, 34527, 34527, 120407, 120407, 245035, 245035, 
 697563, 697563, 245035, 245035, 697563, 697563, 245035, 245035, 2688153, 2688153, 
 245035, 245035, 2688153, 2688153, 91, 91, 91, 91, 91, 91, 
 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 
 1033, 1033, 6073, 6073, 1033, 1033, 6073, 6073, 4577, 4577, 
 6073, 6073, 4577, 4577, 6073, 6073, 1337, 1337, 1337, 1337, 
 1337, 1337, 1337, 1337, 29913, 29913, 120149, 120149, 29913, 29913, 
 120149, 120149, 71735, 71735, 613479, 613479, 71735, 71735, 613479, 613479, 
 218301, 218301, 711725, 711725, 218301, 218301, 711725, 711725, 1177, 1177, 
 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 1177, 
 1177, 1177, 1177, 1177, 9867, 9867, 28099, 28099, 9867, 9867, 
 28099, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 28099, 
 48041, 48041, 48041, 48041, 48041, 48041, 48041, 48041, 246297, 246297, 
 346719, 346719, 246297, 246297, 346719, 346719, 2662657, 2662657, 4817803, 4817803, 
 2662657, 2662657, 4817803, 4817803, 11814485, 11814485, 11814485, 11814485, 11814485, 11814485, 
 11814485, 11814485
};

const int MAX = (1<<24)-20;
char hh[11][MAX+20];
short pd[11][MAX+20];
short hx[MAX+20];

inline int get_happy(int b, int v)
{
    char& r = hh[b][v];
    //TR(b|v|int(r));
    assert(v > 0 && v < MAX);
    if ( r >= 0 ) return r;
    if ( r == -2 ) return r = 0;
    int d = v%b, n = v/b;
    int sum = d*d;
    if ( pd[b][n] >= 0 )
        sum += pd[b][n];
    else {
        while ( n ) {
            d = n%b;
            sum += d*d;
            n /= b;
        }
    }
    assert(sum > 0 && sum < MAX);
    pd[b][v] = sum;
    //TR(b|v|sum);
    if ( sum == v ) return r = 0;
    if ( hh[b][sum] >= 0 ) return r = hh[b][sum];
    r = -2;
    r = get_happy(b, sum);
    TR(b|v|int(r));
    return r;
}

inline int sum(int b, int v)
{
    int ret = 0;
    while ( v ) {
        int d = v%b;
        ret += d*d;
        v/=b;
    }
    return ret;
}

void make_happy(int b)
{
    int cnt = 0;
    memset(hh[b], -1, sizeof(hh[b]));
    memset(pd[b], -1, sizeof(pd[b]));
    hh[b][0] = 0;
    hh[b][1] = 1;
    pd[b][0] = 0;
    pd[b][1] = 1;
    forNF ( i, 2, MAX ) {
        if ( i > 100000 && i%b == 0 ) {
            static int dd[20];
            forN ( j, b ) dd[j] = j*j;
            int ib = i/b;
            for ( ; i < MAX; i += b, ++ib ) {
                int sum0 = pd[b][ib];
                for ( int j = 0; j < b; ++j ) {
                    int sum = sum0 + dd[j];
                    pd[b][i+j] = sum;
                    assert(sum == ::sum(b, i+j));
                    cnt += hh[b][i+j] = hh[b][sum];
                }
            }
            break;
        }
        cnt += get_happy(b, i);
    }
    TR(b|cnt);
}

void init_table()
{
    forNF ( b, 2, 11 ) {
        int mask = 1<<(b-2);
        make_happy(b);
        forNF ( i, 2, MAX ) {
            assert(hh[b][i] >= 0);
            if ( hh[b][i] )
                hx[i] |= mask;
        }
    }
    memset(b_min, 0, sizeof(b_min));
    forNF ( i, 2, MAX ) {
        forN ( bb, 512 ) {
            if ( !b_min[bb] && (bb&hx[i]) == bb ) {
                b_min[bb] = i;
            }
        }
    }
    forN ( i, 512 ) {
        cout << b_min[i] << ", ";
        if ( i % 10 == 9 ) cout << '\n';
    }
    cout << endl;
}

int main()
{
    //init_table();

    int num_cases = 1;
    cin >> num_cases >> skip_endl;

    if ( 0 ) {
        memset(hh, -1, sizeof(hh));
        memset(pd, -1, sizeof(pd));
        forNF ( b, 2, 11 ) {
            hh[b][0] = 0;
            hh[b][1] = 1;
            pd[b][0] = 0;
            pd[b][1] = 1;
        }
        TR(get_happy(7,17972));
    }

    forN ( nc, num_cases ) {
        istringstream str(get_str());
        int bb = 0;
        int b;
        while ( str >> b ) {
            assert(b >= 2 && b <= 10);
            bb |= 1<<(b-2);
        }
        assert(bb < 512);
        str.clear();
        if ( !cin ) { cout << "failed read" << endl; return 1; }

        int out = b_min[bb];
        forNF ( v, 2, 40000 ) {
            forNF ( b, 2, 11 ) {
                if ( bb & (1<<(b-2)) ) {
                    if ( !get_happy(b, v) )
                        goto bad;
                }
            }
            out = v;
            break;
        bad:;
        }
        forNF ( b, 2, 11 ) {
            if ( bb & (1<<(b-2)) ) {
                TR(b|out);
                int n = out;
                while ( n > 1 ) {
                    n = sum(b, n);
                    TR(b|n);
                }
            }
        }

        cout << "Case #"<<nc+1<<": ";
        cout << out;
        cout << endl;
    }
}
