#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

map<int,int> flag;

int convert(int a,int b)
{
    string s;
    int c;
    
    s.erase();
    s += (a % b) + '0';
    a /= b;
    while(a >= b)
    {
        s += (a % b) + '0';
        a /= b;
    }
    if(a != 0)
        s += a + '0';
    
    c = s[s.size() - 1] - '0';
    for(a = s.size() - 2;a >= 0;a--)
    {
        c *= 10;
        c += s[a] - '0';
    }
    
    return c;
}

int check(int a,int b)
{
    int c;
    
    a = convert(a,b);
    c = (a % 10) * (a % 10);
    a /= 10;
    while(a > 0)
    {
        c += (a % 10) * (a % 10);
        a /= 10;
    }
    if(c == 1)
        return 1;
    else if(flag[c] == 1)
        return 0;
    else
    {
        flag[c] = 1;
        return check(c,b);
    }
}

int main()
{
    int ncase,ccase;
    int x,y,z;
    string s;
    vector<int> q;
    stringstream ss;
    
    cin >> ncase;
    getline(cin,s);
    for(ccase = 1;ccase <= ncase;ccase++)
    {
        getline(cin,s);
        q.clear();
        ss.clear();
        ss << s;
        x = 0;
        for(y = 0;y < s.size();y++)
            if(s[y] == ' ') x++;
        for(y = 0;y <= x;y++)
        {
            ss >> z;
            q.push_back(z);
        }
        for(x = 2;1;x++)
        {
            for(y = 0;y < q.size();y++)
            {
                flag.clear();
                z = check(x,q[y]);
                if(z == 0) break;
            }
            if(y == q.size() && z == 1)
            {
                cout << "Case #" << ccase << ": " << x << endl;
                break;
            }
        }
    }

    while(getchar()!=EOF);
    return 0;
}
