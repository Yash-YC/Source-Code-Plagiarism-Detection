#pragma warning(disable: 4786)
#include <vector>
#include <sstream>
#include <list>
#include <bitset>
#include <set>
#include <stack>
#include <queue>
#include <functional>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

double Pi =acos(-1.0);
#define oo 2147483647
#define inf 1e17
#define LL __int64
#define eps 1e-8
#define sign(x) ((x)>eps?1:((x)<-eps?-1:0)) 
#define MIN(a,b) (a)<(b)?(a):(b)
#define REP(i,N) for(i=0;i<N;++i)
#define FOR(i,a,b) for(i=(a);i<=(b);++i)
int base[10],bnum;
int flag[10][1000000];
bool check(int c,int b)
{
	int r=0,k,d=c;
	if(flag[b][c]!=0) 
		return flag[b][c]==1;
	flag[b][c]=-1;
	while(d>0)
	{
		k=(d%b);
		r+=k*k;
		d=d/b;		
	}
	if(r==1)
		flag[b][c]=1;
	else if(check(r,b))
		flag[b][c]=1;
	else
		flag[b][c]=-1;
	return flag[b][c]==1;
}
int main()
{
	freopen("small_in.txt","r",stdin);
	freopen("small_out.txt","w",stdout);	
	//freopen("large_in.txt","r",stdin);	
	//freopen("large_out.txt","w",stdout);

	int N,cs;
	int i,ans;
	char line[100];
	cin>>N;
	cin.getline(line,100);
	memset(flag,0,sizeof(flag));
	FOR(cs,1,N)
	{
		cin.getline(line,100);
			istringstream  iss;
		iss.str(line);
		bnum=0;
		while(iss>>base[bnum]) ++bnum;
		ans=2;
		while(true)
		{
			REP(i,bnum)
			{
				if(!check(ans,base[i]))
				{
					++ans;
					break;
				}
			}
			if(i==bnum) break;
		}
		cout<<"Case #"<<cs<<": "<<ans<<endl;
		//printf("Case #%d: %I64d\n",cs,ans);
	}
	return 0;		
}
