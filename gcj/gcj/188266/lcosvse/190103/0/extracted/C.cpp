#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define M 50

double C[50][50];

double dp[M];
int n,cc;

void work_dp()
{
    if (cc >= n)
    {
        dp[0] = 1;
        return;
    }
    dp[n] = 0;
    int i,j;
    double temp,k;
    for (i=n-1;i>=0;i--)
    {
        temp = 1;
        k = 1 - C[i][cc] / C[n][cc];
        for (j=i+1;j<=n&&j<=i+cc;j++)
        {
            //cout << "###" << endl;
            //cout << C[i][cc - (j - i)] * C[n - i][j - i] / C[n][cc] << endl;
            //cout << dp[j] << endl;
            temp += C[i][cc - (j - i)] * C[n - i][j - i] / C[n][cc] * dp[j];
        }
        //cout << temp << " " << k << endl;
        dp[i] = temp / k;
        //cout << dp[i] << endl;
    }
}

double calc(int a,int b)
{
    double res = 1;
    int i;
    for (i=b+1;i<=a;i++) res *= i;
    for (i=1;i<=a - b;i++) res /= i;
    return res;
}
    
void init()
{
    int i,j;
    for (i=1;i<=50;i++)
    for (j=0;j<=i;j++) C[i][j] = calc(i,j);
    C[0][0] = 1;
}

void debug()
{
    int i,j;
    for (i=1;i<=10;i++)
    {
        for (j=0;j<=i;j++) cout << C[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C_small.out","w",stdout);
    init();
    int t;
    cin >> t;
    int i;
    for (i=1;i<=t;i++)
    {
    //debug();
    cin >> n >> cc;
    work_dp();
    printf("Case #%d: %.8lf\n",i,dp[0]);
    }
    return 0;
}
    