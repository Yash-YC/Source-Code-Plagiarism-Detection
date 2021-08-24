#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<math.h>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert> 
#include <list>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
typedef stringstream SS; 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i=0;i<n;i++)
#define fr2(i, a, n) for(i=a;i<n;i++)
#define mem(a, n) memset(a, n, sizeof(a))
const int l = 1 << 10;
typedef vector<int> VI;
inline string getInBase(int n, int b) {
	string s;
	while(n) {
		s = char (n % b + '0') + s;
		n /= b;
	}
	return s;
	
}
inline int getSum(string s) {
	int sum = 0;
	int l = s.sz;
	int i;
	fr(i, l) {
		int a = s[i] - '0';
		sum += a * a;
	}
	return sum;
}
inline int getSums(int n) {
	int sum = 0;
	while(n) {
		int a = n % 10;
		sum += a * a;
		n /= 10;
	}
	return sum;
}
int main() {
	int t;
	scanf("%d", &t);
	string s;
	getline(cin, s);
	int k;
	int i, j;
	int n = 2;
	VI m[11];
	fr2(i, 2, 80003)
		m[2].pb(i);
	for(int base=3;base<=10;base++) {
		int n = 1;
		while(n<=80000) {
			n++;
			string s = getInBase(n, base);
			int sum = 0;
			sum = getSum(s);
			map <int, bool> ma;
			while(1) {
				if(sum==1) {
					m[base].pb(n);
					break;
				}
				if(ma[sum])
					break;
				ma[sum] = 1;
				s = getInBase(sum, base);
				sum = getSum(s);
			}
		
		}
	}
/*	fr(i, m[6].sz)
		cout << m[6][i] << " ";
		cout << endl;
	fr(i, m[8].sz)
                cout << m[8][i] << " ";
                cout << endl;
	fr(i, m[8].sz)
                cout << m[9][i] << " ";
                cout << endl;
	*/
	for(k=1;k<=t;k++) {
		char bo[1000];
		string s;
		gets(bo);
		s = bo;
		int a[10];
		int c = 0;
		SS ss;
		ss << s;
		while(ss >> s) {
			a[c++] = atoi(s.c_str());
		}
		VI v1 = m[a[0]];
		vector <int> tmp(80002);
	
		int num = -1;
		fr(i, c) {
			vector <int> res = vector <int> (tmp.begin(), set_intersection(all(v1), all(m[a[i]]), tmp.begin()));
			v1 = res;
			num = res[0];
			
		}
			
		printf("Case #%d: %d\n", k, num);
		
	}
}
