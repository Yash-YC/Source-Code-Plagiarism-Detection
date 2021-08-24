#include <stdio.h>
typedef long long ll;
int R,C;
int RN,CN;
struct inter
{
	ll s,w,x;
	ll getDiff(int t)
	{
		int c=s+w;
		int diff = t-x;
		if (diff<0) diff = (c-(-diff)%c)%c;
		else diff%=c;
		return diff;
	}
	ll nearSouth(int t)
	{
		ll diff=getDiff(t);
		if (diff<s) return 0;
		return s+w-diff;
	}
	ll nearWest(int t)
	{
		ll diff=getDiff(t);
		if (diff>=s) return 0;
		return s-diff;
	}
}I[20][20];
int Vs[50][50];
ll Best[50][50];
ll dj(int r1,int c1,int r2,int c2)
{
	for (int q=0;q<RN;q++) for (int w=0;w<CN;w++)
		Vs[q][w]=0;
	Vs[r1][c1]=1;
	Best[r1][c1]=0;
	while (true)
	{
		int bi,bj;
		ll bc=-1;
		for (int q=0;q<RN;q++) for (int w=0;w<CN;w++)
			if (Vs[q][w]==1)
			{
				if (bc<0 || Best[q][w]<bc)
				{
					bc=Best[q][w];
					bi=q;
					bj=w;
				}
			}
		if (bc<0) break;
		Vs[bi][bj]=2;
		for (int dr=-1;dr<=1;dr+=2)//row cross
		{
			if (bi+dr<0 || bi+dr>=RN) continue;
			int next = bi + dr;
			ll cost = 0;
			if ( next/2 != bi/2 ) cost = 2;
			else cost = 1 + I[bi/2][bj/2].nearSouth(Best[bi][bj]);
			if (Vs[next][bj]==0 || Best[next][bj]>Best[bi][bj]+cost)
			{
				Vs[next][bj]=1;
				Best[next][bj]=Best[bi][bj]+cost;
			}
		}
		for (int dc=-1;dc<=1;dc+=2)//col cross
		{
			if (bj+dc<0 || bj+dc>=CN) continue;
			int next=bj+dc;
			ll cost=0;
			if (next/2 != bj/2) cost = 2;
			else cost = 1 + I[bi/2][bj/2].nearWest(Best[bi][bj]);
			if (Vs[bi][next] == 0 || Best[bi][next]>Best[bi][bj]+cost)
			{
				Vs[bi][next]=1;
				Best[bi][next]=Best[bi][bj]+cost;
			}
		}
	}
	return Best[r2][c2];
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		scanf("%d %d",&R,&C);
		RN=R*2,CN=C*2;
		for (int q=0;q<R;q++) for (int w=0;w<C;w++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			I[q][w].s=a;
			I[q][w].w=b;
			I[q][w].x=c;
		}
		printf("Case #%d: %lld\n",kase,dj(RN-1,0,0,CN-1));
	}
	return 0;
}
