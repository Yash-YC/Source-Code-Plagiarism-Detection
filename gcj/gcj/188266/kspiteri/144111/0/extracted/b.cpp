#include <iostream>

int wait(int s, int w, int t, int now, bool ns)
{
    now += s + w - t % (s + w);
    now %= s + w;
    if (ns) {
	if (now < s)
	    return 0;
	else
	    return s + w - now;
    } else {
	if (now < s)
	    return s - now;
	else
	    return 0;
    }
}

int main()
{
    int C;
    std::cin >> C;
    for (int cs = 1; cs <= C; ++cs) {
	int N, M;
	std::cin >> N >> M;
	int S[20][20];
	int W[20][20];
	int T[20][20];
	for (int i = 0; i < N; ++i) {
	    for (int j = 0; j < M; ++j) {
		std::cin >> S[j][N - i - 1]
			 >> W[j][N - i - 1]
			 >> T[j][N - i - 1];
	    }
	}
	int bits = N + N + M + M - 2;
	int poss = 1 << bits;
	int min = 0;
	for (int i = 0; i < poss; ++i) {
	    int x = 0;
	    int y = 0;
	    int cur = i;
	    int now = 0;
	    for (int j = 0; j < bits; ++j) {
		bool ns = cur % 2;
		cur /= 2;
		if (ns) {
		    if (y == N + N - 1)
			continue;
		    else if (y % 2 == 1)
			now += 2;
		    else
			now += wait(S[x / 2][y / 2],
				    W[x / 2][y / 2],
				    T[x / 2][y / 2],
				    now, true) + 1;
		    ++y;
		} else {
		    if (x == M + M - 1)
			continue;
		    else if (x % 2 == 1)
			now += 2;
		    else
			now += wait(S[x / 2][y / 2],
				    W[x / 2][y / 2],
				    T[x / 2][y / 2],
				    now, false) + 1;
		    ++x;
		}
	    }
	    if (x == M + M - 1 && y == N + N - 1 &&(min == 0 || now < min))
		min = now;
	}
	std::cout << "Case #" << cs << ": " << min << std::endl;
    }
}
