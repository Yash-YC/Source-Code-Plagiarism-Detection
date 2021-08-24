// Problem A. The Last Word.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;


void main()
{
	ofstream fout("output.out");
	ifstream fin("A-large.in");
	string s;
	int n;
	fin >> n;
	for (int j = 1;j <= n;j++) {
		fin >> s;
		vector <char> vec;
		vec.insert(vec.begin(), s[0]);
		for (int i = 1;s[i];i++)
		{
			if (s[i] >= vec[0]) vec.insert(vec.begin(), s[i]);
			else vec.insert(vec.end(), s[i]);
		}
		fout << "Case #" << j << ": ";
		copy(vec.begin(), vec.end(), ostream_iterator<char>(fout, ""));
		fout << endl;
	}

}

