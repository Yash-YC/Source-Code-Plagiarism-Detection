#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <cstdio>
#include <cassert>
#include <cmath>

#if defined (__GNUC__) && (__GNUC__ <= 2)
#include <hash_map>
#include <hash_set>
#else
#include <ext/hash_map>
#include <ext/hash_set>
using namespace __gnu_cxx;
#endif
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
LL s2i(string s) { istringstream i(s); LL x; i>>x; return x; }
template<class T> string i2s(T x) { ostringstream o; o << x; return o.str(); }

#define pi acos(-1.)
#define eps 1e-7
#define inf 1000000000
#define maxn 12000000
#define maxp 1100000

//ifstream fin("data.in");
//#define cin fin

int H[maxn][11];
vector<int> v;

int f(int n,int b) {
    int& ret = H[n][b];
    if(ret==-1) {
        ret = -2;
        int sum = 0;
        while(n) {
            int a = n%b;
            sum += a*a;
            n/=b;
        }
        ret = f(sum,b);
    }
    else if(ret==-2) {
        if(n==1) ret = 1;
        else ret = 0;        
    }
    return ret;
}

int f(int n) {
    REP(i,v.size()) {
        if(!f(n,v[i])) return 0;
    }
    return 1;
}

int main(){
    memset(H,-1,sizeof(H));
    /*
    int n1,n2;
    while(cin>>n1>>n2) {
        cout << f(n1,n2) << endl;
    }
    */
    int T;
    cin>>T;
    string s;
    getline(cin,s);
    FOR(K,1,T) {
        getline(cin,s);
        istringstream iss(s);
        int k;
        v.clear();
        while(iss>>k) v.push_back(k);
        int sol=-1;
        for(int n=2;;n++) {
            if(f(n)) {
                sol = n;
                break;
            }
        }
        cout << "Case #"<<K<<": "<<sol<<endl;
    }
}
