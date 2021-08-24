#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TF {
	int s, w, t;
	int t1, t2, t3, t4;
};
int time[501][501];

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<TF> > tfs;
		for (int i = 0; i < n; i++) {
			vector<TF> tfrow;
			for (int j = 0; j < m; j++) {
				TF tf = {0, 0, 0, 1234567890, 1234567890, 1234567890, 1234567890};
				scanf("%d%d%d", &tf.s, &tf.w, &tf.t);
				tfrow.push_back(tf);
			}
			tfs.push_back(tfrow);
		}

		tfs[n-1][0].t1 = 0;
		for (int i = n - 1; i >= 0 ; i--) {
			for (int j = 0; j < m; j++) {
				TF* tf = &tfs[i][j];
				int cycle = tf->s + tf->w;
				if (tf->t > tf->t1) tf->t = tf->t1 - (cycle - (tf->t - tf->t1) % cycle);
				else tf->t = tf->t1 - (tf->t1 - tf->t) % cycle;
				if (tf->t == tf->t1 - cycle) tf->t = tf->t1;
				int s1 = tf->t;
				int s2 = s1 + cycle;
				int w1 = tf->t + tf->s;
				int w2 = w1 + cycle;

				if (tf->t1 >= s1 && tf->t1 < w1) {
					if (tf->t1 + 1 <= w1) {
						tf->t2 = min(tf->t2, tf->t1 + 1); 
						tf->t4 = min(tf->t4, w1 + 1);
					}
					else {
						tf->t2 = min(tf->t2, s2 + 1);
						tf->t4 = min(tf->t4, s2 + tf->s + 1);
					}
					tf->t3 = min(tf->t3, w1 + 1);
					tf->t4 = min(tf->t4, w1 + tf->w + 1);
				}
				else {
					if (tf->t1 + 1 <= s2) {
						tf->t3 = min(tf->t3, tf->t1 + 1);
						tf->t4 = min(tf->t4, s2 + 1);
					}
					else {
						tf->t3 = min(tf->t3, w2 + 1);
						tf->t4 = min(tf->t4, w2 + tf->w + 1);
					}
					tf->t2 = min(tf->t2, s2 + 1);
					tf->t4 = min(tf->t4, s2 + tf->s + 1);
				}


				if (tf->t > tf->t2) tf->t = tf->t2 - (cycle - (tf->t - tf->t2) % cycle);
				else tf->t = tf->t2 - (tf->t2 - tf->t) % cycle;	
				if (tf->t == tf->t2 - cycle) tf->t = tf->t2;
				s1 = tf->t;
				s2 = s1 + cycle;
				w1 = tf->t + tf->s;
				w2 = w1 + cycle;
				if (tf->t2 < w1) tf->t4 = min(tf->t4, w1 + 1);
				else {
					if (tf->t2 + 1 <= s2) tf->t4 = min(tf->t4, tf->t2 + 1);
					else tf->t4 = min(tf->t4, w2 + 1);
				}


				if (tf->t > tf->t3) tf->t = tf->t3 - (cycle - (tf->t - tf->t3) % cycle);
				else tf->t = tf->t3 - (tf->t3 - tf->t) % cycle;	
				if (tf->t == tf->t3 - cycle) tf->t = tf->t3;
				s1 = tf->t;
				s2 = s1 + cycle;
				w1 = tf->t + tf->s;
				w2 = w1 + cycle;
				if (tf->t3 + 1 <= w1) tf->t4 = min(tf->t4, tf->t3 + 1);
				else tf->t4 = min(tf->t4, s2 + 1);

				if (i > 0) {
					TF* ntf = &tfs[i-1][j];
					ntf->t1 = min(ntf->t1, tf->t2 + 2);
					ntf->t3 = min(ntf->t3, tf->t4 + 2);
				}

				if (j < m-1) {
					TF* ntf = &tfs[i][j+1];
					ntf->t1 = min(ntf->t1, tf->t3 + 2);
					ntf->t2 = min(ntf->t2, tf->t4 + 2);
				}
			}
		}
		printf("Case #%d: %d\n", t, tfs[0][m-1].t4);

	}
	return 0;
}

