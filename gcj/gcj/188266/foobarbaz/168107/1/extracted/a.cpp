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
#include <fstream>

using namespace std;

#define FOR(i,a,b)	for(int i=(a); i<(b); ++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define MP make_pair
#define PB push_back
#define SZ size()
#define iss istringstream 

#define SORT(x) sort(x.begin(), x.end())
#define ALL(x) x.begin(), x.end()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end()) 
#define dbg(x) cerr << #x << " -> '" << (x) << "'\t"
#define dbge(x) cerr << #x << " -> '" << (x) << "'\n"

typedef long long ll, int64;
typedef vector<int> VI;

int64 INF = 1000*1000*1001;

int convert(int x, int base)	{	//convert x from base 10 into base
	int pw = 1, ans = 0;
	while (pw*base <= x)	pw *= base;
	while (pw >= 1)	{
		assert(x < pw*base);
		ans = ans * 10 + (x / pw);
		x -= (x / pw)*pw;
		pw /= base;			
	}
	return ans;
}


int sum_convert(int x, int base)	{	//convert x from base 10 into base and then find sum of squares
	int ans = 0;
	while (x > 0)	{
		int dig = x % base;
		ans += dig*dig;
		x /= base;
	}
	return ans;
}


bool isHappy(int x, int base)	{
	set<int> lst;
	int tmp = sum_convert(x, base);
	lst.insert(1);
	while (lst.find(tmp) == lst.end())	{
		lst.insert(tmp);
		tmp = sum_convert(tmp, base);
	}
	if (tmp == 1)	return true;
	return false;
	
	/*
	int tmp = convert(x, base);
	
	lst.insert(1);
	while (lst.find(tmp) == lst.end())	{
		tot = s
		
		
		lst.insert(tmp);
		int tot = 0;
		while (tmp > 0)	{
			int k = tmp % 10;
			tmp /= 10;
			tot += k*k;
		}
	
		tmp = convert(tot, base);
	}
	*/
	
}

int main(int argc, char* argv[])	{
	int best[2048];
	memset(best, 255, sizeof best);
	/*
	int rem = (1<<9) - 1;
	int i = 2;
	while (rem > 0)	{
		int msk = 0;
		FOR (b, 2, 11)	{
			if (isHappy(i, b))	msk |= 1<<b;
		}
		if (msk == 0)	{	cout << "BAD!" << i << endl;	}//assert(msk != 0);
		
		for (int j = msk; j > 0; j = (j-1)&msk)	{
			if (best[j] == -1)	{
				cout << rem << "\t" << j << "\t" << i << endl;
				best[j] = i;
				rem--;
			}
		}				
		i++;
	}
	*/
	
	assert(argc > 1);
	ifstream fin;
	fin.open(argv[1]);
	while (!fin.eof())	{
		int a, b, c;
		fin >> a >> b >> c;
		best[b] = c;
	}
	fin.close();
	
	/*
	FOR (i, 0, 2048)	if (i%4 == 0)	{
		cout << i << "\t" << best[i] << endl;
	}
	*/
	
	int C;
	cin >> C;
	cin.ignore();
	string s;
	FOR (nc, 1, C+1)	{
		getline(cin, s);
		//cout << "read " << s << endl;
		istringstream iss(s, istringstream::in);
		int msk = 0;
		while (!iss.eof())	{
			int t;
			iss >> t;
			msk |= 1<<t;
		}
		cout << "Case #" << nc << ": " << best[msk] << endl;
	}
	
}
