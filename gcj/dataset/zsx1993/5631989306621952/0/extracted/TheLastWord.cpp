// TheLastWord.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

string compareStr(const string &res, char ch) {
	string tmp1 = res + ch;
	string tmp2 = ch + res;
	if (tmp1 > tmp2) {
		return tmp1;
	}
	else {
		return tmp2;
	}
}

int main()
{
	ifstream in("A-small-attempt0.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out("A-small-attempt0.out");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	string S;
	for (int i = 1; i <= t; i++) {
		cin >> S;
		int slen = S.length();
		string res = "";
		for (int j = 0; j < slen; j++) {
			res = compareStr(res, S[j]);
		}
		cout << "Case #" << i << ": " << res << endl;
	}
	system("pause");
    return 0;
}

