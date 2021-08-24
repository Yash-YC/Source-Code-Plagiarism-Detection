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

void tryCircle(int start, vi & circles, const vi & bff)
{
    if (circles[start] != 0) return;

    int N = bff.size();
    vi vis(N);
    vis[start] = 1;
    int curr = start;
    int length = 1;
    while (true)
    {
        int next = bff[curr];
        if (vis[next])
        {
            if (next == start)
            {
                REP(i,N)
                {
                    if (vis[i])
                    {
                        circles[i] = length;
                    }
                }
                return;
            }
            else
            {
                return;
            }
        }

        vis[next] = 1;
        length++;
        curr = next;
    }
}

void tryLine(int start, vi & longestEndingIn, const vi & bff, const vi & pairs)
{
    if (pairs[start])
    {
        longestEndingIn[start] = max(1, longestEndingIn[start]);
        return;
    }

    int N = bff.size();
    vi vis(N);
    vis[start] = 1;
    int curr = start;
    int length = 1;

    while (true)
    {
        int next = bff[curr];
        if (pairs[next])
        {
            longestEndingIn[next] = max(longestEndingIn[next], length + 1);
            return;
        }

        if (vis[next])
        {
            return;
        }

        vis[next] = 1;
        length++;
        curr = next;
    }
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

    vi pairs(N);
    REP(i,N)
    {
        if (i == bff[bff[i]])
        {
            pairs[i] = 1;
            pairs[bff[i]] = 1;
        }
    }

    vi circles(N);
    REP(start, N)
    {
        if (pairs[start]) continue;

        tryCircle(start, circles, bff);
    }


    vi longestEndingIn(N);
    REP(start, N)
    {
        if (circles[start]) continue;

        tryLine(start, longestEndingIn, bff, pairs);
    }

    int res = 0;
    REP(i,N)
    {
        res += longestEndingIn[i];
    }

    REP(i,N)
    {
        res = max(res, circles[i]);
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
