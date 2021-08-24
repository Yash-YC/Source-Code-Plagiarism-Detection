// Uses the gnu multiprecision library GMP
// Run with arguments NROFCPUS input file and concatenate the output files 1..100 to obtain the result
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <gmpxx.h>
#include <gmp.h>
#include <unistd.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
// typedef long double ld;
typedef mpq_class ld;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}


int N;
ld F;
char li[1000000];
int s[1000000];

int chk(ld d) {
	if (d < 0)
		return -1;
	vector<pair<ld,pair<int, ld> > > v;
	REP(i,0,N+1) {
		v.push_back({s[i]-i*(F+d), {-i, s[i]-i*(F-d)}});
	}
	sort(v.begin(), v.end());
	ld mir = -1e100;
	int res = N+10;
	for (auto &p : v) {
		if (mir >= p.second.second) {
			setmin(res, -p.second.first);
		}
		setmax(mir, p.second.second);
	}
	if (res > N+1)
		return -1;
	return res;
}

void readcase() {
	int fa, fb;
	scanf("%d %d.%d %s ", &N, &fa, &fb, li);
}

void docase() {
	int fa, fb;
	scanf("%d %d.%d %s ", &N, &fa, &fb, li);
	F = ld(1000000*fa+fb, 1000000);
	s[0] = 0;
	REP(i,0,N)
		s[i+1] = s[i]+(li[i] == '1');
	ld a = -1, b = 1;
	REP(ru,0,30) {
		ld m = (a+b)/2;
		if (chk(m) != -1)
			b = m;
		else
			a = m;
	}
	fprintf(stderr, "a = %s, b = %s\n", a.get_str().c_str(), b.get_str().c_str());
	assert(chk(a) == -1 && chk(b) != -1);
	printf("%d\n", chk(b));
}

int CPUS;

void blub(int i) {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		if (test%CPUS == i) {
			fprintf(stderr, "Test %d/%d\n", test+1, T);
			char fn[1000];
			sprintf(fn, "%d", test+1);
			freopen(fn, "w", stdout);
			printf("Case #%d: ", test+1);
			docase();
		} else
			readcase();
		fflush(stdout);
		fflush(stderr);
	}
	fprintf(stderr, "DONE %d\n", i);
}

int main(int argc, char **argv) {
	sscanf(argv[1], "%d", &CPUS);
	REP(i,0,CPUS) {
		if (!fork()) {
			freopen(argv[2], "r", stdin);
			blub(i);
			return 0;
		}
	}
	return 0;
}
