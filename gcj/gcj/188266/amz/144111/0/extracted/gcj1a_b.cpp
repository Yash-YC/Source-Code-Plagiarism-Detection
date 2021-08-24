#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <cmath>

using namespace std;

struct Cell {
	int S;
	int W;
	int T;

	int curPos(int t) {
		int div = S+W;
		int result = (t-T) % div;
		if (result < 0)
			result += div;
		return result;
	}
	bool isNSGreen(int t) { return curPos(t) < S; }
	bool isEWGreen(int t) { return curPos(t) >= S; }

	int timeToCross(int t, bool horiz)
	{
		if (horiz) {
			if (isEWGreen(t))
				return 1;
			else
				return 1+(S-curPos(t));
		} else {
			if (isNSGreen(t))
				return 1;
			else
				return 1+(S+W-curPos(t));
		}
	}
};

typedef vector<vector<Cell>> City;
typedef vector<vector<unsigned int>> Grid;

struct Point {
	int x, y;
	Point (int _x, int _y) : x(_x), y(_y) {}
};

unsigned int timeToCross(int sx, int sy, int ex, int ey, City& city, unsigned int t)
{
	int s, e;
	bool horiz;
	if (sx == ex && sy != ey) {
		// Vertical move
		s = sy;
		e = ey;
		horiz = false;
	} else if (sy == ey && sx != ex) {
		// Horizontal move
		s = sx;
		e = ex;
		horiz = true;
	} else {
		// oops?
		throw exception();
	}

	if (sx == 1 && sy == 1 && ex == 2 && ey == 1) {
		int a = 0;
	}

	// Crossing street
	if (s/2 == e/2) {
		return city[sx/2][sy/2].timeToCross(t, horiz);
	}

	// Moving along block
	else {
		return 2;
	}
}

void tryPoint(Point p, int x, int y, City& city, Grid& grid, list<Point> &todo)
{
	unsigned int t0 = grid[p.x][p.y];
	unsigned int t = t0 + timeToCross(p.x, p.y, x, y, city, t0);
	if (grid[x][y] > t) {
		grid[x][y] = t;
		todo.push_back(Point(x,y));
	}
}

void processPoint(Point p, City& city, Grid& grid, list<Point> &todo, int w, int h)
{
	if (p.x > 0)
		tryPoint(p, p.x-1, p.y, city, grid, todo);
	if (p.y > 0)
		tryPoint(p, p.x, p.y-1, city, grid, todo);
	if (p.x < w-1)
		tryPoint(p, p.x+1, p.y, city, grid, todo);
	if (p.y < h-1)
		tryPoint(p, p.x, p.y+1, city, grid, todo);
}

void processCase(int lineN, istream& in, ostream& out)
{
	// Parse case
	int N, M;
	in >> N >> M;
	City cells(M, vector<Cell>(N, Cell()));
	for (int y=0; y<N; y++) {
		for (int x=0; x<M; x++) {
			Cell &c = cells[x][y];
			in >> c.S >> c.W >> c.T;
		}
	}

	// Create grid
	int w = M*2;
	int h = N*2;
	Grid grid(w, vector<unsigned int>(h, (unsigned int)-1));

	list<Point> todo;
	todo.push_back(Point(0, h-1));
	grid[0][h-1] = 0;

	while (todo.size() > 0) {
		Point curPoint = todo.front();
		todo.pop_front();
		processPoint(curPoint, cells, grid, todo, w, h);
	}

	// Process
	int t = grid[w-1][0];

	// Print result
	out << "Case #" << lineN << ": ";
	out << t;
	out << endl;
}

int main()
{
	ifstream in("B-small-attempt0.in");
	//ostream& out = cout;
	ofstream out("B-small-attempt0.out", std::ios_base::out | std::ios_base::binary);

	int nCases;
	in >> nCases;
	for (int i=0; i<nCases; i++) {
		processCase(i+1, in, out);
	}

	out.flush();
}
