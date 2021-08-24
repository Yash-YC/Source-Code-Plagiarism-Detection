// GoogleCodeJam.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "limits.h"
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include "djs.h"
#include "V_Utilities.h"
#include "vMatrix.h"

using namespace std;
using namespace vMath;

int trans_atoi (string x)
{
	return atoi(x.c_str()); 
}

float trans_atof (string x)
{
	return atof(x.c_str()); 
}

bool isHappy[100000][10];
bool isSure[100000][10];

int baseM_to_base10(vector<int> *M,int base)
{
	int base10 = 0;
	long long int mul = 1;
	Rep(i,M->size())
	{
		base10 += (*M)[i]*mul;
		mul *= base;
	}
	return base10;
} 

void base10_to_baseM(int base10,vector<int>* M,int base)
{
	M->clear();
    int Num=base10; //number to convert.
    while (Num)
    {
        M->push_back(Num%base);
        Num /= base; //Do the division
    }

} 

int SquareAndSum(vector<int> *N,int base)
{
	int sum = 0;
	Rep(i,N->size())
	{
		sum += ((*N)[i])*((*N)[i]);
	}
	N->clear();
	base10_to_baseM(sum,N,base);
	return sum;
}

bool IsHappy(vector<int> *N,int base)
{
	int n = baseM_to_base10(N,base);
	int test = SquareAndSum(N,base);

	if(isSure[n][base])
		return isHappy[n][base];
	
	isSure[n][base] = 1;
	if(test == 1)
	{
		isHappy[n][base] = 1;
		return true;
	}else
	{	
		return (isHappy[n][base] = IsHappy(N,base));
	}
}



int main(int argc, char* argv[])
{


	int numCase;
	FILE* wfile;
	string line;
	char output[255];
	vector<string> tempString;
	vector<int> tempInt;
	vector<int> tempInt2;
	vector<double> tempFloat;
	vector<long long> tempLL;
	vector<vector<char>> tempVectorChar;
	vector<vector<int>> tempVectorInt;

	printf("Starting... \n");

	ifstream myfile;
	myfile.open("C:\\Documents and Settings\\Administrator\\Desktop\\A-small-attempt1.in",ios::in);
	if (!myfile.is_open()) return 0;

	wfile = fopen("C:\\Documents and Settings\\Administrator\\Desktop\\out.txt","w");	
	

	For(i,0,100000)
		For(j,0,10)
		{
			isHappy[i][j] = 0;
			isSure[i][j] = 0;	
		}

	getline(myfile,line);

	numCase = atoi(line.c_str());
	cout << numCase <<endl;

	for(int i = 0;i<numCase;++i)
	{
		tempString.clear();
		tempInt.clear();
		getline(myfile,line);
		StringSplit(&line,' ',&tempString);
		tempInt.resize(tempString.size());
		transform(All(tempString),tempInt.begin(),trans_atoi);	

		int p = 2;

		for(;p<100000;++p)
		{
			bool isSatAll = true;
			vector<int> num;
			Rep(j,tempInt.size())
			{
				base10_to_baseM(p,&num,tempInt[j]);
				if(!(isSatAll = IsHappy(&num,tempInt[j])))
				{
					break;
				}
			}
		
			if(isSatAll) break;
		
		}
		


		fprintf(wfile,"Case #%d: ",i+1);
		printf("Case #%d: ",i+1);

		fprintf(wfile,"%d",p);
		printf("%d",p);		

		fprintf(wfile,"\r\n");
		printf("\r\n");
		

	}

	fclose(wfile);
	myfile.close();
	
	return 0;
}

