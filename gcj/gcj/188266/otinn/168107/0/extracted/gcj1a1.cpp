#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

const int lim = 12000000;
unsigned know[9][lim / 32];
unsigned happy[9][lim / 32];
unsigned small[20];

inline bool get(const int base, int num) {
	const int NUM = num;
	vector <int> to;
	int t1, t2;
	memset(small, 0, sizeof(small));
	//cout << base << " " << num << endl;
	while(!(know[base - 2][num / 32] & (1 << (num % 32)))) {
		//cout << num << endl;
		//system("pause");
		if(num < 20 * 32 && (small[num / 32] & (1u << (num % 32))))
			goto end;
		if(num < 20 * 32)
			small[num / 32] |= (1u << (num % 32));
		to.push_back(num);
		//cout << num << endl;
		t1 = 0;
		t2 = num;
		while(t2) {
			//cout << (t2 % base) << "^2 + " << endl;
			t1 += (t2 % base) * (t2 % base);
			t2 /= base;
		}
		num = t1;
	}
end:;
	to.push_back(NUM);
	//cout << "== " << num << endl << endl;
	//system("pause");
	//for(int i = 0; i < 9; ++i)
	//	cout << i << ": " << know[i][0] << " " << happy[i][0] << endl;
	foreach(i, 0, to) {
		//cout << "to: " << to[i] << endl;
		know[base - 2][to[i] / 32] |= (1u << (to[i] % 32));
		if(happy[base - 2][num / 32] & (1u << (num % 32)))
			happy[base - 2][to[i] / 32] |= (1u << (to[i] % 32));
	}
	//for(int i = 0; i < 9; ++i)
	//	cout << i << ": " << know[i][0] << " " << happy[i][0] << endl;
	//cout << "b = " << base << ", n = " << NUM << "(" << num << "): " << int(happy[base - 2][NUM / 32] & (1 << (NUM % 32))) << endl;
	//system("pause");
	return (happy[base - 2][NUM / 32] & (1 << (NUM % 32)));
}

int main() {
	memset(know, 0, sizeof(know));
	memset(happy, 0, sizeof(happy));
	for(int i = 0; i < 9; ++i) {
		know[i][0] |= (1 << 1);
		happy[i][0] |= (1 << 1);
	}
	string s;
	getline(cin, s);
	int test = 0;
	while(getline(cin, s)) {
		++test;
		vector <int> bases;
		int t;
		stringstream ss(s);
		while(ss >> t)
			bases.push_back(t);
		for(int i = 2; ; ++i) {
			foreach(j, 0, bases)
				if(!get(bases[j], i))
					goto next;
			printf("Case #%d: %d\n", test, i);
			break;
next:;
		}
	}
	return 0;
}
