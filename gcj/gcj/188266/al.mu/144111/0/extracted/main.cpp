#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int NMAX = 22;
const int RMAX = 2*NMAX;

typedef long long TIME;
const TIME TMAX = LLONG_MAX;


struct Cross 
{
	TIME s, w, t;
};
struct Pos
{
	TIME t_in;
};


int n, m, rn, rm;

Cross cross[NMAX][NMAX];
Pos   pos[RMAX][RMAX];

struct Qu
{
	int i, j;
	
	Qu(int the_i, int the_j)
		:i(the_i), j(the_j)
	{}

	bool operator<(const Qu& that)const
	{
		return pos[i][j].t_in < pos[that.i][that.j].t_in;
	}
};

void input()
{
	cin >> n >> m;
	rn = 2*n;
	rm = 2*m;

	for(int i=0; i<NMAX; i++)
	{
		for(int j=0; j<NMAX; j++)
		{
			cross[i][j].s = 0;
			cross[i][j].w = 0;
			cross[i][j].t = 0;
		}
	}
	for(int ri=0; ri<RMAX; ri++)
	{
		for(int rj=0; rj<RMAX; rj++)
		{
			pos[ri][rj].t_in = TMAX;
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> cross[i][j].s >> cross[i][j].w >> cross[i][j].t;
		}
	}
}

std::priority_queue<Qu> qu;

void moveToPos(int iPos, int jPos, TIME tNew)
{
	if( iPos<0 || iPos>=rn ) return;
	if( jPos<0 || jPos>=rm ) return;

	if( pos[iPos][jPos].t_in > tNew )
	{
		////cout << "   to ("<<iPos<<" "<<jPos<<"): "<<tNew<<endl;
		pos[iPos][jPos].t_in = tNew;
		qu.push( Qu(iPos,jPos) );
	}
}

TIME solve()
{
	while(qu.size()) qu.pop();

	int riDst = 0;
	int rjDst = rm-1;

	moveToPos(rn-1,0,0);

	while( qu.size() )
	{
		Qu cur = qu.top();
		qu.pop();
		int ri = cur.i;
		int rj = cur.j;
		TIME tNow = pos[ri][rj].t_in;

		////cout << "from ("<<ri<<" "<<rj<<"): "<<tNow<<endl;

	
		//Find who waits
		TIME nsWait, weWait;
		{
			Cross &cr = cross[ri/2][rj/2];
			TIME cycleTime = tNow-cr.t+(cr.s+cr.w)*(cr.s+cr.w);
			cycleTime %= (cr.s+cr.w);
			if( cycleTime < cr.s )
			{
				// north-south green
				nsWait = 0;
				weWait = cr.s - cycleTime;
			}
			else
			{
				// north-south red
				nsWait = cr.s+cr.w - cycleTime;
				weWait = 0;
			}
		}
		
		// north-south dir
		if( ri&1 )
		{
			moveToPos(ri-1,rj,tNow+1+nsWait);
			moveToPos(ri+1,rj,tNow+2);
		}
		else
		{
			moveToPos(ri-1,rj,tNow+2);
			moveToPos(ri+1,rj,tNow+1+nsWait);
		}

		// west-east dir
		if( rj&1 )
		{
			moveToPos(ri,rj-1,tNow+1+weWait);
			moveToPos(ri,rj+1,tNow+2);	
		}
		else
		{
			moveToPos(ri,rj-1,tNow+2);
			moveToPos(ri,rj+1,tNow+1+weWait);
		}
	}	
	
	return pos[riDst][rjDst].t_in;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numTests = 0;
	cin >> numTests;
	for(int it=0; it<numTests; it++)
	{
		input();
		TIME result = solve();
		cout << "Case #" << it+1 << ": " << result << endl;
	}
	return 0;
}

