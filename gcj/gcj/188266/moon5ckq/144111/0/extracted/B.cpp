#include <cstdio>
#include <cstring>
#define oo 25
#define nn 1605
#define New() (&Link[Link_len++])
struct Tlnk
{
	int v,s,g,r;
	Tlnk *next;
}	*e[nn],Link[nn*20];
struct Tnode
{
	int s,w,t;
}	a[oo][oo];
long long f[nn];
int id[oo][oo];
int Test,N,M,Case,K;
int Link_len;
bool mk[nn];

inline void Readin()
{
	scanf("%d%d",&N,&M);
	for (int i=N;i>0;--i)
		for (int j=1;j<=M;++j)
			scanf("%d%d%d",&a[i][j].s,&a[i][j].w,&a[i][j].t);
}

inline void Add(int x,int y,int s,int g,int r)
{
	Tlnk *L=New();
	L->v=y;
	L->s=s;
	L->g=g;
	L->r=r;
	L->next=e[x];
	e[x]=L;
}

inline void Prepare()
{
	K=0;
	memset(e,0,sizeof e);
	Link_len=0;
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j)
		{
			id[i][j]=++K;
			K+=3;
		}
			
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j)
		{
			if (j<M)
			{
				Add(id[i][j]+1,id[i][j+1],-1,2,0);
				Add(id[i][j]+2,id[i][j+1]+3,-1,2,0);
			}
			if (i<N)
			{
				Add(id[i][j]+3,id[i+1][j],-1,2,0);
				Add(id[i][j]+2,id[i+1][j]+1,-1,2,0);
			}
			if (j>1)
			{
				Add(id[i][j]+0,id[i][j-1]+1,-1,2,0);
				Add(id[i][j]+3,id[i][j-1]+2,-1,2,0);
			}
			if (i>1)
			{
				Add(id[i][j]+0,id[i-1][j]+3,-1,2,0);
				Add(id[i][j]+1,id[i-1][j]+2,-1,2,0);
			}
			
			Tnode u=a[i][j];
			Add(id[i][j]+0,id[i][j]+1,u.t+u.s,u.w,u.s);
			Add(id[i][j]+1,id[i][j]+0,u.t+u.s,u.w,u.s);
			
			Add(id[i][j]+2,id[i][j]+1,u.t,u.s,u.w);
			Add(id[i][j]+1,id[i][j]+2,u.t,u.s,u.w);
			
			Add(id[i][j]+2,id[i][j]+3,u.t+u.s,u.w,u.s);
			Add(id[i][j]+3,id[i][j]+2,u.t+u.s,u.w,u.s);
			
			Add(id[i][j]+3,id[i][j]+0,u.t,u.s,u.w);
			Add(id[i][j]+0,id[i][j]+3,u.t,u.s,u.w);
		}
}

inline long long Calc(int s,int g,int r,long long u)
{
	if (s==-1) return u+2;
	s%=g+r;
	if (u+1<=s)
	{
		if (u+1<=s-r) return u+1;
		return s+1;
	}
	else{
		long long v=u-s;
		v%=g+r;
		v++;
		if (v<=g) return u+1;
		else
			return u+1-v+g+r+1;
	}
}

inline void Solve()
{
	memset(f,63,sizeof f);
	memset(mk,0,sizeof mk);
	f[1]=0;
	
	while (true)
	{
		int u=0;
		for (int i=1;i<=K;++i)
			if (!mk[i] && (!u || f[u]>f[i])) u=i;
		
		mk[u]=true;
		if (u==K-1) break;
		
		for (Tlnk *l=e[u];l;l=l->next)
			f[l->v]<?=Calc(l->s,l->g,l->r,f[u]);
	}
	
	printf("%I64d\n",f[K-1]);
}

int main()
{
	//freopen("i.txt","r",stdin);
	
	for (scanf("%d",&Test);Test--;)
	{
		printf("Case #%d: ",++Case);
		Readin();
		Prepare();
		Solve();
	}
	
	return 0;
}
