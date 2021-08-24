#include<stdio.h>

long long C[45][45];

int c, n, test;
void get_C()
{
    int i, j, mid;
    for(i = 0; i < 41; i ++)
        C[i][0] = 1;
    
    for(i = 1; i < 41; i ++)
    {
        mid = i / 2;
        for(j = 1; j <= mid; j ++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        
        for(j = mid + 1; j <= i; j ++)
            C[i][j] = C[i][i - j];
    }
}

double get_pro(int i, int j)
{
    double ans;
    ans = C[c - i][j - i] * 1.0 / C[c][n];
    return ans * C[i][n - j + i];    
}

int flag[100], t;
double dp[100];

double get_exp(int i)
{
    if(i == c)
        return 0.0;
    
    if(flag[i] == t)
        return dp[i];
    
    int j;
    double sum = 1.0;
    
    if(i == 0)
    {
        sum = get_exp(n) + 1;
        dp[i] = sum;
    }
    else
    {
        for(j = i + 1; j <= c && j <= n + i; j ++)
        {
            sum += get_pro(i, j) * get_exp(j);
        }
        dp[i] = sum / (1 - get_pro(i, i));
    }
    flag[i] = t;
    return dp[i];
}
int main()
{
    int test;
    get_C();
    scanf("%d", &test);
    
    for(t = 1; t <= test; t ++)
    {
        scanf("%d%d", &c, &n);
        printf("Case #%d: %.7lf\n", t, get_exp(0));
    }
}


//p(i,j)=C(c-i£¬j-i)*C(i£¬n-j+i)/C(c,n)
