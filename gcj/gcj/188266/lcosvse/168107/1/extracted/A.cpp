#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int n;
int data[20];

int res[2000];

void read_data()
{
    string buf;
    getline(cin,buf);
    stringstream sin(buf);
    n = 0;
    int d;
    while (sin >> d)
    {
        n++;
        data[n] = d;
    }
}

int used[1100];

int change(int base,int s)
{
    int res = 0;
    while (s)
    {
        res += (s % base) * (s % base);
        s /= base;
    }
    return res;
}

bool _check(int base,int s)
{
    memset(used,false,sizeof(used));
    int temp;
    while (true)
    {
        temp = change(base,s);
        if (temp == 1) return true;
        if (used[temp]) return false;
        s = temp;
        used[s] = true;
    }
    return true;
}

bool check(int s)
{
    int i;
    for (i=1;i<=n;i++) if (!_check(data[i],s)) return false;
    return true;
}
  
int work_ans()
{
    int value = 0;
    int i;
    for (i=1;i<=n;i++) value += 1 << (data[i] - 2);
    value |= 1;
    value |= 4;
    if (res[value] != -1) return res[value];
    i = 2;
    while (true)
    {
        if (check(i)) break;
        //cout << i << endl;
        //if (i % 100000 == 0) fprintf(stderr,"%d\n",i);
        i++;
    }
    res[value] = i;
    return i;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,i;
    string buf;
    getline(cin,buf);
    stringstream sin(buf);
    sin >> t;   
    int ans;
    memset(res,-1,sizeof(res));
    res[511] = 11814485;
    for (i=1;i<=t;i++)
    {
    fprintf(stderr,"%d\n",i);
    read_data();
    ans = work_ans();
    cout << "Case #" << i << ": ";
    cout << ans << endl;
    }
    return 0;
}
