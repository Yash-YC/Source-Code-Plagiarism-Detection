#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define MAX 1000
#define BASE 11

int sq[10];
char memo[MAX][BASE];

int faz(int i, int j)
{
    int soma,n;

    if (i >= MAX)
    {
        for(soma = 0, n = i; n > 0; n /= j)
            soma += sq[n%j];
        return(faz(soma,j));
    }

    if (memo[i][j] > -1) return(memo[i][j]);

    memo[i][j] = 0;

    for(soma = 0, n = i; n > 0; n /= j)
        soma += sq[n%j];

    memo[i][j] = faz(soma,j);

    return(memo[i][j]);
}

int main(void)
{
    int T;

    for(int i = 0; i < 10; i++)
        sq[i] = i*i;

    memset(memo,-1,sizeof(memo));
    for(int i = 0; i < BASE; i++)
        memo[1][i] = 1;

    /*
    int x;
    scanf("%d %d",&T,&x);
    printf("%d\n",faz(T,x));
    return(0);
    */

    scanf("%d\n",&T);
    for(int caso = 1; caso <= T; caso++)
    {
        char s[2048];
        fgets(s,2048,stdin);
        vector<int> b;
        int x;

        istringstream ss;
        ss.str(string(s));
        while (ss >> x)
            b.push_back(x);

        int i;
        for(i = 2; ;i++)
        {
            int j;
            for(j = 0; j < (int)b.size(); j++)
                if (!faz(i,b[j]))
                    break;
            if (j == (int)b.size())
                break;
        }
        printf("Case #%d: %d\n",caso,i);
    }

    return(0);
}

