/**********************************************************************
Author: Felicia
Created Time:  2009/9/12 8:59:47
File Name: a.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

typedef long long int64;
const int maxint = 0x7FFFFFFF;
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;

const int maxn = 10000;

int ha[maxn][11];

int next(int n, int b) {
	int ret = 0;
	while (n) {
		int t = n % b;
		ret += t * t;
		n /= b;
	}
	return ret;
}

int happy(int n, int b) {
	set <int> h;
	while (h.find(n) == h.end()) {
		if (n == 1)
            return 1;
		h.insert(n);
		n = next(n, b);
	}
	return 0;
}

int main() {
    freopen("a-small.out", "w", stdout);
    int ca;
    scanf("%d", &ca);
    char s[1000];
    gets(s);
    vector <int> b;
    memset(ha, -1, sizeof(ha));
    for (int T = 1; T <= ca; ++T) {
        b.clear();
        printf("Case #%d: ", T);
        gets(s);
        stringstream oo(s);
        int t;
        while (oo >> t) {
            b.push_back(t);
        }
        for (int j = 2; ; ++j) {
            bool flag = true;
            for (int i = 0; flag && i < b.size(); ++i) {
                if (!happy(j, b[i]))
                    flag = false;
            }
            if (flag) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}

