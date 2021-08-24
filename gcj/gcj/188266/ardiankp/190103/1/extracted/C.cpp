#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
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

////////////////////

int tc, ntc;
int n, c;
double dp[50];
bool used[50];

double comb[51][51];
void gen_comb()
{
	int i, j;
	for (i=0; i<=50; i++) for (j=0; j<=50; j++)
	{
		if (i < j) comb[i][j] = 0;
		else if (j == 0) comb[i][j] = 1;
		else comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
	}
}

double doit(int x)
{
	if (x == c) return 0;
	double& res = dp[x];
	if (used[x]) return res;
	used[x] = true;
	
	// ada x, sisa = n-x
	int i;
	res = 0;
	double A = 0;
	
	double p, tot=0;
	for (i=0; i<=n; i++)
	{
		if (x + i > c) break;
		p = comb[x][n-i] * comb[c-x][i];
		tot += p;
		
		if (i == 0) A = p;		
		res += p * (1 + doit(x+i));
	}
	
	//printf("%d: %lf %lf %lf\n", x, A, res, tot);
	
	A /= tot;
	res /= tot;
	res /= (1-A);
	
	
	return res;
}

int main()
{
	FILE* fi = fopen("C-large.in", "r");
	FILE* fo = fopen("C-large.out", "w");
	
	gen_comb();
	
	fscanf(fi, "%d", &ntc);
	for (tc=1; tc<=ntc; tc++)
	{
		fscanf(fi, "%d %d", &c, &n);
		memset(used, 0, sizeof(used));
		
		double res = doit( 0 );
		printf("Case #%d: %.10lf\n", tc, res);
		fprintf(fo, "Case #%d: %.10lf\n", tc, res);
	}
	
	fclose(fi); fclose(fo);
	
}