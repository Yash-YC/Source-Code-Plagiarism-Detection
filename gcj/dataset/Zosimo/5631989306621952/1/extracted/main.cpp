#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);
#define bidirectional(a,b) graph[a].push_back(b);graph[b].push_back(a);
using namespace std;

string f(string s)
{
    stack<char> tmp;
    tmp.push(s[0]);
    for(int i=1;i<s.size();++i)
    {
        if(s[i]>=tmp.top())
        {
            tmp.push(s[i]);
        }else
        {
            string tempo;
            while(!tmp.empty())
            {
                tempo+=tmp.top();
                tmp.pop();
            }
            tmp.push(s[i]);
            for(int i=tempo.size()-1;i>=0;--i){tmp.push(tempo[i]);}
        }
    }
    string ans;
    while(!tmp.empty())
    {
        ans+=tmp.top();
        tmp.pop();
    }
    return ans;
}

int main()
{
    IOS
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int cases;
    cin>>cases;
    string s;
    for(int c=1;c<=cases;++c)
    {
        cin>>s;
        cout<<"Case #"<<c<<": "<<f(s)<<endl;
    }
}
