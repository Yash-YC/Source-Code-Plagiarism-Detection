#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define SZ(a) ((int)(a).size())
#define MOD 1000000000
#define MODL 9

using namespace std;

typedef long long LL;
typedef vector <long long> VI;
typedef vector <double> VD;
typedef vector <vector<long long> > VVI;
typedef pair <int,int> PII;
typedef vector <LL> VL;
typedef vector <string> VS;

VI split(string s, string t=" ") {
    VI ret;
    int a,b=0;
    while ((a=s.find_first_not_of(t,b))!=-1) {
        b=s.find_first_of(t,a);
        ret.push_back(atol(s.substr(a,b-a).c_str()));
    }
    return ret;
}

#define INF 0x7fffffff
int conv(int n, int b) {
    int ret = 0;
    while (n) {
        ret += (n % b) * (n % b);
        n /= b;
    }
    return ret;
}

main()
{
    int t;
    scanf("%d\n", &t);
    char buf[1000];
    for (int tt = 0; tt < t; tt++) {
        gets(buf);
        VI vec = split(buf);
        int ret = 2;
        while (1) {
            bool good_number = true;
            for (int i=0; i<vec.size(); i++) {
                int n = conv(ret,vec[i]);
                for (int j=0; j<100; j++) {
                    n = conv(n,vec[i]);
                }
                if (n != 1) {
                    good_number = false;
                    break;
                }
            }
            if (good_number) {
                printf("Case #%d: %d\n", tt+1, ret);
                break;
            }
            ret++;
        }

    }
}
