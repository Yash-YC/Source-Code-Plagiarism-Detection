#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

//solution

ifstream o("A-small-attempt0.in");
ofstream oo("a-small.out");

//istringstream ss;

int N;

//for reading data
const int LINE_LENGTH = 501; 
char str[LINE_LENGTH];


//bases
int nb;
int bases[9];

void read()
{
	
	o>>N;
	cout<<N<<endl;
	
	o.getline(str,LINE_LENGTH);
	
}

long tentobase(long n, int base)
{
	long result=0;
	long tenbase=1;
	while(n>0)
	{
		result+=(n%base)*tenbase;
		n=n/base;
		tenbase*=10;
	}
	return result;
}

long square(long n)
{
	long result=0;
	while(n>0)
	{
		result+=(n%10)*(n%10);
		n=n/10;
	}
	return result;
}


bool ishappy(long n, int base)
{
	vector<long> temp;
	n=tentobase(n, base);
	temp.push_back(n);
	while(n!=1)
	{
		n=square(n);
		n=tentobase(n, base);
		for(vector<long>::iterator it=temp.begin(); it!=temp.end(); it++)
			if(long(*it)==n)
				return false;
		temp.push_back(n);
		
	}
	return true;
}


bool ishappytoall(long n)
{
	for(int i=0; i<nb; i++)
		if(ishappy(n, bases[i])==false)
			return false;
	return true;
}




void onecase(int n)
{
	long i, j;

	nb=0;
	string strstr;

	getline(o, strstr);
	istringstream ss(strstr);
	//o.getline(str,LINE_LENGTH);
	//ss<<str;
	
	cout<<"case "<<n<<": "<<str<<"......"<<endl;
	
	//	ss<<str;
		while(ss>>i)
		{
			cout<<i<<endl;
			bases[nb]=i;
			nb++;
		}

	for(i=2; ishappytoall(i)==false; i++);
	oo<<"Case #"<<n<<": "<<i<<"\n";
	cout<<"Case #"<<n<<": "<<i<<"\n";
}

int main()
{
	int result;
	read();
	cout<<"READ!"<<endl;
	for(int i=1; i<=N; i++)
	{	
		onecase(i);	
	}
	oo.close();
//	char c='0';
//	cout<<(int)c<<endl;
//	c='9';
//	cout<<(int)c<<endl;
	return 0;
}
