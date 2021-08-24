#include <cstdio>
#include <set>
#include <bitset>
#include <algorithm>
using namespace std;

static const int BIGSIZE = 100000000;

int next(int n, int base) {
    int sum = 0;
    while (n>0) {
        sum += (n%base)*(n%base);
        n/=base;
    }
    return sum;
}


bool isHappy(int n, int base) {
    set<int> used;
    while (n!=1 && used.count(n)==0) {
        used.insert(n);
        n = next(n, base);
    }
    
    if (n==1) {
/*        for (set<int>::iterator it = used.begin(); it!=used.end(); it++)*/
//             helper.set(*it, 1);
        return true;
    }
    else {
        return false;
    }
}

int bigset[BIGSIZE];

// int main() {
//     fill(bigset, bigset+BIGSIZE, 0);
//     
//     for (int base=3; base<=10; base++) {
//         set<int> helper;
//         printf("base: %d\n", base);
//         int sss = 0;
//         for (int n=2; n<BIGSIZE; n++)
//             if (isHappy(n, base, helper)) {
//                 bigset[n]++;
//                 if (sss++<20) printf(" %d", n);
//                 if (n<10000) helper.insert(n);
//             }
// 
//         printf("\n");
//     }
//     
//     int best = 0;
//     for (int i=2; i<BIGSIZE; i++)
//         if (bigset[i]>best)
//             printf("%d -> %d!\n", bigset[i], i), best=bigset[i];
//     
//     return 0;
// }


int main() {
    int C; scanf("%d", &C);
    
    int X[10];
    
    for (int c=0; c<C; c++) {
        int xi = 0;
        while (true) {
            char eee; scanf("%d%c", &X[xi++], &eee);
            //printf("%d\n", int(eee));
            if (eee!=' ') break;
        }
        //printf("---\n");
        
        for (int n=2; ; n++) {
            bool ok = true;
            for (int i=0; i<xi; i++)
                ok = ok && isHappy(n, X[i]);
            if (ok) {
                printf("Case #%d: %d\n", c+1, n);
                break;
            }
        }

    }
    
    return 0;
}

