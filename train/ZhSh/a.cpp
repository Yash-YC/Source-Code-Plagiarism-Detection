#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <list>
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

string solve(const string & S)
{
    int N = S.length();
    char maxC = 'A';
    REP(i,N)
    {
        maxC = max(maxC, S[i]);
    }

    int maxCPosition = -1;
    REP(i,N)
    {
        if (S[i] == maxC)
        {
            maxCPosition = i;
            break;
        }
    }


    list<char> resList;
    if (maxCPosition != 0)
    {
        string prefix = S.substr(0, maxCPosition);
        string prefixMax = solve(prefix);
        for (int i = 0; i < maxCPosition; ++i)
        {
            resList.push_back(prefixMax[i]);
        }
    }

    for (int i = maxCPosition; i < N; ++i)
    {
        if (S[i] == maxC)
        {
            resList.push_front(S[i]);
        }
        else
        {
            resList.push_back(S[i]);
        }
    }

    string res(resList.begin(), resList.end());

    return res;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        string S;
        cin >> S;

        cout << "Case #" << csIx << ": " << solve(S) << endl;
    }
    
    return 0;
}
