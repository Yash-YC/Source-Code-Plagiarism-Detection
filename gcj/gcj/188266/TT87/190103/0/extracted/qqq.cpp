// Tim  defines
#include <vector> 
#include <queue> 
#include <set>
#include <map> 

#include <numeric>
#include <algorithm> 
#include <string.h> 

#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 

using namespace std;
//#pragma comment(linker, "/STACK:20000000")

// useful defines
#define sz(x) (int)(x).size()
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define Ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i) 
#define Rep(i,n) for (int i=0;i<(n);++i)
#define RepV(i,v) for (int i=0;i<sz(v);++i)
#define Fill(a,b) memset(&a,b,sizeof(a))   
#define All(c) (c).begin(),(c).end() 
typedef long long LL;
typedef pair <int,int> PI;
typedef pair<double, double> PD;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <PI> VP;
const int oo = (1<<30);
const double eps = 1e-10;
const double INF = 1e10;


int T,n,m,k;
double dp[50];


double cnk(int k, int n){
	double res = 1.0;
	Ford(i,n,k+1){
		res *= double(i)/double(i-k);
	}
	return res;
}

double go(int x){
	if (x==k)
		return 1;
	if (dp[x] > -eps)
		return dp[x];

	int l = min( k - x, n);
	double res = 0;
	For(i,1,l)
		res += (cnk(i,k-x)/cnk(n,k))*cnk(n-i,x) * (go(x+i)+1);

	double q= cnk(n,x)/cnk(n,k);
	res += (res+1)*(1/(1-q) - 1.0);
	return dp[x] = res;

}

int main() { 
	freopen("C.in","rt",stdin);
	freopen("C.out","wt",stdout);
	
	scanf("%d\n",&T);
	For(TT,1,T){
		scanf("%d%d\n",&k,&n);
		For(i,0,k)
			dp[i] = -1.0;
		printf("Case #%d: %.7lf\n",TT,	go(n));
	}

}


