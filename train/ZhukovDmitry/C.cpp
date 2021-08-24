#include "bits/stdc++.h"

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template <class _T> inline string tostr(const _T &a) { ostringstream os(""); os << a; return os.str(); }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;

int n;
int a[1024];
VI g[1024];
int d[1024];
bool u[1024];

int dfs(int k, int x0, int y0)
{
	if (d[k]) return d[k];
	int &ans = d[k];
	ans = 1;
	forn(i1, g[k].sz)
	{
		int i = g[k][i1];
		if (k == x0 && i == y0) continue;
		ans = max(ans, dfs(i, x0, y0) + 1);
	}
	return ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	int tc;
	scanf("%d", &tc);
	For(tn, 1, tc)
	{
		printf("Case #%d: ", tn);
		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%d", &a[i]);
			a[i]--;
			g[a[i]].pb(i);
		}
		int ans = 0;
		forn(i, n)
		{
			clr(u);
			int x = i;
			forn(j, n)
			{
				x = a[x];
			}
			int k = 0;
			forn(j, n)
			{
				if (u[x]) break;
				u[x] = true;
				x = a[x];
				k++;
			}
			ans = max(ans, k);
		}
		int ans2 = 0;
		forn(i, n)
		{
			int x = i;
			int y = a[x];
			if (a[y] != x || x > y) continue;
			clr(d);
			ans2 += dfs(x, x, y) + dfs(y, y, x);
		}
		ans = max(ans, ans2);

		printf("%d\n", ans);
		forn(i, n)
		{
			g[i].clear();
		}

		fprintf(stderr, "Case #%d: %0.0lf ms\n", tn, clock() * 1000.0 / CLOCKS_PER_SEC);
	}
	fprintf(stderr, "---\n");
	
	return 0;
}
