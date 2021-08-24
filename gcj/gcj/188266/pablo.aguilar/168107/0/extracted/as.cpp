#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int const M = 4000000;
int s2[11][M];
int b[11];
int nb;
bool seen[M];
bool done[11][M];
bool works[11][M];

bool good(int n, int b)
{
//    cout << n << '\t' << b << '\t' << s2[b][n] << endl;
    if( n == 1 )
        return true;
    if( done[b][n] )
        return works[b][n];

    bool& rv = works[b][n];
    if( seen[n] )
        rv = false;
    else
    {
        seen[n] = true;
        rv = good(s2[b][n], b);
        seen[n] = false;
    }

    done[b][n] = true;
    return rv;
}

int main()
{
    for( int i = 1; i < M; ++i )
    {
        for( int b = 2; b <= 10; ++b )
        {
            int ud = i % b;
            int rs = i / b;
            s2[b][i] = s2[b][rs] + ud*ud;
        }
    }

    string line;
    int T;
    getline(cin, line);
    sscanf(line.c_str(), "%d", &T);
    for( int C = 1; C <= T; ++C )
    {
        getline(cin, line);
        istringstream ss(line);

        nb = 0;
        int b;
        while( ss >> b )
            ::b[nb++] = b;


        int rv = -1;
        for( int n = 2; n < M; ++n )
        {
            bool ok = true;
            for( int bi = 0; bi != nb; ++bi )
                if( !good(n, ::b[bi]) )
                {
                    ok = false;
                    break;
                }

            if( ok )
            {
                rv = n;
                break;
            }
        }

        printf("Case #%d: %d\n", C, rv);
    }

    return 0;
}
