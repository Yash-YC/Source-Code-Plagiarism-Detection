#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

//cout.precision(12);
//cout.setf( std::ios::fixed, std:: ios::floatfield );

const long long MOD = 1000000007LL;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;

template<class T> void printImpl(const vector<T> & coll) { copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " ")); cout << endl; }
template<class T, int N> void printImpl(T (&coll)[N]) { copy(coll, coll + N, ostream_iterator<T>(cout, " ")); cout << endl; }
template<class Key, class Value> void printImpl(const map<Key, Value> & data) { typename map<Key, Value>::const_iterator it; for (it = data.begin(); it != data.end(); ++it) { cout << it->first << ":" << it->second << endl; } }
template<class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

bool check(const vi & data, const vi & bff)
{
    int K = data.size();
    if (K < 2) return false;

    for (int i = 1; i < K - 1; ++i)
    {
        int curr = data[i];
        if (data[i+1] != bff[curr] && data[i-1] != bff[curr])
        {
            return false;
        }
    }

    int curr = data[0];
    if (data[1] != bff[curr] && data[K-1] != bff[curr])
    {
        return false;
    }
    curr = data[K-1];
    if (data[0] != bff[curr] && data[K-2] != bff[curr])
    {
        return false;
    }

    return true;
}

int solve()
{
    int N;
    cin >> N;
    vi bff(N);
    REP(i,N)
    {
        cin >> bff[i];
        bff[i]--;
    }

    int res = 0;
    for (int b = 1; b < (1 << N); ++b)
    {
        vi data;
        for (int i = 0; i < N; ++i)
        {
            if (b & (1 << i)) data.push_back(i);
        }

        do
        {
            if (check(data, bff))
            {
                res = max<int>(res, data.size());
            }
        } while (next_permutation(data.begin(), data.end()));
    }

    return res;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        cout << "Case #" << csIx << ": " << solve() << endl;
    }
    
    return 0;
}
