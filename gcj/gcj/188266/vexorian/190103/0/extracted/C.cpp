#include<string>
#include<iostream>
#include<sstream>
#include<assert.h>
#include<cstdio>
#include<map>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<queue>
#include<functional>
#include<set>

using namespace std;

//=========================================================
// program:
//
long long combs[41][41];


long long GoodCombs(int n, int c, int x, int y)
{
    /*long long &res = goodcombs[n][c][x][y];
    if(res==-1)
    {
        res = 0;
        if(c==0)  { res = (x==0); }
        else if(n==0) res=0;
        else
        {
            //take one of the ones we need
            if(x&&y)
                res += y*GoodCombs(n-1, c-1, x-1, y-1);
            
            //take one we do not need.
            res += (n-y)*GoodCombs(n-1, c-1, x, y);
        }
    }
    if( res>combs[n][c] )
    {
        cout<<n<<"," <<c<<","<<x<<","<<y<<" . "<<res<<" . "<<combs[n][c]<<endl;
    }*/
    if( n-y < c-x ) return 0;
    
    long long res = combs[y][x] * combs[n-y][c-x];
    
    assert( n>=y);
    assert( c>=x);
    
    assert(res<= combs[n][c]);
    return res;
}


char visited[41];
double mem[41];



double rec(int n, int c, int g)
{
    if( visited[g])
        return mem[g];
    visited[g] = true;
    if(g==c) return 0;
    double & res = mem[g];
    res = 0;
    
    double top = 0;
    for (int i=1; (i<=(c-g) ) && (i<=n) ; i++ )
        top += ( GoodCombs(c,n, i,c-g) / double(combs[c][n]) ) * (1+rec(n,c,g+i) );
    double p0 = ( GoodCombs(c,n,  0,c-g) / double(combs[c][n]) );
    double bot = 1 - p0;
    top += p0;
    assert(bot>0);
    
    
    //cout<<g<<" : "<<top<<", "<<bot<<endl;
    
    res = top/bot;
    return res;
}


double  solve(int n , int c)
{
    /*cout<<"|| "<<GoodCombs(2,1, 1, 1)<<endl;
    cout<<"|< "<<GoodCombs(2,1, 0, 1)<<endl;
    cout<<"|> "<<combs[2][1]<<endl;*/
    memset(visited, 0, sizeof(visited));
    return rec(n,c, 0);
}


inline void init()
{
    memset( combs, 0, sizeof(combs) );
    for (int i=0; i<=40; i++) combs[i][0] = 1;
    for (int i=1; i<=40; i++)
        for (int j=1; j<=i; j++)
            combs[i][j] = combs[i-1][j-1] + combs[i-1][j];
            
}
//=========================================================
// I/O:
//
int main()
{
    init();
    int C; cin>>C;
    for (int i=1;i<=C;i++)
    {
        cerr<<"["<<i<<" / "<<C<<"]"<<endl;

        int c,n; cin>>c>>n;
        
        cout<<"Case #"<<i<<": " ;
        cout.precision(10);
        cout  <<  solve(n,c)<<endl;
        
    }
    return 0;
}
