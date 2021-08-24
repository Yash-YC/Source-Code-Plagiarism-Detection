#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
typedef long long ent;
const int MAX=12000000;
char memo[MAX][11];
int bigmemo[(1<<11)];
//-1 no se
//2 visited, but not known

bool happy(int x, int b) { //x happy in base b
    if (x==1) return 1;
    if (memo[x][b]>=0) return memo[x][b]; //if it is 2, i'm cycling
    memo[x][b]=0;
    int p=x;
    int ans=0;
    while (x>0) {
        ans+=(x%b)*(x%b);
        x/=b;
    }
    
    //cerr << "       "<<p << "->" << ans << " .. " << t << endl;
    return memo[p][b]=happy(ans,b);
}

int f(int mask) { //minim que es lucky amb les bases:
    mask=mask-mask%4; //0 and 1 do not count
    if (bigmemo[mask]>=0) return bigmemo[mask];
    for (int i=2;i<MAX;++i) {
        bool ok=true;
        for (int j=2;ok and j<=10;++j) if ((mask>>j)%2) {
            if (not happy(i,j)) ok=false;
        }
        if (ok) return bigmemo[mask]=i;
    }
    return -1;
}

int main() {
    for (int i=0;i<MAX;++i) for (int j=0;j<11;++j) memo[i][j]=-1;
    for (int i=0;i<(1<<11);++i) bigmemo[i]=-1;


    for (int i=0;i<(1<<11);++i) if (i%4==0) {
        f(i);
        cerr << "mask " << i << endl;
    }
    cerr << "data precalculed!" << endl;
    int t; cin >> t;
    string s;
    getline(cin,s);
    for (int z=1;z<=t;++z) {
        getline(cin,s);
        cout << "Case #"<<z<<": ";
        stringstream ss;
        ss << s;
        int x;
        int mask=0;
        while (ss >> x) mask|=(1<<x);
        cout << f(mask) << endl;
    }
}
