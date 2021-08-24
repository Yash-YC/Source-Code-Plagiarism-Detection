#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

int toDecimal(string s, int base)
{
    int v, i, result = 0;
    for(i = 0 ; i < s.size() ; i++)
    {
          if(s[i]>='0' && s[i] <= '9')  v = s[i] - '0';
          else v = s[i]-'A'+10;
          result = result*base+v;
    }
    return result;
}

string toBase(int num, int base)
{
       if(num ==0) return "0";
       string str;
       while(num!=0)
       {
        int nlet = num%base;
        if(nlet<10) str += (nlet+'0');
        else str += (nlet-10+'A');
        num/= base;
       }
       reverse(str.begin(),str.end());
       return str;
}

int next (int n , int b)
{
	string s = toBase(n,b);
	int num = 0;
	for ( int i  = 0 ; i < s.size() ; i ++ )
		num += (s[i]-'0') * (s[i]-'0');
	return num;
}
bool ishappy ( int n , int b )
{
	set<int> vis;
	while ( 1 )
	{
		if ( n == 1 )
			return 1;
		if ( vis.find(n) != vis.end())
			return 0;
		vis.insert(n);
		n = next (n,b);
	}
	return 0;
}

int main ()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);
	int tt;
	cin >> tt;
	string s;
	getline(cin,s);
	for ( int t =1 ; t <= tt ; t++)
	{
		getline(cin,s);
		stringstream ss(s);
		vector<int> bs;
		int tmp;
		while (1)
		{
			ss>>tmp;
			if ( ss.fail())
				break;
			bs.push_back(tmp);
		}
		int i,j;
		for ( i = 2 ; ; i ++)
		{
			for (j =0 ; j < bs.size(); j ++ )
				if ( ! ishappy(i,bs[j]) )
					break;
			if ( j == bs.size() )
				break;
		}
		printf("Case #%d: %d\n",t,i);
	}
	return 0;
}
