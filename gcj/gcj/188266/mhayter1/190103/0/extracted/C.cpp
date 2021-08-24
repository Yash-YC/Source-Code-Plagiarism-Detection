#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<vector>
#include<deque>
#include<iomanip>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define forn(i,s,e) for(int i=(s),_e=(e);i<_e;i++)
#define rep(i,n) forn(i,0,n)
#define pb push_back 
#define db(i) cout<<#i<<"= "<<i<<endl; 

ifstream fin("C-small.in");
ofstream fout("output.out");

int nunique,ntotake;

int main()
{
    int ntests;
    fin>>ntests;
    rep(ij,ntests)
    {
        //do crazy solution
        fin>>nunique>>ntotake;
        double ans=(0.+nunique+ntotake)/ntotake;
        fout<<"Case #"<<ij+1<<": "<<setprecision(7)<<fixed<<ans<<endl;
            
    }
    printf("done\n");
    int z;
    scanf("%d",&z);
    return 0;
}
