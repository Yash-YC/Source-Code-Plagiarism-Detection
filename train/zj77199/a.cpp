#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string a;
int T;
char in[1005];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf(" %s",in);
        a.clear();
        for(char *p=in;*p;++p)
        {
            if(*p+a>a+'p')
                a=*p+a;
            else a=a+*p;
        }
        printf("Case #%d: %s\n",t,a.c_str());
    }
    return 0;
}
