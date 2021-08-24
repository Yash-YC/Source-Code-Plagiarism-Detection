#include <fstream>
#include <iostream>
#include <strstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void eol(istream &is) {
	string str;
	getline(is, str);
}

template <typename T>
T GetOneInALine(istream &inStream) {
	T toReturn;
	inStream >> toReturn;
	eol(inStream);
	return toReturn;
}

template <typename T>
vector<T> GetAllInALine(istream &inStream) {
	string line;
	getline(inStream, line);
	istrstream lineStream(line.c_str());
	vector<T> toReturn;
	T toAdd;
	while (!lineStream.eof()) {
		lineStream >> toAdd;
		toReturn.push_back(toAdd);
	}
	return toReturn;
}

int Sum(int base, int num) {
	int dig = num % base;
	dig *= dig;
	num /= base;
	if (num)
		dig += Sum(base, num);
	return dig;
}

int numDigs(int base, int num) {
	if (num)
		return numDigs(base, num/base);
	else
		return 0;
}

int maxNum(int base, int num) {
	if (num==0)
		return base;
	return base * maxNum(base, num/base);
}

bool Happy(int base, int num, vector<int> &v) {
	if (num == 1)
		return true;
	if (v[num] == 1)
		return true;
	if (v[num] == -1)
		return false;
	int sum = Sum(base, num);
	if (sum == 1)
		return true;
	v[num] = -1;
	bool toRet = Happy(base, sum, v);
	if (toRet)
		v[num] = 1;
	return toRet;
}

int Process(const vector<int>& inVec) {
	vector<vector<int>> v2(inVec.size(), vector<int>(100000,0));
	int i=2;
	do {
		bool happy = true;
		for (unsigned int j=0; j<inVec.size(); ++j) {
			if (!Happy(inVec[j], i, v2[j]))
				happy = false;
		}
		if (happy)
			return i;
		++i;
	} while(1);
	return 0;
}

int Run(istream &inStream) {
	int N;
	inStream >> N;
	eol(inStream);
	for (int j=0; j<N; ++j) {
		vector<int> inVec = GetAllInALine<int>(inStream);
		cout << "Case #" << j+1 << ": " << Process(inVec) << "\n";
	}

	return 0;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
		return Run(cin);
	else {
		ifstream inStream(argv[1]);
		return Run(inStream);
	}
}
