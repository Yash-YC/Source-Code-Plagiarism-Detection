#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int T;

fstream in, out;

int len;
int bases[10];
int N = 50000;

int happy[10][50000];

int next(int x, int b) {
	int ret = 0;
	int y = x;
	while (y > 0) {
		int digit = y % b;
		ret += digit * digit;
		y /= b;
	}
	return ret;
}

int ishappy(int x, int i) {
	if (happy[i][x] != -1) {
		return happy[i][x];
	} else {
		happy[i][x] = 0;
		int n = next(x, bases[i]);
		happy[i][x] = ishappy(n, i);
	}
	
	return happy[i][x];
}

bool ishappy(int x) {
	for (int i = 0; i < len; i++) {
		if (ishappy(x, i) == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	in.open("prob1.in", fstream::in);
	out.open("prob1.out", fstream::out);

	in >> T;

	int temp;
	char temp2;
	bool done;
	bool found;
    for (int i = 0; i < T; i++) {
		len = 0;
		bases[0] = temp;
		done = false;
		while (! done) {
			in >> temp;
			in >> noskipws >> temp2;
			if (temp2 == '\n') {
				done = true;
			}
			bases[len] = temp;
			len++;
		}
        
		found = false;
		for (int ii = 0; ii < len; ii++) {
			for (int jj = 0; jj < N; jj++) {
				happy[ii][jj] = -1;
			}
			happy[ii][1] = 1;
		}
		int test = 2;
		int ans;
		while (! found) {
			if (ishappy(test)) {
				ans = test;
				found = true;
			}
			test++;
		}


		out << "Case #" << i + 1 << ": " << ans << endl;
    }
    
	in.close();
	out.close();

	return 0;
}
