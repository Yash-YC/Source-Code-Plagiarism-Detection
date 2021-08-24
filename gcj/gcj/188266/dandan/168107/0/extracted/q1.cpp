#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

//#include "stdafx.h"
//#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_BASE 10
char symbols[37] = "0123456789ABCDEFGHIJKLMNoPQRSTUVWXYZ";

using namespace std;

int GetIndex(char * pString, char search)
{
	int index = 0;
	while(*pString != (char)0) //Loop will finish at null character if no match is found
	{
		if(*pString==search)
			break;
		pString++;
		index++;
	}
	return index;
}


int DecToBase(int base, long iDec, char* szString)
{
	//Check base is between 2 and 36
	if(base<2||base>MAX_BASE)
		return 0; //Failed
	//If input is 0, output is 0
	if(iDec==0){
		strcpy(szString,"0");
		return 1;
	}
	
	int count = 0;
	char chResult[256] = "";
	char* pChResult = chResult;
	while(iDec > 0 && count++<256)
	{
		*pChResult = symbols[iDec % base];
		pChResult++;
		iDec = iDec/base;	//iDec = itself divided by base
	}
	strcpy(chResult,_strrev(chResult));	
	strcpy(szString,chResult);

	return 1;
}

int BaseToDec(char* number, int base)
{
	if(base<2||base>MAX_BASE)
		return 0; //Failed

	int NumLength = strlen(number);
	int PlaceValue, total = 0;
	//Work out the place value of the first digit (base^length-1)
	PlaceValue = (int)pow(base*1.0,NumLength-1);
	
	//For each digit, multiply by its place value and add to total
	for(int i=0;i<NumLength;i++)
	{
		total += GetIndex(symbols,*number)*PlaceValue;
		number++;
		PlaceValue /= base; //Next digit's place value (previous/base)
	}
	return total;
}


long sum_digits(int base, char* str)
{
	long sum =0;
	for (int i=0; str[i]; i++) {
		int j = str[i]-'0';
		sum += j*j;
	}

	return sum;
}

bool is_happy(long num, int base)
{
	char str[5000];
	char str2[5000];

	DecToBase(base, num, str);

	vector<string> history;
	vector<string>::iterator it;

	while (true) {
		int sum = sum_digits(base, str);
		DecToBase(base, sum, str);
		it = find(history.begin(), history.end(), str);
		if (it!=history.end()) break;
		history.push_back(str);
	}

	if (!strcmp(str,"1")) return true;
	return false;

}

int main()

{

	int T;
	vector<vector<int> > bases;

	string fn;
	fn = "A-small-attempt1.in";
	ifstream infile;
	infile.open (fn.c_str(), ifstream::in);
	infile>>T;
	bases.resize(T);
	
	string line;
	getline(infile, line);
	for (int i=0; i<T; i++) {		
		getline(infile, line);
		istringstream ss(line);
		int b;
		while (!ss.eof()) {
			ss>>b;
			bases[i].push_back(b);
		}
	}
	infile.close();


	ofstream outfile;
	outfile.open (fn.append(".out").c_str(), ifstream::out);

	for (int i=0; i<T; i++) {
		outfile<<"Case #"<<i+1<<": ";

 		long start=2;
		int pos = 0;
		bool found = true;
		
		do {
			found = true;
			for (int j=0; j<bases[i].size(); j++) {
				bool bb = is_happy(start, bases[i][j]);
				int tt = bases[i][j];
				if (!is_happy(start, bases[i][j])) {
					start++;
					found = false;
					break;
				}
			}
		} while (!found);


		outfile<<start<<endl;

	}

	outfile.close();

	return 0;
}