/* A.cpp
 * By: Michael Robertson
 * Google Code Jam Round 1
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>


#define INFILE "A-small-attempt1.in"
#define OUTFILE "a.out"

using namespace std;

int ishappy( int number, int base, int call = 0);
int changebase( int number, int base);

int main() {
	
	ifstream file;
	ofstream output;
	output.open(OUTFILE);
	int numCases;
	file.open(INFILE);
	if (file.is_open()) {
		file >> numCases;
//		cout << numCases;
	} else {
		cerr << "error opening file" << endl;
	}
	string in;
	getline(file,in);
	for (int i = 0; i < numCases; i++) {
		cout << "Case #" << i+1 << ": ";
		output << "Case #" << i+1 << ": ";
		istringstream o;
		getline(file,in);
		o.str(in);
		int bases[10];
		int i, temp;
		o >> bases[0];
		for (i = 1; i < 10; i++) {
			o >> temp;
			if (bases[i-1] != temp) {
				bases[i] = temp;
			} else {
				break;
			}
		}
		int num = 1;
		bool base [10];
		bool found = 0;
		while (found==0) {
			num++;
			found = 1;
			for (int j =0; j < i; j++) {
				base[j] = ishappy( num, bases[j]);
				found = found&&base[j];
			}
			//cout << num <<  " found " << found << endl;
		}
		cout << num << endl;
		output << num << endl;
	}
	//~ cout << "TEST: " << ishappy(3, 2) << endl;
	//~ cout << "TEST: " << changebase(10, 2) << endl;
}

int ishappy( int number, int base, int call) {
	number = changebase(number, base);
	int length;
	ostringstream o;
	o<<number;
	length = o.str().size();
	int num[length];
	int newNum = 0;
	for (int i = 0; i < length; i++) {
		num[i]= number/pow(10,length-(1+i));
		number -= num[i]*pow(10,length-(1+i));
		newNum += num[i]*num[i];
	}
	number = newNum;
	//cout << number << endl;
	if (number == 1) {
		return 1;
	} else if ((number < 1)||(call > 50)) {
		return 0;
	} else {
		return ishappy (number, base, call+1);
	}
}

int changebase( int number, int base) {
	int num = 0;
	int digits[100];
	int i =-1;
	while (number > 0) {
	i++;
	digits[i]=number%base;
	number =number/base;
	}
	for (int j = i; j>=0; j--) {
		num += digits[j]*pow(10,j);
	}
	return num;
}
