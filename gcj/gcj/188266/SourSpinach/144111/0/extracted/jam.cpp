//CODEJAM B

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

#define f first
#define s second

int main()
{
	//vars
	ifstream cin ("B-large.in");
	ofstream cout ("B-large.out");
	int T,N,sy,sx,y,x,t,c,a,b,t2,c2;
	int dyn[25][25][4];
	int ts[25][25],tw[25][25],tt[25][25];
	pair<pair<pair<int,int>,int>,int> cur;
	//testcase loop
	cin >> N;
		for (T=1; T<=N; T++)
		{
			//input
			cin >> sy >> sx;
				for (a=0; a<sy; a++)
					for (b=0; b<sx; b++)
					{
						cin >> ts[a][b] >> tw[a][b] >> tt[a][b];
						tw[a][b]+=ts[a][b];
						tt[a][b]%=tw[a][b];
					}
			//dynamic
			memset(dyn,100,sizeof(dyn));
			cur.f.f.f=0;
			cur.f.f.s=sy-1;
			cur.f.s=0;
			cur.s=0;
			dyn[sy-1][0][0]=0;
			priority_queue <pair<pair<pair<int,int>,int>,int> > Q;
			Q.push(cur);
				while (!Q.empty())
				{
					//get next state
					cur=Q.top(),Q.pop();
					t=-cur.f.f.f,y=cur.f.f.s,x=cur.f.s,c=cur.s;
					//done?
						if ((y==0) && (x==sx-1) && (c==3))
						{
							cout << "Case #" << T << ": " << t << endl;
							goto done;
						}
					//been here?
						if (dyn[y][x][c]!=t)
							continue;
					//cross street left-right
					t2=(t-tt[y][x]+tw[y][x])%tw[y][x];
						if (t2<ts[y][x])
							t2=ts[y][x]-t2;
						else
							t2=0;
					t2+=t+1;
						if (c<2)
							c2=1-c;
						else
							c2=5-c;
						if (dyn[y][x][c2]>t2)
						{
							dyn[y][x][c2]=t2;
							cur.f.f.f=-t2,cur.s=c2;
							Q.push(cur);
						}
					//cross street up-down
					t2=(t-tt[y][x]+tw[y][x])%tw[y][x];
						if (t2>=ts[y][x])
							t2=tw[y][x]-t2;
						else
							t2=0;
					t2+=t+1;
						if (c%2)
							c2=4-c;
						else
							c2=2-c;
						if (dyn[y][x][c2]>t2)
						{
							dyn[y][x][c2]=t2;
							cur.f.f.f=-t2,cur.s=c2;
							Q.push(cur);
						}
					//go right
						if ((c%2) && (x<sx-1))
						{
							t2=t+2;
							c2=c-1;
								if (dyn[y][x+1][c2]>t2)
								{
									dyn[y][x+1][c2]=t2;
									cur.f.f.f=-t2,cur.f.f.s=y,cur.f.s=x+1,cur.s=c2;
									Q.push(cur);
								}
						}
					//go left
						if ((c%2==0) && (x>0))
						{
							t2=t+2;
							c2=c+1;
								if (dyn[y][x-1][c2]>t2)
								{
									dyn[y][x-1][c2]=t2;
									cur.f.f.f=-t2,cur.f.f.s=y,cur.f.s=x-1,cur.s=c2;
									Q.push(cur);
								}
						}
					//go up
						if ((c>1) && (y>0))
						{
							t2=t+2;
							c2=c-2;
								if (dyn[y-1][x][c2]>t2)
								{
									dyn[y-1][x][c2]=t2;
									cur.f.f.f=-t2,cur.f.f.s=y-1,cur.f.s=x,cur.s=c2;
									Q.push(cur);
								}
						}
					//go down
						if ((c<2) && (y<sy-1))
						{
							t2=t+2;
							c2=c+2;
								if (dyn[y+1][x][c2]>t2)
								{
									dyn[y+1][x][c2]=t2;
									cur.f.f.f=-t2,cur.f.f.s=y+1,cur.f.s=x,cur.s=c2;
									Q.push(cur);
								}
						}
				}
			cout << "Oh crap..." << endl;
done:;
		}
	return(0);
}