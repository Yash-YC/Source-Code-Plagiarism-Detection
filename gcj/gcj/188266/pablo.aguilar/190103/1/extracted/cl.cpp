#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ull;

int const N = 40;
ull choose[N+1][N+1];
double sol[N+1][N+1];

int n, c;

double mem[N+1];
bool seen[N+1];

double solve(int m)
{
    if( m == n )
        return 0;
    if( seen[m] )
        return mem[m];

    seen[m] = true;
    double& rv = mem[m];
    rv = 1;
    double stay = (1.*choose[m][c]) / choose[n][c];

    //cout << m << ' ' << n << ' ' << c << ' ' << stay << endl;
    for( int o = 0; o < c; ++o )
    {
        if( m + (c - o) > n )
            continue;

        ull x = choose[m][o];
        ull y = choose[n - m][c - o];

       // cout << n << ' ' << c << ' ' << m << ' ' << o << ' ';
       // cout << ((1.*max(x, y))/choose[n][c])*min(x,y)*(solve(m+c-o)) << endl;

        rv += ((1.*max(x, y))/choose[n][c])*min(x,y) * (solve(m + c - o));
    }

   // cout << "rv: " << rv << "\tStay: " << stay << endl;
    rv /= (1 - stay);
    return rv;
}

int main()
{
    choose[0][0] = 1;
    {for( int n = 1; n <= N; ++n )
    for( int k = 0; k <= n; ++k )
        choose[n][k] = choose[n-1][k] + (k ? choose[n-1][k-1] : 0);
    }

    for( n = 1; n <= N; ++n )
    for( c = 1; c <= n; ++c )
    {
        memset(seen, 0, sizeof(seen));
        sol[n][c] = 1 + solve(c);
//        cout << n << ' ' << c << ' ' << sol[n][c] << endl;
    }

    int T;
    scanf("%d", &T);
    for( int C = 1; C <= T; ++C )
    {
        scanf("%d %d", &n, &c);
        double rv = sol[n][c];
        //double rv = 1 + solve(c);
        printf("Case #%d: %.6f\n", C, rv);
    }

    return 0;
}
