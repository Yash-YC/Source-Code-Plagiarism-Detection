#include <iostream>
#include <stdio.h>
using namespace std;

long long C[41][41];
double ret[41][41];

void init()
{
    memset(C, 0, sizeof(C));
    memset(ret, 0, sizeof(ret));
    for (int i=0; i<41; i++)
    {
        C[i][0] = 1;
        C[i][i] = 1;
        ret[i][i] = 1;
    }
    
    for (int i=1; i<41; i++)
    {
        for (int j=1; j<=i; j++)
        {
            C[i][j] = C[i][j-1] * (i-j+1) / j;
            //cout << C[i][j] << " ";
        }
        //cout << endl;
    }
    
    for (int i=1; i<41; i++)
    {
        for (int j=0; j<=i; j++)
        {
            ret[i][j] = ret[i-1][j] + 1/((double)C[i-1][j-1]/C[i][j]);
        }
    }
}

int main()
{
    init();
    int caseNum;
    cin >> caseNum;
    for (int caseId=1; caseId<=caseNum; caseId++)
    {
        int C;
        int N;
        cin >> C >> N;
        cout << "Case #" << caseId << ": ";
        printf("%.7f\n", ret[C][N]);
    }
    return 0;
}
