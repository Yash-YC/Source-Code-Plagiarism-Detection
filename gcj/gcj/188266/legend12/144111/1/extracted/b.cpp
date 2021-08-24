#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos {
	int x, y, z;
};

FILE *fp_r, *fp_w;
int t, n, m;
long long state[20][20][4];
queue<pos> q;
pos p;
int s[20][20], w[20][20], t0[20][20];
int ct, at;

int main() {
	fp_r = fopen("b.in", "r");
	fp_w = fopen("b.out", "w");

	fscanf(fp_r, "%d", &t);
	for(int i = 0; i < t; ++i) {
		fscanf(fp_r, "%d %d", &n, &m);

		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < m; ++k) {
				fscanf(fp_r, "%d %d %d", &s[j][k], &w[j][k], &t0[j][k]);
				for(int l = 0; l < 4; ++l)
					state[j][k][l] = -1;
			}
		}

		p.x = n-1;
		p.y = 0;
		p.z = 0;
		state[p.x][p.y][p.z] = 0;
		q.push(p);
		while(1) {
			if (q.empty()) break;

			if (q.front().x == 0 && q.front().y == m-1 && q.front().z == 2) ;
			else {
				switch(q.front().z) {
					case 0:
						if (q.front().y != 0) {
							p.x = q.front().x;
							p.y = q.front().y - 1;
							p.z = 3;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}
						if (q.front().x != n-1) {
							p.x = q.front().x + 1;
							p.y = q.front().y;
							p.z = 1;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}
						
						ct = (state[q.front().x][q.front().y][q.front().z] - t0[q.front().x][q.front().y]) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						if (ct < 0) {
							int r = 1 + (-ct) / (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
							ct = (ct + r * (s[q.front().x][q.front().y] + w[q.front().x][q.front().y])) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						}

						if (ct < s[q.front().x][q.front().y]) at = 0;
						else at = (s[q.front().x][q.front().y] + w[q.front().x][q.front().y] - ct);

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 1;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						if (ct < s[q.front().x][q.front().y]) at = s[q.front().x][q.front().y] - ct;
						else at = 0;

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 3;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						break;
					case 1:
						if (q.front().y != 0) {
							p.x = q.front().x;
							p.y = q.front().y - 1;
							p.z = 2;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}
						if (q.front().x != 0) {
							p.x = q.front().x - 1;
							p.y = q.front().y;
							p.z = 0;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}

						ct = (state[q.front().x][q.front().y][q.front().z] - t0[q.front().x][q.front().y]) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						if (ct < 0) {
							int r = 1 + (-ct) / (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
							ct = (ct + r * (s[q.front().x][q.front().y] + w[q.front().x][q.front().y])) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						}

						if (ct < s[q.front().x][q.front().y]) at = 0;
						else at = (s[q.front().x][q.front().y] + w[q.front().x][q.front().y] - ct);

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 0;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						if (ct < s[q.front().x][q.front().y]) at = s[q.front().x][q.front().y] - ct;
						else at = 0;

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 2;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						break;
					case 2:
						if (q.front().y != m-1) {
							p.x = q.front().x;
							p.y = q.front().y + 1;
							p.z = 1;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}
						if (q.front().x != 0) {
							p.x = q.front().x - 1;
							p.y = q.front().y;
							p.z = 3;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}

						ct = (state[q.front().x][q.front().y][q.front().z] - t0[q.front().x][q.front().y]) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						if (ct < 0) {
							int r = 1 + (-ct) / (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
							ct = (ct + r * (s[q.front().x][q.front().y] + w[q.front().x][q.front().y])) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						}

						if (ct < s[q.front().x][q.front().y]) at = 0;
						else at = (s[q.front().x][q.front().y] + w[q.front().x][q.front().y] - ct);

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 3;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						if (ct < s[q.front().x][q.front().y]) at = s[q.front().x][q.front().y] - ct;
						else at = 0;

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 1;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						break;
					case 3:
						if (q.front().y != m-1) {
							p.x = q.front().x;
							p.y = q.front().y + 1;
							p.z = 0;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}
						if (q.front().x != n-1) {
							p.x = q.front().x + 1;
							p.y = q.front().y;
							p.z = 2;
							if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + 2 < state[p.x][p.y][p.z]) {
								state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + 2;
								q.push(p);
							}
						}

						ct = (state[q.front().x][q.front().y][q.front().z] - t0[q.front().x][q.front().y]) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						if (ct < 0) {
							int r = 1 + (-ct) / (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
							ct = (ct + r * (s[q.front().x][q.front().y] + w[q.front().x][q.front().y])) % (s[q.front().x][q.front().y] + w[q.front().x][q.front().y]);
						}

						if (ct < s[q.front().x][q.front().y]) at = 0;
						else at = (s[q.front().x][q.front().y] + w[q.front().x][q.front().y] - ct);

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 2;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						if (ct < s[q.front().x][q.front().y]) at = s[q.front().x][q.front().y] - ct;
						else at = 0;

						p.x = q.front().x;
						p.y = q.front().y;
						p.z = 0;
						if (state[p.x][p.y][p.z] == -1 || state[q.front().x][q.front().y][q.front().z] + at + 1 < state[p.x][p.y][p.z]) {
							state[p.x][p.y][p.z] = state[q.front().x][q.front().y][q.front().z] + at + 1;
							q.push(p);
						}

						break;
				}
			}

			q.pop();
		}

		fprintf(fp_w, "Case #%d: %d\n", i+1, state[0][m-1][2]);
	}

	fclose(fp_w);
	fclose(fp_r);	

	return 0;
}