#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int process(int n,int base)
{
    int res=0;
    while (n > 0)
    {
        int c = n%base;
        n/=base;
        res+= (c*c);
    }
    return res;
}

set<int> mm[11];

bool ismagic(int n,int base)
{
    for (int i=0;i < 1000;++i)
    {
        if (n == 1)
        {
            mm[base].insert(n);
            return true;
        }
        if (mm[base].find(n) != mm[base].end()) return true;
        n = process(n,base);
    }
    return false;
}

int solve(vector<int> bases)
{
    for (int n = 2;n < 100000;++n)
    {
        for (int i=0;i < bases.size();++i)
            if (!ismagic(n,bases[i])) goto restart;
        return n;
    restart:
        ;
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(1);
    for (int i=0;i < T;++i)
    {
        char buf[512];
        cin.getline(buf,512);
        vector<int> res;
        for (int j=0;j < strlen(buf);++j)
        {
            if (buf[j] == '1') res.push_back(10);
            if (buf[j] >= '2' && buf[j] <= '9') res.push_back(buf[j]-'0');
        }
        cout << "Case #" << i+1 << ": " << solve(res) << endl;
    }
    return 0;
}
