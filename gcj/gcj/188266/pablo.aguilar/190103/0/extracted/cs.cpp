#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int p[1<<10];
double mem[1<<10];
bool seen[1<<10];

int np;
double pr;

int n, c, all;
double solve(int s)
{
    if( s == all )
        return 0;

    if( seen[s] ) return mem[s];
    seen[s] = true;

    double& rv = mem[s];
    rv = 1;
    double stay = 0;

    for( int i = 0; i != np; ++i )
    {
        int nw = (s | p[i]);
        if( nw == s )
            stay += pr;
        else
            rv += pr * solve(s | p[i]);
    }

    rv /= (1 - stay);
//    cout << s << '\t' << stay << '\t' << rv << endl;
    return rv;
}

int main()
{
    int T;
    scanf("%d", &T);
    for( int C = 1; C <= T; ++C )
    {
        printf("Case #%d: ", C);

        scanf("%d %d", &n, &c);
        all = (1<<n) - 1;
        np  = 0;
        memset(seen, 0, sizeof(seen));

        for( int i = 0; i != (1<<n); ++i )
            if( __builtin_popcount(i) == c )
                p[np++] = i;

        pr = 1. / np;

        double rv = solve(0);
        printf("%.6f\n", rv);
    }

    return 0;
}
