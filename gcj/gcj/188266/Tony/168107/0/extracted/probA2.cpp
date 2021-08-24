
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#define HUGE 100000
#define REPS 50

using namespace std;

int b[10], n;
bool good[HUGE][11];

int reduce(int k, int base) {
    for (int i = 0; i < REPS; i++) {
        int j = k, sum = 0;
        while(j > 0) {
            int d = j % base;
            sum += d * d;
            j /= base;    
        }
        k = sum;
        //if (k == 1) {printf("here\n"); system("pause");}
        if (k == 1) return 1;
    }
    //printf("%d\n", k);
    //system("pause");
    return k;
}

void calc() {
    for(int b2 = 2; b2 <= 10; b2++) {
        for(int i = 2; i < HUGE; i++) {
            good[i][b2] = (reduce(i, b2) == 1);
            //if(good[i][b2]) printf("%d %d\n", i, b2);
            //system("pause");
        }
    }
}

int solve() {
    for (int i = 2;; ++i) {
        int j = 0;
        for (; j < n; ++j)
            if (!good[i][b[j]])
                break;
    
        if (j == n) return i;    
    }
    return -1;
}

int main() {
    FILE *fout = fopen("A-small1.out", "w");
    ifstream fin("A-small1.in");
    string w;
    getline(fin, w);
    int T = atoi(w.c_str());
    calc();
    for(int i = 0; i < T; ++i) {
        getline(fin, w);
        istringstream in(w);
        n = 0;
        while(in >> b[n]) ++n;
        
        fprintf(fout, "Case #%d: %d\n", i+1, solve());
    }
    
    return 0;
}
