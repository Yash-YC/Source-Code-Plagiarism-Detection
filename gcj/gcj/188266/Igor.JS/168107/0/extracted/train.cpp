/* Asyamov Igor
e-mail: igor9669@gmail.com*/

#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <set>
#include <stack>
#include <utility>
#include<cassert>
using namespace std;
#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define MP make_pair
#define PB push_back
#define A first
#define B second
#define Len(a) (int)a.length()
#define Sz(a) (int)a.size()
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI > VVI;
#define MAXN 110
const double Eps=1e-6;
const double Pi=2*acos(0.0);
const int inf=1000*1000*1000;

string toString(LL n)
{
	string s="";
	while(n)
	{
		char ch=n%10+'0';
		s=ch+s;
		n/=10;
	}
	return s; 
}
string Convert(LL n,int base)
{
	string r="";
	while(n>=base)
	{
		char ch=n%base+'0';
		n/=base;
		r=ch+r;
	}
	char ch=n+'0';
	if(ch!='0')r=ch+r;
	return r;
}
bool IsHappy(string s,int base)
{
	LL res=0;
	set<string>coll;
	while(1)
	{
		res=0;
		FOR(i,Len(s))
    	{
	    	res+=(s[i]-'0')*(s[i]-'0');
    	}
		if(res==1)break;
		s=Convert(res,base);
		if(coll.find(s)!=coll.end())return false;
		coll.insert(s);
	}
	return true;
}
int main()
{
	freopen("train.in","r",stdin);freopen("train.out","w",stdout);
 	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	//freopen("packrec.in","r",stdin);freopen("packrec.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	FR(cur,1,t+1)
	{
		VI bases;
		string s;
		getline(cin,s);
		s+=" ";
		int x=0;
		FOR(i,Len(s))
		{
			if(s[i]==' ')
			{
				if(x!=0)
				{
					bases.PB(x);
					x=0;
				}
			}
			else
				x=x*10+(s[i]-'0');
		}
		sort(bases.begin(),bases.end());
		for(int k=2;;++k)
		{
			if(IsHappy(Convert(k,bases[0]),bases[0]))
			{
				bool ok=true;
				FR(i,1,Sz(bases))
				{
					if(!IsHappy(Convert(k,bases[i]),bases[i]))
					{
						ok=false;
						break;
					}
				}
				if(ok)
				{
					printf("Case #%d: %d\n",cur,k);
					break;
				}
			}
		}
	}
	return 0;
}