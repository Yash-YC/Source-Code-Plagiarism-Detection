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

int nex(int base, int x)
{
	int res = 0;	
	while (x)
	{
		int a = x % base;
		res += a * a;
		x /= base;
	}
	return res;
}

char doit(int base, int x)
{
	dp[base][1] = 1;
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

char buf[10000];
int main()
{
	FILE* fi = fopen("A-small.in", "r");
	FILE* fo = fopen("A-small.out", "w");
	
	memset(dp, -1, sizeof(dp));
	
	fscanf(fi, "%d", &ntc);
	fgets(buf, 10000, fi);	
	
	for (tc=1; tc<=ntc; tc++)
	{
		fgets(buf, 10000, fi);
		int len = strlen( buf );
		buf[--len] = 0;
		
		vi v = s2vi ( buf );
		int i, j;
		//for (i=0; i<v.size(); i++) printf("%d ", v[i]); printf("\n");
		
		for (i=2;;i++)
		{
			for (j=0; j<v.size(); j++) if (!doit(v[j], i)) break;
			if (j == v.size()) break;
			//printf("i=%d\n", i);
		}
			
		printf("Case #%d: %d\n", tc, i);
		fprintf(fo, "Case #%d: %d\n", tc, i);
	}
	
	fclose(fi); fclose(fo);
}