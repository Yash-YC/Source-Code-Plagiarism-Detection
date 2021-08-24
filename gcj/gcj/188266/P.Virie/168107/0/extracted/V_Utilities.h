#ifndef V_UTILITIES_H_
#define V_UTILITIES_H_

#include <string>
#include <vector>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include <iostream>
#include <fstream>
#include "limits.h"
#include "V_Utilities.h"


using namespace std;


#ifndef max
#define max(a,b) (((a) > (b))? (a) : (b))
#define min(a,b) (((a) < (b))? (a) : (b))
#endif

#ifndef V_MAXINT
#define V_MAXINT 2000000000
#endif

#ifndef V_PI
#define V_PI 3.14159265
#endif

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()




int powInt(int base,int pow)
{
	int i;
	int sum = base;
	for(i = 1;i<pow;i++)
		sum *= base;
	return sum;
}

int IsStringConsistOf(char* string ,char c)
{
	int index = 0;
	while((*string) != '\0')
	{
		if((*string) == c) return index;
		++string;
		++index;
	}
	return -1;
}

int IsStringConsistOfAndSplit(char* string ,char c,int &num)
{
	int index = 0;
	int outIndex = -1;
	while((*string) != '\0')
	{
		if((*string) == c) 
		{
			*string = '\0';
			outIndex = index;
			break;
		}
		++string;
		++index;
	}
	if(outIndex != -1)
	{
		++string;
		num = atoi(string);
	}else num = 0;
	return outIndex;
}

int findEOS(char* string,int max)
{
	for(int i = 0;i<max;i++)
		if(string[i] == '\0')
			return i;
	return 0;
}

int CNR(int num,int den)
{
	int sum = 1;
	int lim = max(den,num-den);
	int de = min(den,num-den);
	int i,j;
	if(num == 0) return 0;
	else if(den == 0) return 1;

	for(i = num;i>lim;i--)
		sum *= i;
	for(j = 1;j<=de;j++)
		sum /= j;
	return sum;
}

void StringSplit(string *s,char token,vector<string> *list)
{
	string line(*s);
	line += token;
	string::iterator iter = line.begin();
	int i = 0;
	int j = 0;

	for(;iter != line.end();iter++,j++)
	{
		if(*iter == token)
		{
			if(i == j) i++;
			else {
				list->push_back(line.substr(i,j-i));
				i = j+1;
			}
		}
	}
}

template <class myType>
void printFunction (myType i) {
  cout << i << " ";
}


#endif