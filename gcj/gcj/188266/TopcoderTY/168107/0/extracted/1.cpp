#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;
 
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); ++i)   
#define ALL(X) (X).begin(),(X).end()
#define present(c,x) ((c).find(x) != (c).end())
typedef long long ll;
template<class T>inline int sz(T& x){return (int)x.size();}
int stoi(string a){int len=sz(a);if(len==1)return a[0]-'0';return a[len-1]-'0'+10*stoi(a.substr(0,len-1));}
template<class T>inline string tostring(T& i){ostringstream oss; oss << i; return oss.str();}
template <class T> void make_unique(T& v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline void eraseV(vector<int>& vec,int val) {vector<int>::iterator it = find(ALL(vec),val);if(it!=vec.end()) vec.erase(it,it+1);}
inline int bitcnt(int n) {int ret = 0; while(n) { ret += n&1; n>>=1;}return ret; }

string getLine()
{
	string ret;
	while(true)
	{
		char ch = getc(stdin);
		if(ch == '\n')break;
		else ret += ch;
	}
	return ret;
}

int getNum()
{
	return stoi(getLine());
}

string trans(int n,int b)
{
	string ret;
	while(n >= b)
	{
		int d = n % b;
		ret += (char)(d + '0');
		n /= b;
	}
	if(n !=0) ret += (char)(n + '0');
	reverse(ALL(ret));
	return ret;
}

bool happy(int n,int b)
{
	map<string,bool> dic;
	string now = trans(n,b);
	while(true)
	{
		if(now[0] == '1' && sz(now) == 1) return true;
		else
		{
			if(dic.count(now) >=1 )return false;
			else dic[now] = true;
		}
		int res = 0;
		for(int i=0;i<sz(now);i++)
		{
			int d = now[i]-'0';
			res += d*d;
		}
		now = trans(res,b);
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int test; test = getNum();
	for(int tt=1;tt<=test;tt++)
	{
		cerr << "Case  "<< tt << endl;
		printf("Case #%d: ",tt);
		string str = getLine();
		istringstream sin(str);
		int temp;
		vector<int> base;
		while(sin>>temp)
			base.push_back(temp);
		int ans = -1;
		
		for(int j=2;;++j){
			bool flag = true;
			for(int i=0;i<sz(base);i++){
				if(happy(j,base[i]) == false){
					flag = false;
					break;
				}
			}
			if(flag){
				ans = j;
				break;
			}
		}

		cout << ans << endl;
	}
	return 0;
} 
