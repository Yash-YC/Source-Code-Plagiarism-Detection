#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long LL;
#define F(l,n) for (int l = 0; l < (int)(n); l++)
main(){

	FILE *fin = freopen("B-large.in", "r", stdin);
	assert (fin != NULL);
	
	FILE *fout = freopen("B-large.out", "w", stdout);
	int T, n;
	vector<int> count(2501,0), res;
	//vector<vector<int> > l;
	//vector<int>l;
	int x;
	
	cin >> T;

	for(int t = 1; t <= T; t++){
		cin >> n;
		res.clear();
		F(i,2*n-1){
			F(j,n){
				cin >> x;
				count[x]++;
				//cout << x << ' ';
				//l.push_back()			
			}
			//cout << endl;

		}
		F(i,2501){
			if (count[i]%2 != 0)
				res.push_back(i);
			count[i] = 0;
		}
		sort(res.begin(),res.end());

		cout << "Case #" << t << ": ";
		F(i,n){
			cout << res[i] << " "; 
		}
		cout << endl;
	
	}
	exit(0);
}
