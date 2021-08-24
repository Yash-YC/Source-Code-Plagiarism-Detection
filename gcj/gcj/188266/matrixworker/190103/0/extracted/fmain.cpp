/*
 * fmain.cpp
 *
 *  Created on: 2009-9-12
 *      Author: sunguoyang07
 *	    E-mail: matrixworker@gmail.com
 *        Note: Solution for small data set,Round 1C, GCJ 2009
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

double compute(int C,int N)
{
	int x=1;

	double d=1/double(C-1);
	while(!(d>2))
	{
		d=d+d/(C-1);
		x++;
	}
	return (double(x))/N;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	assert(fin);
	assert(fout);

	int T, cas=1;
	fin>>T;

	int C,N;
	while(T--)
	{
		fin>>C>>N;
		fout<<"Case #"<<cas++<<": "<< compute(C,N) <<endl;
	}

	fin.close();
	fout.close();

	return 0;
}
