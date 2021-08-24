#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

bool Happy(int number, int base, set<int> nums);

void main()
{
	string strline;
	fstream myin("c:\\A-small-attempt1.in", ios::in);
	fstream myout("c:\\answers.txt",ios::out);
	int T_Case = 0;
	myin>>T_Case;
	getline(myin,strline);
	for(int i = 0; i < T_Case; i++)
	{
		int base[9];
		getline(myin,strline);
		unsigned int g = 0;
		int g1 = 0;
		for(g; g < strline.size(); )
		{
			string ss;
			bool digit = false;
			while(isdigit(strline[g]))
			{
				digit = true;
				ss += strline[g];
				g++;
			}
			if(digit)
			{
				base[g1] = atoi(ss.c_str());
				g1++;
			}
			else
				g++;
		}
		int b_sum = g1;
		base[g1] = 0;
		set<int> nums;
		int num = 2;
		for(num;;num++)
		{
			g1 = 0;
			bool happy = true;
			while(happy)
			{
				happy = Happy(num,base[g1],nums);
				g1++;
				if(base[g1] == 0 || happy == false)
					break;
			}
			if(base[g1] == 0 && happy != false)
				break;
		}
		myout<<"Case #"<<(i+1)<<": "<<num<<endl;
	}
	

	return;
}


bool Happy(int number, int base, set<int> nums)
{
	int temp = number;
	int temp1;
	int sum = 0;

	pair< set<int>::iterator, bool > pr;
	pr = nums.insert(number);
	if(pr.second == false)
		return false;
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
			return Happy(sum,base,nums);
		}
	}
}