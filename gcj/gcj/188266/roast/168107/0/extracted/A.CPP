
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ifstream inFile("test.in");
ofstream outFile("test.out");
int base[1000];

int baseVal[10000];
bool isGoodNum(int val, int base)
{
	int iter = 0;
	while (1)
	{
		int a = val / base;
		int b = val % base;
		int idx = 0;
		while (a != 0)
		{
			baseVal[idx++] = b;
			b = a % base;
			a = a / base;
		}
		baseVal[idx++] = b;
		
		int sumVal = 0;
		for (int i=0; i<idx; i++)
		{
			sumVal += baseVal[i] * baseVal[i];
		}
		if (sumVal == 1)
		{
			return true;
		}

		else if (val == sumVal)
		{
			return false;
		}
		val = sumVal;
		iter++;
		if (iter > 1000)
		{
			return false;;
		}
	}
}
int main()
{
	int caseNum = 0;
	inFile >> caseNum;
	
	string str;
	getline(inFile, str);
	for (int i=0; i<caseNum; i++)
	{
		string line;
		getline(inFile, line);
		int baseNum = 0;
		istringstream lineStream(line);

		while (lineStream>>base[baseNum])
		{
			baseNum++;
		}
		int num = 2;
		while (1)
		{
		//	cout << num << endl;
			int flag = 0;
			for (int k=0; k<baseNum; k++)
			{
				bool bGood = isGoodNum(num, base[k]);
				if (bGood)
				{
					flag++;
				}
				else 
				{
					break;
				}
			}
			if (flag == baseNum)
			{
				break;
			}
			num++;
		}
		outFile << "Case #" << i+1 << ": " << num << endl;
	}
}