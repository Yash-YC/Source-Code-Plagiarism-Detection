#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#include <cassert>
#include <list>
#include <deque>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <queue>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b)) 
#define SETF(x) memset(x,0xff,sizeof(x))
#define SET0(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define PB(x) push_back(x)
#define VI vector <int> 
#define VVI vector < vector <int> > 
#define VS vector <string>
 
using namespace std;

int N;
int arr[11];
map <int, int> M;
int convert(int n, int base)
{
	int ret;
	string s;
	while(n)
	{
		s.push_back(n%base+'0');
		n/=base;
	}
	reverse(ALL(s));
	sscanf(s.c_str(),"%d",&ret);
	return ret;
}
int get_new(int n)
{
	int ret=0;
	while(n)
	{
		ret+=(n%10)*(n%10);
		n/=10;
	}
	return ret;
}
int rconvert(int n, int base)
{
	int ret=0;
	int pow=1;
	while(n)
	{
		ret+=(n%10)*pow;
		pow*=base;
	}
	return ret;
}
bool happy(int base, int n)
{
	//cout<<n<<" "<<base<<endl;
	n=convert(n,base);
	M.clear();
	M[n]=1;
	while(n!=1)
	{
		int temp=n;
		n=get_new(n);
		n=convert(n,base);
		if(M.find(n)!=M.end())
			return false;
		M[n]=1;
		if(n==0)
			return false;
	}
	return true;
}
bool ishappy(int n)
{
	int i;
	for(i=0;i<N;i++)
		if(!happy(arr[i],n))
			return false;
	return true;
}
int main()
{
	int _cas;
	cin>>_cas;
	char buff[50];
	fgets(buff,sizeof(buff),stdin);
	for(int cas=1;cas<=_cas;cas++)
	{
		N=0;
		fgets(buff,sizeof(buff),stdin);
		string S(buff);
		stringstream ss(S);
		int i,val;
		while(ss>>val)
			arr[N++]=val;
		for(i=2;;i++)
		{
			M.clear();
			if(ishappy(i))
				break;
		}
		cout<<"Case #"<<cas<<": "<<i<<endl;
	}
	return 0;
}
