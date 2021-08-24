#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

const int MAX_NUM = 10000000;
vvi happy(11, vi(MAX_NUM));

ll convertToBase(ll num, int base) {
	ll result = 0;
	while (num) {
		result *= 10;
		result += num % base;
		num /= base;
	}
	return result;
}

ll add(ll a, ll b, int base) {
	ll result = 0;
	int carry = 0;
	ll power = 1;
	while (a || b) {
		int tmp = a % 10 + b % 10;
		result += power * ((tmp + carry) % base);
		carry = (tmp + carry) / base;
		a /= 10;
		b /= 10;
		power *= 10;
	}
	result += carry * power;
	return result;
}

ll digitSquareSum(ll num, int base) {
	ll result = 0;
	int origNum = num;
	while (num) {
		int tmp = num % 10;
		tmp *= tmp;
		result += tmp;
		num /= 10;
	}
	return convertToBase(result, base);
}

// 1 - happy
// 2 - unhappy
// 3 - testing
int testNumber(int num, int base)
{
	if (num < MAX_NUM && happy[base][num]) {
		if (happy[base][num] == 3) {
			return happy[base][num] = 2;
		}
		return happy[base][num];
	}
	if (num == 1) {
		return happy[base][num] = 1;
	}
	if (num < MAX_NUM) {
		happy[base][num] = 3;
	}
	int newNum = digitSquareSum(num, base);
	if (num < MAX_NUM) {
		return happy[base][num] = testNumber(newNum, base);
	}
	else {
		return testNumber(newNum, base);
	}
}

int main()
{
	ifstream cin("A-small-attempt0(2).in");
	ofstream cout("file.out");
	
	int N;
	cin >> N;
	string tmp;
	getline(cin, tmp);
	for (int testCase = 0; testCase < N; ++testCase) {
		string testCaseLine;
		getline(cin, testCaseLine);
		istringstream sin(testCaseLine);
		vector <int> bases;
		int tmp;
		while (sin >> tmp, sin) {
			bases.push_back(tmp);
		}
		for (int i = 2; ; ++i) {
			int can = 1;
			for (int curBaseId = 0; curBaseId < bases.size(); ++curBaseId) {
				if (testNumber(convertToBase(i, bases[curBaseId]), bases[curBaseId]) != 1) {
					can = 0;
					break;
				}
			}
			if (can) {
				cout << "Case #" << testCase + 1 << ": " << i << endl;
				break;
			}
		}
	}

	return 0;
}
