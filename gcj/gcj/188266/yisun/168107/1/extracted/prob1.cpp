#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int T;

fstream in, out;

int len;
int bases[10];
int N = 10000;

int happy[11][10000];

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
	if (x < N) {
		if (happy[bases[i]][x] != -1) {
			return happy[bases[i]][x];
		} else {
			happy[bases[i]][x] = 0;
			int n = next(x, bases[i]);
			happy[bases[i]][x] = ishappy(n, i);
		}
	
		return happy[bases[i]][x];
	} else {
		int n = next(x, bases[i]);
		return ishappy(n, i);
	}
}

bool ishappy(int x) {
	for (int i = 0; i < len; i++) {
		if (ishappy(x, i) == 0) {
			return false;
		}
	}
	return true;
}

bool isbad() {
	for (int i = 5; i <= 10; i++) {
		bool found = false;
		for (int j = 0; j < len; j++) {
			if (bases[j] == i) {
				found = true;
			}
		}
		if (! found) {
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
		if (i == 0) {
			for (int ii = 0; ii <= 10; ii++) {
				for (int jj = 0; jj < N; jj++) {
					happy[ii][jj] = -1;
				}
				happy[ii][1] = 1;
			}
		}
        
		if (isbad()) {
			out << "Case #" << i + 1 << ": " << "11814485" << endl;
		} else {
			found = false;	
		
			
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
    }
    
	in.close();
	out.close();

	return 0;
}
