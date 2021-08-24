/*
 TASK:
 LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<bitset>
#include<cstring>
#include<climits>
#include<deque>
#include<utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
template<class key>
struct hashtemp
{

	enum
	{
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;

#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO = 0;
const long double INF = 1 / ZERO, EPSILON = 1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
int s[20][20];
int w[20][20];
int t[20][20];
int r, c;
//0  1  2  3
enum DIR{LR,LL,UL,UR};
int dir[4][2] =
{
{ 0, 1 },
{ 1, 0 },
{ 0, -1 },
{ -1, 0 } };

bool getDir(int i, int j, int k, int &ni, int &nj, int r, int c)
{
	ni = i + dir[k][0];
	nj = j + dir[k][1];
	return ni >= 0 && ni < r && nj < c && nj >= 0;
}
struct state
{
	int i, j;
	DIR k;
	int d;
	bool operator<(const state& s) const
	{
		return d> s.d;
	}
};
int dist[20][20][4];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "rt", stdin);
	freopen("b.out", "wt", stdout);
#endif
	int T;
	cin >> T;
	rep(tt,T)
	{
		cin >> r >> c;
		rep(i,r)
			rep(j,c)
			{
				cin >> s[i][j] >> w[i][j] >> t[i][j];
				t[i][j] %= s[i][j] + w[i][j];
				rep(k,4)
					dist[i][j][k] = INT_MAX;
			}
		state gs =
		{ 0, c - 1, (DIR)3, 0 };
		state ss =
		{ r - 1, 0, (DIR)1, 0 }, ns;
		dist[ss.i][ss.j][ss.k] = 0;
		priority_queue<state> q;
		q.push(ss);
		while (!q.empty())
		{
			ss = q.top();
			q.pop();
			if (ss.i == gs.i && ss.j == gs.j && ss.k == gs.k)
				break;
			rep(l,2)
			{
				int k = (ss.k + l) % 4;
				if (getDir(ss.i, ss.j, k, ns.i, ns.j, r, c))
				{
					ns.k =(DIR)(( (l ? 3 : 1) + ss.k)%4);
					ns.d = ss.d + 2;
					if (ns.d < dist[ns.i][ns.j][ns.k])
					{
						dist[ns.i][ns.j][ns.k] = ns.d;
						q.push(ns);
					}
				}
			}
			rep(l,2)
			{
				ns = ss;
				ns.k =(DIR)(( (l ? 3 : 1) + ss.k)%4);
				int d = ss.d;
				int x = d - t[ss.i][ss.j];
				x %= (s[ss.i][ss.j] + w[ss.i][ss.j]);
				x += t[ss.i][ss.j];
				while (x < t[ss.i][ss.j])
					x += (s[ss.i][ss.j] + w[ss.i][ss.j]);
				if ((ss.k+l) % 2)
				{
					//N-S
					if (x >= t[ss.i][ss.j] + s[ss.i][ss.j])
						d += t[ss.i][ss.j] + s[ss.i][ss.j] + w[ss.i][ss.j] - x
								;
				}
				else
				{
					//E-W
					if (x < t[ss.i][ss.j] + s[ss.i][ss.j])
						d += t[ss.i][ss.j] + s[ss.i][ss.j] - x ;
				}
				ns.d = d+1;
				if (ns.d < dist[ns.i][ns.j][ns.k])
				{
					dist[ns.i][ns.j][ns.k] = ns.d;
					q.push(ns);
				}
			}
		}
		cout<<"Case #"<<tt+1<<": "<<ss.d<<endl;
	}
	return 0;
}
