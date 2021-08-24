#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1100;

vector <int> mask;

int N, C;
double exp[MAXN];
bool tag[MAXN];

inline void dfs(int depth, int start, int mm) {
	if (depth == N) {
		mask.push_back(mm);
		return ;
	}
	for (int i = start; i < C; i++) {
		dfs(depth + 1, i + 1, mm | (1 << i));
	}
}

int main() {
	int task;
	scanf("%d", &task);
	for (int oo = 0; oo < task; oo++) {
		scanf("%d%d", &C, &N);
		mask.clear();
		dfs(0, 0, 0);
//		printf("N = %d C = %d\n", N, C);
		memset(exp, 0, sizeof(double) * (1 << C));
		exp[(1 << C) - 1] = 0.0;
		for (int mm = (1 << C) - 2; mm >= 0; mm--) {
			double a = 0.0, b = 0.0;
			for (int i = (int)mask.size() - 1; i >= 0; i--) {
				int tmpmm = mm | mask[i];
				if (tmpmm == mm) a += 1.0;
				else b += exp[tmpmm];
			}
			a /= (int)mask.size();
			b /= (int)mask.size();
			exp[mm] = (b + 1.0) / (1.0 - a);
		}
//		printf("mask.size = %d ans = %lf\n", (int)mask.size(), exp[0]);
		printf("Case #%d: %.7lf\n", oo + 1, exp[0]);
	}
}
