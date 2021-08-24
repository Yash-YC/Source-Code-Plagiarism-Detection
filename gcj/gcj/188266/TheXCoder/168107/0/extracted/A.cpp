#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
 
#define PI 3.1415926535897932384626433832795
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define rep(i,s,n) for(int i=s; i<n; i++)
#define repe(i,s,n) for(int i=s; i<=n; i++)
#define len(s) int((s).length()) 
#define pv(v) tr(v,i) cout << *i << " "; cout << endl
#define pr(i) cout << "i=" << i << endl
#define pr2(i,j) cout << "i="<<i<<" j="<<j<<endl
#define pr3(i,j,k) cout << "i="<<i<<" j="<<j<<" k="<<k<<endl
#define pr4(i,j,k,m) cout << "i="<<i<<" j="<<j<<" k="<<k<<"m="<<m<<endl;
#define valid(i,j,n,m) (i >= 0 && i < n && j >= 0 && j < m) 

using namespace std;

vector<int> tobaseb(int x,int b) {
	vector<int> ans; int i = 0;
	if(x==0) { ans.pb(0); return ans;}
	while(x) { ans.pb(x%b); x/=b;}
	return ans;
}
/*vectint sum_base(int n1, int n2, int b) {
	vector<int> num1 = tobaseb(n1,b);
	vector<int> num2 = tobaseb(n2,b);
	int n = sz(num1), m = sz(num2), i=0,j=0,c=0;
	while(i<n  && j < m) {
		
	}
	
}*/
int main() {
	int t,c=0;
	cin >> t;
	string x;
	getline(cin,x);
	while(t--) {
		c++;
		vector<int> bases;
		int b;
		string s;
		getline(cin,s);
		istringstream sin(s); 
		while(sin >> b) bases.pb(b);
		//pv(bases);
		int ans = 2;
		while(true) {
			bool flag = true;
			rep(i,0,sz(bases)) {
				
				int sum = ans;
				map<int,bool> exist;
				exist[sum] = true;
				do {
						vector<int> dig = tobaseb(sum,bases[i]);
						int sum_dig = 0;
						tr(dig,j) sum_dig += (*j)*(*j);
						sum = sum_dig;
						if(sum == 1) break;
						else if(exist[sum]) { flag = false; break;}
						else { exist[sum] = true;}
					 	
				}while(true);
				
			}
			if(flag) break;
			ans ++;
		}
		
		cout<<"Case #"<<c<<": "<<ans;
		if(t != 0) cout << endl; 
		
	}	
	return 0;
}
