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
char s[200];
int arr[10];
map<int,bool> mp;

bool check(int x, int b){
	mp.clear();
	while(1){
		int res = 0;
		while(x){
			res += (x%b)*(x%b);
			x/=b;
		}
		if (res == 1)
			return 1;
		if (mp[res]) 
			return 0;
		else
			mp[res] = 1;
		x = res;
	}
	return 0;
}


int main() { 
	freopen("A.in","rt",stdin);
	freopen("A.out","wt",stdout);

	scanf("%d\n",&T);
	For(TT,1,T){
		gets(s);
		n=0;
		stringstream io(s);
		int a=0;
		while(io>>a){
			arr[n++]=a;
		}
		for (int i=2;;++i){
			bool ok = 1;
			Rep(j,n)
				if (!check(i,arr[j])){
					ok = 0;
					break;
				}
			if (ok) {
				printf("Case #%d: %d\n",TT,i);
				break;
			}
		}

	}

}


