#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

typedef long long LL;
typedef vector <string> vs;
typedef vector <int> vi;
typedef vector <LL> vll;
typedef vector <double> vd;
typedef pair <int,int> pii;


vs token(string s, string d)
{
	string t;
	vs res;
	int pos;
	while (true)
	{
		pos = s.find(d);
		if (pos == -1) break;
		t = s.substr(0, pos);
		s = s.substr(pos+d.length());
		if (t != "") res.push_back( t );
	}
	if (s != "") res.push_back( s );
	return res;
}

vs token(string s)
{
	return token(s, " ");
}

vi s2vi(string s, string d)
{
	vs tvs = token(s, d);
	vi res;
	int i;
	for (i=0; i<tvs.size(); i++) res.push_back( atoi(tvs[i].c_str()) 

);
	return res;
}

vi s2vi(string s)
{
	return s2vi(s, " ");
}

///////////////////////

#define INF 1000000000000000LL

int tc, ntc;
int n, m;
int S[25][25], W[25][25], T[25][25];

long long val[25][25][4];
bool used[25][25][4];

struct tt
{
	int r, c, s;
};
bool operator<(const tt& a, const tt& b)
{
	return false;
}

priority_queue< pair<LL,tt> > pq;
void add(const tt& t, LL v)
{
	if (val[t.r][t.c][t.s] > v)
	{
		val[t.r][t.c][t.s] = v;
		pq.push( make_pair(-v, t) );
	}
}

LL get_tim(LL cur, int y, int x, int dir)
{
	//printf("y=%d x=%d : %d\n", y, x, dir);	
	//printf("n=%d, m=%d\n", n, m);
	if (y < 0 || y >= n || x < 0 || x >= m) return -1;
	
	//bool debug = false;
	//if (cur == 6 && y == 0 && x == 1 && dir == 1)
		//debug = true;
	
	LL A, B, C;
	if (dir == 0)
	{
		A = S[y][x];
		B = W[y][x];
		C = T[y][x];
	}
	else
	{
		A = W[y][x];
		B = S[y][x];
		C = T[y][x] + S[y][x];
	}
	
	//if (debug) printf("%lld -- %lld %lld %lld\n", cur, A, B, C);
	
	LL period = A + B;
	C %= period;
	
	LL part = cur;
	part = (part-C)%period;
	if (part < 0) part += period;
	
	// bisa langsung nyebrang
	if (part < A) return cur + 1;
	return cur + (period-part) + 1;
}

void get_nex(tt cur, LL cval, int dir, tt& nex, LL& nval)
{
	nex = cur;
	if (dir == 0)
	{
		if (cur.s & 2) 
		{
			nex.s -= 2;
			nval = cval + 2;
		}
		else
		{
			nex.s += 2;
			if (nex.s & 1) nval = get_tim(cval, nex.r-1, nex.c, 0);
			else nval = get_tim(cval, nex.r-1, nex.c - 1, 0);
			nex.r--;
			return;
		}
	}
	
	if (dir == 2)
	{
		if (!(cur.s & 2))
		{
			nex.s += 2;
			nval = cval + 2;
		}
		else
		{
			nex.s -= 2;
			if (nex.s & 1) nval = get_tim(cval, nex.r, nex.c, 0);
			else nval = get_tim(cval, nex.r, nex.c-1, 0);
			
			nex.r ++;
			return;
		}
	}

	if (dir == 3)
	{
		if (cur.s & 1) 
		{
			nex.s--;
			nval = cval + 2;
		}
		else
		{
			nex.s++;
			if (nex.s & 2) nval = get_tim(cval, nex.r, nex.c-1, 1);
			else nval = get_tim(cval, nex.r-1, nex.c-1, 1);
			nex.c--;
			return;
		}
	}
	
	if (dir == 1)
	{
		if (!(cur.s & 1))
		{
			nex.s++;
			nval = cval + 2;
		}
		else
		{
			nex.s--;
			if (nex.s & 2) nval = get_tim(cval, nex.r, nex.c, 1);
			else nval = get_tim(cval, nex.r-1, nex.c, 1);
			nex.c++;
			return;
		}
	}
	
	
		
}

LL dijkstra()
{
	int i, j, k;
	for (i=0; i<=n; i++) for (j=0; j<=m; j++) for (k=0; k<4; k++)
		val[i][j][k] = INF;
		
	memset(used, 0, sizeof(used));
		
	tt cur, nex;
	LL cval, nval;
	cur.r = cur.c = 0;
	cur.s = 3;
	
	pq = priority_queue< pair<LL,tt> >();
	add(cur, 0);
	
	pair<LL,tt> xx;
	while (!pq.empty())
	{
		xx = pq.top();
		pq.pop();
		
		cur = xx.second;
		if (used[cur.r][cur.c][cur.s]) continue;
		used[cur.r][cur.c][cur.s] = true;						
		cval = -xx.first;
		
//		printf("%d %d %d : %lld\n", cur.r, cur.c, cur.s, cval);
		
		if (cur.r == n && cur.c == m) return cval;
		
		for (i=0; i<4; i++)
		{
			get_nex(cur, cval, i, nex, nval);
			if (nval != -1)
				add(nex, nval);
		}
	}
	
	return -1;
}

int main()
{
	FILE* fi = fopen("B-small0.in", "r");
	FILE* fo = fopen("B-small0.out", "w");
	
	fscanf(fi, "%d", &ntc);
	int i, j;
	for (tc=1; tc<=ntc; tc++)
	{
		fscanf(fi, "%d %d", &n, &m);
		for (i=0; i<n; i++) for (j=0; j<m; j++)
			fscanf(fi, "%d %d %d", &S[i][j], &W[i][j], &T[i][j]);			
		
		LL res = dijkstra();		
		printf("Case #%d: %lld\n", tc, res);
		fprintf(fo, "Case #%d: %lld\n", tc, res);
	}
	
	
}