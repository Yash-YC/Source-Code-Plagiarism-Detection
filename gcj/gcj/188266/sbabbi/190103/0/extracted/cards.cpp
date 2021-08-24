#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

const int matsize=5000;

double mat [matsize][40];

vector<long long> maskpregenerate;

void fillprob(int nehogia,int mazzo,int tipi,int posizione,double stdprob)
{
    long long mask=0;
    for (int i=0;i < nehogia;++i) mask |=(1 << i);
    double prob=1.0/maskpregenerate.size();
    for (int i=0;i < maskpregenerate.size();++i)
       mat[posizione][__builtin_popcount(mask | maskpregenerate[i])]+=(prob*stdprob);
}

double solve(int C,int N)
{
    if (C == N) return 1;
    memset(mat,0,sizeof(double)*matsize*40);
    mat[0][N] = 1.0;


    for (int i=1;i < matsize;++i)
    {
        for (int j=0;j < 40;++j)
            if (mat[i-1][j] != 0)
                fillprob(j,N,C,i,mat[i-1][j]);
    }
/*    for (int i=0;i < 99;++i)
   {
     for (int j=0;j < 40;++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }*/
    double res=0;
    for (int i=1;i < matsize;++i)
        res+=(mat[i][C]-mat[i-1][C])*(i+1);
    return res;
}

int main ()
{
    int T;


    cin >> T;
    for (int i=0;i < T;++i)
    {
        maskpregenerate.clear();
        int C,N;
        cin >> C >> N;
        for (long long m=0;m < (1 << C);++m)
            if (__builtin_popcount(m) == N) maskpregenerate.push_back(m);
        cout << "Case #" << (i+1) << ": "<< fixed << setprecision(7) << solve(C,N) << endl;
    }
    return 0;
}
