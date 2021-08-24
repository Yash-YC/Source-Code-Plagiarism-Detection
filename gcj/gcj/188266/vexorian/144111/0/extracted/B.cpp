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
int N, M;

struct light
{
    int s,w,t;
} lights[3][3];

const int MTIME=2000;
int mem[6][6][MTIME];

bool IsGreen( light & li, bool horz, int t)
{
    int cycle = (li.s + li.w);
    int ct = t % cycle;
    int mt = li.t%cycle;
    
    char cur[cycle];
    fill(cur, cur+20, 'w');
    for (int i=0; i<li.s; i++)
        cur[ (mt+i)%cycle ] = 's';
        
    return ( (cur[ct] == 's') != horz);
    
}

int rec(int y, int x, int t)
{
    int &res = mem[y][x][t];
    if ( (y==0) && (x==2*M-1) ) return t;
    else if( t>= MTIME ) return MTIME;
    else if(res==-1)
    {
        int r = y/2, c = x/2;
        res = MTIME;
        //to the right
        if(x!=2*M-1)
        {
            //cross light?
            if( x%2==0)
            {
                if( IsGreen( lights[r][c], true, t) )
                    res = std::min(res, rec(y,x+1,t+1) );
            }
            else res = std::min(res, rec(y,x+1,t+2));
        }
        
        //to the left
        if(x!=0)
        {
            //cross light?
            if( x%2!=0)
            {
                if( IsGreen( lights[r][c], true, t) )
                    res = std::min(res, rec(y,x-1,t+1) );
            }
            else res = std::min(res, rec(y,x-1,t+2));
        }

        //to the down
        if(y!=2*N-1)
        {
            //cross light?
            if( y%2==0)
            {
                if( IsGreen( lights[r][c], false, t) )
                    res = std::min(res, rec(y+1,x,t+1) );
            }
            else res = std::min(res, rec(y+1,x,t+2));
        }
        
        //to the up
        if(y!=0)
        {
            //cross light?
            if( y%2!=0)
            {
                if( IsGreen( lights[r][c], false, t) )
                    res = std::min(res, rec(y-1,x,t+1) );
            }
            else res = std::min(res, rec(y-1,x,t+2));
        }
        //wait
        res = std::min(res, rec(y,x,t+1) );
        //if(t<3) cout<<"("<<y<<","<<x<<","<<t<<") = "<<res<<endl;
    }
    return res;
}

int solve()
{
    memset(mem,-1,sizeof(mem));
    return rec( 2*N-1, 0, 0);
}

inline void init(){}
//=========================================================
// I/O:
//
int main()
{
    init();
    int C; cin>>C;
    for (int ii=1;ii<=C;ii++)
    {
        cerr<<"["<<ii<<" / "<<C<<"]"<<endl;
        cin>> N >> M;
        for (int i=0; i< N ; i++)
            for (int j=0; j<M; j++)
                cin>> lights[i][j].s >>lights[i][j].w >> lights[i][j].t;
        cout<<"Case #"<<ii<<": " <<solve()  << endl;
        
        
    }
    return 0;
}
