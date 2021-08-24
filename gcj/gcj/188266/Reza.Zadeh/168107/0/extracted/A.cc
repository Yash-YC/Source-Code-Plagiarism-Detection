#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <ctype.h>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back


/*change n into base b*/
#define N 14000000

int mem[N][11];

bool ishappy(ll n, int b) {
	if(b== 2 || b==4) return true;

	int ret;
	if(n < N)
		ret = mem[n][b];
	if(ret != -1 && n < N) return ret;
	
	set<ll> seen;

	ll curn = n;
	while(1) {
		if(seen.find(curn)!=seen.end()) {
			ret = false;
			break;
		}
		seen.insert(curn);

		ll tempn = curn;
		ll sum=0;
		
		while(tempn!=0){
		    	sum+=(tempn%b)*(tempn%b);
			tempn/=b;
		}
	
		if(sum == 1) {
			ret = true;
			break;
		}

		if(curn < N && mem[curn][b] == 0){
			ret = false;
			break;
		}

		curn = sum;
	}

	if(n < N)
		mem[n][b] = ret;
	return ret;
}


int main(){
	memset(mem, -1, sizeof(mem));
	int T;
	string temp;
	getline(cin, temp);
	T = atoi(temp.c_str());
	for(int cnt = 0; cnt < T; cnt++) {
		getline(cin, temp);
		stringstream ss(temp.c_str());
		int hah;
		vector<int> bases;
		while(ss >> hah) bases.push_back(hah);

		for(int ret = 2; true; ret++) {
			bool allgood = true;
			for(int i = 0; i < bases.size(); i++)
				if(!ishappy(ret, bases[i])) 
					{allgood = false; break;}
			if(allgood) {
				cout << "Case #" << (cnt+1) << ": " << ret << endl;
				break;
			}
			if(ret%1000000==0) cout << ret  << endl;
		}
	}
}


