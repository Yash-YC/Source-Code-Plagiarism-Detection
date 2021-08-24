#include <vector>
#include <string>
#include <map>
#include <algorithm>
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
	for (i=0; i<tvs.size(); i++) res.push_back( atoi(tvs[i].c_str()) );
	return res;
}

vi s2vi(string s)
{
	return s2vi(s, " ");
}

//////////////////////////

int tc, ntc;
char dp[11][10000];
char dpnex[11][10000];

inline int nex(int base, int x)
{
	if (x < 10000 && dpnex[base][x] != -1) return dpnex[base][x];
	
	int res = 0;	
	while (x)
	{
		int a = x % base;
		res += a * a;
		x /= base;
	}
	
	if (x < 10000) dpnex[base][x] = res;	
	return res;
}

inline char doit(int base, int x)
{
	x = nex(base, x);
	
	int xx = x;	
	while (dp[base][x] == -1)
	{
		dp[base][x] = 0;
		x = nex(base, x);	
	}		
	if (dp[base][x] == 0) return 0;
	
	x = xx;
	while (dp[base][x] == 0)
	{
		dp[base][x] = 1;
		x = nex(base, x);
	}
	return 1;
}

vector <int> happy_lis[11];
void gen()
{
	int b;
	for (b=2; b<=10; b++)
	{
		if (b == 2 || b == 4) continue;
		
		int i;
		for (i=2; i<=11814485; i++) if (doit(b, i))
			happy_lis[b].push_back( i );
		printf("%d\n", happy_lis[b].size());
	}
}

char buf[10000];
int main()
{
	FILE* fi = fopen("A-large.in", "r");
	FILE* fo = fopen("A-large.out", "w");
	
	memset(dp, -1, sizeof(dp));
	memset(dpnex, -1, sizeof(dpnex));
	
	int i, j;
	for (i=2; i<=10; i++) dp[i][1] = 1;
	
	gen();
	printf("finish gen\n");
	
	fscanf(fi, "%d", &ntc);
	fgets(buf, 10000, fi);	
	
	for (tc=1; tc<=ntc; tc++)
	{
		fgets(buf, 10000, fi);
		int len = strlen( buf );
		buf[--len] = 0;
		
		vi v = s2vi ( buf );
		v.resize(remove(v.begin(), v.end(), 2) - v.begin());
		v.resize(remove(v.begin(), v.end(), 4) - v.begin());
		//for (i=0; i<v.size(); i++) printf("%d ", v[i]); printf("\n");
		
		int pos[10];
		for (i=0; i<10; i++) pos[i] = 0;
					
		int a, b;
		if (v.empty()) a = 2;
		else
		{	
			while (true)
			{
				if (v.empty()) break;
				
				a = happy_lis[v[0]][ pos[0] ];
				b = 0;
				for (j=1; j<v.size(); j++)
				{
					b = happy_lis[v[j]][ pos[j] ];
					if (a != b) break;
				}
				if (j == v.size()) break;
				if (a < b) pos[0]++;
				else pos[j]++;			
			}
		}
			
		printf("Case #%d: %d\n", tc, a);
		fprintf(fo, "Case #%d: %d\n", tc, a);
	}
	
	fclose(fi); fclose(fo);
}