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
double k[41],w[41];
double cc[41][41];
void init()
{
	int i,j,r;
	REP(i,41)
		REP(j,41)
			cc[i][j]=0;
	REP(i,41)
	{
		REP(j,i+1)
		{
			cc[i][j]=1;
			REP(r,j)
			{
				cc[i][j]*=i-r;
				cc[i][j]/=r+1;
			}
		}
	}
} 
int main()
{
	freopen("small_in.txt","r",stdin);
	freopen("small_out.txt","w",stdout);	
	//freopen("large_in.txt","r",stdin);	
	//freopen("large_out.txt","w",stdout);
	
	int N,cs;
	int a,b;
	double ppp;
	int i,j,ss;	
	cin>>N;
	init();
	FOR(cs,1,N)
	{
		cin>>a>>b;
		FOR(i,b+1,a)
		{
			k[i]=0;
			w[i]=0;
		}
		k[b]=1;
		w[b]=1;
		FOR(i,b+1,a)
		{
			if(i>b+b)
				ss=i-b;
			else
				ss=b;
			FOR(j,ss,i-1)
				w[i]+=(cc[a-j][i-j]*cc[j][b-i+j])/cc[a][b]*w[j];
			FOR(j,ss,i-1)
			{
				ppp=(cc[a-j][i-j]*cc[j][b-i+j])/cc[a][b]*w[j];			
				k[i]+=k[j]*ppp/w[i];
				k[i]+=cc[a][b]/(cc[a-j][i-j]*cc[j][b-i+j])*ppp/w[i];
			}
		}
		//cout<<"Case #"<<cs<<": "<<endl;
		printf("Case #%d: %.7f\n",cs,k[a]);
	}
	return 0;		
}
