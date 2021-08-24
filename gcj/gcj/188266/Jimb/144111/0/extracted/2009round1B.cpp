// Using libUtil from libGlov (Game Library of Victory) available at http://bigscreensmallgames.com/libGlov
#include "utilUtils.h"
#include "utilFile.h"
#include "utilString.h"
#include "assert.h"
#include "utilArray.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include "utilRand.h"
#include <vector>
#include <queue>
using namespace std;

int N, M;
int w, h;
typedef struct {
	int S, W, T;
	int cycle;
	int bestT;
} Node;
Node nodes[21][21];

int bestT[21*2][21*2];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Elem {
public:
	Elem(int _x, int _y, int _t):x(_x),y(_y),T(_t)
	{
	}
	int x, y, T;
	bool operator<(const Elem &e) const
	{
		return T >= e.T;
	}
};

int findTimeEW(int ix, int iy, int T)
{
	int tt = T - nodes[ix][iy].T + nodes[ix][iy].cycle;
	tt %= nodes[ix][iy].cycle;
	if (tt < nodes[ix][iy].S)
	{
		// currently red
		return T + (nodes[ix][iy].S - tt);
	}
	// no waiting
	return T;
}

int findTimeNS(int ix, int iy, int T)
{
	int tt = T - nodes[ix][iy].T + nodes[ix][iy].cycle;
	tt %= nodes[ix][iy].cycle;
	if (tt < nodes[ix][iy].S)
		return T; // no waiting, already green
	return T + (nodes[ix][iy].cycle - tt);
}

char *doB(char **&toks)
{
	static char buf[16384];
	N = atoi(*toks++);
	M = atoi(*toks++);
	memset(bestT, 0, sizeof(bestT));
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			nodes[j][i].S = atoi(*toks++);
			nodes[j][i].W = atoi(*toks++);
			nodes[j][i].T = atoi(*toks++);
			nodes[j][i].cycle = nodes[j][i].S + nodes[j][i].W;
			nodes[j][i].T %= nodes[j][i].cycle;
		}
	}
	w = M*2;
	h = N*2;
	int startx = 0, starty = h - 1;
	int destx = w - 1, desty = 0;
	priority_queue<Elem, vector<Elem> > pq;
	pq.push(Elem(startx, starty, 0));
	while (!pq.empty())
	{
		Elem e = pq.top();
		pq.pop();
		for (int i=0; i<4; i++)
		{
			int x = e.x + dx[i];
			int y = e.y + dy[i];
			if (x>=0 && y>=0 && x<w && y<h)
			{
				Elem e2(x, y, e.T);
				if (e.x&1 && dx[i]<0 ||
					!(e.x&1) && dx[i]>0)
				{
					int ix = (MIN(e.x, e2.x))/2;
					int iy = (e.y & ~1)/2;
					e2.T = findTimeEW(ix, iy, e.T) + 1;
				} else if (e.y&1 && dy[i]<0 ||
					!(e.y&1) && dy[i]>1)
				{
					int ix = (e.x & ~1)/2;
					int iy = (MIN(e.y, e2.y))/2;
					e2.T = findTimeNS(ix, iy, e.T) + 1;
				} else {
					// Walking down the street
					e2.T += 2;
				}
				if (!bestT[e2.x][e2.y] || e2.T < bestT[e2.x][e2.y])
				{
					bestT[e2.x][e2.y] = e2.T;
					pq.push(e2);
				}
			}
		}
	}

	sprintf(buf, "%d", bestT[destx][desty]);
	return buf;
}
