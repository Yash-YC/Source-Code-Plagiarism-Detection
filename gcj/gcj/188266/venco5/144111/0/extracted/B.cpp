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

const int INF = 999999999;
int N, M;
int ww[32][32];
int ss[32][32];
int tt[32][32];

struct State {
    int t, i, j, c;
    bool operator<(const State& s) const {
        if ( t != s.t ) return t < s.t;
        if ( i != s.i ) return i < s.i;
        if ( j != s.j ) return j < s.j;
        return c < s.c;
    }
};
int mt[32][32][4];
set<State> q;

void add(int t, int i, int j, int c)
{
    //TR(t|i|j|c);
    assert(unsigned(c) < 4);
    if ( unsigned(i) >= unsigned(N) || unsigned(j) >= unsigned(M) ||
         mt[i][j][c] <= t ) return;
    //TR(t|i|j|c);
    mt[i][j][c] = t;
    State s;
    s.t = t;
    s.i = i;
    s.j = j;
    s.c = c;
    q.insert(s);
}

int main()
{
    int num_cases = 1;
    cin >> num_cases >> skip_endl;
    forN ( nc, num_cases ) {
        cin >> N >> M >> skip_endl;
        forN ( i, N ) forN ( j, M ) {
            cin >> ss[i][j] >> ww[i][j] >> tt[i][j];
            tt[i][j] %= ss[i][j]+ww[i][j];
        }
        cin >> skip_endl;
        if ( !cin ) { cout << "failed read" << endl; return 1; }

        int ret = INF;
        memset(mt, 127, sizeof(mt));
        q.clear();
        add(0, N-1, 0, 2);
        while ( !q.empty() ) {
            State ps = *q.begin();
            q.erase(q.begin());
            int t = ps.t, i = ps.i, j = ps.j, c = ps.c;
            //TR(t|i|j|c);
            if ( i == 0 && j == M-1 && c == 1 ) {
                ret = t;
                break;
            }
            int s = ss[i][j], w = ww[i][j], t0 = tt[i][j], p = s + w, wt;
            //TR(s|w|t0|p);
            wt = ((t0-t)%p+p)%p;
            //TR(wt);
            if ( wt > w ) wt = 0;
            //TR(wt);
            if ( c & 2 ) {
                add(t+2, i+1, j, c^2);
                add(t+wt+1, i, j, c^2);
            }
            else {
                add(t+2, i-1, j, c^2);
                add(t+wt+1, i, j, c^2);
            }
            wt = ((t0+s-t)%p+p)%p;
            //TR(wt);
            if ( wt > s ) wt = 0;
            //TR(wt);
            if ( c & 1 ) {
                add(t+2, i, j+1, c^1);
                add(t+wt+1, i, j, c^1);
            }
            else {
                add(t+2, i, j-1, c^1);
                add(t+wt+1, i, j, c^1);
            }
        }
        //TR(ret);

        cout << "Case #"<<nc+1<<": ";
        cout << ret;
        cout << endl;
    }
}
