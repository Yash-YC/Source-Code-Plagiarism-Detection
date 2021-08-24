#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++) 
#define all(a) (a).begin(),(a).end()
#define FR(i,x,y) for(int i=x;i<y;++i)
#define FRZ(i,y) FR(i,0,y)
typedef long long int ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
#define PB push_back
#define SZ(a) (int)(a).size()
#define GI ({ll t ;scanf("%lld",&t);t;})
string itostr(ll a)
{
    ostringstream ss;
    ss << a;
    return ss.str();
}
ll strtoi(string ab)
{
    stringstream ss(ab);
    ll a;
    ss >> a;
    return a;
}
ll convtodec(ll a, ll base)
{
    ll result = 0;
    ll mul = 1;
    while(a)
    {
	ll n = a % 10;
	a /= 10;
	result += n * mul;
	mul *= base;
    }
    return result;
}
ll convtobase(ll a, ll base)
{
    string result = "";
    while(a)
    {
	result +=(( a % base) + '0');
	a /= base;
    }
    reverse(all(result));
    return strtoi(result);
}
ll sq(ll a)
{
    ll ans = 0;
    while(a)
    {
	ll x = a % 10;
	a /= 10;
	ans += x * x;
    }
    return ans;
}
bool solve(ll a, ll base)
{
    set<ll> s;
    a = convtobase(a,base);
    s.insert(a);
    while(1)
    {
	a = sq(a);
	a = convtobase(a,base);
	if(a == 1ll) return true;
	if(s.find(a) != s.end()) return false;
	else s.insert(a);
    }
}
int main()
{
    ll nC = GI;
    getchar();
    for(ll nc = 1; nc <= nC;++nc)
    {
	printf("Case #%d: ",nc);
	string str;
	getline(cin,str);
	ll ans = 2;
	vector<ll> base;
	stringstream ss(str);
	ll temp;
	while(ss >> temp)
	    base.PB(temp);
	while(1)
	{
	    bool ff = true;
	    FRZ(i,SZ(base))
	    {
		if(!solve(ans,base[i]))
		{
		    ans ++;
		    ff = false;
		    break;
		}
	    }
	    if(ff) break;
	}
	cout << ans << endl;
    }
    return 0;
}
