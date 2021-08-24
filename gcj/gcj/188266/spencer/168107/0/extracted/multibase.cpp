#include <stdio.h>
#include <iostream>
#include <sstream>
#include <ext/hash_set>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FOREACH(it,c) for(__typeof(c.begin())it=c.begin();it!=c.end();it++)
typedef vector<int> VI;

hash_set<int> done[12], happy[12];

bool ishappy(int n, int base) {
    if (done[base].find(n) != done[base].end())
        return happy[base].find(n) != happy[base].end();
    done[base].insert(n);

    int next = 0, copy = n;
    while(copy) {
        int last = copy%base;
        next += last*last;
        copy /= base;
    }
    if (ishappy(next, base)) {
        happy[base].insert(n);
        return true;
    }
    else return false;
}

int main() {
    FILE *fin = fopen("multibase.in", "r"), *fout = fopen("multibase.out", "w");

    FOR(base, 2, 10) {
        done[base].insert(1);
        happy[base].insert(1);
    }

    int tests; fscanf(fin, "%d\n", &tests);
    REP(t, tests) {
        VI bases_needed = VI();
        char input[1000];
        fgets(input, 1000, fin);
        string s(input);
        istringstream iss(s);
        int val;
        do {
            iss >> val;
            bases_needed.push_back(val);
        } while(iss);
        bases_needed.pop_back();

        int i = 2;
        while(true) {
            bool ok = true;
            FOREACH(it, bases_needed) {
                if (!ishappy(i, *it)) ok = false;
                if (!ok) break;
            }
            if (ok) break;
            i++;
        }
        fprintf(fout, "Case #%d: %d\n", t+1, i);
    }
    return 0;
}
