#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define dbg(x) cout << #x << " -> " << x << "\t" << flush;
#define dbge(x) cout << #x << " -> " << x << "\t" << endl;
#define LET(x,a) typeof(a) x(a)
#define FORI(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(LET(i,a);i < (b);++i)
#define FORZ(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define CS c_str()
#define PB push_back
#define SZ size()
#define INF (int)1e9+1
typedef long long LL;
vector<int> Bases;
char isHappy[1000000][10];
bool vis[1000000];

string toBase(int a, int b)
{
    string str;
    while(a)
    {
        str += a%b;
        a /= b;
    }
    return str;
}


bool happy(int num, int b)
{
    if(num == 1)
        return 1;
    if(isHappy[num][b] != -1)
        return isHappy[num][b];
    if(vis[num])
        return 0;
    vis[num] = 1;
    string con = toBase(num, b);
    LL nn = 0;
    FORZ(i, con.SZ)
        nn += (con[i])*(con[i]);
    isHappy[num][b] = happy(nn, b);
    vis[num] = 0;
    return isHappy[num][b];
    
}

int Bit[2048];

bool Anc(int a, int mask, int ind)
{
    if(!mask)
        return 1;
    if(Bit[mask] > a)
        return false;
    int ll = happy(a, Bases[ind]) && Anc(a, mask^(1<<Bases[ind]), ind - 1);
        return ll;
}

int main()
{
    int nC = GI;
    memset(isHappy, -1, sizeof isHappy);
    for(int nc = 1; nc <= nC; ++nc)
    {
        char str[1001]={0};
        while(strlen(str) == 0 || isspace(str[0]))
            gets(str);
        stringstream ss(str);
        int num;
        Bases.clear();
        int fo = 0;
        while(ss >> num)
        {
            if(num == 2 || num == 4)
                ;
            else Bases.PB(num), fo |= 1 << num;
        }

        for(int x = 2; ; ++x)
        {
            if(Anc(x, fo, Bases.SZ-1))
            {
                Bit[fo] = x;
                printf("Case #%d: %d\n",nc, x);
                break;
            }
        }
    }
}
