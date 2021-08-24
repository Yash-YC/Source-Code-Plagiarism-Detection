#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;
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
bool hp[1000];
bool isHappy(int n,int b)
{
	int s = 0;
	while(n)
	{
		s+=(n%b)*(n%b);
		n/=b;
	}
	if(s==1)return true;
	if(hp[s])return false;
	hp[s]=1;
	return isHappy(s,b);
}
int main()
{
	freopen("A-small-attempt0 (1).in","rt",stdin);
	freopen("A-small-attempt0 (1).out","wt",stdout);

	int tt;
	cin>>tt;
	int n;
	string s;
	vector<int> bs;
	getline(cin,s);
	for(int t = 0 ; t < tt ; t ++)
	{
		bs.clear();
		getline(cin,s);
		stringstream ss;
		ss<<s;
		while(ss>>n)
			bs.pb(n);
		int i;
		for(i = 2 ; ; i++)
		{
			bool h =1;
			for(int j = 0 ; j < sz(bs) ; j++)
			{
				memset(hp,0,sizeof(hp));
				if(!isHappy(i,bs[j]))
				{	h = 0;break;}
			}
			if(h)
				break;
		}
		cout<<"Case #"<<t+1<<": "<<i<<endl;

	}

	return 0;
}
