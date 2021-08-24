#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int doit(int x, int y, int t,
	 int N, int M, vector <vector <int> > &S,
	 vector <vector <int> > &W, vector <vector <int> > &T)
{
	if (x == M * 2 - 1 && y == N * 2 - 1) {
		return 0;
	}
	int ret = 1 << 30;
	int cycle = S[y / 2][x / 2] + W[y / 2][x / 2];
	int org = ((t - T[y / 2][x / 2]) % cycle + cycle) % cycle;
	int cross;
	if (x % 2 == 0) {
		if (org >= S[y / 2][x / 2]) {
			cross = 1;
		} else {
			cross = S[y / 2][x / 2] - org + 1;
		}
		ret = min(ret, cross + doit(x + 1, y, t + cross,
					    N, M, S, W, T));
	} else if (x < M * 2 - 1) {
		ret = min(ret, 2 + doit(x + 1, y, t + 2, N, M, S, W, T));
	}
	if (y % 2 == 0) {
		if (org < S[y / 2][x / 2]) {
			cross = 1;
		} else {
			cross = cycle - org + 1;
		}
		ret = min(ret, cross + doit(x, y + 1, t + cross,
					    N, M, S, W, T));
	} else if (y < N * 2 - 1) {
		ret = min(ret, 2 + doit(x, y + 1, t + 2, N, M, S, W, T));
	}
	return ret;
}

int CrossingTheRoad(int N, int M, vector <vector <int> > &S,
		    vector <vector <int> > &W, vector <vector <int> > &T)
{
	return doit(0, 0, 0, N, M, S, W, T);
}

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N, M;
		cin >> N >> M;

		vector <vector <int> > S(N, M);
		vector <vector <int> > W(N, M);
		vector <vector <int> > T(N, M);
		for (int y = N - 1; y >= 0; y--) {
			for (int x = 0; x < M; x++) {
				cin >> S[y][x] >> W[y][x] >> T[y][x];
			}
		}

		int ret = CrossingTheRoad(N, M, S, W, T);

		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
