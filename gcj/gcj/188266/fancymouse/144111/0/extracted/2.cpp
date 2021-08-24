#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;

typedef long long int64;
const int MaxN = 20;
const int MaxV = 4*MaxN*MaxN;
int S[MaxN][MaxN];
int W[MaxN][MaxN];
int T[MaxN][MaxN];
int n,m;
int64 dij(int s,int t);
int adj(int n){return n&1 ? n+1 : n-1;}
int cross(int n){return n&1 ? n-1 : n+1;}
int cost(int i,int j,int dir,int t);
bool Range(int a,int b,int c){return a<=b && b<c;}
int main()
{
	int _;
	cin>>_;
	for(int cases=1;cases<=_;cases++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>S[i][j]>>W[i][j]>>T[i][j];
		int v = 4*n*m;
		cout<<"Case #"<<cases<<": "<<dij(0,v-1)<<endl;
	}
	return 0;
}
int cost(int i,int j,int dir,int t)
{
	int s = S[i][j], w = W[i][j], t0 = T[i][j];
	t -= t0;
	t %= s+w;
	if(t < 0) t += s+w;
	int result = 1;
	if(dir == 0)
	{
		if(t >= s)
			result += s+w-t;
	}
	else
	{
		if(t < s)
			result += s-t;
	}
	return result;
}
int64 dij(int s,int t)
{
	const int64 INF = 0x0fffffffffffffffll;
	int64 d[MaxV];
	bool v[MaxV];
	memset(v,false,sizeof(v));
	int n2 = n*2, m2 = m*2;
	for(int i=0;i<n2*m2;i++)
		d[i] = INF;
	d[s] = 0;
	for(int i=1;i<n2*m2;i++)
	{
		int id = -1;
		int64 curmin = INF;
		for(int j=0;j<n2*m2;j++)
			if(!v[j] && d[j] < curmin)
				id = j, curmin = d[j];
		v[id] = true;
		if(id == t) break;
		int x = id / m2, y = id % m2;
		int x2 = adj(x), y2 = adj(y);
		if(Range(0,x2,n2) && d[id]+2 < d[x2*m2+y])
			d[x2*m2+y] = d[id]+2;
		if(Range(0,y2,m2) && d[id]+2 < d[x*m2+y2])
			d[x*m2+y2] = d[id]+2;
		x2 = cross(x), y2 = cross(y);
		int64 c = cost(x/2,y/2,0,d[id]);
		if(d[id] + c < d[x2*m2+y])
			d[x2*m2+y] = d[id] + c;
		c = cost(x/2,y/2,1,d[id]);
		if(d[id] + c < d[x*m2+y2])
			d[x*m2+y2] = d[id] + c;
	}
	return d[t];
}
