#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

bool IsHappy(int number, int base, set<int> nums);

void main()
{
	string line;

	fstream myin("c:\\A-small-attempt1.in", ios::in);
	fstream myout("c:\\answers.txt",ios::out);

	//Get the Test Case
	int T_Case = 0;
	myin>>T_Case;

	getline(myin,line);


	//Do each Test Case
	for(int i = 0; i < T_Case; i++)
	{
		int base[9];
		//Get each line of bases and parse each base into the array
		getline(myin,line);
		unsigned int k = 0;
		int k1 = 0;
		for(k; k < line.size(); )
		{
			string ss;
			bool digit = false;
			while(isdigit(line[k]))
			{
				digit = true;
				ss += line[k];
				k++;
			}
			if(digit)
			{
				base[k1] = atoi(ss.c_str());
				k1++;
			}
			else
				k++;
		}


		//Get the num of bases
		int b_sum = k1;
		base[k1] = 0;

		//Using set to avoid loops
		set<int> nums;

		//Search from one until one integer is a happy integer for all bases 
		int num = 2;
		for(num;;num++)
		{
			k1 = 0;
			bool happy = true;
			while(happy)
			{
				happy = IsHappy(num,base[k1],nums);
				k1++;
				if(base[k1] == 0 || happy == false)
					break;
			}
			if(base[k1] == 0 && happy != false)
				break;
		}

		//Output
		myout<<"Case #"<<(i+1)<<": "<<num<<endl;
	}
	

	return;
}


bool IsHappy(int number, int base, set<int> nums)
{
	int temp = number;
	int temp1;
	int sum = 0;

	pair< set<int>::iterator, bool > pr;
	pr = nums.insert(number);
	if(pr.second == false)
		return false;

	/*if( (number * number) < base)
		return false;
		*/
	else
	{
		while(temp > 0)
		{
			temp1 = temp%base;
			sum += temp1 * temp1;
			temp = temp/base;
		}
		if(sum == 1)
			return true;
		else
		{
			return IsHappy(sum,base,nums);
		}
	}
}