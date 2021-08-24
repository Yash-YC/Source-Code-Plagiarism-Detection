#include<stdio.h>
#include<algorithm>
using namespace std;
struct cross
{
	int s,w,t;
}cr[20][20];
struct hn
{
	int i,j,t;
	bool operator<(const hn &z)const
	{
		return t>z.t;
	}
}h[20*20*4];
int t[40][40];
int gs(int t,const cross &cro)
{
	int z=((t-cro.t)%(cro.s+cro.w)+(cro.s+cro.w))%(cro.s+cro.w);
	if(z<cro.s)return 0;
	else return cro.s+cro.w-z;
}
int gw(int t,const cross &cro)
{
	int z=((t-cro.t)%(cro.s+cro.w)+(cro.s+cro.w))%(cro.s+cro.w);
	if(z>=cro.s)return 0;
	else return cro.s-z;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c;
	scanf("%d",&c);
	for(int cc=1;cc<=c;cc++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d%d%d",&cr[i][j].s,&cr[i][j].w,&cr[i][j].t),cr[i][j].t%=(cr[i][j].s+cr[i][j].w);
		h[0].i=0,h[0].j=0,h[0].t=0;
		memset(t,0x7f,sizeof(t));
		t[h[0].i][h[0].j]=0;
		int hh=1;
		while(hh)
		{
/*
			for(int i=0;i<hh;i++)printf("%d %d %d %d\n",h[i].i,h[i].j,h[i].t,t[h[i].i][h[i].j]);
			putchar('\n');
*/
			if(h[0].t>t[h[0].i][h[0].j])
			{
				pop_heap(h,h+(hh--));
				continue;
			}
			hn z=h[0];
			pop_heap(h,h+(hh--));
			if(z.i%2)
			{
				if(z.i+1<n+n)
				{
					h[hh]=z;
					h[hh].i++;
					h[hh].t+=2;
					if(h[hh].t<t[h[hh].i][h[hh].j])
					{
						t[h[hh].i][h[hh].j]=h[hh].t;
						push_heap(h,h+(hh++));
					}
				}
				h[hh]=z;
				h[hh].i--;
				h[hh].t+=gs(h[hh].t,cr[z.i/2][z.j/2])+1;
				if(h[hh].t<t[h[hh].i][h[hh].j])
				{
					t[h[hh].i][h[hh].j]=h[hh].t;
					push_heap(h,h+(hh++));
				}
			}
			else
			{
				if(z.i)
				{
					h[hh]=z;
					h[hh].i--;
					h[hh].t+=2;
					if(h[hh].t<t[h[hh].i][h[hh].j])
					{
						t[h[hh].i][h[hh].j]=h[hh].t;
						push_heap(h,h+(hh++));
					}
				}
				h[hh]=z;
				h[hh].i++;
				h[hh].t+=gs(h[hh].t,cr[z.i/2][z.j/2])+1;
				if(h[hh].t<t[h[hh].i][h[hh].j])
				{
					t[h[hh].i][h[hh].j]=h[hh].t;
					push_heap(h,h+(hh++));
				}
			}
			if(z.j%2)
			{
				if(z.j+1<m+m)
				{
					h[hh]=z;
					h[hh].j++;
					h[hh].t+=2;
					if(h[hh].t<t[h[hh].i][h[hh].j])
					{
						t[h[hh].i][h[hh].j]=h[hh].t;
						push_heap(h,h+(hh++));
					}
				}
				h[hh]=z;
				h[hh].j--;
				h[hh].t+=gw(h[hh].t,cr[z.i/2][z.j/2])+1;
				if(h[hh].t<t[h[hh].i][h[hh].j])
				{
					t[h[hh].i][h[hh].j]=h[hh].t;
					push_heap(h,h+(hh++));
				}
			}
			else
			{
				if(z.j)
				{
					h[hh]=z;
					h[hh].j--;
					h[hh].t+=2;
					if(h[hh].t<t[h[hh].i][h[hh].j])
					{
						t[h[hh].i][h[hh].j]=h[hh].t;
						push_heap(h,h+(hh++));
					}
				}
				h[hh]=z;
				h[hh].j++;
				h[hh].t+=gw(h[hh].t,cr[z.i/2][z.j/2])+1;
				if(h[hh].t<t[h[hh].i][h[hh].j])
				{
					t[h[hh].i][h[hh].j]=h[hh].t;
					push_heap(h,h+(hh++));
				}
			}
		}
//		printf("%d %d %d %d\n",h[0].i,h[0].j,h[0].t,t[h[0].i][h[0].j]);
		printf("Case #%d: %d\n",cc,t[n+n-1][m+m-1]);
/*
		for(int i=0;i<n+n;i++)
		{
			for(int j=0;j<m+m;j++)printf("%d ",t[i][j]);
			putchar('\n');
		}
*/
	}
}
