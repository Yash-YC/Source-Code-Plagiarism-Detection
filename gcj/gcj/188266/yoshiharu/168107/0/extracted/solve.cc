#include <iostream>
using namespace std;

int
ishappy(int digit, int base)
{
    int sum;
    int n;
    int i;
    
//cerr << "    checking: " << digit << "," << base << endl;
    for (i = 0; i < 10; i++) {
        sum = 0;
        do {
            n = digit % base;
            digit /= base;
            sum += n * n;
        } while (digit > 0);
        digit = sum;
//cerr << "      " << i << ":result=" << digit << endl;
        while (digit % base > base) {
            digit /= base;
        }
        if (digit == base || digit == 1) {
            return 1;
        }
    }
    return 0;
}

void
solve(int cases)
{
    char line[128];
    int base[16];
    char *p;
    int N;
    int i;
    int d;

    // read
    gets(line);
    p = strtok(line, " ");
    i = 0;
    while (p != NULL) {
        base[i++] = atoi(p);
        p = strtok(NULL, " ");
    }
    N = i;

    // solve
    for (d = 2;; d++) {
        for (i = 0; i < N; i++) {
//cerr << "  try " << d << endl;
            if (!ishappy(d, base[i])) {
                break;
            }
        }
        if (i == N) break;
    }

    // output result
    cout << "Case #" << cases << ": " << d << endl;
}

int
main()
{
    int N, i;

    cin >> N;
    (void)getchar();
    for (i = 0; i < N; i++) {
        solve(i + 1);
    }

}
