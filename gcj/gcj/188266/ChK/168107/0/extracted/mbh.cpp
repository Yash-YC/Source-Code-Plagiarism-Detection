/*
OS: Microsoft Windows XP Professional
Compiler: Bloodshed Dev-C++ 4.9.9.2
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int t;
int b[10], pb;

char num2[50];
int num3;
bool Jud(int num, int base)
{
    int k=0, i;
    num3=num;
    while (k<1000)
    {
        if (num3==1)
            return true;
        itoa(num3, num2, base);
        num3=0;
        for (i=0; i<strlen(num2); i++)
            num3+=(num2[i]-'0')*(num2[i]-'0');
        k++;
    }
    return false;
}
int main()
{
    freopen("mbh.in", "r", stdin);
    freopen("mbh.out", "w", stdout);
    int i, j, k, tmp, ch;
    bool key;
    cin>>t; cin.get();
    for (i=1; i<=t; i++)
    {
        pb=0;
        while (true)
        {
            cin>>b[pb];
            pb++;
            ch=cin.peek();
            if (ch==10 || ch==13)
                break;
        }
        cin.get();
        for (j=2; ;j++)
        {
            key=true;
            for (k=0; k<pb; k++)
                if (!Jud(j, b[k]))
                {
                    key=false;
                    break;
                }
            if (key)
            {
                cout<<"Case #"<<i<<": "<<j<<endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
