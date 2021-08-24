#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int T;
int C;
int N;

double prob[41][41];

double binom[42][42];

double val[41];

fstream in, out;

int main() {
	in.open("prob3.in", fstream::in);
	out.open("prob3.out", fstream::out);
	out.precision(10);


	in >> T;

	binom[0][0] = 1;
	for (int t = 1; t <= 41; t++) {
		binom[t][0] = 1;
		for (int u = 1; u < t; u++) {
			binom[t][u] = binom[t - 1][u - 1] + binom[t - 1][u];
		}
		binom[t][t] = 1;
	}

    for (int i = 0; i < T; i++) {
		in >> C >> N;
		double ans;

		for (int x = 0; x <= C; x++) {
			for (int y = 0; y <= C; y++) {
				if (y < x) {
					prob[x][y] = 0;
				} else {
					if (N - y + x < 0 || N - y + x > x) {
						prob[x][y] = 0;
					} else {
						prob[x][y] = binom[x][N - y + x] * binom[C - x][y - x] / binom[C][N];
					}
				}					
			}
		}

		val[C] = 0;
		for (int w = C - 1; w >= 0; w--) {
			double sum = 1;
			for (int v = w + 1; v <= C; v++) {
				sum += prob[w][v] * val[v];
			}
			val[w] = sum / (1 - prob[w][w]);
		}

		out << "Case #" << i + 1 << ": " << val[0] << endl;
    }
    
	in.close();
	out.close();

	return 0;
}
