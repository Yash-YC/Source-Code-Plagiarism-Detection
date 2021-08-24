#include <iostream>
#include <fstream>
#include <strstream>
#include <vector>
using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

int T;
int n;
char str[1000];

bool used[2000000];

bool check(int x, int base) {
	memset(used, false, sizeof(used));
	char vs[100];
	int t = 0;
	while(x > 0) {
		vs[t++] = x % base;
		x /= base;
	}
	int vss = 0;
	for(int i = t - 1; i >= 0; --i) {
		vss = vss * 10 + vs[i];
	}
	//used[vss] = true;
	while(true) {
		int tmp = 0;
		while(vss > 0) {
			int x2 = vss % 10;
			tmp += x2 * x2;
			vss /= 10;
		}
		if(tmp == 1) {
			return true;
		}
		if(tmp == 0) {
			return false;
		}
		vss = tmp;
		if(used[vss]) {
			return false;
		}
		used[vss] = true;
		char vs[100];
		int t = 0;
		while(vss > 0) {
			vs[t++] = vss % base;
			vss /= base;
		}
		vss = 0;
		for(int i = t - 1; i >= 0; --i) {
			vss = vss * 10 + vs[i];
		}
	}
}

int main() {
	in.getline(str, 999);
	T = atoi(str);
	char num[10];
	for(int x = 1; x <= T; ++x) {
		in.getline(str, 999);
		strstream strs;
		vector<int> v;
		strs << str;
		while(strs >> num) {
			v.push_back(atoi(num));
		}
		for(int i = 2; i < 1000000; ++i) {
			bool flag = true;
			for(int j = 0; j < v.size(); ++j) {
				if(!check(i, v[j])) {
					flag = false;
					break;
				}
			}
			if(flag) {

				out << "Case #" << x << ": " << i << endl;
				break;
			}

		}
	}
	
}