#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const int MAXN = 10;
int bases[MAXN];

int power(int x ,int y)
{
	int result = 1;
	for (int i = 1 ; i <= y ; ++i)
		result *= x;
	return result;
}


vector<int> InToBase(int number,int base)
{
	vector<int> Reverse,Result;
	while (number > 0){
		Reverse.push_back(number % base);
		number /= base;
	}
	for (int i = Reverse.size()-1 ; i >=0 ; --i)
		Result.push_back(Reverse[i]);
	return Result;  

}

int ToDecimal(int number, int base)
{
	int result = 0 , count = 0;
	while (number > 0) {
		int digit = number % 10;
		number /= 10;
		result += digit * power(base,count);
		count++;
	}
	return result;
}

bool check(const vector<int> &number)
{
	int sum = 0;
	for (int i = 0 ; i < number.size() ; ++i){
		sum += number[i];
		if (sum > 1)
			return false;
	}
	return true;
}


bool IsHappy(vector<int> digit,int base)
{
	vector<vector<int>> used;
	while (1){
		int result = 0;
 		for (int i = 0 ; i < digit.size() ; ++i){
			int thisdigit = ToDecimal(digit[i],base);
			result += thisdigit * thisdigit;
		}
		vector<int> temp =InToBase(result,base);

		digit = temp;
		if (check(temp))
			return true;
		vector<vector<int>>::iterator iter;
		for (iter = 	used.begin() ; iter != used.end() ; ++iter)
			if (*iter == temp)
				return false;
		used.push_back(temp);
	}

}




int main()
{
	ifstream in("a.in");
	ofstream out("a.out");
	int T;

	in >> T;
	string temp;
	getline(in,temp);
	for (int k = 1 ; k <= T ; ++k){


	getline(in,temp);
	int avi = 0 ;
	while (1){
 		int pos = temp.find(" ");
		if (pos == string::npos){
			bases[avi++] = atoi(temp.c_str());
			break;
		}
		string tempstr = temp.substr(0,pos);
		bases[avi++] = atoi(tempstr.c_str());
		temp.erase(0,pos+1);
	}

	int number = 1;
	bool found = false;
	while (!found){
		found = true;
		++number;
		for (int j = 0 ; j < avi ; ++j){
			 vector<int> newbase = InToBase(number,bases[j]);
			 if (!IsHappy(newbase,bases[j])){
				 found = false;
				 break;
			 }
		}
		if (found){
			out << "Case #" << k <<": " << number << endl;
			found = true;
		}
	}
	}
	return 0;
}
