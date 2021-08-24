#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;

void OpenFiles(ifstream &in, ofstream &out) {
	in.open("A-small-attempt0.in");
	out.open("result.txt");
	
	if(in.fail() || out.fail())
		cout << "Failed to open input or output file." << endl;
}

bool isHappyRec(int num, int base, set<int> &used) {
	
	if(used.find(num) != used.end())
		return false;
	used.insert(num);
	
	int exp;
	for (exp = 1; (num/pow(base, exp)) >= 1; ++exp);
	
	int newnum = 0;
	for (exp = exp-1; exp >= 0; --exp) {
		int x = num / pow(base, exp);
		newnum += pow(x, 2);
		num -= x * pow(base, exp);
	}
	
	if (newnum == 1)
		return true; // it's happy
	else {
		return isHappyRec(newnum, base, used); // try more
	}
	return false;
}

bool isHappy(int num, int base) {
	set<int> used;
	return isHappyRec(num, base, used);
}

int FindHappyNum(int &num, int base) {
	++num;
	while(true) {
		if (isHappy(num, base))
			return num;
		
		++num;
	}
}

int main (int argc, char * const argv[]) {
	ifstream in;
	ofstream out;
	OpenFiles(in, out);
    int numCases;
	in >> numCases;

	for (int i = 0; i < numCases; ++i) {
		vector<int> bases(11);
		in >> bases[0];
		int numBases = 1;
		for (int j = 1; in.get() != '\n' && !in.fail(); ++j) {
			in >> bases[j];
			++numBases;
		}
		
		int num = 1;
		bool works = false;
		while (!works) {
			works = true;
			num = FindHappyNum(num, bases[0]);
			for (int i = 1; (i < numBases) && works; ++i) {
				if (!isHappy(num, bases[i])) {
					works = false;
				}
			}
		}
		out << "Case #" << i+1 << ": " << num << endl;;
	}
	
	return 0;
}
