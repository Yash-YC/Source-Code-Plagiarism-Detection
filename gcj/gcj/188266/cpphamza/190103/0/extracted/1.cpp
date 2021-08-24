#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

int C, N;
vector<int> v;
double P;

const int MAX_LEVEL = 1000;
bool vis[MAX_LEVEL][1<<10];
double table[MAX_LEVEL][1<<10];
double get(int level, int mask){

	if((mask == (1<<C)-1) || level >= MAX_LEVEL)
		return 0;

	if(vis[level][mask])
		return table[level][mask];

	double r = 1;
	for(int i = 0 ; i < (int)v.size() ; i++)
		r += P*get(level+1, mask|v[i]);

	vis[level][mask] = true;
	return table[level][mask] = r;
}

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	//freopen("C-small-attempt0.in", "rt", stdin);
	//freopen("C-small-attempt0.out", "wt", stdout);
	freopen("C-small-attempt1.in", "rt", stdin);
	freopen("C-small-attempt1.out", "wt", stdout);
	//freopen("C-large.in", "rt", stdin);
	//freopen("C-large.out", "wt", stdout);

	int tt; cin >> tt;
	for(int t = 0 ; t < tt ; t++){
		cin >> C >> N;
		v.clear();

		for(int i = 0 ; i < (1<<C) ; i++){
			if(__builtin_popcount(i) != N)continue;
			v.push_back(i);
		}

 		P = 1.0/v.size();
		memset(vis, 0, sizeof vis);
		double res = get(0, 0);
		printf("Case #%d: %.7lf\n", t+1, res);
	}

	return 0;
}
