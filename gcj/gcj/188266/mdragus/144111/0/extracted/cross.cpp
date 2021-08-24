#include<stdio.h>
#include<vector>
#include<set>
#define mkp make_pair
#define pb push_back

using namespace std;

const int maxn = 40;
const int INF = 1000000000;

int MAT[maxn][maxn][6];
vector<pair<int,pair<int,int> > > VECT;
int N,M,NRT;
vector<pair<int,int> > TI;
int S[maxn][maxn],W[maxn][maxn],T[maxn][maxn];


inline int abs(int x){return x < 0 ? -x : x;}

int ver(int timp,int x,int y,int dir)
{
	int p = S[x][y] + W[x][y];
	int timp1 = T[x][y] % p;
	timp %= p;
	int i,c;
	for(c = 0,i = timp;i <= 10000;++i,++c)
	{
		if (i % p == timp1)break;
	}
	if (dir == 1) return c;
	c += S[x][y];
	c %= p;
	return c;
/*	TI.clear();
	if (timp1 != 0)
	{
		TI.pb(mkp(0,2));
		TI.pb(mkp(timp1,1));
	}
	else
	{
		TI.pb(mkp(timp1,1));
		TI.pb(mkp(timp1 + S[x][y],2));
	}
	for(int i = 2;i < 6; ++i)
			TI.pb(mkp(TI[i - 2].first + p,TI[i - 2].second));
	timp += p;
	int cur = INF;
//	printf("%d\n",timp);
	for(int i = 0;i < 5; ++i)
	{
		int act = TI[i].first;
		int urm = TI[i + 1].first;
//		printf("%d %d %d\n",act,urm,TI[i].second);
		if (TI[i].second == dir) 
		{
			if (act >= timp) cur = min(cur,abs(timp - act));
			//cur = min(cur,abs(timp - urm + 1));
			if (timp >= act && timp < urm) cur = 0;
		}
	}
	return cur;
*/
}

void check(int x,int y,int poz,int timp)
{
	if (MAT[x][y][poz] > timp) 
	{
		MAT[x][y][poz] = timp;
		VECT.pb(mkp(x,mkp(y,poz)));
	}
}


int main()
{
	freopen("cross.in","r",stdin);
	freopen("cross.out","w",stdout);
	scanf("%d\n",&NRT);
	for(int nr = 1;NRT;--NRT,++nr)
	{
		scanf("%d %d",&N,&M);
		for(int i = 1;i <= N; ++i)
				for(int j = 1;j <= M; ++j) scanf("%d %d %d",&S[i][j],&W[i][j],&T[i][j]);
		for(int i = 1;i <= N; ++i)
			for(int j = 1;j <= M; ++j)
				for(int k = 1;k <= 4; ++k)
					MAT[i][j][k] = INF;
		MAT[N][1][1] = 0;
//		printf("%d\n",ver(1,1,1,2));
		VECT.pb(mkp(N,mkp(1,1)));
		for(int i = 0;i < (int)VECT.size(); ++i)
		{
			int x = VECT[i].first;
			int y = VECT[i].second.first;
			int poz = VECT[i].second.second;
			int timp = MAT[x][y][poz];
//			printf("%d %d\n",poz,timp);
			if (poz == 1)
			{
				if (x != N)	check(x + 1,y,3,timp + 2);
				if (y != 1) check(x,y - 1,2,timp + 2);
				int timpnou = timp + ver(timp,x,y,1);
				check(x,y,3,timpnou + 1);
			   	timpnou = timp + ver(timp,x,y,2);
				check(x,y,2,timpnou + 1);	
			}
			if (poz == 2)
			{
				if (y != M) check(x,y + 1,1,timp + 2);
			   	if (x != N) check(x + 1,y,4,timp + 2);
				int timpnou = timp + ver(timp,x,y,1);
				check(x,y,4,timpnou + 1);
				timpnou = timp + ver(timp,x,y,2);
				check(x,y,1,timpnou + 1);	
			}
			if (poz == 3)
			{
				if (x != 1) check(x - 1,y,1,timp + 2);
				if (y != 1) check(x,y - 1,4,timp + 2);
				int timpnou = timp + ver(timp,x,y,1);
				check(x,y,1,timpnou + 1);
				timpnou = timp + ver(timp,x,y,2);
			//	printf(" -- %d %d \n",timpnou,timp);
				check(x,y,4,timpnou + 1);
			}
			if (poz == 4)
			{
				if (x != 1) check(x - 1,y,2,timp + 2);
				if (y != M) check(x,y + 1,3,timp + 2);
				int timpnou = timp + ver(timp,x,y,1);
				check(x,y,2,timpnou + 1);
				timpnou = timp + ver(timp,x,y,2);
				check(x,y,3,timpnou + 1);
			}
		}
		printf("Case #%d: %d\n",nr,MAT[1][M][4]);
	}



	return 0;
}


