#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

string str(long long n) {
    string s;
    s += ((n%10)+ '0');
    n/= 10;
    while (n > 0) {
        s += ((n%10) + '0');
        n/=10;
    }
    reverse(s.begin(), s.end());
    return s;
}

long long pasa(long long n, long long base) {
    string s;
    s += str(n%base);
    n/= base;
    while (n >0) {
        s += str(n%base);
        n/=base;
    }
    reverse(s.begin(), s.end());
    stringstream iss(s);
    long long res;
    iss >> res;
    return res;
}

bool is_happy(long long n, long long base, map<long long, bool>& memo) {
    if (memo.count(n)) return memo[n];
    long long suma = 0;
    long long ini = n;
    while (n > 0) {
        suma += (n%base)*(n%base);
        n/=base;
    }
    long long temp = suma;
    suma = pasa(suma, base);
    if (suma == 1) return memo[n] = true;
    else {
        memo[ini] = false;
        return memo[n] = is_happy(temp, base, memo);
    }
}
        
int main() {
    int k, caso = 1;
    cin >> k;
    cin.ignore();
    while (k--) {
        string s;
        getline(cin,s);
        stringstream iss(s);
        vector<long long> base;
        long long a;
        while (iss >> a) base.push_back(a);
        bool happy = false;
        long long i;
        vector<map<long long, bool> >memo(base.size());
        for (i =2; not happy; ++i) {
            bool all = true;
            for (int j = 0; j < base.size(); ++j) {
                all &= is_happy(i, base[j], memo[j]);
                memo[j].clear();
            }
            happy = all;
        }
        cout << "Case #" << caso++ << ": " << i - 1 << endl;
    }
}
