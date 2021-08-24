#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct loc_t
{
	int r;
	int c;
	int l;
	loc_t(){}
	loc_t(int R,int C,int L):r(R),c(C),l(L){}
	bool operator<(const loc_t& L) const
	{
		return r<L.r || r==L.r&&c<L.c || r==L.r&&c==L.c&&l<L.l;
	}
};
int R,C;
int a[20][20][4];
int S[20][20];
int W[20][20];
int T[20][20];
int wait_NS(int t,int S,int W,int T)
{
	int x=(t-T)%(S+W); if (x<0) x+=S+W;
	if (x<S) return 0;
	else return S+W-x;
}
int wait_EW(int t,int S,int W,int T)
{
	int x=(t-T)%(S+W); if (x<0) x+=S+W;
	if (x<S) return S-x;
	else return 0;
}
void dijkstra(loc_t src)
{
	memset(a,0x3F,sizeof(a));
	priority_queue<pair<int,loc_t> > Q;
	Q.push(make_pair(0,src));
	while (Q.size())
	{
		pair<int,loc_t> P=Q.top();
		loc_t L=P.second;
		Q.pop();
		if (L.r<0||L.c<0||L.r>=R||L.c>=C) continue;
		if (a[L.r][L.c][L.l]<P.first)
			continue;
		a[L.r][L.c][L.l]=P.first;
		//walk along the road
		switch(L.l)
		{
		case 0:
			Q.push(make_pair(P.first+2,loc_t(L.r-1,L.c,2)));
			Q.push(make_pair(P.first+2,loc_t(L.r,L.c-1,1)));
			break;
		case 1:
			Q.push(make_pair(P.first+2,loc_t(L.r-1,L.c,3)));
			Q.push(make_pair(P.first+2,loc_t(L.r,L.c+1,0)));
			break;
		case 2:
			Q.push(make_pair(P.first+2,loc_t(L.r+1,L.c,0)));
			Q.push(make_pair(P.first+2,loc_t(L.r,L.c-1,3)));
			break;
		case 3:
			Q.push(make_pair(P.first+2,loc_t(L.r+1,L.c,1)));
			Q.push(make_pair(P.first+2,loc_t(L.r,L.c+1,2)));
			break;
		}
		//walk across the road
		switch(L.l)
		{
		case 0:
			Q.push(make_pair(P.first+wait_NS(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,2)));
			Q.push(make_pair(P.first+wait_EW(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,1)));
			break;
		case 1:
			Q.push(make_pair(P.first+wait_NS(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,3)));
			Q.push(make_pair(P.first+wait_EW(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,0)));
			break;
		case 2:
			Q.push(make_pair(P.first+wait_NS(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,0)));
			Q.push(make_pair(P.first+wait_EW(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,3)));
			break;
		case 3:
			Q.push(make_pair(P.first+wait_NS(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,1)));
			Q.push(make_pair(P.first+wait_EW(P.first,S[L.r][L.c],W[L.r][L.c],T[L.r][L.c])+1,
				loc_t(L.r,L.c,2)));
			break;
		}
	}
}
int main()
{
	int _C,i,j,k;
	cin >> _C;
	for (i=1; i<=_C; i++)
	{
		cin >> R >> C;
		for (j=0; j<R; j++)
			for (k=0; k<C; k++)
				cin >> S[j][k] >> W[j][k] >> T[j][k];
		//4 vertices per intersection
		//1|2
		//---
		//3|4
		dijkstra(loc_t(R-1,0,2));
		printf("Case #%d: %d\n",i,a[0][C-1][1]);
	}
	return 0;
}