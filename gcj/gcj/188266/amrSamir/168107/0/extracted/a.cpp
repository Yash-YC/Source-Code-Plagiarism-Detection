/*
 * a.cpp
 *
 *  Created on: ??þ/??þ/????
 *      Author: Amr
 */


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <complex>
using namespace std;

set <int> f;

bool  isG(int i, int b){
	if( i == 1 )return 1;
	int sum = 0;
	//cout << i << " : ";
	while(i){
		//cout << i%b << " ";
		sum += (i%b)*(i%b);
		i/=b;
	}
	int sz = f.size();
	f.insert(sum);
	if( sz == f.size()) return 0;
	return isG(sum,b);
}

int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
	int t;
	scanf("%d ",&t);
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i+1 << ": " ;
		string s;
		getline(cin,s);
		stringstream ss(s);
		vector <int> bs;
		int tt;
		while(ss >> tt )
			bs.push_back(tt);
		for(int i = 2 ; ; i++ ){
			bool can = 1;
			for (int j = 0; j < bs.size(); ++j) {
				f.clear();
				if( !isG(i,bs[j]) ){ can = 0; break;  }
			}
			if(can){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
