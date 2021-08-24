// 1A_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream"
#include "string.h"
using namespace std;

#define INFILE "A-small.in"
#define OUTFILE "A-small.out"

char str[1000];
int base[10];
int numbase;


int isHappy(int num, int b)
{
	int count=0;
	while (num!=1)
	{
		count++;
		if (count>100)
			return 0;
		int du;
		int sum=0;
		while (num!=0)
		{
			du=num%b;
			num=num/b;
			sum+=du*du;
		}
		num=sum;
	}
	return 1;
}

int accept(int num)
{
	for (int i=0; i<numbase; i++)
		if (!isHappy(num,base[i]))
			return 0;
	return 1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream infile(INFILE);
	ofstream outfile(OUTFILE);
	int t;
	infile>>t;
	infile.getline(str,1000);
	for (int i=0; i<t; i++)
	{
		infile.getline(str,1000);
		char* ptr=strtok(str," ");
		numbase=0;
		while (ptr!=NULL)
		{
			base[numbase]=atoi(ptr);
			numbase++;
			ptr=strtok(NULL," ");
		}
		int j=2;
		while (!accept(j))
		{
			j++;
		}
		outfile<<"Case #"<<i+1<<": "<<j<<endl;
	}
	infile.close();
	outfile.close();
	return 0;
}

