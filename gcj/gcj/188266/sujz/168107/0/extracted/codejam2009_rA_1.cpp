// codejam2009_rA_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

string convert(int num,int bs)
{
	char outputdata[1000];
	int m,n;  

	m = 0;  
	n = 0;  

	while (num)   
	{  
		m = num % bs;  
		if (m > 9)  
		{  
			outputdata[n] = m + 'A' - 10;  
		}  
		else  
		{  
			outputdata[n] = m + '0';  
		}  
		num = num / bs;  
		n++;  
	}  

	for (m = 0; m <= n / 2 - 1; m++)    
	{  
		char t;  
		t = outputdata[m];  
		outputdata[m] = outputdata[n - 1 - m];  
		outputdata[n - 1 - m] = t;  
	}  
	outputdata[n] = '\0'; 
	string v(outputdata);
	return v;
}

bool isHappy(int num,int bs)
{
	vector<int> traverse;
	string v = convert(num,bs);
	int sum = 0;
	for (int k = 0; k < v.size();k++)
	{
		sum += (v[k]-'0')*(v[k]-'0');
	}

	while (sum != 1)
	{
		vector<int>::iterator it;
		for (it = traverse.begin(); it < traverse.end(); it++)
		{
			if (*it == sum)
			{
				break;
			}
		}
		if (it == traverse.end())
		{
			traverse.push_back(sum);
			string v = convert(sum,bs);
			sum = 0;
			for (int k = 0; k < v.size();k++)
			{
				sum += (v[k]-'0')*(v[k]-'0');
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("A-small-attempt0.in");
	outFile.open("out.txt");

	char str[1000];
	inFile.getline(str,1000);
	int T = atoi(str);

	for (int i = 0; i < T; i++)
	{
		inFile.getline(str,1000);
		string str2(str);
		vector<int> base;
		size_t pos = 0;
		string tmp;

		size_t found = str2.find_first_of(' ');
		while(found != string::npos)
		{
			tmp = str2.substr(pos,found);
			base.push_back(atoi(tmp.c_str()));
			pos = found;
			found = str2.find_first_of(' ',pos+1);
		}
		tmp = str2.substr(pos,str2.size()-pos);
		base.push_back(atoi(tmp.c_str()));

		int start = 2;
		int j = 0;
		while (1)
		{
			bool happy = isHappy(start,base[j]);
			while(happy && j < base.size())
			{
				j++;
				if (j < base.size())
				{
					happy &= isHappy(start,base[j]);
				}				
			}
			if (j == base.size())
			{
				outFile << "Case #" << i+1 << ": " << start << endl;
				break;
			}
			else
			{
				start++;
				j = 0;
			}
		}		
	}
	
	inFile.close();
	outFile.close();
	return 0;
}

